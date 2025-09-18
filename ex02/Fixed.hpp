/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:11:16 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/05/30 16:59:32 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

#define DEF "\33[0m"
#define RED "\33[31m"
#define GRE "\33[32m"
#define YEL "\33[33m"
#define BLU "\33[34m"
#define MAG "\33[35m"
#define CYA "\33[36m"
#define WHI "\33[37m"

class Fixed 
{
	private:
		int fixedPoint;
		static const int fractBites = 8;
	public:
		Fixed();
		Fixed(const Fixed& a);
		Fixed(const int a);
		Fixed(const double a);
	public:
		int 					getRawBits(void) const;	
		void 					setRawBits(int const raw);
		int 					getFractBits(void) const;
	public:
		float 					toFloat(void) const;
		int 					toInt(void) const;
		int 					power(void) const;
	public:
		static Fixed& 			min(Fixed& a, Fixed& b);
		static Fixed& 			max(Fixed& a, Fixed& b);
		static const Fixed& 	min(const Fixed& a, const Fixed& b);
		static const Fixed& 	max(const Fixed& a, const Fixed& b);
	public:
		Fixed& 					operator=(const Fixed& a);
		Fixed& 					operator+=(const Fixed& a);
		Fixed 					operator+(const Fixed& a) const;
		Fixed& 					operator-=(const Fixed& a);
		Fixed 					operator-(const Fixed& a) const;
	public:
		Fixed& 					operator*=(const Fixed& a);
		Fixed 					operator*(const Fixed& a) const;
		Fixed& 					operator/=(const Fixed& a);
		Fixed 					operator/(const Fixed& a) const;
	public:
		Fixed& 					operator++();
		const Fixed 			operator++(int);
		Fixed& 					operator--();
		const Fixed 			operator--(int);
	public:
		bool 					operator<(const Fixed& a) const;
		bool 					operator>(const Fixed& a) const;
		bool 					operator==(const Fixed& a) const;	
		bool 					operator!=(const Fixed& a) const;
		bool 					operator<=(const Fixed& a) const;
		bool 					operator>=(const Fixed& a) const;
	public:
		~Fixed();
};

#endif
