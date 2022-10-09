add_executable(tractrix_test tractrix_test.cpp)

target_link_libraries(tractrix_test 
  PRIVATE 
  GTest::GTest 
  tractrix)

gtest_discover_tests(tractrix_test)