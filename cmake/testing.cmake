enable_testing()

macro(aoc_add_test target)

  add_test(${target} ${target})

  target_link_libraries(${target} PRIVATE Catch2::Catch2)

endmacro()
