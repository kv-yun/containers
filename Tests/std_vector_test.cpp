/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_vector_test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:56:16 by yun               #+#    #+#             */
/*   Updated: 2021/10/26 07:11:01 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <string>

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int	std_vector_test()
{
	std::cout<<"===== TEST " <<"STD::"<<GRN"VECTOR "<<NC"====="<<std::endl<<std::endl;
	{
		std::cout<<"[TEST "<<RED"1"<<NC"]- Vector basic functions"<<std::endl<<std::endl;
		std::vector<int>		std_vector_int;
		std::vector<std::string>	std_vector_str;

		std::cout <<"name_vector_type: size capacity max_size bool_empty"<<std::endl<<std::endl;
		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<" "<<std_vector_int.empty()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<" "<<std_vector_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Push_back()"NC<<std::endl<<std::endl;

		std_vector_int.push_back(42);
		std_vector_str.push_back("Hello World");

		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl<<std::endl;

		std_vector_int.push_back(5);
		std_vector_str.push_back("Goodbye Space");

		std_vector_int.push_back(24);
		std_vector_str.push_back("Earth");

		std_vector_int.push_back(-68);
		std_vector_str.push_back("42");

		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl<<std::endl;

		std::cout<<CYN"Iterator"NC<<std::endl<<std::endl;
		std::cout<<CYN"iterator && const_iterator"NC<<std::endl;
		std::vector<int>::iterator		std_ite_int = std_vector_int.end();
		std::vector<std::string>::iterator	std_ite_str = std_vector_str.end();
		std::vector<int>::const_iterator		std_const_ite_int = std_vector_int.end();
		std::vector<std::string>::const_iterator	std_const_ite_str = std_vector_str.end();

		std::cout<<"std_vector_int:";
		for (std::vector<int>::iterator	std_it_int = std_vector_int.begin(); std_it_int != std_ite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"std_vector_str:";
		for (std::vector<std::string>::iterator std_it_str = std_vector_str.begin(); std_it_str != std_ite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl;
		std::cout<<"const std_vector_int:";
		for (std::vector<int>::const_iterator	std_it_int = std_vector_int.begin(); std_it_int != std_const_ite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"const std_vector_str:";
		for (std::vector<std::string>::const_iterator std_it_str = std_vector_str.begin(); std_it_str != std_const_ite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"reverse_iterator && const_reverse_iterator"NC<<std::endl;

		std::vector<int>::reverse_iterator		std_rite_int = std_vector_int.rend();
		std::vector<std::string>::reverse_iterator	std_rite_str = std_vector_str.rend();
		std::vector<int>::const_reverse_iterator		std_const_rite_int = std_vector_int.rend();
		std::vector<std::string>::const_reverse_iterator	std_const_rite_str = std_vector_str.rend();

		std::cout<<"reverse std_vector_int:";
		for (std::vector<int>::reverse_iterator	std_it_int = std_vector_int.rbegin(); std_it_int != std_rite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"reverse std_vector_str:";
		for (std::vector<std::string>::reverse_iterator std_it_str = std_vector_str.rbegin(); std_it_str != std_rite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl;
		std::cout<<"const reverse std_vector_int:";
		for (std::vector<int>::const_reverse_iterator	std_it_int = std_vector_int.rbegin(); std_it_int != std_const_rite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"const reverse std_vector_str:";
		for (std::vector<std::string>::const_reverse_iterator std_it_str = std_vector_str.rbegin(); std_it_str != std_const_rite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"Iterator + && - "NC<<std::endl;

		std::vector<int>::iterator first_it = std_vector_int.begin();
		std::vector<int>::iterator second_it = std_vector_int.begin();
		std::vector<int>::iterator res_it;

		std::vector<int>::reverse_iterator rfirst_it = std_vector_int.rbegin();
		std::vector<int>::reverse_iterator rsecond_it = std_vector_int.rbegin();
		std::vector<int>::reverse_iterator reverse_res_it;
	
		second_it +=2 ;
		res_it = first_it + 2;
		std::cout<<"res it2 - it1: "<<second_it - first_it<<std::endl;
		std::cout<<"res_it: "<<*res_it<<std::endl;
		res_it = second_it - 2;
		std::cout<<"res_it: "<<*res_it<<std::endl;
		rsecond_it+=2;
		reverse_res_it = rfirst_it + 2;
		std::cout<<"rit2 - rit1: "<<rsecond_it - rfirst_it<<std::endl;
		std::cout<<"reverse_res_it: "<<*reverse_res_it<<std::endl;
		reverse_res_it = rsecond_it - 2;
		std::cout<<"reverse_res_it: "<<*reverse_res_it<<std::endl<<std::endl;

		std::cout<<CYN"Operator[] && at(size_type n)"NC<<std::endl<<std::endl;

		std::cout<<"std_vector_int[2]: "<<std_vector_int[2]<<std::endl;
		std::cout<<"std_vector_int[3]: "<<std_vector_int[3]<<std::endl<<std::endl;
		std::cout<<"std_vector_str.at(1): "<<std_vector_str.at(1)<<std::endl;
		std::cout<<"std_vector_str.at(2): "<<std_vector_str.at(2)<<std::endl<<std::endl;

		std::cout<<CYN"Pop_back()"NC<<std::endl<<std::endl;

		std_vector_int.pop_back();
		std_vector_str.pop_back();

		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl<<std::endl;
		std_ite_int = std_vector_int.end();
		std_ite_str = std_vector_str.end();
		std::cout<<"std_vector_int:";
		for (std::vector<int>::iterator std_it_int = std_vector_int.begin(); std_it_int != std_ite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"std_vector_str:";
		for (std::vector<std::string>::iterator	std_it_str = std_vector_str.begin(); std_it_str != std_ite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"Functions: empty(), front(), back()"NC<<std::endl<<std::endl;

		std::cout<<"std_vetor_int: "<<std_vector_int.empty()<<" "<<std_vector_int.front()<<" "<<std_vector_int.back()<<std::endl;
		std::cout<<"std_vetor_str: "<<std_vector_str.empty()<<" "<<std_vector_str.front()<<" "<<std_vector_str.back()<<std::endl<<std::endl;

		std::cout<<CYN"Assign(...)"NC<<std::endl<<std::endl;

		std::cout<<CYN"assign(size_type n, value_type const &val)"NC<<std::endl;
		std_vector_int.assign(2, 0);
		std_vector_str.assign(2, "AH");
		std_ite_int = std_vector_int.end();
		std_ite_str = std_vector_str.end();

		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl<<std::endl;

		std::cout<<"std_vector_int:";
		for (std::vector<int>::iterator std_it_int = std_vector_int.begin(); std_it_int != std_ite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"std_vector_str:";
		for (std::vector<std::string>::iterator	std_it_str = std_vector_str.begin(); std_it_str != std_ite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl<<std::endl;

		std_vector_int.assign(10, 12345);
		std_vector_str.assign(10, "");
		std_ite_int = std_vector_int.end();
		std_ite_str = std_vector_str.end();

		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl<<std::endl;

		std::cout<<"std_vector_int:";
		for (std::vector<int>::iterator std_it_int = std_vector_int.begin(); std_it_int != std_ite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"std_vector_str:";
		for (std::vector<std::string>::iterator	std_it_str = std_vector_str.begin(); std_it_str != std_ite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"assign(InputIterator first, InputIterator last)"NC<<std::endl;
		std::vector<int>	std_assign_int;
		std::vector<std::string> std_assign_str;

		for (int i = 0; i < 10; i++)
		{
			std_assign_int.push_back(i);
			std_assign_str.push_back("a");
		}
		std::vector<int>::iterator it_int = std_assign_int.begin();
		std::vector<std::string>::iterator it_str = std_assign_str.begin();
		std::vector<int>::iterator ite_int = std_assign_int.end();
		std::vector<std::string>::iterator ite_str = std_assign_str.end();

		ite_int--;
		ite_str--;
//		ite_int++;
//		ite_str++;
		std_vector_int.assign(it_int, ite_int);
		std_vector_str.assign(it_str, ite_str);

		std_ite_int = std_vector_int.end();
		std_ite_str = std_vector_str.end();
		std::cout<<"std_vector_int:";
		for (std::vector<int>::iterator std_it_int = std_vector_int.begin(); std_it_int != std_ite_int; std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl;
		std::cout<<"std_vector_str:";
		for (std::vector<std::string>::iterator	std_it_str = std_vector_str.begin(); std_it_str != std_ite_str; std_it_str++)
			std::cout<<" "<<*std_it_str;
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Reserve()"NC<<std::endl;
	
		std_vector_str.reserve(20);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" " \
			<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<" "<<std_vector_str.empty()<<std::endl;
		std_vector_int.reserve(5);
		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<" "<<std_vector_int.empty()<<std::endl;
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Get_allocator()"NC<<std::endl<<std::endl;
		int *int_tab;

		int_tab = std_vector_int.get_allocator().allocate(5);
		for(int i =0; i < 5; i++)
			int_tab[i] = i;
		std::cout<<"int_tab[5]: ";
		for (int i =0; i < 5; i++)
			std::cout<<int_tab[i]<<" ";
		std_vector_int.get_allocator().deallocate(int_tab, 5);
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Insert(iterator position, size_type n, value_type &val)"NC<<std::endl<<std::endl;
		std_vector_int.insert(std_vector_int.begin(), 15, 42);
		std::cout<<"std_vector_int: "<<std_vector_int.size()<<" " \
			<<std_vector_int.capacity()<<" "<<std_vector_int.max_size()<<" "<<std_vector_int.empty()<<std::endl;
		std::cout<<"std_vector_int: ";
		for (std::vector<int>::iterator std_it_int = std_vector_int.begin(); std_it_int != std_vector_int.end(); std_it_int++)
			std::cout<<" "<<*std_it_int;
		std::cout<<std::endl<<std::endl;
	}
	{
		std::vector<std::string> std_vector_str(8);
		std::vector<std::string> std_vector_operator;
		std::vector<std::string>::const_iterator	std_it_str;
		std::vector<std::string>::const_iterator	std_ite_str;

		std::cout<<"[TEST "<<RED"2"<<NC"]- Operator && Copy constructor && Iterator constructor"<<std::endl<<std::endl;

		std_vector_str.push_back("First");
		std_vector_str.push_back("Second");


		std::vector<std::string> std_vector_cpy(std_vector_str);
		std_it_str = std_vector_cpy.begin();
		std_ite_str = std_vector_cpy.end();
		std::vector<std::string> std_vector_it(std_it_str, std_ite_str);
		std_vector_operator = std_vector_str;

		std::cout<<CYN"vector_name size capacity"NC<<std::endl<<std::endl;

		std::cout<<"std_vector_str "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<std::endl;
		std::cout<<"std_vector_cpy "<<std_vector_cpy.size()<<" "<<std_vector_cpy.capacity()<<std::endl;
		std::cout<<"std_vector_operator "<<std_vector_operator.size()<<" "<<std_vector_operator.capacity()<<std::endl;
		std::cout<<"std_vector_it "<<std_vector_it.size()<<" "<<std_vector_it.capacity()<<std::endl<<std::endl;

		std::cout<<CYN"Check == "NC<<std::endl<<std::endl;

		int	res = 0;
		res = std_vector_str == std_vector_cpy;
		std::cout<<"std_vector_cpy: "<<res<<std::endl;
		res = std_vector_str == std_vector_operator;
		std::cout<<"std_vector_operator: "<<res<<std::endl;
		res = std_vector_str == std_vector_it;
		std::cout<<"std_vector_it: "<<res<<std::endl<<std::endl;

		std::cout<<CYN"insert(...)"NC<<std::endl<<std::endl;
		std::cout<<CYN"insert(iterator position, value_type &val)"NC<<std::endl;

		std::vector<std::string>::iterator	it;

		it = std_vector_cpy.begin();
		std_vector_cpy.insert(it, "Big Boss");
		it = std_vector_str.begin();
		std_vector_str.insert(it, "Small Boss");

		it = std_vector_cpy.end();
		std::cout<<"std_vector_cpy: ";
		for (std::vector<std::string>::iterator itt = std_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt<<" ";
		std::cout<<std::endl;
		std::cout<<"std_vector_str: ";
		it = std_vector_str.end();
		for (std::vector<std::string>::iterator itt = std_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"Check != "NC<<std::endl<<std::endl;

		res = std_vector_str != std_vector_cpy;
		std::cout<<"std_vector_str != std_vector_cpy: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"Swap()"NC<<std::endl<<std::endl;
		std::cout<<CYN"vector.swap"NC<<std::endl;
		std_vector_str.swap(std_vector_cpy);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl;
		std::cout<<"std_vector_cpy: "<<std_vector_cpy.size()<<" "<<std_vector_cpy.capacity()<<" "<<std_vector_cpy.max_size()<<std::endl<<std::endl;
		std::cout<<"std_vector_str: ";
		it = std_vector_str.end();
		for (std::vector<std::string>::iterator itt = std_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl;
		std::cout<<"std_vector_cpy: ";
		it = std_vector_cpy.end();
		for (std::vector<std::string>::iterator itt = std_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"swap(vector<T> &x, vector<T> &y)"NC<<std::endl;
		std::swap(std_vector_str, std_vector_cpy);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<" "<<std_vector_str.max_size()<<std::endl;
		std::cout<<"std_vector_cpy: "<<std_vector_cpy.size()<<" "<<std_vector_cpy.capacity()<<" "<<std_vector_cpy.max_size()<<std::endl<<std::endl;
		std::cout<<"std_vector_str: ";
		it = std_vector_str.end();
		for (std::vector<std::string>::iterator itt = std_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl;
		std::cout<<"std_vector_cpy: ";
		it = std_vector_cpy.end();
		for (std::vector<std::string>::iterator itt = std_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Erase()"NC<<std::endl<<std::endl;;
		std::cout<<CYN"erase(iterator position)"NC<<std::endl;
		std_vector_str.erase(std_vector_str.begin());
		it = std_vector_str.end();
		std::cout<<"std_vector_str: ";
		for (std::vector<std::string>::iterator itt = std_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"erase(iterator first, iterator last)"NC<<std::endl;
		it = std_vector_cpy.begin();
		it+=3;
		std::vector<std::string>::iterator	ite;
		ite = std_vector_cpy.end();
		std_vector_cpy.erase(it, ite);
		it = std_vector_cpy.end();
		std::cout<<"std_vector_cpy: ";
		for (std::vector<std::string>::iterator itt = std_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Check > && >= "NC<<std::endl;
		res = std_vector_str > std_vector_cpy;
		std::cout<<"std_vector_str > std_vector_cpy: "<<res<<std::endl<<std::endl;
		res = std_vector_str > std_vector_cpy;
		std::cout<<"std_vector_str >= std_vector_cpy: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"Check < && <= "NC<<std::endl;
		res = std_vector_str < std_vector_cpy;
		std::cout<<"std_vector_str < std_vector_cpy: "<<res<<std::endl<<std::endl;
		res = std_vector_str <= std_vector_cpy;
		std::cout<<"std_vector_str <= std_vector_cpy: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"Clear()"NC<<std::endl<<std::endl;
		std_vector_it.clear();;
		it = std_vector_it.end();
		std::cout<<"std_vector_it: "<<std_vector_it.empty();
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Front - Back"NC<<std::endl<<std::endl;
		std_vector_cpy.push_back("hello");
		std_vector_str.push_back("ah");
		std_vector_str.push_back("bh");
		std::cout<<"std_vector_cpy: "<<std_vector_cpy.front()<<" "<<std_vector_cpy.back()<<std::endl;
		std::cout<<"std_vector_str: "<<std_vector_str.front()<<" "<<std_vector_str.back()<<std::endl<<std::endl;

		std::cout<<CYN"Resize()"NC<<std::endl<<std::endl;

		std_vector_str.resize(15);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<std::endl;
		std::cout<<"std_vector_str: ";
		for (std::vector<std::string>::iterator it = std_vector_str.begin(); it != std_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		std_vector_str.resize(18);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<std::endl;
		std::cout<<"std_vector_str: ";
		for (std::vector<std::string>::iterator it = std_vector_str.begin(); it != std_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		std_vector_str.resize(100);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<std::endl;
		std::cout<<"std_vector_str: ";
		for (std::vector<std::string>::iterator it = std_vector_str.begin(); it != std_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		std_vector_str.resize(3);
		std::cout<<"std_vector_str: "<<std_vector_str.size()<<" "<<std_vector_str.capacity()<<std::endl;
		std::cout<<"std_vector_str: ";
		for (std::vector<std::string>::iterator it = std_vector_str.begin(); it != std_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl<<std::endl;
	}
	{
		std::vector<int>	std_vector_int;
		std::vector<int>	std_vector_int_cpy;
		std::vector<int>::iterator it;
		std::vector<int>::iterator itt;
		std::vector<int>::iterator ite;

		std::cout<<"[TEST "<<RED"3"<<NC"]- Time exec"<<std::endl<<std::endl;
		std::cout<<CYN"Push 1 000 0000"NC<<std::endl;
		for (int i = 0; i < 1000000; i++)
		{
			std_vector_int.push_back(i);
		}
		std::cout<<CYN"End push"NC<<std::endl;
		it = std_vector_int.begin();
		ite = std_vector_int.end();
		itt = std_vector_int_cpy.begin();
		ite--;
		std::cout<<CYN"insert(iterator position, InputIterator first, InputIterator last)"NC<<std::endl;
		std::cout<<CYN"Insert 1 000 000"NC<<std::endl;
		std_vector_int_cpy.insert(itt, it, ite);
		std::cout<<CYN"End Insert"NC<<std::endl;
	}

	return 0;
}
