
set(HEX_GAME_LIB_NAME "hexGameLib")



set(SOURCES
	game/Game.cpp
)

set(HEADERS
	game/Game.hpp
)



add_library(${HEX_GAME_LIB_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${HEX_GAME_LIB_NAME} PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	# #include <game/Game.hpp>
)