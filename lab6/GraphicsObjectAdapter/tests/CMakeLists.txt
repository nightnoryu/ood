add_executable(GraphicsObjectAdapterTest
               GraphicsObjectAdapter.test.cpp)

target_link_libraries(GraphicsObjectAdapterTest PUBLIC catch2 fakeit)
add_test(NAME GraphicsObjectAdapterTest COMMAND EditorTest)
