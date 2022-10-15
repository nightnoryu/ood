#include "CDesigner.h"

CDesigner::CDesigner(CShapeFactory& shapeFactory)
	: m_shapeFactory(shapeFactory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream& stream)
{
	// TODO
	return {};
}
