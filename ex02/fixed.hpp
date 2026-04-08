/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:21:53 by atabarea          #+#    #+#             */
/*   Updated: 2026/04/08 12:37:17 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	public:
	//Member functions
		Fixed(void);
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed&);
		~Fixed(void);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const);
	//Operator overload functions:
		Fixed& operator=(const Fixed&);
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		Fixed operator+(const Fixed&) const;
		Fixed operator-(const Fixed&) const;
		Fixed operator*(const Fixed&) const;
		Fixed operator/(const Fixed&) const;
		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);

	private:
		int _fixed_point;
		static const int _fractional_bits;
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed);
bool operator>(const Fixed&, const Fixed&);
bool operator<(const Fixed&, const Fixed&);
bool operator<=(const Fixed&, const Fixed&);
bool operator>=(const Fixed&, const Fixed&);
bool operator==(const Fixed&, const Fixed&);
bool operator!=(const Fixed&, const Fixed&);

#endif