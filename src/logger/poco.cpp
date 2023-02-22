#include <iostream>
#include <memory>
#include <string>

#include "logger/logger.h"
#include "logger/poco.h"

namespace LearnCMake {

// =================================

class PocoLogger: public LoggerType {
public:
	PocoLogger(Poco::Logger &logger);
	~PocoLogger() = default;
	void info(const std::string message);
	void error(const std::string message);
private:
	Poco::Logger &_logger;
};

PocoLogger::PocoLogger(Poco::Logger &logger) :
		_logger(logger) {
}

void PocoLogger::info(const std::string message) {
	this->_logger.information(message);
}

void PocoLogger::error(const std::string message) {
	this->_logger.error(message);
}

// =================================

void registerPocoLogger(Poco::Logger &logger) {
	Logger::get()->setLoggerType(std::make_unique < PocoLogger > (logger));
}

}
