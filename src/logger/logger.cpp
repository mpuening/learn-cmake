#include <iostream>
#include <memory>
#include <string>

#include "logger/logger.h"

namespace LearnCMake {

// =================================

class ConsoleLogger: public LoggerType {
public:
	ConsoleLogger() = default;
	~ConsoleLogger() = default;
	void info(const std::string message);
	void error(const std::string message);
};

void ConsoleLogger::info(const std::string message) {
	std::cout << message << std::endl;
}

void ConsoleLogger::error(const std::string message) {
	std::cout << message << std::endl;
}

// =================================

Logger::Logger() {
	this->_loggerType = std::make_unique<ConsoleLogger>();
}

void Logger::info(const std::string message) {
	this->_loggerType->info(message);
}

void Logger::error(const std::string message) {
	this->_loggerType->error(message);
}

void Logger::setLoggerType(std::unique_ptr<LoggerType> loggerType) {
	this->_loggerType = std::move(loggerType);
}

// =================================

Logger *Logger::_singleton = nullptr;

Logger* Logger::get() {
	if (!_singleton) {
		_singleton = new Logger;
	}
	return _singleton;
}

}

