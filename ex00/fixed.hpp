/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:21:53 by atabarea          #+#    #+#             */
/*   Updated: 2026/03/31 11:55:58 by atabarea         ###   ########.fr       */
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
		Fixed(Fixed());
		~Fixed(void);
	private:
		int fixed_point;
		static const int fractional_bits;
};

#endif