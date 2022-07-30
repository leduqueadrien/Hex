
###############################################################################
#################################### SETUP ####################################
###############################################################################

set(CONS_APP mainCons)

set(SOURCES
    MainHexCons.cpp
    Menu.cpp
    UI.cpp
    GameUI.cpp
    PositionSaver.cpp
    Cursor.cpp
)

set(HEADERS
    Menu.hpp
    UI.hpp
    GameUI.hpp
    PositionSaver.hpp
    Cursor.hpp
)


###############################################################################
#################################### MAIN #####################################
############################ IMPLEMENTATION/BUILD #############################
###############################################################################


add_executable(${CONS_APP} ${SOURCES} ${HEADERS})

target_link_libraries(${CONS_APP} PUBLIC
    HexGameLib
    #ncurses ?
)

target_include_directories(${CONS_APP} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

###############################################################################
#################################### MAIN #####################################
############################## INSTALL/PACKAGING ##############################
###############################################################################

install(TARGETS ${CONS_APP} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")


###############################################################################
#################################### TEST #####################################
############################ IMPLEMENTATION/BUILD #############################
###############################################################################

if (STUFF_TESTING)

    set(TEST_CONS testCons)

    set(TEST_SOURCES
        testCons.cpp
        ConsoleUI.cpp
    )

    set(TEST_HEADERS
        ConsoleUI.hpp
    )


    add_executable(${TEST_CONS} ${TEST_SOURCES} ${TEST_HEADERS})

    target_link_libraries(${TEST_CONS} PUBLIC
        HexGameLib
    )

    target_include_directories(${TEST_CONS} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
###############################################################################
#################################### TEST #####################################
############################## INSTALL/PACKAGING ##############################
###############################################################################

    install(TARGETS ${TEST_CONS} DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

endif()
