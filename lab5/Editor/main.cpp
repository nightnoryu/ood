#include "Editor/CEditor.h"
#include "Saver/HTML/CHtmlSaver.h"

int main()
{
	CHtmlSaver saver;
	CEditor editor(std::cin, std::cout, saver);
	editor.Start();

	return EXIT_SUCCESS;
}
