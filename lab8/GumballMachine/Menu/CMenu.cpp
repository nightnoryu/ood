#include "CMenu.h"
#include <sstream>

CMenu::CMenu(std::istream& input, std::ostream& output, unsigned int initialBallCount)
	: m_input(input)
	, m_output(output)
	, m_gumballMachine(initialBallCount)
{
}

void CMenu::Start()
{
	std::string command;

	while (m_running && (m_output << "> ") && std::getline(m_input, command))
	{
		std::istringstream args(command);
		std::string commandName;

		args >> commandName;

		try
		{
			auto const handler = GetCommandHandler(commandName);
			handler(args);
		}
		catch (std::exception const& e)
		{
			m_output << "Error: " << e.what() << std::endl;
		}
	}

	m_output << "Bye\n";
}
CMenu::CommandHandler CMenu::GetCommandHandler(std::string const& commandName)
{
	if (commandName == "InsertQuarter")
	{
		return [this](std::istream& /* input */) {
			InsertQuarter();
		};
	}
	else if (commandName == "EjectQuarter")
	{
		return [this](std::istream& /* input */) {
			EjectQuarter();
		};
	}
	else if (commandName == "TurnCrank")
	{
		return [this](std::istream& /* input */) {
			TurnCrank();
		};
	}
	else if (commandName == "Refill")
	{
		return [this](std::istream& input) {
			Refill(input);
		};
	}
	else if (commandName == "Status")
	{
		return [this](std::istream& /* input */) {
			Status();
		};
	}
	else if (commandName == "Exit")
	{
		return [this](std::istream& /* input */) {
			Exit();
		};
	}

	throw std::runtime_error("unknown command: " + commandName);
}

void CMenu::InsertQuarter()
{
	m_gumballMachine.InsertQuarter();
}

void CMenu::EjectQuarter()
{
	m_gumballMachine.EjectQuarter();
}

void CMenu::TurnCrank()
{
	m_gumballMachine.TurnCrank();
}

void CMenu::Refill(std::istream& args)
{
	unsigned int count;
	if (!(args >> count))
	{
		throw std::invalid_argument("invalid ball count");
	}

	m_gumballMachine.Refill(count);
}

void CMenu::Status()
{
	m_output << m_gumballMachine.ToString() << "\n";
}

void CMenu::Exit()
{
	m_running = false;
}
