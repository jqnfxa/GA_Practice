#pragma once
#include "evolution/interface.hpp"


class MixerCrossover : public ICrossover
{
	double alpha_;
	double left_bound_;
	double right_bound_;
public:
        MixerCrossover(double alpha, double left, double right);

	generation_t cross(const generation_t &generation, double cross_p) const final;
	genom_t mix(genom_t parent_a, genom_t parent_b) const;
};
