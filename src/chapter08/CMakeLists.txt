add_executable(fork_example fork_example.c)
add_executable(wait_example wait_example.c)
add_executable(double_fork double_fork.c)
add_executable(fork_wait fork_wait.c)

target_link_libraries(fork_example apue-lib)
target_link_libraries(wait_example apue-lib)
target_link_libraries(double_fork apue-lib)
target_link_libraries(fork_wait apue-lib apue-wait)

