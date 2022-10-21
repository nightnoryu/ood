#pragma once

#include "../Document/IDocument.h"

class ISaver
{
public:
	virtual void Save(IDocument const& document, std::string const& path) = 0;

	virtual ~ISaver() = default;
};
