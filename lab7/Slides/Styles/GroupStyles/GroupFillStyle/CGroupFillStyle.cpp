#include "CGroupFillStyle.h"

CGroupFillStyle::CGroupFillStyle(IStyleEnumerator const& enumerator)
	: m_enumerator(enumerator)
{
}

bool CGroupFillStyle::IsEnabled() const
{
	bool enabled = true;

	m_enumerator([&enabled](IStyle& style) {
		enabled &= style.IsEnabled();
	});

	return enabled;
}

void CGroupFillStyle::Enable()
{
	m_enumerator([](IStyle& style) {
		style.Enable();
	});
}

void CGroupFillStyle::Disable()
{
	m_enumerator([](IStyle& style) {
		style.Disable();
	});
}

std::optional<RgbaColor> CGroupFillStyle::GetColor() const
{
	// TODO: implement with optional
	return std::nullopt;
}

void CGroupFillStyle::SetColor(RgbaColor color)
{
	m_enumerator([color](IStyle& style) {
		style.SetColor(color);
	});
}