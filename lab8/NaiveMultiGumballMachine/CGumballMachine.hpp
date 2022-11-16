#pragma once

#include <iostream>
#include <sstream>

class CGumballMachine
{
public:
	enum class State
	{
		SoldOut,
		NoQuarter,
		HasQuarter,
		Sold,
	};

	CGumballMachine(unsigned count)
		: m_ballCount(count)
		, m_state(count > 0 ? State::NoQuarter : State::SoldOut)
	{
	}

	void InsertQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You can't insert a quarter, the machine is sold out\n";
			break;
		case State::NoQuarter:
			cout << "You inserted a quarter\n";
			m_state = State::HasQuarter;
			++m_quarterCount;
			break;
		case State::HasQuarter:
			cout << "You can't insert another quarter\n";
			break;
		case State::Sold:
			cout << "Please wait, we're already giving you a gumball\n";
			break;
		}
	}

	void EjectQuarter()
	{
		using namespace std;
		switch (m_state)
		{
		case State::HasQuarter:
			cout << "Quarters returned: " << m_quarterCount << "\n";
			m_state = State::NoQuarter;
			m_quarterCount = 0;
			break;
		case State::NoQuarter:
			cout << "You haven't inserted a quarter\n";
			break;
		case State::Sold:
			cout << "Sorry you already turned the crank\n";
			break;
		case State::SoldOut:
			cout << "You can't eject, you haven't inserted a quarter yet\n";
			break;
		}
	}

	void TurnCrank()
	{
		using namespace std;
		switch (m_state)
		{
		case State::SoldOut:
			cout << "You turned but there's no gumballs\n";
			break;
		case State::NoQuarter:
			cout << "You turned but there's no quarter\n";
			break;
		case State::HasQuarter:
			cout << "You turned...\n";
			m_state = State::Sold;
			--m_quarterCount;
			Dispense();
			break;
		case State::Sold:
			cout << "Turning twice doesn't get you another gumball\n";
			break;
		}
	}

	void Refill(unsigned numBalls)
	{
		m_ballCount = numBalls;
		m_state = numBalls > 0 ? State::NoQuarter : State::SoldOut;
	}

	std::string ToString() const
	{
		std::ostringstream ss;
		ss << "Mighty Gumball, Inc.\n"
		   << "C++-enabled Standing Gumball Model #2016 (with state)\n"
		   << "Inventory: " << m_ballCount << " gumball" << (m_ballCount != 1 ? "s" : "") << "\n"
		   << "Quarters: " << m_quarterCount << "\n"
		   << "Machine is " << StateToString() << "\n";

		return ss.str();
	}

private:
	void Dispense()
	{
		using namespace std;
		switch (m_state)
		{
		case State::Sold:
			cout << "A gumball comes rolling out the slot\n";
			--m_ballCount;
			--m_quarterCount;

			if (m_ballCount == 0)
			{
				cout << "Oops, out of gumballs\n";
				cout << "Ejecting leftover quarters: " << m_quarterCount << "\n";
				m_quarterCount = 0;
				m_state = State::SoldOut;
				return;
			}

			if (m_quarterCount == 0)
			{
				cout << "Out of quarters\n";
				m_state = State::NoQuarter;
				return;
			}

			cout << "Still got " << m_quarterCount << " quarters\n";
			break;
		case State::NoQuarter:
			cout << "You need to pay first\n";
			break;
		case State::SoldOut:
		case State::HasQuarter:
			cout << "No gumball dispensed\n";
			break;
		}
	}

	std::string StateToString() const
	{
		switch (m_state)
		{
		case State::SoldOut:
			return "sold out";
		case State::NoQuarter:
			return "waiting for quarter";
		case State::HasQuarter:
			return "waiting for turn of crank";
		case State::Sold:
			return "delivering a gumball";
		default:
			return "";
		}
	}

	unsigned m_ballCount = 0;
	unsigned m_quarterCount = 0;
	State m_state = State::SoldOut;
};
