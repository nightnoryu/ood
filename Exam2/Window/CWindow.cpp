#include "CWindow.h"

CWindow::CWindow(std::unique_ptr<IWindowImpl>&& impl)
	: m_impl(std::move(impl))
{
}

void CWindow::SetTitle(std::string const& title)
{
	m_impl->SetTitle(title);
}
