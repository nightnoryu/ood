#include "CModalWindow.h"

CModalWindow::CModalWindow(std::unique_ptr<IWindowImpl>&& impl)
	: CWindow(std::move(impl))
{
}

void CModalWindow::Open()
{
	m_impl->ShowModal();
}

void CModalWindow::Close()
{
	m_impl->CloseModal();
}
