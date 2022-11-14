add_executable(GumballMachine
               main.cpp GumballMachine/IGumballMachine.h State/IState.h State/SoldState/CSoldState.cpp State/SoldState/CSoldState.h State/SoldOutState/CSoldOutState.cpp State/SoldOutState/CSoldOutState.h State/HasQuarterState/CHasQuarterState.cpp State/HasQuarterState/CHasQuarterState.h State/NoQuarterState/CNoQuarterState.cpp State/NoQuarterState/CNoQuarterState.h GumballMachine/CGumballMachine.cpp GumballMachine/CGumballMachine.h)

add_subdirectory(tests)
