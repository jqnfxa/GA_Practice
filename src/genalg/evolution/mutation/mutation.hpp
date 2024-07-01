#pragma once


#include "evolution/interface.hpp"

class SubstanceMutation: public IMutation
{
    double left_bound_;
	double right_bound_;
public:
    SubstanceMutation(double left_bound, double right_bound);
    generation_t mutate(const generation_t &generation, double cross_p) const override;
};