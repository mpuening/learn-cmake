add_executable(
	actuator_test

	health_test.cpp
	info_test.cpp
)


target_link_libraries(
	actuator_test
	PRIVATE
	logger_lib
	actuator_lib
	Poco::Foundation
	Poco::Util
)

DiscoverTests(actuator_test)
