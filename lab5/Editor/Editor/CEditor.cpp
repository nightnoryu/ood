#include "CEditor.h"
#include "../Document/CDocument.h"

CEditor::CEditor(std::istream& input, std::ostream& output)
	: m_document(std::make_unique<CDocument>())
	, m_input(input)
	, m_output(output)
{
}

void CEditor::Start()
{
	// TODO
}

void CEditor::InsertParagraph(std::istream& input)
{
	std::string index;
	std::string text;

	if (!(input >> index) && std::getline(input, text))
	{
		m_output << "Invalid parameters for paragraph\n";
	}

	std::optional<std::size_t> optionalIndex;
	if (index != "end")
	{
		optionalIndex = static_cast<std::size_t>(std::stoi(index));
	}

	m_document->InsertParagraph(text, optionalIndex);
}

void CEditor::InsertImage(std::istream& input)
{
}
