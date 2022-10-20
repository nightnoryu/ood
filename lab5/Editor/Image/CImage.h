#pragma once

#include "IImage.h"
#include <set>

class CImage : public IImage
{
public:
	CImage(std::string const& path, int width, int height);

	std::string GetPath() const override;

	int GetWidth() const override;
	int GetHeight() const override;

	void Resize(int width, int height) override;

	static void ValidateDimensions(int width, int height);

private:
	static int const MIN_WIDTH = 1;
	static int const MAX_WIDTH = 5000;

	static int const MIN_HEIGHT = 1;
	static int const MAX_HEIGHT = 5000;

	static inline std::set<std::string> const IMAGE_EXTENSIONS = { ".jpg", ".png", ".svg" };

	static inline std::string const BASE_FILENAME = "image_";

	static void ValidateImageFormat(std::string const& path);
	static void ValidateFileExists(std::string const& path);

	static std::string GetNextFilename();

	static std::size_t m_nextImageId;

	std::string m_path;
	int m_width;
	int m_height;
};
