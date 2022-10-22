#define CATCH_CONFIG_MAIN
#include "../Document/CDocument.h"
#include "../Image/CImage.h"
#include "../Paragraph/CParagraph.h"
#include "catch.hpp"
#include "fakeit.hpp"
#include <filesystem>

TEST_CASE("document model")
{
	fakeit::Mock<IHistory> historyMock;
	fakeit::Fake(Method(historyMock, CanUndo));
	fakeit::Fake(Method(historyMock, Undo));
	fakeit::Fake(Method(historyMock, CanRedo));
	fakeit::Fake(Method(historyMock, Redo));
	fakeit::Fake(Method(historyMock, AddAndExecuteCommand));

	fakeit::Mock<ISaver> saverMock;
	fakeit::Fake(Method(saverMock, Save));

	auto& history = historyMock.get();
	auto& saver = saverMock.get();

	SECTION("document")
	{
		GIVEN("a document")
		{
			CDocument document(history, saver);

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

			WHEN("inserting a paragraph")
			{
				document.InsertParagraph("whatever", std::nullopt);

				THEN("it delegates to history")
				{
					fakeit::Verify(Method(historyMock, AddAndExecuteCommand)).Exactly(1);
				}
			}

			WHEN("inserting an image")
			{
				document.InsertImage("image.jpg", 50, 50, std::nullopt);

				THEN("it delegates to history")
				{
					fakeit::Verify(Method(historyMock, AddAndExecuteCommand)).Exactly(1);
				}
			}

			WHEN("changing the title")
			{
				document.SetTitle("whatever");

				THEN("it delegates to history")
				{
					fakeit::Verify(Method(historyMock, AddAndExecuteCommand)).Exactly(1);
				}
			}

			WHEN("operating with history")
			{
				document.CanUndo();
				document.Undo();
				document.CanRedo();
				document.Redo();

				THEN("it delegates to history")
				{
					fakeit::Verify(Method(historyMock, CanUndo)).Exactly(1);
					fakeit::Verify(Method(historyMock, Undo)).Exactly(1);
					fakeit::Verify(Method(historyMock, CanRedo)).Exactly(1);
					fakeit::Verify(Method(historyMock, Redo)).Exactly(1);
				}
			}

			WHEN("saving the document")
			{
				document.Save("whatever");

				THEN("it delegates to saver")
				{
					fakeit::Verify(Method(saverMock, Save)).Exactly(1);
				}
			}
		}
	}

	SECTION("image")
	{
		std::string const path = "image.jpg";

		WHEN("trying to create with invalid dimensions")
		{
			THEN("it throws an exception")
			{
				REQUIRE_THROWS_AS(CImage(path, 0, 10, history), std::invalid_argument);
				REQUIRE_THROWS_AS(CImage(path, 10, 0, history), std::invalid_argument);

				REQUIRE_THROWS_AS(CImage(path, 5001, 10, history), std::invalid_argument);
				REQUIRE_THROWS_AS(CImage(path, 10, 5001, history), std::invalid_argument);
			}
		}

		WHEN("trying to create with borderline dimensions")
		{
			THEN("it is created just fine")
			{
				REQUIRE_NOTHROW(CImage(path, 1, 10, history));
				REQUIRE_NOTHROW(CImage(path, 10, 1, history));

				REQUIRE_NOTHROW(CImage(path, 5000, 10, history));
				REQUIRE_NOTHROW(CImage(path, 10, 5000, history));
			}
		}

		WHEN("trying to create with invalid file extension")
		{
			THEN("it throws an exception")
			{
				REQUIRE_THROWS_AS(CImage("test.txt", 10, 10, history), std::invalid_argument);
			}
		}

		WHEN("trying to create with absent file")
		{
			THEN("it throws an exception")
			{
				REQUIRE_THROWS_AS(CImage("non_existing.jpg", 10, 10, history), std::runtime_error);
			}
		}

		WHEN("creating with valid parameters")
		{
			std::string tmpPath;

			{
				std::size_t const width = 50;
				std::size_t const height = 90;
				CImage image(path, width, height, history);
				tmpPath = image.GetPath();

				THEN("parameters match")
				{
					REQUIRE(image.GetWidth() == width);
					REQUIRE(image.GetHeight() == height);
				}

				THEN("a temporary path and file is generated")
				{
					REQUIRE(tmpPath != path);
					REQUIRE(std::filesystem::exists(tmpPath));
				}

				WHEN("resizing the image")
				{
					image.Resize(10, 10);

					THEN("it delegates to history")
					{
						fakeit::Verify(Method(historyMock, AddAndExecuteCommand)).Exactly(1);
					}
				}
			}

			AND_WHEN("image is destroyed")
			{
				THEN("temporary file is deleted")
				{
					REQUIRE_FALSE(std::filesystem::exists(tmpPath));
				}
			}
		}
	}

	SECTION("paragraph")
	{
		WHEN("creating a paragraph")
		{
			std::string const text = "boobz";
			CParagraph paragraph(text, history);

			THEN("it has initial text")
			{
				REQUIRE(paragraph.GetText() == text);
			}

			AND_WHEN("changing the text")
			{
				paragraph.SetText("NO BOOBZ D:");

				THEN("it delegates to history")
				{
					fakeit::Verify(Method(historyMock, AddAndExecuteCommand)).Exactly(1);
				}
			}
		}
	}

	SECTION("document item")
	{
		std::string const value = "one flesh one bone one true religion";

		fakeit::Mock<IImage> imageMock;
		fakeit::When(Method(imageMock, GetPath)).AlwaysReturn(value);
		fakeit::Fake(Method(imageMock, GetWidth));
		fakeit::Fake(Method(imageMock, GetHeight));
		fakeit::Fake(Method(imageMock, Resize));

		fakeit::Mock<IParagraph> paragraphMock;
		fakeit::When(Method(paragraphMock, GetText)).AlwaysReturn(value);
		fakeit::Fake(Method(paragraphMock, SetText));

		auto& image = imageMock.get();
		std::shared_ptr<IImage> imagePtr(&image);

		auto& paragraph = paragraphMock.get();
		std::shared_ptr<IParagraph> paragraphPtr(&paragraph);

		WHEN("creating a document item with image")
		{
			CDocumentItem item(std::move(imagePtr));

			THEN("it has that image")
			{
				REQUIRE(item.GetImage() != nullptr);
				REQUIRE(item.GetImage()->GetPath() == value);
			}

			THEN("it has no paragraph")
			{
				REQUIRE(item.GetParagraph() == nullptr);
			}
		}

		WHEN("creating a document item with paragraph")
		{
			CDocumentItem item(std::move(paragraphPtr));

			THEN("it has that paragraph")
			{
				REQUIRE(item.GetParagraph() != nullptr);
				REQUIRE(item.GetParagraph()->GetText() == value);
			}

			THEN("it has no image")
			{
				REQUIRE(item.GetImage() == nullptr);
			}
		}
	}
}

TEST_CASE("commands")
{
	SECTION("change document title")
	{
	}

	SECTION("delete item")
	{
	}

	SECTION("insert document item")
	{
	}

	SECTION("resize image")
	{
	}

	SECTION("set paragraph text")
	{
	}
}

TEST_CASE("history")
{
	// TODO
}

TEST_CASE("html saver")
{
	// TODO
}
