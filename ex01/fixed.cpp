/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:47:32 by atabarea          #+#    #+#             */
/*   Updated: 2026/04/10 10:45:21 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int Fixed::_fractional_bits = 8;

//Constructor and destructor functions:

Fixed::Fixed(void)
{
	this->setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = val << _fractional_bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(val * (1 << _fractional_bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//Class member functions:

int Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point >> _fractional_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (1 << _fractional_bits));
}

//Operator overload:

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}
