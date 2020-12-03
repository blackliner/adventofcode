add_library(aoc_1 aoc_1.cpp aoc_1.h)

add_executable(aoc_1_test aoc_1_test.cpp)

target_link_libraries(aoc_1_test PRIVATE aoc_1)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/advent_input.txt
               ${CMAKE_CURRENT_BINARY_DIR}/advent_input.txt COPYONLY)

aoc_add_test(aoc_1_test)
