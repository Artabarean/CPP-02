/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabarea <atabarea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:48:44 by atabarea          #+#    #+#             */
/*   Updated: 2026/04/10 11:24:46 by atabarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "Subject Tests" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;

    std::cout << "Comparison Operators" << std::endl;
    Fixed const c( 10 );
    Fixed const d( 10.1f );

    std::cout << "c: " << c << " | d: " << d << std::endl;
    std::cout << "c < d  : " << (c < d) << " (expected 1)" << std::endl;
    std::cout << "c > d  : " << (c > d) << " (expected 0)" << std::endl;
    std::cout << "c <= d : " << (c <= d) << " (expected 1)" << std::endl;
    std::cout << "c >= d : " << (c >= d) << " (expected 0)" << std::endl;
    std::cout << "c == c : " << (c == c) << " (expected 1)" << std::endl;
    std::cout << "c != d : " << (c != d) << " (expected 1)" << std::endl;

    std::cout << "Arithmetic Operators" << std::endl;
    Fixed const e( 2 );
    Fixed const f( 4.2f );

    std::cout << "e: " << e << " | f: " << f << std::endl;
    std::cout << "e + f : " << (e + f) << std::endl;
    std::cout << "f - e : " << (f - e) << std::endl;
    std::cout << "e * f : " << (e * f) << std::endl;
    std::cout << "f / e : " << (f / e) << std::endl;

    std::cout << "Increment/Decrement Operators" << std::endl;
    Fixed g( 1 );
    std::cout << "g     : " << g << std::endl;
    std::cout << "++g   : " << ++g << std::endl;
    std::cout << "g++   : " << g++ << std::endl;
    std::cout << "g     : " << g << std::endl;
    std::cout << "--g   : " << --g << std::endl;
    std::cout << "g--   : " << g-- << std::endl;
    std::cout << "g     : " << g << std::endl;

    return (0);
}
