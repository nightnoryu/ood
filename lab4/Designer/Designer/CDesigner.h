#pragma once

#include "IDesigner.h"

class CDesigner : public IDesigner
{
public:
private:
	CPictureDraft CreateDraft(std::istream& stream) override;
};
