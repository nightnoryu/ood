#include "ArgumentParser/CArgumentParser.h"
#include "Transformer/CTransformer.h"
#include <iostream>

int main(int argc, char const** argv)
{
	try
	{
		CArgumentParser parser(argc, argv);
		auto const args = parser.Parse();

		CTransformer transformer(args);
		transformer.Transform();
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
