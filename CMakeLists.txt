
cmake_minimum_required(VERSION 3.11)

################### project ##########################
project(HEX)

################### options ##########################
option(STUFF_TESTING "enable targets to compile the stuff testing file" OFF)

################### package ##########################
find_package(SDL2 REQUIRED)


################### configure file ###################

################### app ##############################
add_subdirectory(src)


################### doc #############################

# do in build dir :
# cmake ../source/ -DCMAKE_INSTALL_PREFIX:PATH=$(pwd)/../install