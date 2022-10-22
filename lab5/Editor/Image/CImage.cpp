#include "CImage.h"
#include "../Command/ResizeImageCommand/CResizeImageCommand.h"
#include <filesystem>

namespace fs = std::filesystem;

CImage::CImage(std::string const& path, int width, int height, IHistory& history)
	: m_history(history)
{
	ValidateDimensions(width, height);
	m_width = width;
	m_height = height;

	ValidateImageFormat(path);
	ValidateFileExists(path);

	auto newPath = fs::temp_directory_path() / (GetNextFilename() + fs::path(path).extension().string());
	fs::copy(path, newPath);

	m_path = newPath.string();
}

CImage::~CImage() noexcept
{
	fs::remove(m_path);
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
	m_history.AddAndExecuteCommand(std::make_unique<CResizeImageCommand>(
		std::shared_ptr<IImage>(this),
		m_width,
		m_height,
		width,
		height));
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

void CImage::ValidateFileExists(std::string const& path)
{
	if (!fs::exists(path))
	{
		throw std::runtime_error("image does not exist");
	}
}

std::string CImage::GetNextFilename()
{
	return BASE_FILENAME + std::to_string(m_nextImageId++);
}

std::size_t CImage::m_nextImageId = 1;
