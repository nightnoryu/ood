#include "CHtmlSaver.h"
#include <fstream>
#include <numeric>

void CHtmlSaver::Save(IDocument const& document, std::string const& path)
{
	std::ofstream output(path);

	output << "<html>\n"
		   << "<head>\n"
		   << "  <title>" << document.GetTitle() << "</title>\n"
		   << "</head>\n"
		   << "<body>\n";

	output << "  <h1>" << document.GetTitle() << "</h1>\n";

	for (std::size_t i = 0; i < document.GetItemsCount(); ++i)
	{
		auto item = document.GetItem(i);

		if (auto const& image = item.GetImage())
		{
			output << "  <img src=\"" << image->GetPath() << "\" "
				   << "width=\"" << image->GetWidth() << "\" "
				   << "height=\"" << image->GetHeight() << "\">";
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
