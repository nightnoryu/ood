#pragma once

#include "CPictureDraft.h"

class IDesigner
{
	virtual CPictureDraft CreateDraft(std::istream& stream) = 0;

	virtual ~IDesigner() = default;
};
