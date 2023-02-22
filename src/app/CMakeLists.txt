#
# This is the main app executable
#
add_executable(app app.cpp)
target_link_libraries(
	app

	PRIVATE
	Poco::Foundation
	Poco::Util

	logger_lib
	actuator_lib
)

