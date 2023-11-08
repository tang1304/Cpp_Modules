/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:28:09 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/08 11:46:28 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	std::string	fileName;
	std::string	outfilePath;
	std::string	content;
	std::string	s1;
	std::string	s2;

	if (argc != 4){
		std::cout << "Error, the program must take 3 arguments : a filename and 2 strings" << std::endl;
		return (0);
	}
	std::ifstream infile(argv[1]);
	if (!infile.is_open()){
		std::cout << "Error while trying to open " << argv[1] << std::endl;
		return (1);
	}
	fileName = std::string(argv[1]);
	outfilePath = fileName + ".replace";
	std::ofstream outfile(outfilePath.c_str());
	if (!outfile.is_open()){
		std::cout << "Error while trying to open " << outfilePath << std::endl;
		infile.close();
		return (1);
	}
	s1 = std::string(argv[2]);
	s2 = std::string(argv[3]);
	while (1){
		if (infile.eof())
			break ;
		std::getline(infile, content);
		while (1){
			size_t	found;
			found = content.find(s1);
			if (found != std::string::npos && s1.size() > 0){
				outfile << content.substr(0, found) << s2;
				content = content.substr(found + s1.size());
			}
			else{
				outfile << content;
				break ;
			}
		}
	}
	infile.close();
	outfile.close();
	return (0);
}
