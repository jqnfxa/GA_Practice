#pragma once
#include "evolution/interface.hpp"
#include "structures/polynomial.hpp"


class PolynomialEvaluator : public IEvaluator
{
	Polynomial<genom_t> polynomial_;
public:
	explicit PolynomialEvaluator(const Polynomial<genom_t> &polynomial);
	double evaluate(const genom_t &genom) const final;
};
