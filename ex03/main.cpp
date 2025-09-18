/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:49:32 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/02 20:17:16 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
 
std::ostream& operator<<(std::ostream& os, const Fixed& a);

std::ostream& operator<<(std::ostream& os, const Fixed& a)
{
	// The default precision for std::cout is usually 6.
	// return (os << std::setprecision(9) << a.toFloat());
	return (os << a.toFloat());
}

void recieveArgs(Fixed &x, Fixed& y, std::string point)
{
	double num1;
	double num2;
	
	while (1)
	{
		std::cout << "Point " << point << ". x = ";
		std::cin >> num1;
		if (std::cin.eof()) exit(EXIT_FAILURE);
		// If the user enters input that doesn't match the expected data type 
		// (e.g., a string when an integer is expected), the failbit will be set.
		if (std::cin.fail() || !std::cin.good() || std::cin.bad())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			// std::cout << "fail: " << std::cin.fail() << std::endl;
			// std::cout << "good: " << std::cin.good() << std::endl;
			// std::cout << "bad: " << std::cin.bad() << std::endl;
			std::cout << "Wrong type of argument. Try again" << std::endl;
			continue;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "There are extra signs: " << std::cin.gcount() << ". Try again" << std::endl;
				continue;
			}
		}
		std::cout << "Point " << point << ". y = ";
		std::cin >> num2;
		if (std::cin.eof()) exit(EXIT_FAILURE);
		if (std::cin.fail() || !std::cin.good() || std::cin.bad())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			// std::cout << "fail: " << std::cin.fail() << std::endl;
			// std::cout << "good: " << std::cin.good() << std::endl;
			// std::cout << "bad: " << std::cin.bad() << std::endl;
			std::cout << "Wrong type of argument. Try again" << std::endl;
			continue;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			if (std::cin.gcount() > 1)
			{
				std::cout << "There are extra signs: " << std::cin.gcount() << ". Try again" << std::endl;
				continue;
			}
		}
		x = num1;
		y = num2;
		break;
	}
}

int main(void) 
{
	// =============== MANUAL INPUT =============== //
	Fixed x1;
	Fixed y1;
	recieveArgs(x1, y1, "A");
	Fixed x2;
	Fixed y2;
	recieveArgs(x2, y2, "B");
	Fixed x3;
	Fixed y3;
	recieveArgs(x3, y3, "C");
	Fixed x4;
	Fixed y4;
	recieveArgs(x4, y4, "P");
	std::cout << "\n-----------------------------\n" << std::endl;
	const Point p(x4, y4); 
	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;
	std::cout << std::endl << "The triagle: " << std::endl;
	const Point a(x1, y1);
	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	const Point b(x2, y2); 
	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	const Point c(x3, y3); 
	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	if (bsp(a, b, c, p))
			std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
		else
			std::cout << RED << "FALSE" << DEF << std::endl;

	// =================== TESTS ================== //
	
	// std::cout << "\n-----------------------------\n" << std::endl;
	// // Var 0: 123456, 123456, -1, 1, 17.33, -19.004, 0, 9 (false)
	// {
	// 	const Point a(123456, 123456);
	// 	const Point b(-1, 1);
	// 	const Point c(17.33, -19.004);
	// 	const Point p(0, 9);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }

	// std::cout << "\n-----------------------------\n" << std::endl;
	
	// // Var 1: 0, 0, 5, 10, 10, 5, 5, 5 (true)
	// {
	// 	const Point a(0, 0);
	// 	const Point b(5, 10);
	// 	const Point c(10, 5);
	// 	const Point p(5, 5);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }
	// std::cout << "\n-----------------------------\n" << std::endl;

	// // Var 2: -3, 6, 5.5, -5.33, 8, 8, 1, -2.1 (false)
	// {
	// 	const Point a(-3, 6);
	// 	const Point b(5.5, -5.33);
	// 	const Point c(8, 8);
	// 	const Point p(1, -2.1);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }
	// std::cout << "\n-----------------------------\n" << std::endl;
	// // Var 3: 0, 0, 25, 10, 10, 0, 7, 0 (true)
	// {
	// 	const Point a(0, 0);
	// 	const Point b(25, 10);
	// 	const Point c(10, 0);
	// 	const Point p(7, 0);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }
	// std::cout << "\n-----------------------------\n" << std::endl;
	// // Var 4: 0, 0, 25, 10, 10, 0, 11, 0 (false)
	// {
	// 	const Point a(0, 0);
	// 	const Point b(25, 10);
	// 	const Point c(10, 0);
	// 	const Point p(11, 0);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }
	// std::cout << "\n-----------------------------\n" << std::endl;
	// // Var 5: 0, 0, 0, 5, 0, 10, 0, 6 (false)
	// {
	// 	const Point a(0, 0);
	// 	const Point b(0, 5);
	// 	const Point c(0, 10);
	// 	const Point p(0, 6);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }
	
	// std::cout << "\n-----------------------------\n" << std::endl;
	// // Var 6: -3, 6, 5.5, -5.33, -28.5, 18, -15, 3 (false)
	// {
	// 	const Point a(-3, 6);
	// 	const Point b(5.5, -5.33);
	// 	const Point c(-28.5, 18);
	// 	const Point p(-15, 3);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }

	// std::cout << "\n-----------------------------\n" << std::endl;
	// // Var 7: 0, 0, 0, 5, 5, 10, 0, 3 (false)
	// {
	// 	const Point a(0, 0);
	// 	const Point b(0, 5);
	// 	const Point c(5, 10);
	// 	const Point p(0, 3);
		
	// 	std::cout << "Point P (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	// 	std::cout << std::endl << "The triagle: " << std::endl;
	// 	std::cout << "\tPoint A (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint B (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	// 	std::cout << "\tPoint C (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	// 	if (bsp(a, b, c, p))
	// 		std::cout << GRE << "\n\tTRUE" << DEF << std::endl;
	// 	else
	// 		std::cout << RED << "\n\tFALSE" << DEF << std::endl;
	// }
	
	return 0;
}




// {
	// 	std::cout << 256 * 256 * 128 - 1 << std::endl;
	// 	std::cout << 256L * 256L * 256L * 128L - 1L << std::endl << __INT_MAX__ << std::endl;
	// 	Fixed a(8388607);
	// 	std::cout << a << std::endl;
	// 	Fixed b(8388608);
	// 	std::cout << b << std::endl;
	// 	// Fixed c(16581376);
	// 	// std::cout << c << std::endl;
	// }
