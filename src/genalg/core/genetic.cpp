#include <algorithm>
#include <cmath>
#include <iostream>
#include "genetic.hpp"


GeneticAlgorithmReport::GeneticAlgorithmReport(
	const generation_t &generation,
	const generation_t &best_individuals
)	: generation_(generation)
	, best_individuals_(best_individuals) {}


double GeneticAlgorithmReport::accuracy(double best) const
{
	double sum_accuracy = 0;
	for (const auto gen : best_individuals_)
	{	
		sum_accuracy += std::fabs(best - gen)/(std::fabs(best) + std::fabs(gen));
	}
	return 1.0 - sum_accuracy/best_individuals_.size();
}


generation_t GeneticAlgorithmReport::best_solution() const
{
	return best_individuals_;
}


GeneticAlgorithm::GeneticAlgorithm(
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
) 	: initial_size_(initial_size)
	, max_generations_(max_generations)
	, mut_p_(mut_p)
	, cross_p_(cross_p)
	, selector_(selector)
	, crossover_(crossover)
	, mutator_(mutator)
	, evaluator_(evaluator)
	, left_(left)
	, right_(right)
	, polynomial_(polynomial) {}


std::vector<generation_t> GeneticAlgorithm::find_solution(double left, double right)
{
	Generation generation(
		initial_size_,
		mut_p_,
		cross_p_,
		reinterpret_cast<ISelector *>(selector_->clone()),
		reinterpret_cast<ICrossover *>(crossover_->clone()),
		reinterpret_cast<IMutation *>(mutator_->clone()),
		reinterpret_cast<IEvaluator *>(evaluator_->clone()),
		left,
		right
	);

	std::vector<generation_t> solution;
	solution.push_back(generation.generation());
	while (generation.generation_number() < max_generations_)
	{
		generation.next_generation();
		solution.push_back(generation.generation());
	}

	return solution;
}


std::vector<genom_t> GeneticAlgorithm::best_solution(const generation_t &generation, std::size_t count) const
{
	if (count >= generation.size())
	{
		throw std::out_of_range("error: too many individuals to pick");
	}

	auto chosen_generation = generation;
	std::ranges::sort(chosen_generation, [&] (const auto &lhs, const auto &rhs) {
		return evaluator_->evaluate(lhs) > evaluator_->evaluate(rhs);
	});

	chosen_generation.resize(count);
	return chosen_generation;
}


std::vector<std::vector<GeneticAlgorithmReport>> GeneticAlgorithm::run(std::size_t count)
{
	std::vector<std::vector<GeneticAlgorithmReport>> solutions;

	bool has_maximum = true;
	while (has_maximum)
	{
		std::vector<generation_t> solution = find_solution(left_, right_);
		genom_t best_individual = best_solution(solution.back(), 1)[0];

		if (!is_maximum(best_individual))
		{
			has_maximum = false;
			continue;
		}

		std::vector<GeneticAlgorithmReport> new_solution;
		for (const auto &generation : solution)
		{
			new_solution.emplace_back(generation, best_solution(generation, count));
		}

		solutions.push_back(new_solution);
		evaluator_->add_constraint(best_individual);
	}

	return solutions;
}


bool GeneticAlgorithm::is_maximum(genom_t genom) const
{
	const auto epsilon = 0.1;
	const auto left = polynomial_(genom) - polynomial_(genom - epsilon);
	const auto right = polynomial_(genom) - polynomial_(genom + epsilon);

	return !std::signbit(left) && !std::signbit(right);
}
