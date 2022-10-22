#pragma once

#include "../../DocumentItem/IImage.h"
#include "../AbstractCommand/CAbstractCommand.h"

class CResizeImageCommand : public CAbstractCommand
{
public:
	CResizeImageCommand(std::shared_ptr<IImage>&& image, int imageWidth, int imageHeight, int newWidth, int newHeight);

private:
	void DoExecute() override;
	void DoRollback() override;

	std::shared_ptr<IImage> m_image;
	int m_imageWidth;
	int m_imageHeight;
	int m_newWidth;
	int m_newHeight;
};
