add_library(menu menu.cpp)
target_include_directories(menu PUBLIC include)
set(public_headers menu.h)

target_link_libraries(menu PRIVATE diagram)
