#define CATCH_CONFIG_MAIN
#include "../GumballMachine/CGumballMachine.h"
#include "../State/HasQuarterState/CHasQuarterState.h"
#include "../State/NoQuarterState/CNoQuarterState.h"
#include "../State/SoldOutState/CSoldOutState.h"
#include "../State/SoldState/CSoldState.h"
#include "catch.hpp"
#include "fakeit.hpp"

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

TEST_CASE("states")
{
	fakeit::Mock<IGumballMachine> machineMock;

	fakeit::Fake(Method(machineMock, ReleaseBall));

	fakeit::Fake(Method(machineMock, AddQuarter));
	fakeit::Fake(Method(machineMock, ReleaseQuarter));
	fakeit::When(Method(machineMock, GetMaxQuarterCount)).AlwaysReturn(2);

	fakeit::Fake(Method(machineMock, SetSoldOutState));
	fakeit::Fake(Method(machineMock, SetNoQuarterState));
	fakeit::Fake(Method(machineMock, SetSoldState));
	fakeit::Fake(Method(machineMock, SetHasQuarterState));

	auto& machine = machineMock.get();

	GIVEN("a sold out state")
	{
		CSoldOutState state(machine);

		WHEN("inserting a quarter")
		{
			state.InsertQuarter();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("ejecting a quarter")
		{
			state.EjectQuarter();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("turning the crank")
		{
			state.TurnCrank();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("dispensing")
		{
			state.Dispense();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}
	}

	GIVEN("no quarter state")
	{
		fakeit::When(Method(machineMock, GetQuarterCount)).AlwaysReturn(0);
		CNoQuarterState state(machine);

		WHEN("inserting a quarter")
		{
			state.InsertQuarter();

			THEN("has quarter state is set")
			{
				fakeit::Verify(Method(machineMock, SetHasQuarterState)).Once();
			}
		}

		WHEN("ejecting a quarter")
		{
			state.EjectQuarter();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("turning the crank")
		{
			state.TurnCrank();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("dispensing")
		{
			state.Dispense();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}
	}

	GIVEN("has quarter state")
	{
		fakeit::When(Method(machineMock, GetQuarterCount)).AlwaysReturn(1);
		CHasQuarterState state(machine);

		WHEN("inserting a quarter")
		{
			state.InsertQuarter();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("ejecting a quarter")
		{
			state.EjectQuarter();

			THEN("no quarter state is set")
			{
				fakeit::Verify(Method(machineMock, SetNoQuarterState)).Once();
			}
		}

		WHEN("turning the crank")
		{
			state.TurnCrank();

			THEN("sold state is set")
			{
				fakeit::Verify(Method(machineMock, SetSoldState)).Once();
			}
		}

		WHEN("dispensing")
		{
			state.Dispense();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}
	}

	GIVEN("sold state")
	{
		CSoldState state(machine);

		WHEN("inserting a quarter")
		{
			state.InsertQuarter();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("ejecting a quarter")
		{
			state.EjectQuarter();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("turning the crank")
		{
			state.TurnCrank();

			THEN("nothing happens")
			{
				fakeit::VerifyNoOtherInvocations(machineMock);
			}
		}

		WHEN("dispensing with filled machine")
		{
			fakeit::When(Method(machineMock, GetBallCount)).Return(5);
			fakeit::When(Method(machineMock, GetQuarterCount)).AlwaysReturn(1);
			state.Dispense();

			THEN("no quarter state is set")
			{
				fakeit::Verify(Method(machineMock, SetNoQuarterState));
			}
		}

		WHEN("dispensing with empty machine")
		{
			fakeit::When(Method(machineMock, GetBallCount)).Return(0);
			state.Dispense();

			THEN("sold out state is set")
			{
				fakeit::Verify(Method(machineMock, SetSoldOutState));
			}
		}
	}
}
