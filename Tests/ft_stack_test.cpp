/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:12:29 by yun               #+#    #+#             */
/*   Updated: 2021/10/25 05:51:00 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Stack/stack.hpp"
#include "tests.hpp"
#include <iostream>
#include <string>
#include <list>

#define NC "\e[0m"
#define RD "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RDB "\e[41m"

int	ft_stack_test()
{
	std::cout<<"===== TEST FT::"<<GRN"STACK "<<NC"====="<<std::endl<<std::endl;
	{
		ft::stack<int>		ft_stack_int;
		ft::stack<std::string>	ft_stack_str;
		std::cout<<"[TEST "<<RD"1"<<NC"]- Basic functions"<<std::endl<<std::endl;
		std::cout<<CYN"name_stack: size empty"NC<<std::endl<<std::endl;

		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Push()"NC<<std::endl<<std::endl;

		ft_stack_int.push(42);
		ft_stack_str.push("Hello World");
		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;
		ft_stack_int.push(24);
		ft_stack_str.push("Goodby");
		ft_stack_int.push(5);
		ft_stack_str.push("yeah");
		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Top()"NC<<std::endl<<std::endl;

		std::cout<<"ft_stack_int: "<<ft_stack_int.top()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.top()<<std::endl<<std::endl;

		std::cout<<CYN"Pop()"NC<<std::endl<<std::endl;

		ft_stack_int.pop();
		ft_stack_str.pop();
		std::cout<<CYN"stack_name: size top empty"NC<<std::endl<<std::endl;
		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.top()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.top()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;
		

	}
	{
		std::cout<<"-------------------------------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"2"<<NC"]- Test overload && cpy constructor"<<std::endl<<std::endl;
		ft::stack<int>	ft_stack_int;
		ft::stack<int>	ft_stack_operator;

		ft_stack_int.push(42);
		ft_stack_int.push(-55);
		ft_stack_int.push(0);

		ft_stack_operator = ft_stack_int;
		ft::stack<int>	ft_stack_cpy(ft_stack_int);

		int	res;

		res = 0;
		if (ft_stack_operator == ft_stack_int)
			res = 1;
		std::cout<<CYN"Test equality between cpy, operator and orignal stack"NC<<std::endl;
		std::cout<<"ft_stack_operator "<<res<<std::endl;
		res = 0;
		if (ft_stack_cpy == ft_stack_int)
			res = 1;
		std::cout<<"ft_stack_cpy "<<res<<std::endl;
		res = 0;
		if (ft_stack_operator == ft_stack_int)
			res = 1;
		std::cout<<"ft_stack_operator "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Test relational operator after modif cpy "NC<<std::endl;

		std::cout<<CYN"Check != "NC<<std::endl<<std::endl;
		ft_stack_cpy.push(48);
		res = 0;
		res = ft_stack_operator != ft_stack_int;
		std::cout<<"ft_stack_operator != ft_stack_int: "<<res<<std::endl;
		res = ft_stack_cpy != ft_stack_int;
		std::cout<<"ft_stack_cpy != ft_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check < "NC<<std::endl<<std::endl;

		res = ft_stack_operator < ft_stack_int;
		std::cout<<"ft_stack_operator < ft_stack_int: "<<res<<std::endl;
		res = ft_stack_cpy < ft_stack_int;
		std::cout<<"ft_stack_cpy < ft_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check <= "NC<<std::endl<<std::endl;

		res = ft_stack_operator <= ft_stack_int;
		std::cout<<"ft_stack_operator <= ft_stack_int: "<<res<<std::endl;
		res = ft_stack_cpy <= ft_stack_int;
		std::cout<<"ft_stack_cpy <= ft_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check > "NC<<std::endl<<std::endl;

		res = ft_stack_operator > ft_stack_int;
		std::cout<<"ft_stack_operator > ft_stack_int: "<<res<<std::endl;
		res = ft_stack_cpy > ft_stack_int;
		std::cout<<"ft_stack_cpy > ft_stack_int "<<res<<std::endl<<std::endl;

		std::cout<<CYN"Check >= "NC<<std::endl<<std::endl;

		res = ft_stack_operator >= ft_stack_int;
		std::cout<<"ft_stack_operator >= ft_stack_int: "<<res<<std::endl;
		res = ft_stack_cpy >= ft_stack_int;
		std::cout<<"ft_stack_cpy >= ft_stack_int "<<res<<std::endl<<std::endl;

	}
	{
		std::cout<<"-----------------------------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"3"<<NC"]- Stack with STL List container"<<std::endl<<std::endl;
		ft::stack<int, std::list<int> > ft_stack_int;
		ft::stack<std::string, std::list<std::string> > ft_stack_str;
		std::cout<<CYN"name_stack: size empty"NC<<std::endl<<std::endl;

		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Push()"NC<<std::endl<<std::endl;

		ft_stack_int.push(442);
		ft_stack_str.push("Hello MyFriends");
		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;
		ft_stack_int.push(22);
		ft_stack_str.push("<3");
		ft_stack_int.push(-5);
		ft_stack_str.push("LIST OMG");
		ft_stack_int.push(5);
		ft_stack_str.push("Hihihi");
		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Top()"NC<<std::endl<<std::endl;

		std::cout<<"ft_stack_int: "<<ft_stack_int.top()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.top()<<std::endl<<std::endl;

		std::cout<<CYN"Pop()"NC<<std::endl<<std::endl;

		ft_stack_int.pop();
		ft_stack_str.pop();
		std::cout<<CYN"stack_name: size top empty"NC<<std::endl<<std::endl;
		std::cout<<"ft_stack_int: "<<ft_stack_int.size()<<" "<<ft_stack_int.top()<<" "<<ft_stack_int.empty()<<std::endl;
		std::cout<<"ft_stack_str: "<<ft_stack_str.size()<<" "<<ft_stack_str.top()<<" "<<ft_stack_str.empty()<<std::endl<<std::endl;
		
	}

	{
		ft::stack<int>	ft_stack_int;

		std::cout<<"--------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"4"<<NC"]- Time exec"<<std::endl<<std::endl;
		std::cout<<CYN"Push 1 000 0000"NC<<std::endl;

		for (int i = 0; i < 1000000; i++)
			ft_stack_int.push(i);
		std::cout<<CYN"End push"NC<<std::endl;
	}

	return 0;
}
