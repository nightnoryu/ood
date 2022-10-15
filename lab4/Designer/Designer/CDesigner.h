#pragma once

#include "../ShapeFactory/CShapeFactory.h"
#include "IDesigner.h"

class CDesigner : public IDesigner
{
public:
	explicit CDesigner(CShapeFactory& shapeFactory);

	CPictureDraft CreateDraft(std::istream& stream) override;

private:
	CShapeFactory& m_shapeFactory;
};
