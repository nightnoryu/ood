#include "CWin32WindowImpl.h"
#include <iostream>

void CWin32WindowImpl::SetTitle(std::string const& title)
{
	std::cout << "Set win32 window title to \"" << title << "\"" << std::endl;
}

void CWin32WindowImpl::ShowModal()
{
	std::cout << "Show win32 modal" << std::endl;
}

void CWin32WindowImpl::ShowPopup()
{
	std::cout << "Show win32 popup" << std::endl;
}

void CWin32WindowImpl::CloseModal()
{
	std::cout << "Close win32 modal" << std::endl;
}

void CWin32WindowImpl::ClosePopup()
{
	std::cout << "Close win32 popup" << std::endl;
}
