#pragma once

#include "../Command/ICommand.h"
#include "ICommandExecutor.h"

class IHistory : public ICommandExecutor
{
public:
	virtual bool CanUndo() const = 0;
	virtual void Undo() = 0;

	virtual bool CanRedo() const = 0;
	virtual void Redo() = 0;
};
