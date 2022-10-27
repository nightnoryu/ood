#include "CSetParagraphTextCommand.h"

CSetParagraphTextCommand::CSetParagraphTextCommand(std::string& paragraphText, std::string const& newText)
	: m_paragraphText(paragraphText)
	, m_newText(newText)
{
}

void CSetParagraphTextCommand::DoExecute()
{
	std::swap(m_paragraphText, m_newText);
}

void CSetParagraphTextCommand::DoRollback()
{
	std::swap(m_paragraphText, m_newText);
}
