/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:11:08 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/02 17:20:09 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0) {}

Fixed::Fixed(const Fixed& a) {operator=(a);}

// Fixed::Fixed(const int a) {fixedPoint = a * power();}

// Fixed::Fixed(const double a) {fixedPoint = roundf(a * power());}

Fixed::Fixed(const int a) {
	if (a < -(256 * 256 * 128) || a > (256 * 256 * 128 - 1))
	{
		std::cerr << "\tError from int ctor: " << std::endl\
		<< "\tOverflow! Can't write in fixedPoint " << a << std::endl;
		std::cout << "\tPrint number < 8388607 or > -8388607\n" << std::endl;
		// exit(EXIT_FAILURE);
	}
	fixedPoint = a * power();
}

Fixed::Fixed(const double a) {
	if ((a > 0 && (a > __INT_MAX__ / power())) || \
			(a < 0 && (a < (-1 - __INT_MAX__ / power()))))
	{
		std::cerr << "\tError from double ctor: " << std::endl\
		<< "\tOverflow! Can't write in fixedPoint " << static_cast<long long>(a) << "\n" << std::endl;
		// exit(EXIT_FAILURE);
	}
	fixedPoint = roundf(a * power());
}

int Fixed::getRawBits(void) const {return (fixedPoint);}

int Fixed::getFractBits(void) const { return (fractBites); }

void Fixed::setRawBits(int const raw) {fixedPoint = raw;}

float Fixed::toFloat(void) const {return((static_cast<double>(fixedPoint)) / (1 << fractBites));}

int Fixed::toInt(void) const {return (fixedPoint / (1 << fractBites));}

int Fixed::power(void) const
{
	int num = 1;
	for (int i = 0; i < fractBites; ++i)
		num *= 2;
	return (num);
}

Fixed::~Fixed() {}

// ======================= STATIC FUNCTIONS ===========================
// independent of any object of the class. 
// can be called even if no objects of the class exist.
// can also be accessed using the class name through the ::.
// can access static data members and static member functions inside or outside of the class.
// have a scope inside the class and cannot access the current object pointer.
// You can also use it like a counter of objects.

Fixed& Fixed::min(Fixed& a, Fixed& b) {return ((a.fixedPoint < b.fixedPoint) ? a : b);}

Fixed& Fixed::max(Fixed& a, Fixed& b) {return ((a.fixedPoint > b.fixedPoint) ? a : b);}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {return ((a.fixedPoint < b.fixedPoint) ? a : b);}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {return ((a.fixedPoint > b.fixedPoint) ? a : b);}

// ====================================================================
// ============================ OPERATORS =============================
// ====================================================================

// copy assignement operator
Fixed& Fixed::operator=(const Fixed& a)
{
	if (&a == this)
	return (*this);
	if (a.fixedPoint == __INT_MAX__)
	std::cerr << "Too big num" << std::endl;
	fixedPoint = a.getRawBits();
	return (*this);
}

// ============= 4 arithmetic operators (plus ans minus) ==============
Fixed& Fixed::operator+=(const Fixed& a) 
{
	fixedPoint += a.fixedPoint;
	if ((fixedPoint + a.fixedPoint) - a.fixedPoint != fixedPoint)
		std::cerr << "Error: overflow" << std::endl;
	return (*this);
}

Fixed Fixed::operator+(const Fixed& a) const
{
	if ((fixedPoint + a.fixedPoint) - a.fixedPoint != fixedPoint)
		std::cerr << "Error: overflow" << std::endl;
	Fixed sum = *this;
	sum.fixedPoint += a.fixedPoint;
	return (sum);
}

Fixed& Fixed::operator-=(const Fixed& a) 
{
	if ((fixedPoint - a.fixedPoint) + a.fixedPoint != fixedPoint)
		std::cerr << "Error: overflow" << std::endl;
	fixedPoint -= a.fixedPoint;
	return (*this);
}

Fixed Fixed::operator-(const Fixed& a) const
{
	if ((fixedPoint - a.fixedPoint) + a.fixedPoint != fixedPoint)
		std::cerr << "Error: overflow" << std::endl;
	Fixed sum = *this;
	sum.fixedPoint -= a.fixedPoint;
	return (sum);
}

// ============ 4 arithmetic operators (multiply ans division) ===========

Fixed& Fixed::operator*=(const Fixed& a) 
{
	if ((fixedPoint > 0 && (static_cast<long double>(getRawBits()) * a.toFloat()) > __INT_MAX__) || \
		(fixedPoint < 0 && (static_cast<long double>(getRawBits()) * a.toFloat()) < -1 - __INT_MAX__))
	{
		std::cerr << "\nError: overflow!!!\n" << std::endl;
		exit(EXIT_FAILURE);
	}
	fixedPoint *= a.toFloat();
	return (*this);
}

Fixed Fixed::operator*(const Fixed& a) const
{
	Fixed sum (*this);
	sum *= a;
	return (sum);
}

Fixed& Fixed::operator/=(const Fixed& a) 
{
	if (a.fixedPoint == 0)
		std::cerr << "Delimiter can't be 0" << std::endl;
	fixedPoint /= a.toFloat();
	return (*this);
}

Fixed Fixed::operator/(const Fixed& a) const
{
	if (a.fixedPoint == 0)
		std::cerr << "Delimiter can't be 0" << std::endl;
	Fixed sum = *this;
	sum /= a;
	return (sum);
}

// ====================== increments and decrements ======================
// preincrement
Fixed& Fixed::operator++()
{
	if (fixedPoint == __INT_MAX__)
		std::cerr << "Too big num" << std::endl;
	fixedPoint += 1;
	return (*this);
}

// postincrement
const Fixed Fixed::operator++(int)
{
	if (fixedPoint == __INT_MAX__)
		std::cerr << "Too big num" << std::endl;
	Fixed a;
	a.fixedPoint = fixedPoint;
	fixedPoint += 1;
	return (a);
}

Fixed& Fixed::operator--()
{
	if (fixedPoint == -1 - __INT_MAX__)
		std::cerr << "Too big num" << std::endl;
	fixedPoint -= 1;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	if (fixedPoint == -1 - __INT_MAX__)
		std::cerr << "Too big num" << std::endl;
	Fixed a;
	a.fixedPoint = fixedPoint;
	--(fixedPoint);
	return (a);
}

// ====================== 6 comparison operators ======================

bool Fixed::operator<(const Fixed& a) const
{
	return (fixedPoint < a.fixedPoint);
}

bool Fixed::operator>(const Fixed& a) const
{
	return (a.fixedPoint < fixedPoint);
}

bool Fixed::operator==(const Fixed& a) const
{
	return !(a.fixedPoint < fixedPoint || fixedPoint < a.fixedPoint);
}

bool Fixed::operator!=(const Fixed& a) const
{
	return !(a.fixedPoint == fixedPoint);
}

bool Fixed::operator<=(const Fixed& a) const
{
	return !(fixedPoint > a.fixedPoint);
}

bool Fixed::operator>=(const Fixed& a) const
{
	return !(fixedPoint < a.fixedPoint);
}
