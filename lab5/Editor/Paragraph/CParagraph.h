#pragma once

#include "../Document/ICommandExecutor.h"
#include "../DocumentItem/IParagraph.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(std::string const& text, ICommandExecutor& commandExecutor);

	std::string GetText() const override;

	void SetText(std::string const& text) override;

private:
	std::string m_text;
	ICommandExecutor& m_commandExecutor;
};
