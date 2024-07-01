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
	Polynomial<genom_t> polynomial({0, 0, -1});
	double left = -2;
	double right = 2;
	double mut_p = 0.6;
	double cross_p = 0.4;
	std::size_t initial_size = 10;
	std::size_t max_generations = 100;

	Generation generation(
		initial_size,
		mut_p,
		cross_p,
		new RouletteWheel,
		new MixerCrossover(0.5, left, right),
		new SubstanceMutation(left, right),
		new PolynomialEvaluator(polynomial)
	);

	GeneticAlgorithm algorithm(
		polynomial,
		generation,
		max_generations
	);

	algorithm.run();
	for (std::size_t i = 0; i < max_generations; ++i)
	{
		auto best_solution = algorithm.best_solution(i);

		for (const auto &individual : best_solution)
		{
			std::cout << individual << ' ' << '\n';
		}
	}

	return 0;
}
