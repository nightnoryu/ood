#pragma once

#include "../ShapeFactory/CShapeFactory.h"
#include "IDesigner.h"

class CDesigner : public IDesigner
{
public:
	explicit CDesigner(CShapeFactory& shapeFactory);

	CPictureDraft CreateDraft(std::istream& stream, std::ostream& errorStream) override;

private:
	static char const COMMENT_CHARACTER = '#';

	CShapeFactory& m_shapeFactory;
};
