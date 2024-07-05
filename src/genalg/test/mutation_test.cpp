#include <gtest/gtest.h>
#include "../evolution/mutation/mutation.hpp"
#include <math.h>

generation_t SubstanceMutation(generation_t generation, generation_t r_first, generation_t r_second, double l, double r, double cross_p)
{
    generation_t mutate_individual;
    double temp;
    for (size_t i = 0; i < generation.size(); i++)
    {
        mutate_individual.push_back(generation[i]);
        if (r_first[i] < cross_p)
        {
            temp = (r - l) / 100 * r_second[i];
            if (temp < l)
                temp = l;

            if (temp > r)
                temp = r;

            mutate_individual[i] += temp;
        }
    }
    return mutate_individual;
}


TEST(IMutationTest, SubstanceMutationClassicTest)
{
    generation_t generation = {0.2371, 1.1234, 2.0012, 0.9831, 1.4236};
    generation_t random_first = {0.2741, 0.1289, 0.7385, 0.3412, 0.8194};
    generation_t random_second = {-0.5641, 0.3481, 0.2225, 0.7427, -0.9129};
    double cross_p = 0.3;
	double left_bound_ = 0;
    double right_bound_ = 3;
    generation_t ans = {0.2371, 1.13384, 2.0012, 0.9831, 1.4236};

    generation_t mutate_individual = SubstanceMutation(generation, random_first, random_second, left_bound_, right_bound_, cross_p);

    for (int i = 0; i < ans.size(); i++)
    {
        EXPECT_TRUE(std::fabs(ans[i] - mutate_individual[i]) < 0.0001);
    }
	
}


TEST(IMutationTest, SubstanceMutationOutOfRangeTest)
{
    generation_t generation = {1.19973, 1.18914, 0.610354, 2.28771, 2.37712};
    generation_t random_first = {0.12305, 0.913268, 0.344488, 0.396081, 0.578466};
    generation_t random_second = {0.97288, 0.980508, 0.693026, 0.454962, 0.619046};
    double cross_p = 0.8;
	double left_bound_ = 0;
    double right_bound_ = 3;
    generation_t ans = {1.22892, 1.18914, 0.631145, 2.30136, 2.39569};

    generation_t mutate_individual = SubstanceMutation(generation, random_first, random_second, left_bound_, right_bound_, cross_p);

    for (int i = 0; i < ans.size(); i++)
    {
        EXPECT_TRUE(std::fabs(ans[i] - mutate_individual[i]) < 0.00001);
    }
	
}
