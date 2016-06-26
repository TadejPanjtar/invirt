cmake_minimum_required(VERSION 2.6)
project(testinvirt)

# get ntdll.lib also from https://github.com/hzeroo/Carberp/tree/master/source%20-%20absource/pro/all%20source/RemoteCtl/ntdll

# exevutable writes into console, but it is practically the same as in project VMDE
add_executable(invirt detect.c  global.h  ntos.h  sup.h detect.h  main.c  sup.c  variables.h
minirtl/_strcat.c  minirtl/_strcmpi.c  minirtl/_strlen.c   minirtl/_strstr.c
minirtl/_strcmp.c  minirtl/_strcpy.c   minirtl/_strncpy.c  minirtl/hextou64.c minirtl/rtltypes.h
)

add_library(lib_invirt STATIC 
detect.c  global.h  ntos.h  sup.h detect.h   sup.c  variables.h
minirtl/_strcat.c  minirtl/_strcmpi.c  minirtl/_strlen.c   minirtl/_strstr.c
minirtl/_strcmp.c  minirtl/_strcpy.c   minirtl/_strncpy.c  minirtl/hextou64.c minirtl/rtltypes.h

)


add_executable(detect_vm testlib/main.cpp testlib/detect_vm.h )

target_link_libraries(detect_vm lib_invirt )

INSTALL(TARGETS invirt detect_vm DESTINATION bin)

