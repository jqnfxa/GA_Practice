#include <cmath>
#include <iostream>
#include "evaluator.hpp"


PolynomialEvaluator::PolynomialEvaluator(const Polynomial<genom_t> &polynomial)
	: polynomial_(polynomial) {}


double PolynomialEvaluator::evaluate(const genom_t &genom) const
{
	const auto epsilon = 1e-6;
	double penalty = std::fabs((polynomial_(genom + epsilon) - polynomial_(genom - epsilon)) / (2.0 * epsilon));

	for (const auto &constraint : constraints_)
	{
		penalty += 1.0 / std::fabs(genom - constraint);
	}

	return polynomial_(genom) - penalty;
}


void PolynomialEvaluator::add_constraint(const genom_t &genom)
{
	constraints_.push_back(genom);
}


void PolynomialEvaluator::reset_constraints()
{
	constraints_.clear();
}


PolynomialEvaluator *PolynomialEvaluator::clone() const
{
	return new PolynomialEvaluator(polynomial_);
}
