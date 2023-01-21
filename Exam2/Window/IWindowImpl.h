#pragma once

#include <string>

class IWindowImpl
{
public:
	virtual void SetTitle(std::string const& title) = 0;

	virtual void ShowModal() = 0;
	virtual void ShowPopup() = 0;

	virtual void CloseModal() = 0;
	virtual void ClosePopup() = 0;

	virtual ~IWindowImpl() = default;
};
