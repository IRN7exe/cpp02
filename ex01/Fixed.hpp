/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:11:16 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/05/30 16:57:08 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{ 
	private:
		int fixedPoint;
		static const int fractBites = 8;
	public:
		Fixed();
		Fixed(const Fixed& a);
		Fixed(const int a);
		Fixed(const float a);
		Fixed& operator=(const Fixed& a);
		int getRawBits(void) const;	
		int getFractBits(void) const;	
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		int power(void) const;
		~Fixed();
};

#endif
