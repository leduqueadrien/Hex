
if(BUILD_MAIN_CONSOLE)
    add_subdirectory(console)
endif()

if(BUILD_MAIN_GRAPHIC)
    add_subdirectory(graphic)
endif()

if(BUILD_MAIN_BENCHMARK)
    add_subdirectory(benchmark)
endif()
