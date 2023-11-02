/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:28:09 by tgellon           #+#    #+#             */
/*   Updated: 2023/11/02 12:44:55 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv){
	std::string	infile;
	std::string	outfilePath;
	std::string	content;
	std::string	s1;
	std::string	s2;

	if (argc != 4){
		std::cerr << "Error, the program must take 3 arguments, a filename and 2 strings" << std::endl;
		return (0);
	}
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open()){
		std::cerr << "Error while trying to open " << argv[1] << std::endl;
		return (1);
	}
	infile = std::string(argv[1]);
	outfilePath = infile + ".replace";
	std::ofstream outfile(outfilePath.c_str());
	if (!outfile.is_open()){
		std::cerr << "Error while trying to open " << outfilePath << std::endl;
		inputFile.close();
		return (1);
	}
	s1 = std::string(argv[2]);
	s2 = std::string(argv[3]);
	while (1){
		if (inputFile.eof())
			break ;
		std::getline(inputFile, content);
		while (1){
			size_t	found;
			found = content.find(s1);
			if (found != std::string::npos){
				outfile << content.substr(0, found) << s2;
				content = content.substr(found + s1.size());
			}
			else{
				outfile << content;
				break ;
			}
		}
	}
	inputFile.close();
	outfile.close();
	return (0);
}
