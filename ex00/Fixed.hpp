/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:11:16 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/02 19:53:04 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed 
{
	private:
		int fixedPoint;
		static const int fractBites = 8;
	public:
		Fixed();
		Fixed(const Fixed& a);
		Fixed& operator=(const Fixed& a);
		~Fixed();
	public:
		int getRawBits(void) const;	
		void setRawBits(int const raw);
};

#endif
