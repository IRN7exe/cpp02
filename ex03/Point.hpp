/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:06:03 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/05/31 17:27:41 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp" 
#include <iostream>

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const Point& a);

		Fixed getX(void) const;
		Fixed getY(void) const;
		void printPoint(void) const;
		~Point();
	private:
		Point& operator=(const Point& a);		
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
int findSide(const Point& a, const Point& b, const Point& c);
void recieveArgs(Fixed &x, Fixed& y, std::string point);

#endif