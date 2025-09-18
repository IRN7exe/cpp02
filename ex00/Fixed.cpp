/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:11:08 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/02 19:53:21 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():fixedPoint(0) {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed& a)
{
	std::cout << "Copy constructor called" << std::endl;
	// fixedPoint = a.getRawBits();
	operator=(a);
	// fixedPoint = a.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& a)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &a)
	    return (*this);
	fixedPoint = a.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint);
}

void Fixed::setRawBits(int const raw) {fixedPoint = raw;}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}