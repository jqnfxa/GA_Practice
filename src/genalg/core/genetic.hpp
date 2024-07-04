#pragma once
#include "structures/polynomial.hpp"
#include "evolution/interface.hpp"
#include "core/generation.hpp"


class GeneticAlgorithmReport
{
	generation_t best_individuals_;
	generation_t generation_;
public:
	explicit GeneticAlgorithmReport(const generation_t &generation, const generation_t &best_individuals);
	double accuracy() const;
	generation_t best_solution() const;
};


class GeneticAlgorithm
{
	std::size_t initial_size_;
	std::size_t max_generations_;
	double mut_p_;
	double cross_p_;
	ISelector *selector_;
	ICrossover *crossover_;
	IMutation *mutator_;
	IEvaluator *evaluator_;
	double left_;
	double right_;
	Polynomial<genom_t> polynomial_;
public:
	GeneticAlgorithm(
		std::size_t initial_size,
		std::size_t max_generations,
		double mut_p,
		double cross_p,
		ISelector *selector,
		ICrossover *crossover,
		IMutation *mutator,
		IEvaluator *evaluator,
		double left,
		double right,
		const Polynomial<genom_t> &polynomial
	);

	std::vector<std::vector<GeneticAlgorithmReport>> run(std::size_t count = 5);
	std::vector<generation_t> find_solution(double left, double right);
	std::vector<genom_t> best_solution(const generation_t &generation, std::size_t count = 3) const;
	bool is_maximum(genom_t genom) const;
};
