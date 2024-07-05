#pragma once
#include <random>


template <typename T>
T random(T from, T to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(from, to);
	return dis(gen);
}


template <typename T>
T rnd(T from, T to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(from, to);
	return dis(gen);
}
