#include "pch.h"
#include "../Baseball/baseball.cpp"

TEST(BaseballGame, InvalidArgument) {

	Baseball baseball;

	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1543"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("121"), std::invalid_argument);
}

TEST(BaseballGame, PerfectMatch) {
	string answer = "123";
	Baseball baseball(answer);
	Result result = baseball.guess(answer);

	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}