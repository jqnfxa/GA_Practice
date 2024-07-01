#pragma once


class GeneticAlgorithm {
public:
    GeneticAlgorithm(const Polynomial& polynomial, double l, double r, size_t populationSize, double mutationRate, double crossoverRate)
        : poly(polynomial), left(l), right(r), popSize(populationSize), mutationRate(mutationRate), crossoverRate(crossoverRate) {
        std::srand(std::time(0));
        initializePopulation();
    }

    void run(size_t generations) {
        for (size_t gen = 0; gen < generations; ++gen) {
            std::vector<double> newGeneration;
            for (size_t i = 0; i < popSize; ++i) {
                double parent1 = selectParent();
                double parent2 = selectParent();
                double offspring = crossover(parent1, parent2);
                mutate(offspring);
                newGeneration.push_back(offspring);
            }
            population = newGeneration;
        }
    }

    double getBestSolution() const {
        return *std::max_element(population.begin(), population.end(), [this](double a, double b) {
            return poly.evaluate(a) < poly.evaluate(b);
        });
    }

private:
    void initializePopulation() {
        for (size_t i = 0; i < popSize; ++i) {
            double individual = left + static_cast<double>(std::rand()) / RAND_MAX * (right - left);
            population.push_back(individual);
        }
    }

    double selectParent() {
        double best = population[std::rand() % popSize];
        for (size_t i = 1; i < 5; ++i) {
            double challenger = population[std::rand() % popSize];
            if (poly.evaluate(challenger) > poly.evaluate(best)) {
                best = challenger;
            }
        }
        return best;
    }

    double crossover(double parent1, double parent2) {
        if (static_cast<double>(std::rand()) / RAND_MAX < crossoverRate) {
            return left + static_cast<double>(std::rand()) / RAND_MAX * (right - left);
        }
        return (parent1 + parent2) / 2.0;
    }

    void mutate(double& individual) {
        if (static_cast<double>(std::rand()) / RAND_MAX < mutationRate) {
            individual += (static_cast<double>(std::rand()) / RAND_MAX - 0.5) * (right - left) / 10.0;
        }
    }

    const Polynomial& poly;
    double left, right;
    size_t popSize;
    double mutationRate, crossoverRate;
    std::vector<double> population;
};
