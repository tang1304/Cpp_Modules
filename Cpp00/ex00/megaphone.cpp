/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:53:47 by tgellon           #+#    #+#             */
/*   Updated: 2023/09/29 14:19:16 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string str;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else{
		for (int i = 1; i < argc; i++){
			str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			std::cout << static_cast<char>(toupper(str[j]));
		}
		std::cout << std::endl;
	}
	return (0);
}