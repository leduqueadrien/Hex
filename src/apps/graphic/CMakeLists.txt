
set(SOURCES
	graphic/Framework.cpp
)

set(HEADERS
	graphic/Framework.hpp
)

add_library(graphic ${SOURCES} ${HEADERS})

target_include_directories(graphic PUBLIC 
	"${CMAKE_CURRENT_SOURCE_DIR}"
	# #include <graphic/Framework.hpp>
)