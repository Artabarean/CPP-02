/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:21:53 by atabarea          #+#    #+#             */
/*   Updated: 2026/04/10 10:37:39 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed&);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed& operator=(const Fixed&);
	private:
		int _fixed_point;
		static const int _fractional_bits;
};

#endif