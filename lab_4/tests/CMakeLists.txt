add_executable(houses_test houses_test.cpp)

target_link_libraries(houses_test 
  PRIVATE 
  GTest::GTest 
  houses)

gtest_discover_tests(houses_test)