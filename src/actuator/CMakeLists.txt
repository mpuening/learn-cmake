#
# Actuator library
#
add_library(
	actuator_src

	OBJECT 
	include/actuator/health.h
	health.cpp
	include/actuator/info.h
	info.cpp
)

target_include_directories(
	actuator_src

	INTERFACE
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"

	PUBLIC
	include
	../logger/include
)

include(BuildInfo)
BuildInfo(actuator_src)

add_library(actuator_lib STATIC)
target_link_libraries(actuator_lib actuator_src)

