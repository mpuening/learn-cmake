#include <iostream>
#include <gtest/gtest.h>

#include "Poco/Logger.h"

#include "logger/logger.h"
#include "logger/poco.h"

TEST(LoggerTest, LogInfoMessage) {

	LearnCMake::Logger::get()->info("Info Message");

	EXPECT_EQ(true, true);
}

TEST(LoggerTest, LogErrorMessage) {

	LearnCMake::Logger::get()->error("Error Message");

	EXPECT_EQ(true, true);
}

TEST(LoggerTest, LogPocoInfoMessage) {

	Poco::Logger &pocoLogger = Poco::Logger::get("Test");
	LearnCMake::registerPocoLogger(pocoLogger);
	LearnCMake::Logger::get()->info("Info Message");

	EXPECT_EQ(true, true);
}

TEST(LoggerTest, LogPocoErrorMessage) {

	Poco::Logger &pocoLogger = Poco::Logger::get("Test");
	LearnCMake::registerPocoLogger(pocoLogger);
	LearnCMake::Logger::get()->error("Error Message");

	EXPECT_EQ(true, true);
}
