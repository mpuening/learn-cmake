#pragma once

#include <string>

namespace LearnCMake {

class Health {

public:

	Health() = default;
	~Health() = default;

	std::string getStatus();

private:

	Health(const Health&) = delete;
	Health& operator=(const Health&) = delete;

};

}
