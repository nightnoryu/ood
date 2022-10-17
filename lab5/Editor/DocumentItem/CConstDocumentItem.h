#pragma once

#include "../Image/IImage.h"
#include "../Paragraph/IParagraph.h"
#include <memory>

class CConstDocumentItem
{
public:
	std::shared_ptr<IImage const> GetImage() const;
	std::shared_ptr<IParagraph const> GetParagraph() const;

	virtual ~CConstDocumentItem() = default;
};
