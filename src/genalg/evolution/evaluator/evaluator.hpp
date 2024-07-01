#pragma once
#include "evolution/interface.hpp"


// TODO: move implementation in cpp file
class PolynomialEvaluator : public IEvaluator
{
	Polynomial<genom_t> polynomial_;
public:
	explicit PolynomialEvaluator(const Polynomial<genom_t> &polynomial) : polynomial_(polynomial) {}
	double evaluate(const genom_t &genom) { return polynomial_(genom); }
};
