#pragma once

#include "../PictureDraft/CPictureDraft.h"

class CPainter
{
public:
	void DrawPicture(CPictureDraft const& draft, ICanvas& canvas);
};
