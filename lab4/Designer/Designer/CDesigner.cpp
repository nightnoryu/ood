#include "CDesigner.h"
#include <iostream>

CDesigner::CDesigner(IShapeFactory& shapeFactory)
	: m_shapeFactory(shapeFactory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& stream, std::ostream& errorStream)
{
	CPictureDraft draft;
	std::string description;

	while (std::getline(stream, description))
	{
		if (description.empty() || description.starts_with(COMMENT_CHARACTER))
		{
			continue;
		}

		try
		{
			draft.AddShape(m_shapeFactory.CreateShape(description));
		}
		catch (std::exception const& e)
		{
			errorStream << "Error: " << e.what() << "\n  Skipping '" << description << "' shape" << std::endl;
		}
	}

	return draft;
}
