#define CATCH_CONFIG_MAIN
#include "../Shapes/Ellipse/CEllipse.h"
#include "../Shapes/Rectangle/CRectangle.h"
#include "../Shapes/RegularPolygon/CRegularPolygon.h"
#include "catch.hpp"
#include "fakeit.hpp"

TEST_CASE("shapes")
{
	fakeit::Mock<ICanvas> canvasMock;
	fakeit::When(Method(canvasMock, SetColor)).AlwaysReturn();
	fakeit::When(Method(canvasMock, DrawLine)).AlwaysReturn();
	fakeit::When(Method(canvasMock, DrawEllipse)).AlwaysReturn();

	auto& canvas = canvasMock.get();

	SECTION("ellipse")
	{
		GIVEN("color, center point, vertical and horizontal radius")
		{
			auto const color = Color::Red;
			Point const center = { 100, 200 };
			int const hRadius = 20;
			int const vRadius = 30;

			WHEN("creating an ellipse")
			{
				CEllipse ellipse(color, center, hRadius, vRadius);

				THEN("it has correct parameters")
				{
					REQUIRE(ellipse.GetColor() == color);

					REQUIRE(ellipse.GetCenter() == center);

					REQUIRE(ellipse.GetHorizontalRadius() == hRadius);
					REQUIRE(ellipse.GetVerticalRadius() == vRadius);
				}

				AND_WHEN("drawing the ellipse")
				{
					ellipse.Draw(canvas);

					THEN("it is drawn correctly")
					{
						REQUIRE(fakeit::Verify(Method(canvasMock, SetColor).Using(color)));
						REQUIRE(fakeit::Verify(Method(canvasMock, DrawEllipse).Using(center, hRadius, vRadius)));
					}
				}
			}
		}
	}

	SECTION("rectangle")
	{
		GIVEN("color, left top corner, right bottom corner")
		{
			auto const color = Color::Red;
			Point const leftTop = { 100, 200 };
			Point const rightBottom = { 200, 400 };

			WHEN("creating a rectangle")
			{
				CRectangle rectangle(color, leftTop, rightBottom);

				THEN("it has correct parameters")
				{
					REQUIRE(rectangle.GetColor() == color);

					REQUIRE(rectangle.GetLeftTop() == leftTop);
					REQUIRE(rectangle.GetRightBottom() == rightBottom);
				}

				AND_WHEN("drawing the rectangle")
				{
					rectangle.Draw(canvas);

					THEN("it is drawn correctly")
					{
						REQUIRE(fakeit::Verify(Method(canvasMock, SetColor).Using(color)));
						// TODO: DrawLine
					}
				}
			}
		}

		GIVEN("color, left top corner, width and height")
		{
			auto const color = Color::Red;
			Point const leftTop = { 100, 200 };
			int const width = 100;
			int const height = 200;

			WHEN("creating a rectangle")
			{
				CRectangle rectangle(color, leftTop, width, height);

				THEN("it has correct parameters")
				{
					REQUIRE(rectangle.GetColor() == color);

					REQUIRE(rectangle.GetLeftTop() == leftTop);
					REQUIRE(rectangle.GetRightBottom() == Point{ leftTop.x + width, leftTop.y + height });
				}
			}
		}
	}

	SECTION("regular polygon")
	{
		GIVEN("color, vertex count, center point and radius")
		{
			auto const color = Color::Red;
			std::size_t const vertexCount = 3;
			Point const center = { 100, 200 };
			int const radius = 30;

			WHEN("creating a regular polygon")
			{
				CRegularPolygon polygon(color, vertexCount, center, radius);

				THEN("it has correct parameters")
				{
					REQUIRE(polygon.GetColor() == color);

					REQUIRE(polygon.GetVertexCount() == vertexCount);
					REQUIRE(polygon.GetCenter() == center);
					REQUIRE(polygon.GetRadius() == radius);
				}

				AND_WHEN("drawing the polygon")
				{
					polygon.Draw(canvas);

					THEN("it is drawn correctly")
					{
						REQUIRE(fakeit::Verify(Method(canvasMock, SetColor).Using(color)));
						// TODO: DrawLine
					}
				}
			}
		}

		GIVEN("invalid vertex count")
		{
			std::size_t const vertexCount = 1;

			WHEN("creating a regular polygon")
			{
				THEN("it throws an exception")
				{
					REQUIRE_THROWS_AS(CRegularPolygon(Color::Green, vertexCount, {1, 1}, 1), std::invalid_argument);
				}
			}
		}

		GIVEN("borderline invalid vertex count")
		{
			std::size_t const vertexCount = 2;

			WHEN("creating a regular polygon")
			{
				CRegularPolygon polygon(Color::Green, vertexCount, {1, 1}, 1);

				THEN("it is created all right and has the right vertex count")
				{
					REQUIRE(polygon.GetVertexCount() == vertexCount);
				}
			}
		}
	}

	SECTION("triangle")
	{
	}
}

TEST_CASE("shape factory")
{
}

TEST_CASE("picture draft")
{
}

TEST_CASE("designer")
{
}

TEST_CASE("painter")
{
}

TEST_CASE("canvas")
{
}
