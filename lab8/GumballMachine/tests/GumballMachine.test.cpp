#define CATCH_CONFIG_MAIN
#include "../GumballMachine/CGumballMachine.h"
#include "catch.hpp"

std::string BuildMachineStr(unsigned int expectedBallCount, std::string const& expectedState)
{
	std::ostringstream ss;
	ss << "Mighty Gumball, Inc.\n"
	   << "C++-enabled Standing Gumball Model #2016 (with state)\n"
	   << "Inventory: " << expectedBallCount << " gumball" << (expectedBallCount != 1 ? "s" : "") << "\n"
	   << "Machine is " << expectedState << "\n";

	return ss.str();
}

TEST_CASE("gumball machine")
{
	GIVEN("a machine with 2 balls")
	{
		CGumballMachine machine(2);

		WHEN("it is just created")
		{
			THEN("it contains 2 balls and is in the no quarter state")
			{
				auto const str = machine.ToString();
				REQUIRE(str == BuildMachineStr(2, "waiting for quarter"));
			}
		}

		WHEN("trying to turn the crank")
		{
			machine.TurnCrank();

			THEN("nothing changes")
			{
				auto const str = machine.ToString();
				REQUIRE(str == BuildMachineStr(2, "waiting for quarter"));
			}
		}

		WHEN("trying to return the quarter")
		{
			machine.EjectQuarter();

			THEN("nothing changes")
			{
				auto const str = machine.ToString();
				REQUIRE(str == BuildMachineStr(2, "waiting for quarter"));
			}
		}

		WHEN("inserting a quarter")
		{
			machine.InsertQuarter();

			THEN("machine is waiting for the crank")
			{
				auto const str = machine.ToString();
				REQUIRE(str == BuildMachineStr(2, "waiting for turn of crank"));
			}

			AND_WHEN("inserting another quarter")
			{
				machine.InsertQuarter();

				THEN("machine is still waiting for the crank")
				{
					auto const str = machine.ToString();
					REQUIRE(str == BuildMachineStr(2, "waiting for turn of crank"));
				}
			}

			AND_WHEN("returning the quarter")
			{
				machine.EjectQuarter();

				THEN("machine is waiting for quarter")
				{
					auto const str = machine.ToString();
					REQUIRE(str == BuildMachineStr(2, "waiting for quarter"));
				}
			}

			AND_WHEN("turning the crank")
			{
				machine.TurnCrank();

				THEN("a gumball is dispensed and the machine is waiting for quarter")
				{
					auto const str = machine.ToString();
					REQUIRE(str == BuildMachineStr(1, "waiting for quarter"));
				}

				AND_WHEN("turning the crank again")
				{
					machine.TurnCrank();

					THEN("nothing changes")
					{
						auto const str = machine.ToString();
						REQUIRE(str == BuildMachineStr(1, "waiting for quarter"));
					}
				}
			}
		}
	}

	GIVEN("a machine with 0 balls")
	{
		CGumballMachine machine(0);

		WHEN("it is just created")
		{
			THEN("it contains zero balls and is in the sold out state")
			{
				auto const str = machine.ToString();
				REQUIRE(str == BuildMachineStr(0, "sold out"));
			}
		}

		WHEN("inserting a quarter")
		{
			machine.InsertQuarter();

			THEN("the machine is still sold out")
			{
				auto const str = machine.ToString();
				REQUIRE(str == BuildMachineStr(0, "sold out"));
			}

			AND_WHEN("turning the crank")
			{
				machine.TurnCrank();

				THEN("no balls are dispensed and the machine is still sold out")
				{
					auto const str = machine.ToString();
					REQUIRE(str == BuildMachineStr(0, "sold out"));
				}
			}
		}
	}
}
