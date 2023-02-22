add_executable(
	logger_test

	logger_test.cpp
)

target_link_libraries(
	logger_test

	PRIVATE
	logger_lib
	Poco::Foundation
	Poco::Util
)

DiscoverTests(logger_test)
