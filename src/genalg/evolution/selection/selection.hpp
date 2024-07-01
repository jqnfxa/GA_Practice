#pragma once

#include "evolution/interface.hpp"
#include "evolution/evaluator/evaluator.hpp"

class RouletteWheel: public ISelector
{
public:
    generation_t select(const generation_t &generation, const IEvaluator *evaluator) final;
};