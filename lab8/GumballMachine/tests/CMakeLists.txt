add_executable(GumballMachineTest
               GumballMachine.test.cpp)

target_link_libraries(GumballMachineTest PUBLIC catch2)
add_test(NAME GumballMachineTest COMMAND GumballMachineTest)
