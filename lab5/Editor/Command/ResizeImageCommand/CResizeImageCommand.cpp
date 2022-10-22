#include "CResizeImageCommand.h"
#include "../../Image/CImage.h"

CResizeImageCommand::CResizeImageCommand(std::shared_ptr<IImage>&& image, int imageWidth, int imageHeight, int newWidth, int newHeight)
	: m_image(std::move(image))
	, m_imageWidth(imageWidth)
	, m_imageHeight(imageHeight)
	, m_newWidth(newWidth)
	, m_newHeight(newHeight)
{
	CImage::ValidateDimensions(m_newWidth, m_newHeight);
}

void CResizeImageCommand::DoExecute()
{
	m_image->Resize(m_newWidth, m_newHeight);
}

void CResizeImageCommand::DoRollback()
{
	m_image->Resize(m_imageWidth, m_imageHeight);
}
