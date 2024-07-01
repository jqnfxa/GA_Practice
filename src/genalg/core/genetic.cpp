#include "genetic.hpp"


GeneticAlgorithm::GeneticAlgorithm(
	const Polynomial<genom_t> &polynomial,
	Generation &generation,
	std::size_t max_generations
)
	: polynomial_(polynomial)
	, generation_(generation)
	, max_generations_(max_generations)
	, generations_() {}


void GeneticAlgorithm::run()
{
	generations_.clear();
	generations_.push_back(generation_.generation());

        while (generation_.generation_number() < max_generations)
	{
		generation_.next_generation();
		generations_.push_back(generation_.generation());
	}
}


std::vector<genom_t> GeneticAlgorithm::best_solution(std::size_t generation, std::size_t count = 3) const
{
	if (generation >= generations_.size())
	{
		throw std::out_of_range("error: generation index out of range");
	}

	if (count >= generations_[generation].size())
	{
		throw std::out_of_range("error: too many individuals to pick");
	}

	auto chosen_generation = generations_[generation];
	std::ranges::sort(chosen_generation, [&] (const auto &lhs, const auto &rhs) {
		return polynomial_(lhs) > polynomial_(rhs);
	});

	chosen_generation.resize(count);
	return chosen_generation;
}
