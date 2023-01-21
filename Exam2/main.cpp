#include "Window/CWindow.h"
#include "Window/Modal/CModalWindow.h"
#include "Window/Popup/CPopupWindow.h"
#include "WindowImpl/OSX/CosxWindowImpl.h"
#include "WindowImpl/Win32/CWin32WindowImpl.h"
#include <iostream>

void WorkWithWindow(CWindow& window)
{
	window.Open();
	window.SetTitle("testing");
	window.Close();
}

int main()
{
	CPopupWindow win32Popup(std::make_unique<CWin32WindowImpl>());
	CModalWindow osxModal(std::make_unique<COSXWindowImpl>());

	WorkWithWindow(win32Popup);
	std::cout << std::endl;
	WorkWithWindow(osxModal);

	return EXIT_SUCCESS;
}
