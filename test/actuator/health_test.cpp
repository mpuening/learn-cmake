#include <gtest/gtest.h>

#include "actuator/health.h"

TEST(HealthTest, VerifyStatus) {

	LearnCMake::Health health;
	EXPECT_EQ("UP", health.getStatus());
}

