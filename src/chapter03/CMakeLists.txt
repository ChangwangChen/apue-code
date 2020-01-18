add_executable(can_seek can_seek.c)
add_executable(file_hole file_hole.c)
add_executable(compare compare.c)
add_executable(efficient_io effecient_io.c)
add_executable(multiThread multithreads.c)

find_package(Threads)

target_link_libraries(multiThread ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(multiThread apue-lib)
target_link_libraries(file_hole apue-lib)
target_link_libraries(efficient_io apue-lib)
