#pragma once

#include "../Command/ICommand.h"
#include <vector>

class CHistory
{
public:
	bool CanUndo() const;
	void Undo();

	bool CanRedo() const;
	void Redo();

	void AddAndExecuteCommand(ICommandPtr&& command);

private:
	std::vector<ICommandPtr> m_commands;
	std::size_t m_currentCommandIndex = 0;
};
