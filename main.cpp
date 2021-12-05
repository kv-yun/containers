/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 04:42:57 by yun               #+#    #+#             */
/*   Updated: 2021/12/05 12:27:41 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "Tests/tests.hpp"

int main(int ac, char **av)
{
	if (ac < 3)
	{
		std::cout<<"Use ./ft_containers ft/std container/functions"<<std::endl;
		return 1;
	}
	if (av[1][0] == 's')
	{
		if (av[2][0] == 'v')
			return std_vector_test();
		else if (av[2][0] == 's')
			return std_stack_test();
		else if (av[2][0] == 'm')
			return std_map_test();
		else if (av[2][0] == 'p')
			return std_pair_test();
	}
	else if (av[1][0] == 'f')
	{
		if (av[2][0] == 'v')
			return ft_vector_test();
		else if (av[2][0] == 's')
			return ft_stack_test();
		else if (av[2][0] == 'm')
			return ft_map_test();
		else if (av[2][0] == 'p')
			return ft_pair_test();
	}
	std::cout<<"Use ./ft_containers ft/std container"<<std::endl;
	return 1;
}
