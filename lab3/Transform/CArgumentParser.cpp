#include "CArgumentParser.h"
#include <charconv>

CArgumentParser::CArgumentParser(int argc, char const** argv)
	: m_args(argv + 1, argv + argc)
{
}

Args CArgumentParser::Parse() const
{
	Args args;

	for (auto it = m_args.begin(); it != m_args.end(); ++it)
	{
		if (*it == "--encrypt" && ++it != m_args.end())
		{
			auto& value = *it;
			int key;
			std::from_chars(value.data(), value.data() + value.size(), key);
			args.encryptionKeys.push_back(key);
			continue;
		}

		if (*it == "--decrypt" && ++it != m_args.end())
		{
			auto& value = *it;
			int key;
			std::from_chars(value.data(), value.data() + value.size(), key);
			args.decryptionKeys.push_back(key);
			continue;
		}

		if (*it == "--compress")
		{
			args.compress = true;
			continue;
		}

		if (*it == "--decompress")
		{
			args.decompress = true;
			continue;
		}

		if (args.inputFilename.empty())
		{
			args.inputFilename = *it;
			continue;
		}
		if (args.outputFilename.empty())
		{
			args.outputFilename = *it;
			continue;
		}
	}

	return args;
}
