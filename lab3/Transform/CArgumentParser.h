#pragma once

#include <string>
#include <vector>

struct Args
{
	std::string inputFilename;
	std::string outputFilename;

	std::vector<int> encryptionKeys;
	std::vector<int> decryptionKeys;

	bool compress;
	bool decompress;
};

class CArgumentParser
{
public:
	CArgumentParser(int argc, char const** argv);

	Args Parse() const;

private:
	std::vector<std::string_view> m_args;
};
