
set(SOURCES
	framework/Framework.cpp
)

set(HEADERS
	framework/Framework.hpp
)

add_library(graphic ${SOURCES} ${HEADERS})

target_include_directories(graphic PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	# #include <framework/Framework.hpp>
)



# Main de tests
if (STUFF_TESTING)

	set(TEST_APP test)

	add_executable(${TEST_APP} test.cpp)

	include_directories(${TEST_APP} ${SDL2_INCLUDE_DIRS})
	target_link_libraries(${TEST_APP} ${SDL2_LIBRARIES})

	install(TARGETS ${TEST_APP} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

endif()


# Main Jeu Graphique
set(GRAPH_APP mainGraph)

add_executable(${GRAPH_APP} MainHexGraph.cpp)

target_link_libraries(${GRAPH_APP} PUBLIC
	graphic
	${SDL2_LIBRARIES}
)

include_directories(${GRAPH_APP} ${SDL2_INCLUDE_DIRS})

install(TARGETS ${GRAPH_APP} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")


