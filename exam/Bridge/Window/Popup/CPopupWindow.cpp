#include "CPopupWindow.h"

CPopupWindow::CPopupWindow(std::unique_ptr<IWindowImpl>&& impl)
	: CWindow(std::move(impl))
{
}

void CPopupWindow::Open()
{
	m_impl->ShowPopup();
}

void CPopupWindow::Close()
{
	m_impl->ClosePopup();
}
