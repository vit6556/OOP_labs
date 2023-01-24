add_executable(diagram_test diagram_test.cpp)

target_link_libraries(diagram_test 
  PRIVATE 
  GTest::GTest 
  diagram)

gtest_discover_tests(diagram_test)