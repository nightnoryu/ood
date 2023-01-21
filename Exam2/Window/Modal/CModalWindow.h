#pragma once

#include "../CWindow.h"

class CModalWindow : public CWindow
{
public:
	explicit CModalWindow(std::unique_ptr<IWindowImpl>&& impl);

	void Open() override;
	void Close() override;
};
