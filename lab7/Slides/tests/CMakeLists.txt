add_executable(SlidesTest
               Slides.test.cpp)

target_link_libraries(SlidesTest PUBLIC catch2)
add_test(NAME SlidesTest COMMAND SlidesTest)
