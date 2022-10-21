#pragma once

#include "../../DocumentItem/CDocumentItem.h"
#include "../AbstractCommand/CAbstractCommand.h"
#include <optional>
#include <vector>

class CInsertDocumentItemCommand : public CAbstractCommand
{
public:
	CInsertDocumentItemCommand(std::vector<CDocumentItem>& items, CDocumentItem& newItem, std::optional<std::size_t> index);

private:
	void DoExecute() override;
	void DoRollback() override;

private:
	std::vector<CDocumentItem>& m_items;
	CDocumentItem& m_newItem;
	std::optional<std::size_t> m_index;
};
