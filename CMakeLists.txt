cmake_minimum_required( VERSION 3.0)

project( ld-preload C)

add_library( ld-preload SHARED
src/ld-preload.c
)

add_library( linked SHARED
src/linked.c
)

add_executable( main
src/main.c
)

add_dependencies( main linked)
target_link_libraries( main
-Wl,--no-as-needed
linked
-Wl,--as-needed
)