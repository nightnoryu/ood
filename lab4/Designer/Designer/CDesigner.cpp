#include "CDesigner.h"
#include <iostream>

CDesigner::CDesigner(CShapeFactory& shapeFactory)
	: m_shapeFactory(shapeFactory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& stream)
{
	CPictureDraft draft;
	std::string description;

	while (std::getline(stream, description))
	{
		try
		{
			draft.AddShape(m_shapeFactory.CreateShape(description));
		}
		catch (std::exception const& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}

	return draft;
}
