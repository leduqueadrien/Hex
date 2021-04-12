
set(SOURCES
	game/Game.cpp
)

set(HEADERS
	game/Game.hpp
)

add_library(gameLib ${SOURCES} ${HEADERS})

target_include_directories(gameLib PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	# #include <game/Game.hpp>
)