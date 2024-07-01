#include "polynomial.hpp"
#include <stdexcept>


Polynomial::Polynomial(const std::vector<double> &coefficients)
	: coefficients_(coefficients) {}


double Polynomial::operator()(double x) const
{
	double value{0.0};
	double power{1};

	for (const auto &coefficient : coefficients_)
	{
		value += coefficient * power;
		power *= x;
	}

	return value;
}


double Polynomial::operator[](std::size_t index) const
{
	if (index >= coefficients_.size())
	{
		throw std::out_of_range("index out of range");
	}

	return coefficients_[index];
}


std::uint32_t Polynomial::degree() const
{
	return coefficients_.empty() ? 0 : coefficients_.size() - 1;
}
