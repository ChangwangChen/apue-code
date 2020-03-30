add_library(apue-lib STATIC error.c errorlog.c path.c apue.c system.c prmask.c)
add_library(apue-wait tellwait.c)
add_library(apue-signal-wait tellwait_signal.c)