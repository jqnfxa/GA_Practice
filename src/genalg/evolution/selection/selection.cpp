#include <map>
#include <utility>
#include <algorithm>
#include <vector>

#include "util/random.hpp"
#include "evolution/selection/selection.hpp"
#include "evolution/interface.hpp"


generation_t RouletteWheel::select(const generation_t &generation, const IEvaluator *evaluator){
    std::vector<genom_t> adaptability_arr;
    std::vector<double> relative_percent;
    double sum_adaptability = 0.0;
    double temp = 0.0;
    double min_value = std::numeric_limits<double>::max();

    for (const auto &gen : generation)
    {
        min_value = std::min(min_value, evaluator->evaluate(gen));
    }

    //Calculation of generational fitness
    for (const auto &gen : generation)
    {
        temp = evaluator->evaluate(gen) - min_value;
        adaptability_arr.push_back(temp);
        sum_adaptability += temp;
    }

    //Calculating relative probability
    for (std::size_t i = 0; i < generation.size(); ++i)
    {
        relative_percent.push_back(adaptability_arr[i] / sum_adaptability);
    }

    std::vector<double> cumulativePercent(relative_percent.size());
    cumulativePercent[0] = relative_percent[0];

    for (std::size_t i = 1; i < relative_percent.size(); ++i)
    {
        cumulativePercent[i] = cumulativePercent[i - 1] + relative_percent[i];
    }

    generation_t parents;
    int end_parents = generation.size() * 0.7;
    for (std::size_t i = 0; i < end_parents; i++)
    {
        double randomValue = random<double>(cumulativePercent.front(), cumulativePercent.back());
        auto it = std::lower_bound(cumulativePercent.begin(), cumulativePercent.end(), randomValue);
        if (it != cumulativePercent.end())
        {
            int index = std::distance(cumulativePercent.begin(), it);
            parents.push_back(generation[index]);
        }
        else
            parents.push_back(generation.back());

    }

    return parents;
}


generation_t RankedSelection::select(const generation_t &generation, const IEvaluator *evaluator){
    std::vector<std::pair<double, genom_t>> adaptability_arr; //y x
    std::vector<double> cumulativePercent(generation.size()); //percent

    for (const auto &gen : generation)
    {   
        adaptability_arr.emplace_back(evaluator->evaluate(gen), gen);
    }

    std::sort(adaptability_arr.begin(), adaptability_arr.end());

    double sum_rank = ((1.0 + generation.size())/2.0) * (generation.size());
    cumulativePercent[0] = 1.0/sum_rank;
    for (std::size_t i = 1; i < generation.size(); i++)
    {
        cumulativePercent[i] = cumulativePercent[i - 1] + (1.0 * (i+1))/sum_rank;
    }

    generation_t parents;
    std::size_t end_parents = generation.size() * 0.7;
    for (std::size_t i = 0; i < end_parents; i++)
    {
        double randomValue = random<double>(cumulativePercent.front(), cumulativePercent.back());
        auto it = std::lower_bound(cumulativePercent.begin(), cumulativePercent.end(), randomValue);
        if (it != cumulativePercent.end())
        {
            int index = std::distance(cumulativePercent.begin(), it);
            parents.push_back(adaptability_arr[index].second);
        }
        else
            parents.push_back(adaptability_arr.back().second);
    }
    
    return parents;
}