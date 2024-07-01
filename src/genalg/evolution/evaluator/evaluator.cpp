#include "evaluator.hpp"


PolynomialEvaluator::PolynomialEvaluator(const Polynomial<genom_t> &polynomial)
	: polynomial_(polynomial) {}


double PolynomialEvaluator::evaluate(const genom_t &genom)
{
	return polynomial_(genom);
}
