#define CATCH_CONFIG_MAIN
#include "../ShapeFactory/CShapeFactory.h"
#include "../Shapes/Ellipse/CEllipse.h"
#include "../Shapes/Rectangle/CRectangle.h"
#include "../Shapes/RegularPolygon/CRegularPolygon.h"
#include "../Shapes/Triangle/CTriangle.h"
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
					REQUIRE_THROWS_AS(CRegularPolygon(Color::Green, vertexCount, { 1, 1 }, 1), std::invalid_argument);
				}
			}
		}

		GIVEN("borderline invalid vertex count")
		{
			std::size_t const vertexCount = 2;

			WHEN("creating a regular polygon")
			{
				CRegularPolygon polygon(Color::Green, vertexCount, { 1, 1 }, 1);

				THEN("it is created all right and has the right vertex count")
				{
					REQUIRE(polygon.GetVertexCount() == vertexCount);
				}
			}
		}
	}

	SECTION("triangle")
	{
		GIVEN("color and 3 vertices")
		{
			auto const color = Color::Red;
			Point const vertex1 = { 100, 200 };
			Point const vertex2 = { 150, 250 };
			Point const vertex3 = { 100, 300 };

			WHEN("creating a triangle")
			{
				CTriangle triangle(color, vertex1, vertex2, vertex3);

				THEN("it has correct parameters")
				{
					REQUIRE(triangle.GetColor() == color);

					REQUIRE(triangle.GetVertex1() == vertex1);
					REQUIRE(triangle.GetVertex2() == vertex2);
					REQUIRE(triangle.GetVertex3() == vertex3);
				}

				AND_WHEN("drawing the rectangle")
				{
					triangle.Draw(canvas);

					THEN("it is drawn correctly")
					{
						REQUIRE(fakeit::Verify(Method(canvasMock, SetColor).Using(color)));
						// TODO: DrawLine
					}
				}
			}
		}
	}
}

TEST_CASE("shape factory")
{
	GIVEN("a factory")
	{
		CShapeFactory factory;

		AND_GIVEN("valid ellipse description")
		{
			std::string const description = "ellipse pink 100 100 50 40";

			WHEN("creating a shape")
			{
				auto const shape = factory.CreateShape(description);

				THEN("it is a valid ellipse")
				{
					auto const* ellipse = dynamic_cast<CEllipse const*>(shape.get());

					REQUIRE(ellipse != nullptr);

					REQUIRE(ellipse->GetColor() == Color::Pink);

					REQUIRE(ellipse->GetCenter() == Point{ 100, 100 });
					REQUIRE(ellipse->GetHorizontalRadius() == 50);
					REQUIRE(ellipse->GetVerticalRadius() == 40);
				}
			}
		}

		AND_GIVEN("valid rectangle description")
		{
			std::string const description = "rectangle black 100 100 50 40";

			WHEN("creating a shape")
			{
				auto const shape = factory.CreateShape(description);

				THEN("it is a valid rectangle")
				{
					auto const* rectangle = dynamic_cast<CRectangle const*>(shape.get());

					REQUIRE(rectangle != nullptr);

					REQUIRE(rectangle->GetColor() == Color::Black);

					REQUIRE(rectangle->GetLeftTop() == Point{ 100, 100 });
					REQUIRE(rectangle->GetRightBottom() == Point{ 150, 140 });
				}
			}
		}

		AND_GIVEN("valid regular polygon description")
		{
			std::string const description = "regular-polygon yellow 4 100 100 50";

			WHEN("creating a shape")
			{
				auto const shape = factory.CreateShape(description);

				THEN("it is a valid regular polygon")
				{
					auto const* regularPolygon = dynamic_cast<CRegularPolygon const*>(shape.get());

					REQUIRE(regularPolygon != nullptr);

					REQUIRE(regularPolygon->GetColor() == Color::Yellow);

					REQUIRE(regularPolygon->GetVertexCount() == 4);
					REQUIRE(regularPolygon->GetCenter() == Point{100, 100});
					REQUIRE(regularPolygon->GetRadius() == 50);
				}
			}
		}

		AND_GIVEN("valid triangle description")
		{
			std::string const description = "triangle green 100 200 150 250 100 300";

			WHEN("creating a shape")
			{
				auto const shape = factory.CreateShape(description);

				THEN("it is a valid triangle")
				{
					auto const* triangle = dynamic_cast<CTriangle const*>(shape.get());

					REQUIRE(triangle != nullptr);

					REQUIRE(triangle->GetColor() == Color::Green);

					REQUIRE(triangle->GetVertex1() == Point{ 100, 200 });
					REQUIRE(triangle->GetVertex2() == Point{ 150, 250 });
					REQUIRE(triangle->GetVertex3() == Point{ 100, 300 });
				}
			}
		}

		AND_GIVEN("empty description")
		{
			std::string const description;

			WHEN("trying to create a shape")
			{
				THEN("it throws an exception")
				{
					REQUIRE_THROWS_AS(factory.CreateShape(description), std::invalid_argument);
				}
			}
		}

		AND_GIVEN("description with invalid shape")
		{
			std::string const description = "my-ass red 100 100";

			WHEN("trying to create a shape")
			{
				THEN("it throws an exception")
				{
					REQUIRE_THROWS_AS(factory.CreateShape(description), std::invalid_argument);
				}
			}
		}

		AND_GIVEN("description with invalid arguments count")
		{
		}

		AND_GIVEN("description with invalid color")
		{
			std::string const description = "rectangle bloody 100 100 50 50";

			WHEN("trying to create a shape")
			{
				THEN("it throws an exception")
				{
					REQUIRE_THROWS_AS(factory.CreateShape(description), std::invalid_argument);
				}
			}
		}

		AND_GIVEN("description with invalid number")
		{
			std::string const description = "rectangle green 1s00 100 50 50";

			WHEN("trying to create a shape")
			{
				THEN("it throws an exception")
				{
					REQUIRE_THROWS_AS(factory.CreateShape(description), std::invalid_argument);
				}
			}
		}
	}
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
