/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_pair_test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:36:35 by yun               #+#    #+#             */
/*   Updated: 2021/11/04 08:19:04 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "tests.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int	std_pair_test()
{
	std::cout<<"===== TEST STD::"<<GRN"PAIR "NC<<"====="<<std::endl<<std::endl;
	{
		std::cout<<"[TEST "<<RED"1"<<NC"] - Pair constructor and std::make_pair"<<std::endl<<std::endl;
		std::pair<int, std::string> std_defaut_pair;
		std::pair<int, std::string> std_init_pair(42, "Hello");
		std::pair<int, std::string> std_cpy_pair(std_init_pair);

		std_defaut_pair = std::make_pair<int, std::string>(42, "Hello");
		std::cout<<"std_pair_name: first second"<<std::endl;
		std::cout<<"std_defaut_pair: "<<std_defaut_pair.first<<" "<<std_defaut_pair.second<<std::endl;
		std::cout<<"std_init_pair: "<<std_init_pair.first<<" "<<std_init_pair.second<<std::endl;
		std::cout<<"std_cpy_pair: "<<std_cpy_pair.first<<" "<<std_cpy_pair.second<<std::endl<<std::endl;
	}
	{
		std::cout<<"[TEST "<<RED"2"<<NC"] - Bool operator"<<std::endl<<std::endl;
		std::pair<int, int> std_pair(42, 42);
		std::pair<int, int> std_egal_pair(42, 42);
		std::pair<int, int> std_small_pair(42, 24);
		std::pair<int, int> std_tall_pair(24, 55);

		std::cout<<"std_pair: "<<std_pair.first<<" "<<std_pair.second<<std::endl;
		std::cout<<"std_small_pair: "<<std_small_pair.first<<" "<<std_small_pair.second<<std::endl;
		std::cout<<"std_tall_pair: "<<std_tall_pair.first<<" "<<std_tall_pair.second<<std::endl<<std::endl;

		std::cout<<CYN"Operator =="NC<<std::endl;
		if (std_pair == std_egal_pair)
			std::cout<<"std_egal_pair: True"<<std::endl;
		else
			std::cout<<"std_egal_pair: False"<<std::endl;
		if (std_pair == std_small_pair)
			std::cout<<"std_small_pair: True"<<std::endl;
		else
			std::cout<<"std_small_pair: False"<<std::endl;
		if (std_pair == std_tall_pair)
			std::cout<<"std_tall_pair: True"<<std::endl;
		else
			std::cout<<"std_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator !="NC<<std::endl;
		if (std_pair != std_egal_pair)
			std::cout<<"std_egal_pair: True"<<std::endl;
		else
			std::cout<<"std_egal_pair: False"<<std::endl;
		if (std_pair != std_small_pair)
			std::cout<<"std_small_pair: True"<<std::endl;
		else
			std::cout<<"std_small_pair: False"<<std::endl;
		if (std_pair != std_tall_pair)
			std::cout<<"std_tall_pair: True"<<std::endl;
		else
			std::cout<<"std_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator <="NC<<std::endl;
		if (std_pair <= std_egal_pair)
			std::cout<<"std_egal_pair: True"<<std::endl;
		else
			std::cout<<"std_egal_pair: False"<<std::endl;
		if (std_pair <= std_small_pair)
			std::cout<<"std_small_pair: True"<<std::endl;
		else
			std::cout<<"std_small_pair: False"<<std::endl;
		if (std_pair <= std_tall_pair)
			std::cout<<"std_tall_pair: True"<<std::endl;
		else
			std::cout<<"std_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator >="NC<<std::endl;
		if (std_pair >= std_egal_pair)
			std::cout<<"std_egal_pair: True"<<std::endl;
		else
			std::cout<<"std_egal_pair: False"<<std::endl;
		if (std_pair >= std_small_pair)
			std::cout<<"std_small_pair: True"<<std::endl;
		else
			std::cout<<"std_small_pair: False"<<std::endl;
		if (std_pair >= std_tall_pair)
			std::cout<<"std_tall_pair: True"<<std::endl;
		else
			std::cout<<"std_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator <"NC<<std::endl;
		if (std_pair < std_egal_pair)
			std::cout<<"std_egal_pair: True"<<std::endl;
		else
			std::cout<<"std_egal_pair: False"<<std::endl;
		if (std_pair < std_small_pair)
			std::cout<<"std_small_pair: True"<<std::endl;
		else
			std::cout<<"std_small_pair: False"<<std::endl;
		if (std_pair < std_tall_pair)
			std::cout<<"std_tall_pair: True"<<std::endl;
		else
			std::cout<<"std_tall_pair: False"<<std::endl;
		std::cout<<std::endl;
		std::cout<<CYN"Operator >"NC<<std::endl;
		if (std_pair > std_egal_pair)
			std::cout<<"std_egal_pair: True"<<std::endl;
		else
			std::cout<<"std_egal_pair: False"<<std::endl;
		if (std_pair > std_small_pair)
			std::cout<<"std_small_pair: True"<<std::endl;
		else
			std::cout<<"std_small_pair: False"<<std::endl;
		if (std_pair > std_tall_pair)
			std::cout<<"std_tall_pair: True"<<std::endl;
		else
			std::cout<<"std_tall_pair: False"<<std::endl;
		std::cout<<std::endl<<std::endl;
	}
	return 0;
}
