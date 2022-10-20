#pragma once

#include "../Document/IDocument.h"
#include <iostream>

class CEditor
{
public:
	CEditor(std::istream& input, std::ostream& output);

	void Start();

private:
	void InsertParagraph(std::istream& input);
	void InsertImage(std::istream& input);

	void SetTitle(std::istream& input);

	void List(std::istream& input);

	void ReplaceText(std::istream& input);
	void ResizeImageText(std::istream& input);

	void DeleteItem(std::istream& input);

	void Help(std::istream& input);

	void Undo(std::istream& input);
	void Redo(std::istream& input);

	void Save(std::istream& input);

	std::istream& m_input;
	std::ostream& m_output;

	std::unique_ptr<IDocument> m_document;
};
