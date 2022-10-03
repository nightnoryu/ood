#include "CArgumentParser.h"
#include <iostream>
#include <iterator>

int main(int argc, char const** argv)
{
	CArgumentParser parser(argc, argv);

	Args args;
	try
	{
		args = parser.Parse();
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::copy(args.encryptionKeys.begin(), args.encryptionKeys.end(), std::ostream_iterator<int>(std::cout, ", "));
	std::cout << std::endl;
	std::copy(args.decryptionKeys.begin(), args.decryptionKeys.end(), std::ostream_iterator<int>(std::cout, ", "));
	std::cout << std::endl;

	std::cout << args.compress << std::endl;
	std::cout << args.decompress << std::endl;

	std::cout << args.inputFilename << std::endl;
	std::cout << args.outputFilename << std::endl;

	return EXIT_SUCCESS;
}
