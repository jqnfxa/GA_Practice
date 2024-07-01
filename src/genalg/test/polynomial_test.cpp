#include <gtest/gtest.h>
#include "../structures/polynomial.hpp"


TEST(PolynomialTest, PolynomialCreation)
{
	std::vector<double> coefficients = {1.0, 0.0, -2.0, 3.0};
	Polynomial<double> p(coefficients);

	EXPECT_EQ(p.degree(), 3);
	EXPECT_EQ(p[0], 1.0);
	EXPECT_EQ(p[1], 0.0);
	EXPECT_EQ(p[2], -2.0);
	EXPECT_EQ(p[3], 3.0);
}


TEST(PolynomialTest, PolynomialEvaluation)
{
	std::vector<double> coefficients = {1.0, 0.0, -2.0, 3.0};
	Polynomial<double> p(coefficients);

	EXPECT_DOUBLE_EQ(p(0.0), 1.0);
	EXPECT_DOUBLE_EQ(p(1.0), 2.0);
	EXPECT_DOUBLE_EQ(p(-1.0), -4.0);
	EXPECT_DOUBLE_EQ(p(2.0), 17.0);
}
