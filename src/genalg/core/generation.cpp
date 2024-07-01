#include <stdexcept>
#include "generation.hpp"
#include "../util/random.hpp"


Generation::Generation(
	std::size_t inital_size,
	double mut_p,
	double cross_p,
	ISelector *selector,
	ICrossover *crossover,
	IMutation *mutator,
	IEvaluator *evaluator
)
	: inital_size_(inital_size)
	, generation_number_(1)
	, mut_p_(mut_p)
	, cross_p_(cross_p)
	, selector_(selector)
	, crossover_(crossover)
	, mutator_(mutator)
	, evaluator_(evaluator)
{
	if (selector == nullptr)
	{
		throw std::runtime_error("error: invalid selector");
	}

	if (crossover == nullptr)
	{
		throw std::runtime_error("error: invalid crossover");
	}

	if (mutator == nullptr)
	{
		throw std::runtime_error("error: invalid mutator");
	}

	if (evaluator == nullptr)
	{
		throw std::runtime_error("error: invalid evaluator");
	}
}


double Generation::adaptability(genom_t genom) const
{
	return evaluator_->evaluate(genom);
}


std::size_t Generation::generation_number() const
{
	return generation_number_;
}


generation_t Generation::generation() const
{
	return generation_;
}


void Generation::next_generation()
{
	generation_ = selector_->select(generation_);
	generation_ = crossover_->cross(generation_, cross_p_);
	generation_ = mutator_->mutate(generation_, mut_p_);
	++generation_number_;
}
