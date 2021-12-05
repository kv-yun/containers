/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair_test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 07:42:55 by yun               #+#    #+#             */
/*   Updated: 2021/11/04 08:19:40 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tools/pair.hpp"
#include "../Iterators/reverse_iterator.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "tests.hpp"

#define NC "\e[0m"
#define RD "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RDB "\e[41m"

int ft_pair_test()
{
	std::cout<<"===== TEST FT::"<<GRN"PAIR "NC<<"====="<<std::endl<<std::endl;
	{
		std::cout<<"[TEST "<<RD"1"<<NC"] - Pair constructor and ft::make_pair"<<std::endl<<std::endl;
		ft::pair<int, std::string> ft_defaut_pair;
		ft::pair<int, std::string> ft_init_pair(42, "Hello");
		ft::pair<int, std::string> ft_cpy_pair(ft_init_pair);

		ft_defaut_pair = ft::make_pair<int, std::string>(42, "Hello");
		std::cout<<"ft_pair_name: first second"<<std::endl;
		std::cout<<"ft_defaut_pair: "<<ft_defaut_pair.first<<" "<<ft_defaut_pair.second<<std::endl;
		std::cout<<"ft_init_pair: "<<ft_init_pair.first<<" "<<ft_init_pair.second<<std::endl;
		std::cout<<"ft_cpy_pair: "<<ft_cpy_pair.first<<" "<<ft_cpy_pair.second<<std::endl<<std::endl;
	}
	{
		std::cout<<"[TEST "<<RD"2"<<NC"] - Bool operator"<<std::endl<<std::endl;
		ft::pair<int, int> ft_pair(42, 42);
		ft::pair<int, int> ft_egal_pair(42, 42);
		ft::pair<int, int> ft_small_pair(42, 24);
		ft::pair<int, int> ft_tall_pair(24, 55);

		std::cout<<"ft_pair: "<<ft_pair.first<<" "<<ft_pair.second<<std::endl;
		std::cout<<"ft_small_pair: "<<ft_small_pair.first<<" "<<ft_small_pair.second<<std::endl;
		std::cout<<"ft_tall_pair: "<<ft_tall_pair.first<<" "<<ft_tall_pair.second<<std::endl<<std::endl;

		std::cout<<CYN"Operator =="NC<<std::endl;
		if (ft_pair == ft_egal_pair)
			std::cout<<"ft_egal_pair: True"<<std::endl;
		else
			std::cout<<"ft_egal_pair: False"<<std::endl;
		if (ft_pair == ft_small_pair)
			std::cout<<"ft_small_pair: True"<<std::endl;
		else
			std::cout<<"ft_small_pair: False"<<std::endl;
		if (ft_pair == ft_tall_pair)
			std::cout<<"ft_tall_pair: True"<<std::endl;
		else
			std::cout<<"ft_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator !="NC<<std::endl;
		if (ft_pair != ft_egal_pair)
			std::cout<<"ft_egal_pair: True"<<std::endl;
		else
			std::cout<<"ft_egal_pair: False"<<std::endl;
		if (ft_pair != ft_small_pair)
			std::cout<<"ft_small_pair: True"<<std::endl;
		else
			std::cout<<"ft_small_pair: False"<<std::endl;
		if (ft_pair != ft_tall_pair)
			std::cout<<"ft_tall_pair: True"<<std::endl;
		else
			std::cout<<"ft_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator <="NC<<std::endl;
		if (ft_pair <= ft_egal_pair)
			std::cout<<"ft_egal_pair: True"<<std::endl;
		else
			std::cout<<"ft_egal_pair: False"<<std::endl;
		if (ft_pair <= ft_small_pair)
			std::cout<<"ft_small_pair: True"<<std::endl;
		else
			std::cout<<"ft_small_pair: False"<<std::endl;
		if (ft_pair <= ft_tall_pair)
			std::cout<<"ft_tall_pair: True"<<std::endl;
		else
			std::cout<<"ft_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator >="NC<<std::endl;
		if (ft_pair >= ft_egal_pair)
			std::cout<<"ft_egal_pair: True"<<std::endl;
		else
			std::cout<<"ft_egal_pair: False"<<std::endl;
		if (ft_pair >= ft_small_pair)
			std::cout<<"ft_small_pair: True"<<std::endl;
		else
			std::cout<<"ft_small_pair: False"<<std::endl;
		if (ft_pair >= ft_tall_pair)
			std::cout<<"ft_tall_pair: True"<<std::endl;
		else
			std::cout<<"ft_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator <"NC<<std::endl;
		if (ft_pair < ft_egal_pair)
			std::cout<<"ft_egal_pair: True"<<std::endl;
		else
			std::cout<<"ft_egal_pair: False"<<std::endl;
		if (ft_pair < ft_small_pair)
			std::cout<<"ft_small_pair: True"<<std::endl;
		else
			std::cout<<"ft_small_pair: False"<<std::endl;
		if (ft_pair < ft_tall_pair)
			std::cout<<"ft_tall_pair: True"<<std::endl;
		else
			std::cout<<"ft_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator >"NC<<std::endl;
		if (ft_pair > ft_egal_pair)
			std::cout<<"ft_egal_pair: True"<<std::endl;
		else
			std::cout<<"ft_egal_pair: False"<<std::endl;
		if (ft_pair > ft_small_pair)
			std::cout<<"ft_small_pair: True"<<std::endl;
		else
			std::cout<<"ft_small_pair: False"<<std::endl;
		if (ft_pair > ft_tall_pair)
			std::cout<<"ft_tall_pair: True"<<std::endl;
		else
			std::cout<<"ft_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
	}
	return 0;
}

