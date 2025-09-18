/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:11:08 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/02 20:07:58 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): fixedPoint(0) {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed& a)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = a.fixedPoint;
}

Fixed::Fixed(const int a)
{
	fixedPoint = a * power();
	// std::cout << "\t\t\tconst int -> fixed-point: " << fixedPoint << std::endl;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float a)
{
	fixedPoint = roundf(a * power());
	// std::cout << "\t\t\tfloating -> fixed-point: " << fixedPoint << std::endl;
	std::cout << "Float constructor called" << std::endl;
}
// copy assignement operator
Fixed& Fixed::operator=(const Fixed& a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&a == this)
		return (*this);
	fixedPoint = a.fixedPoint;
	return (*this);
}

int Fixed::power(void) const
{
	int num = 1;
	for (int i = 0; i < fractBites; ++i)
		num *= 2;
	return (num);
}

int Fixed::getFractBits(void) const { return (fractBites); }

int Fixed::getRawBits(void) const { return (fixedPoint); }

void Fixed::setRawBits(int const raw) { fixedPoint = raw; }

float Fixed::toFloat(void) const {
	return((static_cast<double>(fixedPoint)) / (1 << fractBites));
}

int Fixed::toInt(void) const {return (fixedPoint / (1 << fractBites));}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

