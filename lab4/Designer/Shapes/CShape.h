#pragma once

#include "../Canvas/ICanvas.h"

class CShape
{
public:
	explicit CShape(Color color);

	Color GetColor();

	virtual void Draw(ICanvas& canvas) = 0;

private:
	Color m_color;
};
