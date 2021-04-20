
set(HEX_GAME_LIB_NAME "HexGameLib")



set(SOURCES
	hexGame/Board.cpp
	hexGame/Game.cpp
	hexGame/Point.cpp
)

set(HEADERS
	hexGame/Board.cpp
	hexGame/Color.hpp
	hexGame/Game.hpp
	hexGame/GameUI.hpp
	hexGame/Point.cpp
	hexGame/Vecteur.hpp

)



add_library(${HEX_GAME_LIB_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${HEX_GAME_LIB_NAME} PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	# #include <game/Game.hpp>
)