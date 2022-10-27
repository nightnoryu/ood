#pragma once

#include "IImage.h"
#include "IParagraph.h"
#include <memory>

class CConstDocumentItem
{
public:
	CConstDocumentItem(std::shared_ptr<IImage>&& image);
	CConstDocumentItem(std::shared_ptr<IParagraph>&& paragraph);

	std::shared_ptr<IImage const> GetImage() const;
	std::shared_ptr<IParagraph const> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;

protected:
	std::shared_ptr<IImage> m_image = nullptr;
	std::shared_ptr<IParagraph> m_paragraph = nullptr;
};
