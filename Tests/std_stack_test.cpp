/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_stack_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 05:12:11 by yun               #+#    #+#             */
/*   Updated: 2021/10/25 05:51:12 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <list>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int	std_stack_test()
{
	std::cout<<"===== TEST std::"<<GRN"STACK "<<NC"====="<<std::endl<<std::endl;
	{
		std::stack<int>		std_stack_int;
		std::stack<std::string>	std_stack_str;
		std::cout<<"[TEST "<<RED"1"<<NC"]- Basic functions"<<std::endl<<std::endl;
		std::cout<<CYN"name_stack: size empty"NC<<std::endl<<std::endl;

		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Push()"NC<<std::endl<<std::endl;

		std_stack_int.push(42);
		std_stack_str.push("Hello World");
		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;
		std_stack_int.push(24);
		std_stack_str.push("Goodby");
		std_stack_int.push(5);
		std_stack_str.push("yeah");
		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Top()"NC<<std::endl<<std::endl;

		std::cout<<"std_stack_int: "<<std_stack_int.top()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.top()<<std::endl<<std::endl;

		std::cout<<CYN"Pop()"NC<<std::endl<<std::endl;

		std_stack_int.pop();
		std_stack_str.pop();
		std::cout<<CYN"stack_name: size top empty"NC<<std::endl<<std::endl;
		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.top()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.top()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;
		

	}
	{
		std::cout<<"-------------------------------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RED"2"<<NC"]- Test overload && cpy constructor"<<std::endl<<std::endl;
		std::stack<int>	std_stack_int;
		std::stack<int>	std_stack_operator;

		std_stack_int.push(42);
		std_stack_int.push(-55);
		std_stack_int.push(0);

		std_stack_operator = std_stack_int;
		std::stack<int>	std_stack_cpy(std_stack_int);

		int	res;

		res = 0;
		if (std_stack_operator == std_stack_int)
			res = 1;
		std::cout<<CYN"Test equality between cpy, operator and orignal stack"NC<<std::endl;
		std::cout<<"std_stack_operator "<<res<<std::endl;
		res = 0;
		if (std_stack_cpy == std_stack_int)
			res = 1;
		std::cout<<"std_stack_cpy "<<res<<std::endl;
		res = 0;
		if (std_stack_operator == std_stack_int)
			res = 1;
		std::cout<<"std_stack_operator "<<res<<std::endl<<std::endl;

			std::cout<<CYN"Test relational operator astder modif cpy "NC<<std::endl;

		std::cout<<CYN"Check != "NC<<std::endl<<std::endl;
		std_stack_cpy.push(48);
		res = 0;
		res = std_stack_operator != std_stack_int;
		std::cout<<"std_stack_operator != std_stack_int: "<<res<<std::endl;
		res = std_stack_cpy != std_stack_int;
		std::cout<<"std_stack_cpy != std_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check < "NC<<std::endl<<std::endl;

		res = std_stack_operator < std_stack_int;
		std::cout<<"std_stack_operator < std_stack_int: "<<res<<std::endl;
		res = std_stack_cpy < std_stack_int;
		std::cout<<"std_stack_cpy < std_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check <= "NC<<std::endl<<std::endl;

		res = std_stack_operator <= std_stack_int;
		std::cout<<"std_stack_operator <= std_stack_int: "<<res<<std::endl;
		res = std_stack_cpy <= std_stack_int;
		std::cout<<"std_stack_cpy <= std_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check > "NC<<std::endl<<std::endl;

		res = std_stack_operator > std_stack_int;
		std::cout<<"std_stack_operator > std_stack_int: "<<res<<std::endl;
		res = std_stack_cpy > std_stack_int;
		std::cout<<"std_stack_cpy > std_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check >= "NC<<std::endl<<std::endl;

		res = std_stack_operator >= std_stack_int;
		std::cout<<"std_stack_operator >= std_stack_int: "<<res<<std::endl;
		res = std_stack_cpy >= std_stack_int;
		std::cout<<"std_stack_cpy >= std_stack_int "<<res<<std::endl<<std::endl;
	}
	{
		std::cout<<"-----------------------------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RED"3"<<NC"]- Stack with STL List container"<<std::endl<<std::endl;
		std::stack<int, std::list<int> > std_stack_int;
		std::stack<std::string, std::list<std::string> > std_stack_str;
		std::cout<<CYN"name_stack: size empty"NC<<std::endl<<std::endl;

		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Push()"NC<<std::endl<<std::endl;

		std_stack_int.push(442);
		std_stack_str.push("Hello MyFriends");
		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;
		std_stack_int.push(22);
		std_stack_str.push("<3");
		std_stack_int.push(-5);
		std_stack_str.push("LIST OMG");
		std_stack_int.push(5);
		std_stack_str.push("Hihihi");
		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Top()"NC<<std::endl<<std::endl;

		std::cout<<"std_stack_int: "<<std_stack_int.top()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.top()<<std::endl<<std::endl;

		std::cout<<CYN"Pop()"NC<<std::endl<<std::endl;

		std_stack_int.pop();
		std_stack_str.pop();
		std::cout<<CYN"stack_name: size top empty"NC<<std::endl<<std::endl;
		std::cout<<"std_stack_int: "<<std_stack_int.size()<<" "<<std_stack_int.top()<<" "<<std_stack_int.empty()<<std::endl;
		std::cout<<"std_stack_str: "<<std_stack_str.size()<<" "<<std_stack_str.top()<<" "<<std_stack_str.empty()<<std::endl<<std::endl;
		
	}

	{
		std::stack<int>	std_stack_int;

		std::cout<<"--------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RED"4"<<NC"]- Time exec"<<std::endl<<std::endl;
		std::cout<<CYN"Push 1 000 0000"NC<<std::endl;

		for (int i = 0; i < 1000000; i++)
			std_stack_int.push(i);
		std::cout<<CYN"End push"NC<<std::endl;
	}

	return 0;
}
