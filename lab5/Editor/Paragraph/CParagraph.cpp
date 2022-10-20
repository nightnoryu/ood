#include "CParagraph.h"

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(std::string const& text)
{
	m_text = text;
}
