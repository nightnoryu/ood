#include "CImage.h"
#include <filesystem>

namespace fs = std::filesystem;

CImage::CImage(std::string const& path, int width, int height)
{
	ValidateDimensions(width, height);
	m_width = width;
	m_height = height;

	ValidateImageFormat(path);
}

std::string CImage::GetPath() const
{
	return m_path;
}

int CImage::GetWidth() const
{
	return m_width;
}

int CImage::GetHeight() const
{
	return m_height;
}

void CImage::Resize(int width, int height)
{
	// TODO
}

void CImage::ValidateDimensions(int width, int height)
{
	if (width < MIN_WIDTH || width > MAX_WIDTH)
	{
		throw std::invalid_argument("invalid image width");
	}

	if (height < MIN_HEIGHT || height > MAX_HEIGHT)
	{
		throw std::invalid_argument("invalid image height");
	}
}

void CImage::ValidateImageFormat(std::string const& path)
{
	fs::path filePath = path;

	if (IMAGE_EXTENSIONS.find(filePath.extension().string()) == IMAGE_EXTENSIONS.end())
	{
		throw std::invalid_argument("invalid image format");
	}
}
