#include <string>

#include "buildinfo.h"
#include "actuator/info.h"
#include "logger/logger.h"

namespace LearnCMake {

std::string Info::getVersion() {
	return BuildInfo().VERSION;
}

std::string Info::getCommit() {
	return BuildInfo().COMMIT_SHA;
}

std::string Info::getTimestamp() {
	return BuildInfo().TIMESTAMP;
}

void Info::logInfo() {
	LearnCMake::Logger::get()->info("Version: " + BuildInfo().VERSION);
	LearnCMake::Logger::get()->info("Commit: " + BuildInfo().COMMIT_SHA);
	LearnCMake::Logger::get()->info("Timestamp: " + BuildInfo().TIMESTAMP);
}

}

