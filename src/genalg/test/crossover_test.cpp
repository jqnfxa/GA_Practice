#include <gtest/gtest.h>
#include "../evolution/crossover/crossover.hpp"
#include <math.h>

genom_t mix(genom_t parent_a, genom_t parent_b, double alpha_, double left_bound_, double right_bound_, bool get)
{
    if (parent_a > parent_b)
	{
		std::swap(parent_a, parent_b);
	}

	const auto range_left = parent_a - alpha_ * (parent_b - parent_a);
	const auto range_right = parent_b + alpha_ * (parent_b - parent_a);
	const auto left_bound = std::max(left_bound_, range_left);
	const auto right_bound = std::min(right_bound_, range_right);

	return get ? left_bound : right_bound ;
}


generation_t MixerCrossover(generation_t gen, std::vector<double> r_first, std::vector<bool> r_second, double cross_p, double l, double r, double alpha)
{
    generation_t new_generation;
	for (std::size_t i = 0; i < gen.size(); ++i)
	{
		const auto probability = r_first[i];

		if (probability <= cross_p && i + 1 < gen.size())
		{
			new_generation.push_back(mix(gen[i], gen[i + 1], alpha, l, r, r_second[i]));
			new_generation.push_back(gen[i + 1]);
		}

		new_generation.push_back(gen[i]);
	}
    return new_generation;    
}


TEST(ICrossoverTest, MixerCrossoverClassicTest)
{

    generation_t generation = {-0.757638, -1.14964, 1.3326, -1.57267, 1.7436};
    std::vector<double> random_first = {0.174234, 0.129633, 0.538504, 0.358547, 0.273357};
    std::vector<bool> random_second = {true, false, true, true, true};
    double cross_p = 0.5;
	double left_bound_ = -2;
    double right_bound_ = 2;
    double alpha_ = 0.7;
    generation_t new_generation = MixerCrossover(generation, random_first, random_second, cross_p, left_bound_, right_bound_, alpha_);
    std::vector<double> ans = {-1.42404, -1.14964, -0.757638, 2, 1.3326, -1.14964, 1.3326, -2, 1.7436, -1.57267, 1.7436};

    for (int i = 0; i < ans.size(); i++)
    {
        EXPECT_TRUE(std::fabs(ans[i] - new_generation[i]) < 0.0001);
    }
	
}

TEST(ICrossoverTest, MixerCrossoverHighProbTest)
{

    generation_t generation = {3.03569, 6.87043, 3.68466, 1.58623, 1.88246};
    std::vector<double> random_first = {0.619306, 0.661492, 0.552707, 0.658941, 0.711605};
    std::vector<bool> random_second = {true, true, true, true, true};
    double cross_p = 0.9;
	double left_bound_ = 1;
    double right_bound_ = 7;
    double alpha_ = 0.9;
    generation_t new_generation = MixerCrossover(generation, random_first, random_second, cross_p, left_bound_, right_bound_, alpha_);
    std::vector<double> ans = {1, 6.87043, 3.03569, 1, 3.68466, 6.87043, 1, 1.58623, 3.68466, 1.31962, 1.88246, 1.58623, 1.88246};

    for (int i = 0; i < ans.size(); i++)
    {
        EXPECT_TRUE(std::fabs(ans[i] - new_generation[i]) < 0.0001);
    }
	
}