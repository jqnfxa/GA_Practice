#pragma once

#include <vector>
#include <cstdint>
#include <stdexcept>


template <typename T>
class Polynomial
{
	std::vector<T> coefficients_;
public:
	inline Polynomial(const std::vector<T> &coefficients)
		: coefficients_(coefficients) {}

	[[nodiscard]] T operator()(T x) const
	{
		T result{0};
		T power{1};
		for (const auto &coefficient : coefficients_)
		{
			result += coefficient * power;
			power *= x;
		}

		return result;
	}

	[[nodiscard]] T operator[](std::size_t index) const
	{
		if (index >= coefficients_.size())
		{
			throw std::out_of_range("index out of range");
		}

		return coefficients_[index];
	}

	[[nodiscard]] std::size_t degree() const
	{
		return coefficients_.empty() ? 0 : coefficients_.size() - 1;
	}
};
