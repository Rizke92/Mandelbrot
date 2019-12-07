#ifndef __ECE231_COMPLEX_H__
#define __ECE231_COMPLEX_H__

#include <iostream>

class Complex
{
	private:
		double _real; // stores the real component
		double _imag; // stores the imaginary component
	
	public:

	// Constructors
	Complex();
	Complex(double re, double im);  
	Complex(const Complex& z); 

	// access values
	double real() const;
	double imag() const;

	// assignment
	Complex& operator=(double r);
	Complex& operator=(const Complex& z);
	Complex& operator+=(const Complex& z);
	Complex& operator-=(const Complex& z);
	Complex& operator*=(const Complex& z);
	Complex& operator/=(const Complex& z);
};

// basic math operations
Complex operator+(const Complex& a, const Complex& b);
Complex operator-(const Complex& a, const Complex& b);
Complex operator*(const Complex& a, const Complex& b);
Complex operator/(const Complex& a, const Complex& b);

// norm returns the squared magnitude of z
double norm(const Complex& z);
// conj returns the complex conjugate of z
Complex conj(const Complex& z); 
// returns the absolute value of z
double absolute( double r);

// comparison
bool operator==(const Complex& a, const Complex& b);
bool operator==(const Complex& a, double r);
bool operator!=(const Complex& a, const Complex& b);
bool operator!=(const Complex& a, double r);

// write the complex number z to the output stream in the
// format "6+5i" or "6-5i"
std::ostream& operator<<(std::ostream& out, const Complex& z);

#endif // __ECE231_COMPLEX_H__
