#pragma once

#include "../AbstractCommand/CAbstractCommand.h"
#include <string>

class CSetParagraphTextCommand : public CAbstractCommand
{
public:
	CSetParagraphTextCommand(std::string& paragraphText, std::string const& newText);

private:
	void DoExecute() override;
	void DoRollback() override;

	std::string& m_paragraphText;
	std::string m_newText;
};
