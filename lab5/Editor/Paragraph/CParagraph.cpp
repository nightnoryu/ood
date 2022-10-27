#include "CParagraph.h"
#include "../Command/SetParagraphTextCommand/CSetParagraphTextCommand.h"

CParagraph::CParagraph(std::string const& text, IHistory& history)
	: m_text(text)
	, m_history(history)
{
}

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(std::string const& text)
{
	m_history.AddAndExecuteCommand(std::make_unique<CSetParagraphTextCommand>(m_text, text));
}
