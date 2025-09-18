/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:05:51 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/05/31 21:06:27 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// ----------------------- Class Point ----------------------- //

Point::Point(): x(0), y(0) {
	// std::cout << "\nDefault ctor called" << std::endl;
	// std::cout << "x = " << x.toFloat() << "\t\ty = " << y.toFloat() << std::endl;
};

Point::Point(const Fixed& x, const Fixed& y): x(x), y(y) {
	// std::cout << "\nParams ctor called" << std::endl;
	// std::cout << "x = " << x.toFloat() << "\t\ty = " << y.toFloat() << std::endl;
};

Fixed Point::getX(void) const {return x;}

Fixed Point::getY(void) const {return y;}

void Point::printPoint(void) const
{
	// std::cout << "printPoint" << std::endl;
	std::cout << "x = " << x.toFloat() << "\t\ty = " << y.toFloat() << "\n" << std::endl; 
}

Point::Point(const Point& a): x(a.x), y(a.y)
{
	// std::cout << "\nCopy ctor" << std::endl;
	// std::cout << "x = " << x.toFloat() << "\t\ty = " << y.toFloat() << std::endl;
}

Point& Point::operator=(const Point& a)
{
	(void)a;
	// std::cout << "\nCopy assign operator" << std::endl;
	std::cout << "x = " << x.toFloat() << "\t\ty = " << y.toFloat() << std::endl;
	return (*this);
}

Point::~Point() {}