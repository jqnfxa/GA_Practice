#include <map>
#include <utility>
#include <algorithm>
#include <vector>


#include "../util/random.hpp"
#include "evolution/selection/selection.hpp"
#include "evolution/interface.hpp"


generation_t RouletteWheel::select(const generation_t &generation, const IEvaluator *evaluator){
    std::vector<genom_t> adaptability_arr;
    std::vector<int> relative_percent;
    double sum_adaptability = 0.0;
    double temp = 0.0;

    //Calculation of generational fitness
    for (const auto &gen : generation)
    {
        temp = evaluator->evaluate(gen);
        adaptability_arr.push_back(temp);
        sum_adaptability += temp;
    }

    //Calculating relative probability
    for (std::size_t i = 0; i < generation.size(); ++i)
    {
        relative_percent.push_back(static_cast<int>((adaptability_arr[i] / sum_adaptability) * 100));
    }
    
    std::vector<int> cumulativePercent(relative_percent.size());
    cumulativePercent[0] = relative_percent[0];

    for (std::size_t i = 1; i < relative_percent.size(); ++i)
    {
        cumulativePercent[i] = cumulativePercent[i - 1] + relative_percent[i];
    }

    generation_t parents;

    for (std::size_t i = 0; i < static_cast<int>(generation.size() * 0.7); i++)
    {
        int randomValue = random((int) 1, (int) 100);
        auto it = std::lower_bound(cumulativePercent.begin(), cumulativePercent.end(), randomValue);
        int index = std::distance(cumulativePercent.begin(), it);
        parents.push_back(generation[index]);
    }

    return parents;
}
