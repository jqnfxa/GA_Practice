#pragma once
#include <cstdint>
#include <memory>
#include "evolution/interface.hpp"


class Generation
{
	std::size_t inital_size_;
	std::size_t generation_number_;
	double mut_p_;
	double cross_p_;
	generation_t generation_;

	std::unique_ptr<ISelector> selector_;
	std::unique_ptr<ICrossover> crossover_;
	std::unique_ptr<IMutation> mutator_;
	std::unique_ptr<IEvaluator> evaluator_;
public:
	Generation(
		std::size_t inital_size,
		double mut_p,
		double cross_p,
		ISelector *selector,
		ICrossover *crossover,
		IMutation *mutator,
		IEvaluator *evaluator,
		double left,
		double right
	);


	[[nodiscard]] double adaptability(genom_t genom) const;
	[[nodiscard]] std::size_t generation_number() const;
	[[nodiscard]] generation_t generation() const;
	void next_generation();
};
