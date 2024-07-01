#include "crossover.hpp"
#include "util/random.hpp"


MixerCrossover::MixerCrossover(double alpha, double left, double right)
	: alpha_(alpha)
	, left_bound_(left)
	, right_bound_(right) {}


generation_t MixerCrossover::cross(const generation_t &generation, double cross_p) const
{
	generation_t new_generation;

	for (std::size_t i = 0; i < generation.size(); ++i)
	{
		const auto probability = random<double>(0, 1);

		if (probability <= cross_p && i + 1 < generation.size())
		{
			new_generation.push_back(mix(generation[i], generation[i + 1]));
			new_generation.push_back(generation[i + 1]);
		}

		new_generation.push_back(generation[i]);
	}

	return new_generation;
}


genom_t MixerCrossover::mix(genom_t parent_a, genom_t parent_b) const
{
	if (parent_a > parent_b)
	{
		std::swap(parent_a, parent_b);
	}

	const auto range_left = parent_a - alpha_ * (parent_b - parent_a);
	const auto range_right = parent_b + alpha_ * (parent_b - parent_a);
	const auto left_bound = std::max(left_bound_, range_left);
	const auto right_bound = std::min(right_bound_, range_right);

	return random<double>(left_bound, right_bound);
}
