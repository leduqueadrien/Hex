
###############################################################################
#################################### SETUP ####################################
###############################################################################


set(HEX_GAME_LIB_NAME "HexGameLib")

set(HEX_GAME_EXPORT_FILE_NAME "${HEX_GAME_LIB_NAME}_export.hpp")
set(HEX_GAME_CONFIG_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib/cmake/${HEX_GAME_LIB_NAME}")

set(HEX_GAME_TARGET_NAME "${HEX_GAME_LIB_NAME}Targets")

###############################################################################
############################ IMPLEMENTATION/BUILD #############################
###############################################################################


set(SOURCES
	AI/MonteCarlo.cpp
	AI/MonteCarloCrossGame.cpp
	AI/RandomAI.cpp
	hexGame/Board.cpp
	hexGame/Human.cpp
	hexGame/Game.cpp
	hexGame/IterNeighbour.cpp
	hexGame/Player.cpp
	hexGame/Tile.cpp
	Parameters.cpp
	Mediator.cpp
	)

set(HEADERS
	AI/AI.hpp
	AI/MonteCarlo.hpp
	AI/MonteCarloCrossGame.hpp
	AI/RandomAI.hpp
	AI/AdjacentList.hpp
	hexGame/Board.hpp
	hexGame/Human.hpp
	hexGame/Game.hpp
	hexGame/IterNeighbour.hpp
	hexGame/Player.hpp
	hexGame/Tile.hpp
	gameUtils.hpp
	Parameters.hpp
	Mediator.hpp
	Message.hpp
)

add_library(${HEX_GAME_LIB_NAME} ${SOURCES} ${HEADERS})
target_compile_definitions(${HEX_GAME_LIB_NAME} PRIVATE "HexGameLib_EXPORT")

# thread package dependency
find_package(Threads REQUIRED)
target_link_libraries(${HEX_GAME_LIB_NAME} PUBLIC Threads::Threads)

# generate a file suitable for preprocessor inclusion which contains EXPORT macros to be used in library classes
generate_export_header(
	${HEX_GAME_LIB_NAME}
	EXPORT_FILE_NAME ${GENERATED_DIR}/${HEX_GAME_EXPORT_FILE_NAME}
	STATIC_DEFINE ${LIB_STATIC_DEFINE}
)

target_include_directories(${HEX_GAME_LIB_NAME} PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	# #include <game/Game.hpp>
	$<BUILD_INTERFACE:${GENERATED_DIR}>

	$<INSTALL_INTERFACE:${HEX_GAME_CONFIG_INSTALL_DIR}>
)


###############################################################################
################################### CONFIG ####################################
###############################################################################


# generate the config file that is includes the exports
configure_package_config_file(
	${PROJECT_SOURCE_DIR}/cmake/HexGameConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${HEX_GAME_LIB_NAME}Config.cmake
	INSTALL_DESTINATION ${HEX_GAME_CONFIG_INSTALL_DIR}
	PATH_VARS HEX_INCLUDE_INSTALL_DIR
)

# generate the version file for the config file
write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${HEX_GAME_LIB_NAME}ConfigVersion.cmake
	COMPATIBILITY ExactVersion
)


###############################################################################
############################## INSTALL/PACKAGING ##############################
###############################################################################


# install the include files
install(
	FILES
		${HEADERS}
		${GENERATED_DIR}/${HEX_GAME_EXPORT_FILE_NAME}
	DESTINATION
		${HEX_INCLUDE_INSTALL_DIR}/${HEX_GAME_LIB_NAME}
)

# install the library
install(
	TARGETS ${HEX_GAME_LIB_NAME}
	EXPORT ${HEX_GAME_TARGET_NAME}
)


###############################################################################
############################### INSTALL/CONFIG ################################
###############################################################################


# install the configuration files
install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/cmake/${HEX_GAME_LIB_NAME}Config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/cmake/${HEX_GAME_LIB_NAME}ConfigVersion.cmake
	DESTINATION
		${HEX_GAME_CONFIG_INSTALL_DIR}
)


# install the generated <export-name>.cmake file
install(
	EXPORT ${HEX_GAME_TARGET_NAME}
	DESTINATION ${HEX_GAME_CONFIG_INSTALL_DIR}
	NAMESPACE "HEXGAME::"
)
