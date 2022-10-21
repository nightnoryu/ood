#pragma once

#include "../History/CHistory.h"
#include "../Saver/ISaver.h"
#include "IDocument.h"
#include <vector>

class CDocument : public IDocument
{
public:
	explicit CDocument(CHistory& history, ISaver& saver);

	void InsertParagraph(std::string const& text, std::optional<std::size_t> position) override;
	void InsertImage(std::string const& path, int width, int height, std::optional<std::size_t> position) override;

	size_t GetItemsCount() const override;

	CConstDocumentItem GetItem(std::size_t index) const override;
	CDocumentItem GetItem(std::size_t index) override;

	void DeleteItem(std::size_t index) override;

	std::string GetTitle() const override;
	void SetTitle(std::string const& title) override;

	bool CanUndo() const override;
	void Undo() override;

	bool CanRedo() const override;
	void Redo() override;

	void Save(std::string const& path) const override;

private:
	CHistory& m_history;
	ISaver& m_saver;

	std::vector<CDocumentItem> m_items;
	std::string m_title;
};
