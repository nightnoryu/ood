#pragma once

#include "../AbstractCommand/CAbstractCommand.h"
#include <string>

class CChangeDocumentTitleCommand : public CAbstractCommand
{
public:
	CChangeDocumentTitleCommand(std::string& documentTitle, std::string const& newTitle);

private:
	void DoExecute() override;
	void DoRollback() override;

	std::string& m_documentTitle;
	std::string m_newTitle;
};
