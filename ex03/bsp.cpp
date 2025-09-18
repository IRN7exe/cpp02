/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:13:49 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/01 23:26:38 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int findSide(const Point& a, const Point& b, const Point& c)
{
	Fixed A = b.getY() - a.getY();  // y_2 - y_1
	Fixed B = a.getX() - b.getX();  // x_1 - x_2;
	Fixed C = b.getX() * a.getY() - a.getX() * b.getY();  // x_2 * y_1 - x_1 * y_2;
	Fixed checkThirdPoint = A * c.getX() + B * c.getY() + C;   // Ax + By + C = 0;
	if (checkThirdPoint == 0)
		return (1);
	else if (checkThirdPoint < 0)
		return (2);
	else if (checkThirdPoint > 0)
		return (3);
	return (0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool res = false;

	if ((findSide(a, b, c) == findSide(a, b, point) || findSide(a, b, point) == 1) && \
		(findSide(b, c, a) == findSide(b, c, point) || findSide(b, c, point) == 1) && \
		(findSide(a, c, b) == findSide(a, c, point) || findSide(a, c, point) == 1))
	{
		res = true;
		if ((findSide(a, b, point) == 1) || (findSide(b, c, point) == 1) || (findSide(a, c, point) == 1))
			std::cout << CYA << "\n\tPoint on the one edge of the triangle" << DEF << std::endl;	
	}
	if ((findSide(a, b, point) == 1) && (findSide(b, c, point) == 1) && (findSide(a, c, point) == 1))
	{
		std::cout << CYA << "\n\tAll points on one line" << DEF << std::endl;
		res = false;
	}
	return res;
}