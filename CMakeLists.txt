# Find Curses/NCurses
find_package(Curses REQUIRED)

# Create a `ptaskr` target
add_executable(ptaskr
	defs.h
	io.c
	menus.c
	prompts.c
	rendering.c
	structs.c
	tasklists.c
)

# Link Curses to ptaskr, include dirs, etc.
target_include_directories(ptaskr PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(ptaskr ${CURSES_LIBRARIES})

# When `make install` is run, add ptaskr to global PATH
install(TARGETS ptaskr RUNTIME DESTINATION bin)
