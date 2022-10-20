#define CATCH_CONFIG_MAIN
#include "../Document/CDocument.h"
#include "catch.hpp"

TEST_CASE("document model")
{
	SECTION("document")
	{
		GIVEN("a document")
		{
			CDocument document;

			WHEN("it is just created")
			{
				THEN("it has empty title")
				{
					REQUIRE(document.GetTitle().empty());
				}

				THEN("it has no items")
				{
					REQUIRE(document.GetItemsCount() == 0);
				}
			}

			WHEN("settings a title")
			{
				std::string const newTitle = "Final breakthru";
				document.SetTitle(newTitle);

				THEN("it changes")
				{
					REQUIRE(document.GetTitle() == newTitle);
				}
			}

			WHEN("inserting a paragraph")
			{
				// TODO
			}

			WHEN("inserting an image")
			{
				// TODO
			}
		}
	}

	SECTION("image")
	{
	}

	SECTION("paragraph")
	{
	}

	SECTION("document item")
	{
	}
}

TEST_CASE("commands")
{
}
