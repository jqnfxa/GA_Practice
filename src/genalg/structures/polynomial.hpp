#pragma once

#include <vector>
#include <cstdint>


class Polynomial
{
	std::vector<double> coefficients_;
public:
	Polynomial(const std::vector<double> &coefficients);
	double operator()(double x) const;
	double operator[](std::size_t index) const;
	std::uint32_t degree() const;
};
