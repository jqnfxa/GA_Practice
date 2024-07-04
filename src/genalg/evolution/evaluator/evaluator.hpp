#pragma once
#include "evolution/interface.hpp"
#include "structures/polynomial.hpp"


class PolynomialEvaluator : public IEvaluator
{
	Polynomial<genom_t> polynomial_;
	std::vector<genom_t> constraints_;
public:
	explicit PolynomialEvaluator(const Polynomial<genom_t> &polynomial);
	double evaluate(const genom_t &genom) const final;
	void add_constraint(const genom_t &genom) final;
	void reset_constraints() final;
	PolynomialEvaluator *clone() const final;
};
