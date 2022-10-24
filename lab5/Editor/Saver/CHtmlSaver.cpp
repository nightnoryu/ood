#include "CHtmlSaver.h"
#include <filesystem>
#include <fstream>
#include <numeric>

namespace fs = std::filesystem;

void CHtmlSaver::Save(IDocument const& document, std::string const& path)
{
	std::ofstream output(path);
	auto const imagesDirectoryPath = CreateImagesDirectory(path);

	WriteHeader(output, document);

	for (std::size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		auto item = document.GetItem(i);

		if (auto const& image = item.GetImage())
		{
			WriteImage(output, image, imagesDirectoryPath);
		}
		else if (auto const& paragraph = item.GetParagraph())
		{
			WriteParagraph(output, paragraph);
		}
	}

	WriteFooter(output);
}

void CHtmlSaver::WriteHeader(std::ostream& output, IDocument const& document)
{
	output << "<html>\n"
		   << "<head>\n"
		   << "  <title>" << document.GetTitle() << "</title>\n"
		   << "</head>\n"
		   << "<body>\n"
		   << "  <h1>" << document.GetTitle() << "</h1>\n";
}

void CHtmlSaver::WriteImage(std::ostream& output, std::shared_ptr<IImage const> const& image, std::string const& imagesDirectoryPath)
{
	auto imageDestinationPath = fs::path(imagesDirectoryPath) / fs::path(image->GetPath()).filename();
	fs::copy(
		image->GetPath(),
		imageDestinationPath,
		fs::copy_options::overwrite_existing);

	output << "  <img src=\"" << imageDestinationPath.string() << "\" "
		   << "width=\"" << image->GetWidth() << "\" "
		   << "height=\"" << image->GetHeight() << "\" />\n";
}

void CHtmlSaver::WriteParagraph(std::ostream& output, std::shared_ptr<IParagraph const> const& paragraph)
{
	output << "  <p>" << Escape(paragraph->GetText()) << "</p>\n";
}

void CHtmlSaver::WriteFooter(std::ofstream& output)
{
	output << "</body>\n"
		   << "</html>\n";
}

std::string CHtmlSaver::CreateImagesDirectory(std::string const& documentPath)
{
	auto imagesDirectoryPath = GetImagesDirectoryPath(documentPath);
	if (!fs::is_directory(imagesDirectoryPath))
	{
		fs::create_directory(imagesDirectoryPath);
	}

	return imagesDirectoryPath;
}

std::string CHtmlSaver::GetImagesDirectoryPath(std::string const& documentPath)
{
	auto const documentRootPath = fs::path(documentPath).parent_path();
	auto const destinationPath = documentRootPath / IMAGES_DIRECTORY;

	return destinationPath.string();
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
