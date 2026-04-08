/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:47:32 by atabarea          #+#    #+#             */
/*   Updated: 2026/04/08 12:37:47 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int Fixed::_fractional_bits = 8;

//Constructor and destructor functions:

Fixed::Fixed(void)
{
	this->setRawBits(0);
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = val << _fractional_bits;
}

Fixed::Fixed(const float val)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(val * (1 << _fractional_bits));
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& ostream, const Fixed& fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

Fixed& Fixed::operator++(void)
{
	this->_fixed_point = this->_fixed_point + 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return (old);
}

Fixed& Fixed::operator--(void)
{
	this->_fixed_point = this->_fixed_point - 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return (old);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->_fixed_point + other._fixed_point);
	return (res);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;
	res.setRawBits(this->_fixed_point - other._fixed_point);
	return (res);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;
	long temp;
	temp  = (long)this->_fixed_point * (long)other._fixed_point;
	res.setRawBits((int)temp >> _fractional_bits);
	return (res);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;
	long temp;
	temp = (long)this->_fixed_point << _fractional_bits;
	res.setRawBits((int)temp / other._fixed_point);
	return (res);
}

bool operator>(const Fixed& that, const Fixed& other)
{
	if (that.getRawBits() > other.getRawBits())
		return (true);
	return (false);
}

bool operator<(const Fixed& that, const Fixed& other)
{
	if (that.getRawBits() < other.getRawBits())
		return (true);
	return (false);
}

bool operator<=(const Fixed& that, const Fixed& other)
{
	if (that.getRawBits() <= other.getRawBits())
		return (true);
	return (false);
}

bool operator>=(const Fixed& that, const Fixed& other)
{
	if (that.getRawBits() >= other.getRawBits())
		return (true);
	return (false);
}

bool operator==(const Fixed& that, const Fixed& other)
{
	if (that.getRawBits() == other.getRawBits())
		return (true);
	return (false);
}

bool operator!=(const Fixed& that, const Fixed& other)
{
	if (that.getRawBits() != other.getRawBits())
		return (true);
	return (false);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first < second)
		return (first);
	else
		return (second);
}
const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first < second)
		return (first);
	else
		return (second);
}
Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}
const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first > second)
		return (first);
	else
		return (second);
}
