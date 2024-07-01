#pragma once

#include <cstdint>
#include <memory>
#include "../structures/interface.hpp"


class Generation
{
	std::size_t inital_size_;
	std::size_t generation_number_;
	double mut_p_;
	double cross_p_;
	generation_t generation_;

	std::unique_ptr<ISelector> selector_;
public:
	Generation(
		std::size_t inital_size,
		double mut_p,
		double cross_p,
		ISelector *selector
	);


	std::size_t generation_number() const;
	generation_t generation() const;
	void next_generation();
};
