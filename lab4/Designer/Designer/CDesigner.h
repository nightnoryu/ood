#pragma once

#include "../Client/IDesigner.h"
#include "../ShapeFactory/CShapeFactory.h"

class CDesigner : public IDesigner
{
public:
	explicit CDesigner(IShapeFactory& shapeFactory);

	CPictureDraft CreateDraft(std::istream& stream, std::ostream& errorStream) override;

private:
	static char const COMMENT_CHARACTER = '#';

	IShapeFactory& m_shapeFactory;
};
