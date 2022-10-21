#include "CInsertDocumentItemCommand.h"

CInsertDocumentItemCommand::CInsertDocumentItemCommand(std::vector<CDocumentItem>& items, CDocumentItem& newItem, std::optional<std::size_t> index)
	: m_items(items)
	, m_newItem(newItem)
	, m_index(index)
{
}

void CInsertDocumentItemCommand::DoExecute()
{
	if (m_index.has_value())
	{
		m_items.emplace(m_items.begin() + static_cast<int>(m_index.value()), m_newItem);
	}

	m_items.push_back(m_newItem);
}

void CInsertDocumentItemCommand::DoRollback()
{
	if (m_index.has_value())
	{
		m_items.erase(m_items.begin() + static_cast<int>(m_index.value()));
	}

	m_items.pop_back();
}
