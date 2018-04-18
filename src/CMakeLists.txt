add_executable(lsdir chapter01/list_files.c)
add_executable(fork chapter01/std_io.c)

target_link_libraries(lsdir apue-lib)
