#pragma once

#include "../Canvas/ICanvas.h"

class CShape
{
public:
	explicit CShape(Color color);

	Color GetColor() const;

	virtual void Draw(ICanvas& canvas) const = 0;

private:
	Color m_color;
};
