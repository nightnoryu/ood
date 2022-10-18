#pragma once

#include "IDocument.h"
#include <vector>

class CDocument : public IDocument
{
public:
	std::shared_ptr<IParagraph> InsertParagraph(std::string const& text, std::optional<std::size_t> position) override;
	std::shared_ptr<IImage> InsertImage(std::string const& path, int width, int height, std::optional<std::size_t> position) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(std::size_t index) const override;
	CDocumentItem GetItem(std::size_t index) override;

	void DeleteItem(std::size_t index) override;

	std::string GetTitle() const override;
	void SetTitle(std::string const& title) override;

	bool CanUndo() const override;
	bool Undo() override;

	bool CanRedo() const override;
	bool Redo() override;

	void Save(std::string const& path) const override;

private:
	std::vector<CDocumentItem> m_items;
	std::string m_title;
};
