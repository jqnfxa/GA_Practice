#pragma once
#include "structures/polynomial.hpp"
#include "evolution/interface.hpp"
#include "core/generation.hpp"


class GeneticAlgorithm
{
	Polynomial<genom_t> polynomial_;
	Generation &generation_;
	std::size_t max_generations_;
	std::vector<generation_t> generations_;
public:
	GeneticAlgorithm(
		const Polynomial<genom_t> &polynomial,
		Generation &generation,
		std::size_t max_generations
	);

	void run();
	std::vector<genom_t> best_solution(std::size_t generation, std::size_t count = 3) const;
};
