#include <gtest/gtest.h>

#include "actuator/info.h"

TEST(InfoTest, VerifyInfo) {

	LearnCMake::Info info;
	EXPECT_EQ("1.0.0", info.getVersion());
	EXPECT_NE("", info.getCommit());
	EXPECT_NE("", info.getTimestamp());

	info.logInfo();
}

