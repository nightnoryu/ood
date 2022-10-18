#include "CDocument.h"

std::shared_ptr<IParagraph> CDocument::InsertParagraph(std::string const& text, std::optional<std::size_t> position)
{
	return std::shared_ptr<IParagraph>();
}

std::shared_ptr<IImage> CDocument::InsertImage(std::string const& path, int width, int height, std::optional<std::size_t> position)
{
	return std::shared_ptr<IImage>();
}

size_t CDocument::GetItemsCount() const
{
	return m_items.size();
}

CConstDocumentItem CDocument::GetItem(std::size_t index) const
{
	return m_items.at(index);
}

CDocumentItem CDocument::GetItem(std::size_t index)
{
	return m_items.at(index);
}

void CDocument::DeleteItem(std::size_t index)
{
	// TODO
}

std::string CDocument::GetTitle() const
{
	return m_title;
}

void CDocument::SetTitle(std::string const& title)
{
	m_title = title;
}

bool CDocument::CanUndo() const
{
	// TODO
	return false;
}

bool CDocument::Undo()
{
	// TODO
	return false;
}

bool CDocument::CanRedo() const
{
	// TODO
	return false;
}

bool CDocument::Redo()
{
	// TODO
	return false;
}

void CDocument::Save(std::string const& path) const
{
	// TODO
}
