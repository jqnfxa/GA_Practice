#pragma once
#include <vector>


using genom_t = double;
using generation_t = std::vector<genom_t>;


class IClonable
{
public:
	virtual ~IClonable() = default;
	virtual IClonable *clone() const = 0;
};


class IEvaluator : public IClonable
{
public:
	virtual ~IEvaluator() = default;
	virtual double evaluate(const genom_t &genom) const = 0;
	virtual void add_constraint(const genom_t &genom) = 0;
	virtual void reset_constraints() = 0;
};


class ISelector : public IClonable
{
public:
	virtual ~ISelector() = default;
	virtual generation_t select(const generation_t &generation, const IEvaluator *evaluator) = 0;
};


class ICrossover : public IClonable
{
public:
	virtual ~ICrossover() = default;
	virtual generation_t cross(const generation_t &generation, double cross_p) const = 0;
};


class IMutation : public IClonable
{
	double left_bound_;
	double right_bound_;
public:
        explicit IMutation(double left_bound, double right_bound) : left_bound_(left_bound), right_bound_(right_bound) {}

	virtual ~IMutation() = default;
	virtual generation_t mutate(const generation_t &generation, double cross_p) const = 0;
};

