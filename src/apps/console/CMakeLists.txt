
# Main Jeu Console
set(CONS_APP mainCons)

add_executable(${CONS_APP} MainHexCons.cpp)

target_link_libraries(${CONS_APP} PUBLIC
	HexGameLib
)

install(TARGETS ${CONS_APP} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
