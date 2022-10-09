#define CATCH_CONFIG_MAIN
#include "../InputDataStream/FileInputStream/CFileInputStream.h"
#include "../InputDataStream/MemoryInputStream/CMemoryInputStream.h"
#include "../OutputDataStream/FileOutputStream/CFileOutputStream.h"
#include "../OutputDataStream/MemoryOutputStream/CMemoryOutputStream.h"
#include "catch.hpp"
#include <filesystem>

std::vector<std::uint8_t> GetFileContents(std::string const& filename)
{
	std::ifstream stream(filename, std::ios_base::in | std::ios_base::binary);
	stream.unsetf(std::ios::skipws);

	std::istream_iterator<std::uint8_t> begin(stream), end;
	std::vector<std::uint8_t> result(begin, end);

	return result;
}

std::string GetTemporaryFilepath()
{
	auto const tempDir = std::filesystem::temp_directory_path();
	std::filesystem::path tempFilename("output.txt");
	auto const result = tempDir / tempFilename;

	return result.string();
}

// https://en.cppreference.com/w/cpp/filesystem/temp_directory_path

SCENARIO("File input stream")
{
	GIVEN("non existing file path")
	{
		std::string const path = "boobz.txt";

		WHEN("creating a stream")
		{
			THEN("it throws an exception")
			{
				REQUIRE_THROWS_AS(CFileInputStream(path), std::runtime_error);
			}
		}
	}

	GIVEN("a stream with empty data")
	{
		auto const data = GetFileContents("empty.txt");
		CFileInputStream stream("empty.txt");

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
			std::size_t const size = 10;
			auto bytes = new std::uint8_t[size];
			bytes[0] = '!';
			bytes[1] = '!';
			bytes[2] = '!';
			stream.ReadBlock(bytes, size);

			THEN("destination buffer is not changed")
			{
				REQUIRE(bytes[0] == '!');
				REQUIRE(bytes[1] == '!');
				REQUIRE(bytes[2] == '!');
			}

			delete[] bytes;
		}
	}

	GIVEN("a stream with sample data")
	{
		auto const data = GetFileContents("test.txt");
		CFileInputStream stream("test.txt");

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

					THEN("attempting to read byte throws an exception")
					{
						REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
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

			THEN("attempting to read byte throws an exception")
			{
				REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
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

			THEN("attempting to read byte throws an exception")
			{
				REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
			}

			delete[] bytes;
		}
	}
}

SCENARIO("File output stream")
{
	GIVEN("unavailable file path")
	{
		std::string const path = "Y:\boobz.txt";

		WHEN("creating a stream")
		{
			THEN("it throws an exception")
			{
				REQUIRE_THROWS_AS(CFileOutputStream(path), std::runtime_error);
			}
		}
	}
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
			std::size_t const size = 10;
			auto bytes = new std::uint8_t[size];
			bytes[0] = '!';
			bytes[1] = '!';
			bytes[2] = '!';
			stream.ReadBlock(bytes, size);

			THEN("destination buffer is not changed")
			{
				REQUIRE(bytes[0] == '!');
				REQUIRE(bytes[1] == '!');
				REQUIRE(bytes[2] == '!');
			}

			delete[] bytes;
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

					THEN("attempting to read byte throws an exception")
					{
						REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
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

			THEN("attempting to read byte throws an exception")
			{
				REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
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

			THEN("attempting to read byte throws an exception")
			{
				REQUIRE_THROWS_AS(stream.ReadByte(), std::ios_base::failure);
			}

			delete[] bytes;
		}
	}
}

SCENARIO("Memory output stream")
{
	GIVEN("a stream")
	{
		std::vector<std::uint8_t> data;
		CMemoryOutputStream stream(data);

		WHEN("writing a couple of bytes")
		{
			stream.WriteByte('a');
			stream.WriteByte('b');
			stream.WriteByte('c');

			THEN("data vector becomes populated with these bytes")
			{
				REQUIRE(data == std::vector<std::uint8_t>{ 'a', 'b', 'c' });
			}

			AND_WHEN("writing a subsequent block of bytes")
			{
				std::vector<std::uint8_t> bytes = { 'H', 'e', 'l', 'l' };
				stream.WriteBlock(bytes.data(), static_cast<std::streamsize>(bytes.size()));

				THEN("data vector becomes populated with new bytes")
				{
					REQUIRE(data == std::vector<std::uint8_t>{ 'a', 'b', 'c', 'H', 'e', 'l', 'l' });
				}
			}
		}

		WHEN("writing a block of bytes")
		{
			std::vector<std::uint8_t> bytes = { 'H', 'e', 'l', 'l' };
			stream.WriteBlock(bytes.data(), static_cast<std::streamsize>(bytes.size()));

			THEN("data vector matches written bytes")
			{
				REQUIRE(data == bytes);
			}

			AND_WHEN("writing some bytes")
			{
				stream.WriteByte('a');
				stream.WriteByte('b');

				THEN("data vector becomes populated with new bytes")
				{
					REQUIRE(data == std::vector<std::uint8_t>{ 'H', 'e', 'l', 'l', 'a', 'b' });
				}
			}
		}
	}
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
