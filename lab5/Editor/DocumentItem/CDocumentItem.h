#pragma once

#include "CConstDocumentItem.h"
#include <memory>

class CDocumentItem : public CConstDocumentItem
{
public:
	std::shared_ptr<IImage> GetImage();
	std::shared_ptr<IParagraph> GetParagraph();
};
