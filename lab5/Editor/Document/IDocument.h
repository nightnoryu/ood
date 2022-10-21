#pragma once

#include "../DocumentItem/CConstDocumentItem.h"
#include "../DocumentItem/CDocumentItem.h"
#include "../Image/IImage.h"
#include "../Paragraph/IParagraph.h"
#include <memory>
#include <optional>

class IDocument
{
public:
	virtual std::shared_ptr<IParagraph> InsertParagraph(std::string const& text, std::optional<std::size_t> position) = 0;
	virtual std::shared_ptr<IImage> InsertImage(std::string const& path, int width, int height, std::optional<std::size_t> position) = 0;

	virtual std::size_t GetItemsCount() const = 0;

	virtual CConstDocumentItem GetItem(std::size_t index) const = 0;
	virtual CDocumentItem GetItem(std::size_t index) = 0;

	virtual void DeleteItem(std::size_t index) = 0;

	virtual std::string GetTitle() const = 0;
	virtual void SetTitle(std::string const& title) = 0;

	virtual bool CanUndo() const = 0;
	virtual void Undo() = 0;

	virtual bool CanRedo() const = 0;
	virtual void Redo() = 0;

	virtual void Save(std::string const& path) const = 0;

	virtual ~IDocument() = default;
};
