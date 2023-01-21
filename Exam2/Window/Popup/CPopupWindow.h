#pragma once

#include "../CWindow.h"

class CPopupWindow : public CWindow
{
public:
	explicit CPopupWindow(std::unique_ptr<IWindowImpl>&& impl);

	void Open() override;
	void Close() override;
};
