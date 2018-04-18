add_executable(lsdir chapter01/list_files.c)
add_executable(fork chapter01/std_io.c)
add_executable(processcontrol chapter01/processcontol.c)

target_link_libraries(lsdir apue-lib)
target_link_libraries(processcontrol apue-lib)
