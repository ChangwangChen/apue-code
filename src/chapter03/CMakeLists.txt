add_executable(compare compare.c)
add_executable(multiThread multithreads.c)

find_package(Threads)

target_link_libraries(multiThread ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(multiThread apue-lib)