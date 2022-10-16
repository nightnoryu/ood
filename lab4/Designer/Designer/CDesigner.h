#pragma once

#include "../ShapeFactory/CShapeFactory.h"
#include "IDesigner.h"

class CDesigner : public IDesigner
{
public:
	explicit CDesigner(IShapeFactory& shapeFactory);

	CPictureDraft CreateDraft(std::istream& stream, std::ostream& errorStream) override;

private:
	static char const COMMENT_CHARACTER = '#';

	IShapeFactory& m_shapeFactory;
};
