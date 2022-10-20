#pragma once

#include "../AbstractCommand/CAbstractCommand.h"

class CResizeImageCommand : public CAbstractCommand
{
public:
	CResizeImageCommand(int& imageWidth, int& imageHeight, int newWidth, int newHeight);

private:
	void DoExecute() override;
	void DoRollback() override;

	int& m_imageWidth;
	int& m_imageHeight;
	int m_newWidth;
	int m_newHeight;
};
