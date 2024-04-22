/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgellon <tgellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:26:58 by tgellon           #+#    #+#             */
/*   Updated: 2024/02/16 11:03:58 by tgellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Base.hpp"
#include "../incs/A.hpp"
#include "../incs/B.hpp"
#include "../incs/C.hpp"
#include <ctime>
#include <cstdlib>

Base	*generate(){
	srand(std::time(NULL));
	int random = rand() % 3;

	switch(random){
		case (0):{
			Base* base = new A();
			return (base);
		}
		case (1):{
			Base* base = new B();
			return (base);
		}
		case (2):{
			Base* base = new C();
			return (base);
		}
	}
	return (NULL);
}

void	identify(Base *p){
	if (p == NULL)
		std::cout << "NULL pointer" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Object A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object C" << std::endl;
	else
		std::cout << "Bad pointer" << std::endl;
}

void	identify(Base &p){
	try{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Object A" << std::endl;
		return ;
	}
	catch(std::exception &e){
		std::cout << YELLOW << "Bad conversion to A" << WHITE << std::endl;
	}
	try{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Object B" << std::endl;
		return ;
	}
	catch(std::exception &e){
		std::cout << YELLOW << "Bad conversion to B" << WHITE << std::endl;
	}
	try{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Object C" << std::endl;
		return ;
	}
	catch(std::exception &e){
		std::cout << YELLOW << "Bad conversion to C" << WHITE << std::endl;
	}
}

int	main(){
	Base *obj = generate();

	identify(obj);
	identify(*obj);
	delete (obj);
}