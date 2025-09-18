/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhanenk <ikhanenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:49:32 by ikhanenk          #+#    #+#             */
/*   Updated: 2025/06/02 17:17:47 by ikhanenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& a);

std::ostream& operator<<(std::ostream& os, const Fixed& a)
{
	// return (os << a.getRawBits() << "\t" << a.toInt() << "\t" << a.toFloat());
	return (os << a.toFloat());
}

int main( void ) 
{
	// =========   school's test   =======//
	std::cout << CYA << "==================================================" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "|                   School's tests                |" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "==================================================" << DEF << std::endl;
	Fixed			a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;	
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b) << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << CYA << "==================================================" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "|           Operators ++int, ++, --int, --        |" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "==================================================" << DEF << std::endl;

	Fixed	c(-2.4f);
	Fixed   z(0);
	std::cout << CYA << "Testing of float constructor..." << std::endl;
	std::cout << "Fixed	z(0.0);" << DEF << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "z++ = " << z++ << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "++z = " << ++z << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "z-- = " << z-- << std::endl;
	std::cout << "z = " << z << std::endl;
	std::cout << "--z = " << --z << std::endl;
	std::cout << "z = " << z << std::endl;

	Fixed	p(__INT_MAX__);
	std::cout << "\n" << std::endl;
	std::cout << CYA << "Testing of int constructor..." << std::endl;
	std::cout << "Fixed	p(__INT_MAX__);" << DEF << std::endl;
	std::cout << "p++ = " << p++ << std::endl;
	std::cout << "++p = " << ++p << std::endl;
	std::cout << "p-- = " << p-- << std::endl;
	std::cout << "--p = " << --p << std::endl;
	std::cout << std::endl;

	std::cout << YEL << "OPTIONAL\n" << DEF << std::endl;

	Fixed	e(-2.4f);
	Fixed	d(-2.75f);
	Fixed	g(-2.4f);
	Fixed	j(-2.75f);

	std::cout << "Fixed e = " << e << std::endl;
	std::cout << "Fixed d = " << d << std::endl;
	std::cout << "Fixed g (f) = " << g << "\t\t" << "g = e: " << g << "\t\t" << e << std::endl;
	std::cout << "Fixed j (f) = " << d << "\t\t" << "j = d: " << j << "\t\t" << d << std::endl;
	std::cout << std::endl;

	std::cout << CYA << "==================================================" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "|           Operators *, *=, /, /=                |" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "==================================================" << DEF << std::endl;

	std::cout << CYA << "c = -2.4 \t d = -2.75\n" << DEF << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "c *= d = " << (c*=d) << std::endl;
	std::cout << std::endl;
	std::cout << CYA << "e = " << e << "\t g = " << g << DEF << std::endl;
	std::cout << "e * g = " << (e * g) << std::endl;
	std::cout << "e *= g = " << (e*=g) << std::endl;
	std::cout << std::endl;
	std::cout << CYA << "c = " << c << "\t a = " << a << DEF << std::endl;
	std::cout << "c / a = " << (c / a) << std::endl;
	std::cout << "c /= a = " << (c/=a) << std::endl;

	std::cout << std::endl;
	std::cout << CYA << "c = " << c << "\t\t d = " << d << DEF << std::endl;
	std::cout << "c / d = " << (c / d) << std::endl;
	std::cout << "c /= d = " << (c/=d) << std::endl;
	std::cout << std::endl;

	// ------------------------------------------------------------------------------------------------------------ //
	Fixed v(8388606);
	Fixed s(256);
	Fixed t(__INT_MAX__ / 8388606);
	Fixed u(2147483646);
	Fixed w(2147483647);
	std::cout << CYA << "v = " << static_cast<long long>(v.getRawBits()) << "\t" << v << "\t\t s = " << s << DEF << std::endl;
	std::cout << "v / s = " << (v / s) << std::endl;
	std::cout << "v /= s = " << (v/=s) << std::endl;
	std::cout << static_cast<long long>(t.getRawBits()) << "\t" << t << std::endl; 
	std::cout << static_cast<long long>(u.getRawBits()) << "\t" << u << std::endl; 
	std::cout << static_cast<long long>(w.getRawBits()) << "\t" << w << std::endl; 
	// ------------------------------------------------------------------------------------------------------------ //

	std::cout << CYA << "==================================================" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "|               Functions min, max                |" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "==================================================" << DEF << std::endl;
	std::cout << CYA << "c = " << c << "\t d = " << d << DEF << std::endl;
	std::cout << "Max c : d = " << Fixed::max( c, d) << std::endl;
	std::cout << "Min c : d = " << Fixed::min( c, d) << std::endl;
	std::cout << std::endl;
	std::cout << CYA << "a = " << a << "\t b = " << b << DEF << std::endl;
	std::cout << "Max a : b = " << Fixed::max( a, b) << std::endl;
	std::cout << "Min a : b = " << Fixed::min( a, b) << std::endl;
	std::cout << std::endl;

	std::cout << CYA << "==================================================" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "|        Operators <, <=, >, >=, ==, !=           |" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "==================================================" << DEF << std::endl;
	std::cout << CYA << "c = " << c << "\t d = " << d << DEF << std::endl;
	std::cout << "c > d = " << (c > d) << std::endl;
	std::cout << "c >= c = " << (c >= c) << std::endl;
	std::cout << "c < d = " << (c < d) << std::endl;
	std::cout << "c <= d = " << (c <= d) << std::endl;
	std::cout << "c == d = " << (c == d) << std::endl;
	std::cout << "c != d = " << (c != d) << std::endl;
	std::cout << std::endl;

	std::cout << CYA << "==================================================" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "|                Operators +, -                   |" << std::endl;
	std::cout << "|                                                 |"<< std::endl;
	std::cout << "==================================================" << DEF << std::endl;
	std::cout << CYA << "c = " << c << "\t d = " << d << DEF << std::endl;
	std::cout << "d + d = " << (d + d) << std::endl;
	std::cout << "d += c =  " << (d += c) << std::endl;
	std::cout << std::endl;
	std::cout << CYA << "c = " << c << "\t d = " << d << DEF << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "d -= c =  " << (d -= c) << std::endl;
	std::cout << std::endl;

	return 0;
}