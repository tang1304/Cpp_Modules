/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:08:48 by tgellon           #+#    #+#             */
/*   Updated: 2023/12/22 10:40:43 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <iostream>
# include <sstream>
# include <stack>
# include <limits>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define CLEAR "\033[0m"

# define TOKEN "Error, you must have at least two numbers before having this operation token"
# define OVERFLOW "Error, would be using values superior to integer max/min. Overflow risk"

#endif