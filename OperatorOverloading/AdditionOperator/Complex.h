#pragma once

#include <iostream>

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);

	Complex(const Complex & other);

	~Complex();


	Complex & operator=(const Complex & c);


	double getReal() const
	{
		return real;
	}

	double getImaginary() const
	{ 
		return imaginary;
	}
};

std::ostream & operator<<(std::ostream & out, const Complex & c);

Complex operator+(const Complex & c1, const Complex & c2);

Complex operator+(const Complex & c, const double & d);
Complex operator+(const double & d, const Complex & c);
