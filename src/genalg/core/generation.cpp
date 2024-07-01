#include <stdexcept>
#include "generation.hpp"


Generation::Generation(
	std::size_t inital_size,
	double mut_p,
	double cross_p,
	ISelector *selector
)
	: inital_size_(inital_size)
	, generation_number_(1)
	, mut_p_(mut_p)
	, cross_p_(cross_p)
	, selector_(selector)
{
	if (selector == nullptr)
	{
		throw std::runtime_error("error: invalid selector");
	}
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
	generation_ = selector_->select(generation_, mut_p_, cross_p_);
	++generation_number_;
}
