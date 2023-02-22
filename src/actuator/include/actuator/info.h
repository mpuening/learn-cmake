#pragma once

#include <string>

namespace LearnCMake {

class Info {

public:

	Info() = default;
	~Info() = default;

	std::string getVersion();
	std::string getCommit();
	std::string getTimestamp();

	void logInfo();

private:

	Info(const Info&) = delete;
	Info& operator=(const Info&) = delete;
};

}
