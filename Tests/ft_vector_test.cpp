/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 06:44:58 by yun               #+#    #+#             */
/*   Updated: 2021/11/15 13:26:28 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector/vector.hpp"
#include <iostream>
#include <string>

#define NC "\e[0m"
#define RD "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RDB "\e[41m"

int	ft_vector_test()
{
	std::cout<<"===== TEST " <<"FT::"<<GRN"VECTOR "<<NC"====="<<std::endl<<std::endl;
	{
		std::cout<<"[TEST "<<RD"1"<<NC"]- Vector basic functions"<<std::endl<<std::endl;
		ft::vector<int>		ft_vector_int;
		ft::vector<std::string>	ft_vector_str;

		std::cout <<"name_vector_type: size capacity max_size bool_empty"<<std::endl<<std::endl;
		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<" "<<ft_vector_int.empty()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<" "<<ft_vector_str.empty()<<std::endl<<std::endl;

		std::cout<<CYN"Push_back()"NC<<std::endl<<std::endl;

		ft_vector_int.push_back(42);
		ft_vector_str.push_back("Hello World");

		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl<<std::endl;

		ft_vector_int.push_back(5);
		ft_vector_str.push_back("Goodbye Space");

		ft_vector_int.push_back(24);
		ft_vector_str.push_back("Earth");

		ft_vector_int.push_back(-68);
		ft_vector_str.push_back("42");

		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl<<std::endl;

		std::cout<<CYN"Iterator"NC<<std::endl<<std::endl;
		std::cout<<CYN"iterator && const_iterator"NC<<std::endl;
		ft::vector<int>::iterator		ft_ite_int = ft_vector_int.end();
		ft::vector<std::string>::iterator	ft_ite_str = ft_vector_str.end();
		ft::vector<int>::const_iterator		ft_const_ite_int = ft_vector_int.end();
		ft::vector<std::string>::const_iterator	ft_const_ite_str = ft_vector_str.end();

		std::cout<<"ft_vector_int:";
		for (ft::vector<int>::iterator	ft_it_int = ft_vector_int.begin(); ft_it_int != ft_ite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"ft_vector_str:";
		for (ft::vector<std::string>::iterator ft_it_str = ft_vector_str.begin(); ft_it_str != ft_ite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl;
		std::cout<<"const ft_vector_int:";
		for (ft::vector<int>::const_iterator	ft_it_int = ft_vector_int.begin(); ft_it_int != ft_const_ite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"const ft_vector_str:";
		for (ft::vector<std::string>::const_iterator ft_it_str = ft_vector_str.begin(); ft_it_str != ft_const_ite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"reverse_iterator && const_reverse_iterator"NC<<std::endl;

		ft::vector<int>::reverse_iterator		ft_rite_int = ft_vector_int.rend();
		ft::vector<std::string>::reverse_iterator	ft_rite_str = ft_vector_str.rend();
		ft::vector<int>::const_reverse_iterator		ft_const_rite_int = ft_vector_int.rend();
		ft::vector<std::string>::const_reverse_iterator	ft_const_rite_str = ft_vector_str.rend();

		std::cout<<"reverse ft_vector_int:";
		for (ft::vector<int>::reverse_iterator	ft_it_int = ft_vector_int.rbegin(); ft_it_int != ft_rite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"reverse ft_vector_str:";
		for (ft::vector<std::string>::reverse_iterator ft_it_str = ft_vector_str.rbegin(); ft_it_str != ft_rite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl;
		std::cout<<"const reverse ft_vector_int:";
		for (ft::vector<int>::const_reverse_iterator	ft_it_int = ft_vector_int.rbegin(); ft_it_int != ft_const_rite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"const reverse ft_vector_str:";
		for (ft::vector<std::string>::const_reverse_iterator ft_it_str = ft_vector_str.rbegin(); ft_it_str != ft_const_rite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"Iterator + && - "NC<<std::endl;

		ft::vector<int>::iterator first_it = ft_vector_int.begin();
		ft::vector<int>::iterator second_it = ft_vector_int.begin();
		ft::vector<int>::iterator res_it;

		ft::vector<int>::reverse_iterator rfirst_it = ft_vector_int.rbegin();
		ft::vector<int>::reverse_iterator rsecond_it = ft_vector_int.rbegin();
		ft::vector<int>::reverse_iterator reverse_res_it;
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
		

		std::cout<<"ft_vector_int[2]: "<<ft_vector_int[2]<<std::endl;
		std::cout<<"ft_vector_int[3]: "<<ft_vector_int[3]<<std::endl<<std::endl;
		std::cout<<"ft_vector_str.at(1): "<<ft_vector_str.at(1)<<std::endl;
		std::cout<<"ft_vector_str.at(2): "<<ft_vector_str.at(2)<<std::endl<<std::endl;

		std::cout<<CYN"Pop_back()"NC<<std::endl<<std::endl;

		ft_vector_int.pop_back();
		ft_vector_str.pop_back();

		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl<<std::endl;
		ft_ite_int = ft_vector_int.end();
		ft_ite_str = ft_vector_str.end();
		std::cout<<"ft_vector_int:";
		for (ft::vector<int>::iterator ft_it_int = ft_vector_int.begin(); ft_it_int != ft_ite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"ft_vector_str:";
		for (ft::vector<std::string>::iterator	ft_it_str = ft_vector_str.begin(); ft_it_str != ft_ite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"Functions: empty(), front(), back()"NC<<std::endl<<std::endl;

		std::cout<<"ft_vetor_int: "<<ft_vector_int.empty()<<" "<<ft_vector_int.front()<<" "<<ft_vector_int.back()<<std::endl;
		std::cout<<"ft_vetor_str: "<<ft_vector_str.empty()<<" "<<ft_vector_str.front()<<" "<<ft_vector_str.back()<<std::endl<<std::endl;

		std::cout<<CYN"Assign(...)"NC<<std::endl<<std::endl;

		std::cout<<CYN"assign(size_type n, value_type const &val)"NC<<std::endl;
		ft_vector_int.assign(2, 0);
		ft_vector_str.assign(2, "AH");
		ft_ite_int = ft_vector_int.end();
		ft_ite_str = ft_vector_str.end();

		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl<<std::endl;

		std::cout<<"ft_vector_int:";
		for (ft::vector<int>::iterator ft_it_int = ft_vector_int.begin(); ft_it_int != ft_ite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"ft_vector_str:";
		for (ft::vector<std::string>::iterator	ft_it_str = ft_vector_str.begin(); ft_it_str != ft_ite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl<<std::endl;

		ft_vector_int.assign(10, 12345);
		ft_vector_str.assign(10, "");
		ft_ite_int = ft_vector_int.end();
		ft_ite_str = ft_vector_str.end();

		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl<<std::endl;

		std::cout<<"ft_vector_int:";
		for (ft::vector<int>::iterator ft_it_int = ft_vector_int.begin(); ft_it_int != ft_ite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"ft_vector_str:";
		for (ft::vector<std::string>::iterator	ft_it_str = ft_vector_str.begin(); ft_it_str != ft_ite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl<<std::endl;

		std::cout<<CYN"assign(InputIterator first, InputIterator last)"NC<<std::endl;
		ft::vector<int>	ft_assign_int;
		ft::vector<std::string> ft_assign_str;

		for (int i = 0; i < 10; i++)
		{
			ft_assign_int.push_back(i);
			ft_assign_str.push_back("a");
		}
		ft::vector<int>::iterator it_int = ft_assign_int.begin();
		ft::vector<std::string>::iterator it_str = ft_assign_str.begin();
		ft::vector<int>::iterator ite_int = ft_assign_int.end();
		ft::vector<std::string>::iterator ite_str = ft_assign_str.end();

		ite_int--;
		ite_str--;
		ft_vector_int.assign(it_int, ite_int);
		ft_vector_str.assign(it_str, ite_str);

		ft_ite_int = ft_vector_int.end();
		ft_ite_str = ft_vector_str.end();
		std::cout<<"ft_vector_int:";
		for (ft::vector<int>::iterator ft_it_int = ft_vector_int.begin(); ft_it_int != ft_ite_int; ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl;
		std::cout<<"ft_vector_str:";
		for (ft::vector<std::string>::iterator	ft_it_str = ft_vector_str.begin(); ft_it_str != ft_ite_str; ft_it_str++)
			std::cout<<" "<<*ft_it_str;
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Reserve()"NC<<std::endl;

		ft_vector_str.reserve(20);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" " \
			<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<" "<<ft_vector_str.empty()<<std::endl;
		ft_vector_int.reserve(5);
		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<" "<<ft_vector_int.empty()<<std::endl;
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Get_allocator()"NC<<std::endl<<std::endl;
		int *int_tab;

		int_tab = ft_vector_int.get_allocator().allocate(5);
		for(int i =0; i < 5; i++)
			int_tab[i] = i;
		std::cout<<"int_tab[5]: ";
		for (int i =0; i < 5; i++)
			std::cout<<int_tab[i]<<" ";
		ft_vector_int.get_allocator().deallocate(int_tab, 5);
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Insert(iterator position, size_type n, value_type &val)"NC<<std::endl<<std::endl;
		ft_vector_int.insert(ft_vector_int.begin(), 15, 42);
		std::cout<<"ft_vector_int: "<<ft_vector_int.size()<<" " \
			<<ft_vector_int.capacity()<<" "<<ft_vector_int.max_size()<<" "<<ft_vector_int.empty()<<std::endl;
		std::cout<<"ft_vector_int: ";
		for (ft::vector<int>::iterator ft_it_int = ft_vector_int.begin(); ft_it_int != ft_vector_int.end(); ft_it_int++)
			std::cout<<" "<<*ft_it_int;
		std::cout<<std::endl<<std::endl;
	}

	{
		ft::vector<std::string> ft_vector_str(8);
		ft::vector<std::string> ft_vector_operator;
		ft::vector<std::string>::const_iterator	ft_it_str;
		ft::vector<std::string>::const_iterator	ft_ite_str;

		std::cout<<"[TEST "<<RD"2"<<NC"]- Vector constructor && operator ="<<std::endl<<std::endl;

		ft_vector_str.push_back("First");
		ft_vector_str.push_back("Second");


		ft::vector<std::string> ft_vector_cpy(ft_vector_str);
		ft_it_str = ft_vector_cpy.begin();
		ft_ite_str = ft_vector_cpy.end();
		ft::vector<std::string> ft_vector_it(ft_it_str, ft_ite_str);
		ft_vector_operator = ft_vector_str;

		std::cout<<CYN"vector_name size capacity"NC<<std::endl<<std::endl;

		std::cout<<"ft_vector_str "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<std::endl;
		std::cout<<"ft_vector_cpy "<<ft_vector_cpy.size()<<" "<<ft_vector_cpy.capacity()<<std::endl;
		std::cout<<"ft_vector_operator "<<ft_vector_operator.size()<<" "<<ft_vector_operator.capacity()<<std::endl;
		std::cout<<"ft_vector_it "<<ft_vector_it.size()<<" "<<ft_vector_it.capacity()<<std::endl<<std::endl;

		std::cout<<CYN"Check == "NC<<std::endl<<std::endl;

		int	res = 0;
		res = ft_vector_str == ft_vector_cpy;
		std::cout<<"ft_vector_cpy: "<<res<<std::endl;
		res = ft_vector_str == ft_vector_operator;
		std::cout<<"ft_vector_operator: "<<res<<std::endl;
		res = ft_vector_str == ft_vector_it;
		std::cout<<"ft_vector_it: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"insert(...)"NC<<std::endl<<std::endl;
		std::cout<<CYN"insert(iterator position, value_type &val)"NC<<std::endl;

		ft::vector<std::string>::iterator	it;

		it = ft_vector_cpy.begin();
		ft_vector_cpy.insert(it, "Big Boss");
		it = ft_vector_str.begin();
		ft_vector_str.insert(it, "Small Boss");

		it = ft_vector_cpy.end();
		std::cout<<"ft_vector_cpy: ";
		for (ft::vector<std::string>::iterator itt = ft_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt<<" ";
		std::cout<<std::endl;
		std::cout<<"ft_vector_str: ";
		it = ft_vector_str.end();
		for (ft::vector<std::string>::iterator itt = ft_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
	
		std::cout<<CYN"Check != "NC<<std::endl<<std::endl;

		res = ft_vector_str != ft_vector_cpy;
		std::cout<<"ft_vector_str != ft_vector_cpy: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"Swap()"NC<<std::endl<<std::endl;
		std::cout<<CYN"vector.swap"NC<<std::endl;
		ft_vector_str.swap(ft_vector_cpy);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl;
		std::cout<<"ft_vector_cpy: "<<ft_vector_cpy.size()<<" "<<ft_vector_cpy.capacity()<<" "<<ft_vector_cpy.max_size()<<std::endl<<std::endl;
		std::cout<<"ft_vector_str: ";
		it = ft_vector_str.end();
		for (ft::vector<std::string>::iterator itt = ft_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl;
		std::cout<<"ft_vector_cpy: ";
		it = ft_vector_cpy.end();
		for (ft::vector<std::string>::iterator itt = ft_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"swap(vector<T> &x, vector<T> &y)"NC<<std::endl;
		ft::swap(ft_vector_str, ft_vector_cpy);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<" "<<ft_vector_str.max_size()<<std::endl;
		std::cout<<"ft_vector_cpy: "<<ft_vector_cpy.size()<<" "<<ft_vector_cpy.capacity()<<" "<<ft_vector_cpy.max_size()<<std::endl<<std::endl;
		std::cout<<"ft_vector_str: ";
		it = ft_vector_str.end();
		for (ft::vector<std::string>::iterator itt = ft_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl;
		std::cout<<"ft_vector_cpy: ";
		it = ft_vector_cpy.end();
		for (ft::vector<std::string>::iterator itt = ft_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Erase()"NC<<std::endl<<std::endl;;
		std::cout<<CYN"erase(iterator position)"NC<<std::endl;
		ft_vector_str.erase(ft_vector_str.begin());
		it = ft_vector_str.end();
		std::cout<<"ft_vector_str: ";
		for (ft::vector<std::string>::iterator itt = ft_vector_str.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"erase(iterator first, iterator last)"NC<<std::endl;
		it = ft_vector_cpy.begin();
		it+=3; 
		ft::vector<std::string>::iterator	ite;
		ite = ft_vector_cpy.end();
		ft_vector_cpy.erase(it, ite);
		it = ft_vector_cpy.end();
		std::cout<<"ft_vector_cpy: ";
		for (ft::vector<std::string>::iterator itt = ft_vector_cpy.begin(); itt != it; itt++)
			std::cout<<*itt <<" ";
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Check > && >= "NC<<std::endl;
		res = ft_vector_str > ft_vector_cpy;
		std::cout<<"ft_vector_str > ft_vector_cpy: "<<res<<std::endl<<std::endl;
		res = ft_vector_str > ft_vector_cpy;
		std::cout<<"ft_vector_str >= ft_vector_cpy: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"Check < && <= "NC<<std::endl;
		res = ft_vector_str < ft_vector_cpy;
		std::cout<<"ft_vector_str < ft_vector_cpy: "<<res<<std::endl<<std::endl;
		res = ft_vector_str <= ft_vector_cpy;
		std::cout<<"ft_vector_str <= ft_vector_cpy: "<<res<<std::endl<<std::endl;
		std::cout<<CYN"Clear()"NC<<std::endl<<std::endl;
		ft_vector_it.clear();
		it = ft_vector_it.end();
		std::cout<<"ft_vector_it: "<<ft_vector_it.empty();
		std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Front - Back"NC<<std::endl<<std::endl;
		ft_vector_cpy.push_back("hello");
		ft_vector_str.push_back("ah");
		ft_vector_str.push_back("bh");
		std::cout<<"ft_vector_cpy: "<<ft_vector_cpy.front()<<" "<<ft_vector_cpy.back()<<std::endl;
		std::cout<<"ft_vector_str: "<<ft_vector_str.front()<<" "<<ft_vector_str.back()<<std::endl<<std::endl;

		std::cout<<CYN"Resize()"NC<<std::endl<<std::endl;

		ft_vector_str.resize(15);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<std::endl;
		std::cout<<"ft_vector_str: ";
		for (ft::vector<std::string>::iterator it = ft_vector_str.begin(); it != ft_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		ft_vector_str.resize(18);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<std::endl;
		std::cout<<"ft_vector_str: ";
		for (ft::vector<std::string>::iterator it = ft_vector_str.begin(); it != ft_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		ft_vector_str.resize(100);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<std::endl;
		std::cout<<"ft_vector_str: ";
		for (ft::vector<std::string>::iterator it = ft_vector_str.begin(); it != ft_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl;
		ft_vector_str.resize(3);
		std::cout<<"ft_vector_str: "<<ft_vector_str.size()<<" "<<ft_vector_str.capacity()<<std::endl;
		std::cout<<"ft_vector_str: ";
		for (ft::vector<std::string>::iterator it = ft_vector_str.begin(); it != ft_vector_str.end(); it++)
			std::cout<<*it<<" ";
		std::cout<<std::endl<<std::endl;

	}
	{
		ft::vector<int>	ft_vector_int;
		ft::vector<int>	ft_vector_int_cpy;
		ft::vector<int>::iterator it;
		ft::vector<int>::iterator itt;
		ft::vector<int>::iterator ite;

		std::cout<<"[TEST "<<RD"3"<<NC"]- Time exec"<<std::endl<<std::endl;
		std::cout<<CYN"Push 1 000 0000"NC<<std::endl;
		for (int i = 0; i < 1000000; i++)
			ft_vector_int.push_back(i);
		std::cout<<CYN"End push"NC<<std::endl;
		it = ft_vector_int.begin();
		ite = ft_vector_int.end();
		itt = ft_vector_int_cpy.begin();
		ite--;
		std::cout<<CYN"insert(iterator position, InputIterator first, InputIterator last)"NC<<std::endl;
		std::cout<<CYN"Insert 1 000 000"NC<<std::endl;
		ft_vector_int_cpy.insert(itt, it, ite);
		std::cout<<CYN"End Insert"NC<<std::endl;
	}
	return 0;
}
