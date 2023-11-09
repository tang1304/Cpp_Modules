/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:44:45 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/09 15:02:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define DEFAULT_COLOR "\033[0m"

# define BITS 8

# include <iostream>
# include <cmath>

class	Fixed{
private:

	int					_whole;
	static const int	_bits = BITS;

public:

	Fixed();
	Fixed(const int wholeNbr);
	Fixed(const float floatNbr);
	Fixed(const Fixed &oldNbr);
	~Fixed();

	void			setRawBits(int const raw);
	int				getRawBits() const;
	float			toFloat() const;
	int				toInt() const;

	Fixed &operator=(const Fixed &nbr);

};

std::ostream &operator<<(std::ostream &out, Fixed const &nbr);

#endif