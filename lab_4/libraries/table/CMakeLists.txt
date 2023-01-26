add_library(table table.cpp)
target_include_directories(table PUBLIC include)
set(public_headers table.h)

target_link_libraries(table PRIVATE houses)
