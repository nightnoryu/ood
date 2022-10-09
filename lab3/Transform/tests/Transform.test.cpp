#define CATCH_CONFIG_MAIN
#include "../InputDataStream/MemoryInputStream/CMemoryInputStream.h"
#include "catch.hpp"

// https://en.cppreference.com/w/cpp/filesystem/temp_directory_path

SCENARIO("File input stream")
{
}

SCENARIO("File output stream")
{
}

SCENARIO("Memory input stream")
{
	GIVEN("a stream with empty data")
	{
		std::vector<std::uint8_t> data;
		CMemoryInputStream stream(data);

		THEN("it is at EOF")
		{
			REQUIRE(stream.IsEOF());
		}

		WHEN("reading a byte")
		{
			THEN("it throws an exception")
			{
				REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
			}
		}

		WHEN("reading a block")
		{
			THEN("it throws an exception")
			{
				std::size_t const size = 10;
				auto bytes = new std::uint8_t[size];

				REQUIRE_THROWS_AS(stream.ReadBlock(bytes, size), std::ios_base::failure);

				delete[] bytes;
			}
		}
	}

	GIVEN("a stream with sample data")
	{
		std::vector<std::uint8_t> data = { 'H', 'e', 'l', 'l', 'o' };
		CMemoryInputStream stream(data);

		THEN("it is not at EOF")
		{
			REQUIRE_FALSE(stream.IsEOF());
		}

		WHEN("reading by bytes")
		{
			THEN("data matches initial")
			{
				for (auto&& ch : data)
				{
					REQUIRE(stream.ReadByte() == ch);
				}

				AND_WHEN("all data has been read")
				{
					THEN("it is at EOF")
					{
						REQUIRE(stream.IsEOF());
					}
				}
			}
		}

		WHEN("reading some characters by block")
		{
			std::size_t const size = 2;
			auto bytes = new std::uint8_t[size];
			stream.ReadBlock(bytes, static_cast<std::streamsize>(size));

			THEN("data matches initial")
			{
				REQUIRE(std::memcmp(data.data(), bytes, size) == 0);
			}

			THEN("it is not at EOF")
			{
				REQUIRE_FALSE(stream.IsEOF());
			}

			THEN("next byte is read correctly")
			{
				REQUIRE(stream.ReadByte() == data[size]);
			}

			delete[] bytes;
		}

		WHEN("reading everything by block")
		{
			auto bytes = new std::uint8_t[data.size()];
			stream.ReadBlock(bytes, static_cast<std::streamsize>(data.size()));

			THEN("data matches initial")
			{
				REQUIRE(std::memcmp(data.data(), bytes, data.size()) == 0);
			}

			delete[] bytes;
		}

		WHEN("reading more characters than there is in the stream")
		{
			auto bytes = new std::uint8_t[data.size()];
			stream.ReadBlock(bytes, static_cast<std::streamsize>(data.size() + 10));

			THEN("data matches initial")
			{
				REQUIRE(std::memcmp(data.data(), bytes, data.size()) == 0);
			}

			delete[] bytes;
		}
	}
}

SCENARIO("Memory output stream")
{
}

SCENARIO("Encrypting output stream decorator")
{
}

SCENARIO("Decrypting input stream decorator")
{
}

SCENARIO("Compressing output stream decorator")
{
}

SCENARIO("Decompressing input stream decorator")
{
}
