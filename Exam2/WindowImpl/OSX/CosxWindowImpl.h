#pragma once

#include "../../Window/IWindowImpl.h"

class COSXWindowImpl : public IWindowImpl
{
public:
	void SetTitle(std::string const& title) override;

	void ShowModal() override;
	void ShowPopup() override;

	void CloseModal() override;
	void ClosePopup() override;
};
