add_executable(TransformTest
               Transform.test.cpp)

target_link_libraries(TransformTest PUBLIC catch2)
add_test(NAME TransformTest COMMAND TransformTest)
