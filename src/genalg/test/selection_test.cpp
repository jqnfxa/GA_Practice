#include <gtest/gtest.h>
/*
TEST(RouletteWheel, )
{
	std::vector<double> coefficients = {1.0, 0.0, -2.0, 3.0};
	Polynomial<double> p(coefficients);

	EXPECT_EQ(p.degree(), 3);
	EXPECT_EQ(p[0], 1.0);
	EXPECT_EQ(p[1], 0.0);
	EXPECT_EQ(p[2], -2.0);
	EXPECT_EQ(p[3], 3.0);
}*/

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
