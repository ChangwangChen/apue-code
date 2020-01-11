add_executable(can_seek can_seek.c)
add_executable(file_hole file_hole.c)
add_executable(compare compare.c)

target_link_libraries(file_hole apue-lib)

