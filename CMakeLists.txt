
###############################################################################
################################### PROJECT ###################################
###############################################################################

cmake_minimum_required(VERSION 3.11)

project(HEX
    VERSION 1.0.0
    LANGUAGES CXX
)

###############################################################################
#################################### SETUP ####################################
###############################################################################

set(HEX_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include")

option(STUFF_TESTING "enable targets to compile the stuff testing file" OFF)

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

option(BUILD_MAIN_GRAPHIC "Build the executable using SDL2" OFF)
option(BUILD_MAIN_CONSOLE "Build the executable for console" ON)
option(BUILD_MAIN_BENCHMARK "Build the executable for benchark" OFF)


# find_package(SDL2 REQUIRED)

include(CMakePackageConfigHelpers)

include(GenerateExportHeader)
set(GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
message(STATUS "Generated files goes in : ${GENERATED_DIR}")
file(MAKE_DIRECTORY ${GENERATED_DIR})

###############################################################################
############################ IMPLEMENTATION/BUILD #############################
###############################################################################


add_subdirectory(src)


###############################################################################
################################### CONFIG ####################################
###############################################################################


###############################################################################
############################## INSTALL/PACKAGING ##############################
###############################################################################


###############################################################################
############################### INSTALL/CONFIG ################################
###############################################################################
