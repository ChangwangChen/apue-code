add_executable(lsdir chapter01/list_files.c)
add_executable(fork chapter01/std_io.c)
add_executable(processcontrol chapter01/processcontol.c)
add_executable(copy_unbuffered_io chapter01/copy_unbuffered_io.c)
add_executable(copy_std_io chapter01/copy_std_io.c)

target_link_libraries(lsdir apue-lib)
target_link_libraries(processcontrol apue-lib)
target_link_libraries(copy_std_io apue-lib)
