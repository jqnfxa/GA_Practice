

#include "evolution/mutation/mutation.hpp"
#include "util/random.hpp"

SubstanceMutation::SubstanceMutation(double left_bound, double right_bound) : IMutation(left_bound, right_bound) {}

generation_t SubstanceMutation::mutate(const generation_t &generation, double cross_p) const {
    generation_t mutate_individual;
    double temp;
    for (size_t i = 0; i < generation.size(); i++)
    {
        mutate_individual.push_back(generation[i]);
        if (random<double>(0, 1) < cross_p)
        {
            temp = (right_bound_ - left_bound_) / 100 * random<double>(-1, 1);
            if (temp < left_bound_)
                temp = left_bound_;

            if (temp > right_bound_)
                temp = right_bound_;

            mutate_individual[i] += temp;
        }
    }
    return mutate_individual;
}


SubstanceMutation *SubstanceMutation::clone() const
{
	return new SubstanceMutation(left_bound_, right_bound_);
}
