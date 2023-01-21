#pragma once

#include "IWindowImpl.h"
#include <memory>
#include <string>

class CWindow
{
public:
	explicit CWindow(std::unique_ptr<IWindowImpl>&& impl);

	void SetTitle(std::string const& title);

	virtual void Open() = 0;
	virtual void Close() = 0;

protected:
	std::unique_ptr<IWindowImpl> m_impl;
};
