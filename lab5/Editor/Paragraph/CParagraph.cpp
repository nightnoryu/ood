#include "CParagraph.h"
#include "../Command/SetParagraphTextCommand/CSetParagraphTextCommand.h"

CParagraph::CParagraph(std::string const& text, ICommandExecutor& commandExecutor)
	: m_text(text)
	, m_commandExecutor(commandExecutor)
{
}

std::string CParagraph::GetText() const
{
	return m_text;
}

void CParagraph::SetText(std::string const& text)
{
	m_commandExecutor.AddAndExecuteCommand(std::make_unique<CSetParagraphTextCommand>(m_text, text));
}
