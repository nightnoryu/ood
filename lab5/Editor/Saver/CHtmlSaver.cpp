#include "CHtmlSaver.h"
#include <filesystem>
#include <fstream>
#include <numeric>

namespace fs = std::filesystem;

void CHtmlSaver::Save(IDocument const& document, std::string const& path)
{
	std::ofstream output(path);

	auto const imagesDirectoryPath = GetImagesDirectoryPath(path);
	if (!fs::is_directory(imagesDirectoryPath))
	{
		fs::create_directory(imagesDirectoryPath);
	}

	output << "<html>\n"
		   << "<head>\n"
		   << "  <title>" << document.GetTitle() << "</title>\n"
		   << "</head>\n"
		   << "<body>\n"
		   << "  <h1>" << document.GetTitle() << "</h1>\n";

	for (std::size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		auto item = document.GetItem(i);

		if (auto const& image = item.GetImage())
		{
			auto imageDestinationPath = fs::path(imagesDirectoryPath) / fs::path(image->GetPath()).filename();
			fs::copy(image->GetPath(), imageDestinationPath);

			output << "  <img src=\"" << imageDestinationPath.string() << "\" "
				   << "width=\"" << image->GetWidth() << "\" "
				   << "height=\"" << image->GetHeight() << "\" />";
		}
		else if (auto const& paragraph = item.GetParagraph())
		{
			output << "  <p>" << Escape(paragraph->GetText()) << "</p>";
		}

		output << "\n";
	}

	output << "</body>\n"
		   << "</html>\n";
}

std::string CHtmlSaver::Escape(std::string const& str)
{
	return std::accumulate(
		str.begin(),
		str.end(),
		std::string(),
		[](auto const result, auto const ch) {
			auto const escaped = ESCAPE_SEQUENCES.find(ch);
			if (escaped != ESCAPE_SEQUENCES.end())
			{
				return result + escaped->second;
			}
			return result + ch;
		});
}

std::string CHtmlSaver::GetImagesDirectoryPath(std::string const& documentPath)
{
	auto const documentRootPath = fs::path(documentPath).parent_path();
	auto const destinationPath = documentRootPath / IMAGES_DIRECTORY;

	return destinationPath.string();
}
