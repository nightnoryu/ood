#pragma once

#include "../Document/IHistory.h"
#include "../DocumentItem/IParagraph.h"

class CParagraph : public IParagraph
{
public:
	CParagraph(std::string const& text, IHistory& history);

	std::string GetText() const override;

	void SetText(std::string const& text) override;

private:
	std::string m_text;
	IHistory& m_history;
};
