#pragma once

#include "IParagraph.h"

class CParagraph : public IParagraph
{
public:
	std::string GetText() const override;

	void SetText(std::string const& text) override;

private:
	std::string m_text;
};
