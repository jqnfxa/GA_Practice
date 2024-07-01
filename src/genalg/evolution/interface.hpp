#pragma once
#include <vector>


using genom_t = double;
using generation_t = std::vector<genom_t>;


class ISelector
{
public:
	virtual ~ISelector() = default;
	virtual generation_t select(const generation_t &generation) = 0;
};


class ICrossover
{
public:
	virtual ~ICrossover() = default;
	virtual generation_t cross(const generation_t &generation, double cross_p) = 0;
};


class IMutation
{
	double left_bound_;
	double right_bound_;
public:
        explicit IMutation(double left_bound, double right_bound) : left_bound_(left_bound), right_bound_(right_bound) {}

	virtual ~IMutation() = default;
	virtual generation_t mutate(const generation_t &generation, double cross_p) = 0;
};


class IEvaluator
{
public:
	virtual ~IEvaluator() = default;
	virtual double evaluate(const genom_t &genom) = 0;
};
