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
	// P(x) = -x^4+x^3+2x^2-x+1
	//Polynomial<genom_t> polynomial({1, -1, 2, 1, -1});
	Polynomial<genom_t> polynomial({-1, -1, 2, 3, -1, -1});
	double left = -3;
	double right = 3;
	double mut_p = 0.7;
	double cross_p = 0.7;
	std::size_t initial_size = 50;
	std::size_t max_generations = 20;

	GeneticAlgorithm algorithm(
		initial_size,
		max_generations,
                mut_p,
                cross_p,
                new RouletteWheel,
                new MixerCrossover(0.5, left, right),
		new SubstanceMutation(left, right),
                new PolynomialEvaluator(polynomial),
		left,
		right,
		polynomial
	);

	const auto report = algorithm.run(4);

	for (const auto &maximum : report)
	{
		for (const auto &generation_report : maximum)
		{
			for (const auto &individual : generation_report.best_solution())
			{
				std::cout << individual << ' ';
			}

			std::cout << ' ' << generation_report.accuracy() << '\n';
		}

		std::cout << "\n\n\n\n";
	}

	return 0;
}
