/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:47:32 by atabarea          #+#    #+#             */
/*   Updated: 2026/03/31 11:57:38 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(void)
	: fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed())
{
	
	std::cout << "Copy constructor called" << std::endl;
}