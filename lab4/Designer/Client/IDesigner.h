#pragma once

#include "../PictureDraft/CPictureDraft.h"

class IDesigner
{
public:
	virtual CPictureDraft CreateDraft(std::istream& stream, std::ostream& errorStream) = 0;

	virtual ~IDesigner() = default;
};
