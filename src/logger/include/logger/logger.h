#pragma once

#include <string>

namespace LearnCMake {

class LoggerType {
public:
	LoggerType() = default;
	virtual ~LoggerType() = default;
	virtual void info(const std::string message) = 0;
	virtual void error(const std::string message) = 0;
};

class Logger {
public:

	static Logger* get();

	void info(const std::string message);
	void error(const std::string message);

	void setLoggerType(std::unique_ptr<LoggerType> loggerType);

private:

	Logger();
	~Logger() = default;

	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	std::unique_ptr<LoggerType> _loggerType;

	static Logger *_singleton;
};

}
