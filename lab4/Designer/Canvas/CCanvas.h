#pragma once

#include "ICanvas.h"

class CCanvas : public ICanvas
{
public:
	void SetColor(Color color) override;
	void DrawLine(const Point& from, const Point& to) override;
	void DrawEllipse(const Point& center, int width, int height) override;
};
