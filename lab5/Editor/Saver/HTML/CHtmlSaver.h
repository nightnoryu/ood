#pragma once

#include "../ISaver.h"
#include <unordered_map>

class CHtmlSaver : public ISaver
{
public:
	void Save(IDocument const& document, std::string const& path) override;

private:
	static inline std::unordered_map<char, std::string> const ESCAPE_SEQUENCES = {
		{ '&', "&amp;" },
		{ '<', "&lt;" },
		{ '>', "&gt;" },
		{ '"', "&quot;" },
		{ '\'', "&apos;" },
	};

	static std::string Escape(std::string const& result);
};
