#include "COSXWindowImpl.h"
#include <iostream>

void COSXWindowImpl::SetTitle(std::string const& title)
{
	std::cout << "Set osx window title to \"" << title << "\"" << std::endl;
}

void COSXWindowImpl::ShowModal()
{
	std::cout << "Show osx modal" << std::endl;
}

void COSXWindowImpl::ShowPopup()
{
	std::cout << "Show osx popup" << std::endl;
}

void COSXWindowImpl::CloseModal()
{
	std::cout << "Close osx modal" << std::endl;
}

void COSXWindowImpl::ClosePopup()
{
	std::cout << "Close osx popup" << std::endl;
}
