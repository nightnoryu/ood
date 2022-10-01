#include "OutputDataStream/FileOutputStream/CFileOutputStream.h"

int main()
{
	CFileOutputStream stream("test.txt");
	stream.WriteByte('S');

	std::string block = "uck my balls, bitchezzz\n";
	stream.WriteBlock(block.c_str(), static_cast<std::streamsize>(block.length()));

	return EXIT_SUCCESS;
}
