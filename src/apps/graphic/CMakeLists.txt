

###############################################################################
#################################### SETUP ####################################
###############################################################################

set(SOURCES
	MainHexGraph.cpp
	framework/Framework.cpp
	graphicUI/GraphicUI.cpp
)

set(HEADERS
	framework/Framework.hpp
	graphicUI/GraphicUI.hpp
)

###############################################################################
#################################### MAIN #####################################
############################ IMPLEMENTATION/BUILD #############################
###############################################################################

set(GRAPH_APP mainGraph)

add_executable(${GRAPH_APP}
	${SOURCES}
	${HEADERS}
)

target_link_libraries(${GRAPH_APP} PUBLIC
	HexGameLib
	${SDL2_LIBRARIES}
)

message("SDL2_INCLUDE_DIRS : ${SDL2_INCLUDE_DIRS}")

target_include_directories(${GRAPH_APP} PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}" # #include <framework/Framework.hpp>
	${SDL2_INCLUDE_DIRS} # #include <SDL2/SDL.h>
)

###############################################################################
#################################### MAIN #####################################
############################## INSTALL/PACKAGING ##############################
###############################################################################

install(TARGETS ${GRAPH_APP} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")




###############################################################################
#################################### TEST #####################################
############################ IMPLEMENTATION/BUILD #############################
###############################################################################

if (STUFF_TESTING)

	set(TEST_GRAPH testGraph)

	add_executable(${TEST_GRAPH} testGraph.cpp)

	target_include_directories(${TEST_GRAPH} PUBLIC
		${SDL2_INCLUDE_DIRS}
	)
	target_link_libraries(${TEST_GRAPH} ${SDL2_LIBRARIES})


###############################################################################
#################################### TEST #####################################
############################## INSTALL/PACKAGING ##############################
###############################################################################

	install(TARGETS ${TEST_GRAPH} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

endif()
