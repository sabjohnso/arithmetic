find_package(GTest)

find_package(function_utility REQUIRED)
find_package(Boost REQUIRED)

macro(arithmetic_add_test test_name exe_name)
  add_executable(${exe_name} ${ARGN})
  target_link_libraries(${exe_name} PRIVATE
    arithmetic::arithmetic
    GTest::gtest_main)
  add_test(${test_name} ${exe_name})
endmacro()

arithmetic_add_test(magma magma_test magma_test.cpp)
target_link_libraries(magma_test PRIVATE  function_utility::function_utility)
arithmetic_add_test(additive_monoid additive_monoid_test additive_monoid_test.cpp)

arithmetic_add_test(additive additive_test additive_test.cpp)
arithmetic_add_test(multiplicative multiplicative_test multiplicative_test.cpp)
arithmetic_add_test(field field_test field_test.cpp)
target_link_libraries(field_test PRIVATE Boost::boost)


arithmetic_add_test(approximate_field approximate_field_test approximate_field_test.cpp)
arithmetic_add_test(vector_space vector_space_test vector_space_test.cpp)
