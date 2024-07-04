#include <iostream>
#include "structures/polynomial.hpp"
#include "evolution/interface.hpp"
#include "evolution/selection/selection.hpp"
#include "evolution/mutation/mutation.hpp"
#include "evolution/crossover/crossover.hpp"
#include "core/generation.hpp"
#include "core/genetic.hpp"


int main()
{
	// P(x) = -x^2
	Polynomial<genom_t> polynomial({1, -1, 1, 1, -1});
	double left = 0;
	double right = 30;
	double mut_p = 0.8;
	double cross_p = 0.8;
	std::size_t initial_size = 40;
	std::size_t max_generations = 10;

	Generation generation(
		initial_size,
		mut_p,
		cross_p,
		new RankedSelection,
		new MixerCrossover(0.5, left, right),
		new SubstanceMutation(left, right),
		new PolynomialEvaluator(polynomial),
		left,
		right
	);

	GeneticAlgorithm algorithm(
		polynomial,
		generation,
		max_generations
	);

	algorithm.run();
	for (std::size_t i = 0; i < max_generations; ++i)
	{
		auto best_solution = algorithm.best_solution(i, 3);

		std::cout << "gen: " << i + 1 << '\n';
		for (const auto &individual : best_solution)
		{
			std::cout << individual << ' ' << polynomial(individual) << '\n';
		}
		std::cout << '\n';
	}

	return 0;
}
