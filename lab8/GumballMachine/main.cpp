#include "Menu/CMenu.h"

int main()
{
	CMenu menu(std::cin, std::cout, 5);
	menu.Start();

	return EXIT_SUCCESS;
}
