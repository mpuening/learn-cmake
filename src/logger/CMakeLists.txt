#
# Logger library
#
add_library(
	logger_src

	OBJECT 
	include/logger/logger.h
	logger.cpp
	include/logger/poco.h
	poco.cpp
)

target_include_directories(
	logger_src

	INTERFACE
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"

	PUBLIC
	include
)

include_directories(
	Poco::Foundation
	Poco::Util
)
target_link_libraries(
	logger_src

	Poco::Foundation
	Poco::Util
)

add_library(logger_lib STATIC)
target_link_libraries(logger_lib logger_src)

