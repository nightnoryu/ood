add_executable(EditorTest
               Editor.test.cpp)

target_link_libraries(EditorTest PUBLIC catch2 fakeit)
add_test(NAME EditorTest COMMAND EditorTest)
