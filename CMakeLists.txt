project (manner)
set(CMAKE_C_STANDARD_DEFAULT "c11")
add_executable(manner src/manner.c src/windows.c src/config.c)
target_link_libraries(manner ncurses)