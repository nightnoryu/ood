#include "CChangeDocumentTitleCommand.h"

CChangeDocumentTitleCommand::CChangeDocumentTitleCommand(std::string& documentTitle, std::string const& newTitle)
	: m_documentTitle(documentTitle)
	, m_newTitle(newTitle)
{
}

void CChangeDocumentTitleCommand::DoExecute()
{
	std::swap(m_documentTitle, m_newTitle);
}

void CChangeDocumentTitleCommand::DoRollback()
{
	std::swap(m_documentTitle, m_newTitle);
}
