#pragma once

#include <vector>


using genom_t = double;
using generation_t = std::vector<genom_t>;


class ISelector
{
public:
	virtual ~ISelector() = default;
	virtual generation_t select(const generation_t &generation, double mut_p, double cross_p) = 0;
};
