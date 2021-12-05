/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 07:50:34 by yun               #+#    #+#             */
/*   Updated: 2021/10/26 07:50:36 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>
#include <string>
#include "../Map/map.hpp"

#define NC "\e[0m"
#define RD "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RDB "\e[41m"

int ft_map_test()
{
	std::cout<<"===== TEST FT::"<<GRN"MAP "<<NC"====="<<std::endl<<std::endl;
    {
		std::cout<<"[TEST "<<RD"1"<<NC"]- Map member functiomns"<<std::endl<<std::endl;

		ft::map<std::string, int>	ft_map;

        std::cout<<CYN"map_name size empty max_size"NC<<std::endl;
        std::cout<<"ft_map<std::string, int>: "<<ft_map.size()<<" "<<ft_map.empty()<<" "<<ft_map.max_size()<<std::endl<<std::endl;

        std::cout<<CYN"Insert()"NC<<std::endl<<std::endl;
        std::cout<<CYN"insert(value_type const &value)"NC<<std::endl<<std::endl;
        ft::pair<ft::map<std::string, int>::iterator, bool> ret_insert;
        ret_insert = ft_map.insert(ft::make_pair<std::string, int>("pkevin", 5));
        std::cout<<"ret_insert: "<<ret_insert.first->first<< " "<<ret_insert.first->second<< " "<<ret_insert.second<<std::endl;
        std::cout<<"ft_map<std::string, int>: "<<ft_map.size()<<" "<<ft_map.empty()<<" "<<ft_map.max_size()<<std::endl;
        ft_map.insert(ft::make_pair<std::string, int>("roger", 42));
        ft_map.insert(ft::make_pair<std::string, int>("yolo", 42));
        std::cout<<"ft_map<std::string, int>: "<<ft_map.size()<<" "<<ft_map.empty()<<" "<<ft_map.max_size()<<std::endl<<std::endl;
        std::cout<<"ft_map: ";
        for (ft::map<std::string, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
        std::cout<<CYN"Try insert key already present"NC<<std::endl<<std::endl;
        ret_insert = ft_map.insert(ft::make_pair<std::string, int>("pkevin", 5));
        std::cout<<"ret_insert: "<<ret_insert.first->first<< " "<<ret_insert.first->second<< " "<<ret_insert.second<<std::endl<<std::endl;

        std::cout<<CYN"insert(iterator position, value_type &val)"NC<<std::endl;
        std::cout<<CYN"Insert element with key already present"NC<<std::endl;
        ft_map.insert(ft_map.begin(), ft::make_pair<std::string, int>("roger", 53));
    
        std::cout<<"ft_map<std::string, int>: "<<ft_map.size()<<" "<<ft_map.empty()<<" "<<ft_map.max_size()<<std::endl;
        std::cout<<"ft_map: ";
        for (ft::map<std::string, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::cout<<CYN"Try insert new key"NC<<std::endl;
        ft_map.insert(ft_map.begin(), ft::make_pair<std::string, int>("mamamia", 58));
        std::cout<<"ft_map: ";
        for (ft::map<std::string, int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
        std::cout<<CYN"Count(key_type val)"NC<<std::endl<<std::endl;

        std::cout<<"ft_map.count(roger): "<<ft_map.count("roger")<<std::endl;
        std::cout<<"ft_map.count(not_present_key): "<<ft_map.count("not_present_key")<<std::endl<<std::endl;

        std::cout<<CYN"Operator []"NC<<std::endl<<std::endl;
        std::cout<<"ft_map[yolo] "<<ft_map["yolo"]<<std::endl;
        std::cout<<"ft_map[not_present_key] "<<ft_map["not_present_key"]<<" //not present so [] == insert(not_present_key, 0)"<<std::endl<<std::endl;

        std::cout<<CYN"Find()"NC<<std::endl<<std::endl;
        ft::map<std::string, int>::iterator ret_find;
        ft::map<std::string, int>::const_iterator const_ret_find;
        ret_find = ft_map.find("not_present_key");
        std::cout<<"ft_map.find(not_present_key): "<<ret_find->first<<" "<<ret_find->second<<std::endl;
        ret_find = ft_map.find("pkevin");
        std::cout<<"ft_map.find(pkevin): "<<ret_find->first<<" "<<ret_find->second<<std::endl<<std::endl;
        const_ret_find = ft_map.find("not_present_key");
        std::cout<<"ft_map.find(not_present_key): "<<const_ret_find->first<<" "<<const_ret_find->second<<std::endl;
        const_ret_find = ft_map.find("pkevin");
        std::cout<<"ft_map.find(pkevin): "<<const_ret_find->first<<" "<<const_ret_find->second<<std::endl<<std::endl;

        std::cout<<CYN"Get_allocator()"NC<<std::endl<<std::endl;

        ft::pair<const std::string, int> *pair_tab;

        pair_tab = ft_map.get_allocator().allocate(8);
        for (int i =0; i < 8; i++)
        {
            pair_tab[i].second = i;
        }
        std::cout<<"pair_tab: ";
        for (int i =0; i < 8; i++)
        {
            std::cout<<pair_tab[i].second<<" ";
        }
        ft_map.get_allocator().deallocate(pair_tab, 8);
    
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Key_comp()"NC<<std::endl<<std::endl;

        ft::map<std::string, int>::key_compare ft_cmp = ft_map.key_comp();

        std::string first_str = "Hey";
        std::string second_str = "Hah";

        std::cout<<"ft_cmp(first_str, second_str): "<<ft_cmp(first_str, second_str)<<std::endl;
        std::cout<<"ft_cmp(second_str, first_str): "<<ft_cmp(second_str, first_str);

        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Value_comp()"NC<<std::endl<<std::endl;

        ft::map<std::string, int>::value_compare ft_val_cmp = ft_map.value_comp();
        ft::map<std::string, int>::iterator it1 = ft_map.find("pkevin");
        ft::map<std::string, int>::iterator it2 = ft_map.find("yolo");

        std::cout<<"ft_val_cmp(pkevin, yolo): "<<ft_val_cmp(*it1, *it2)<<std::endl;
        std::cout<<"ft_val_cmp(yolo, pkevin): "<<ft_val_cmp(*it2, *it1)<<std::endl<<std::endl;

        std::cout<<"----------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"2"<<NC"]- Map iterator"<<std::endl<<std::endl;
		std::cout<<CYN"Map iterator && const_iterator"NC<<std::endl;

        ft::map<std::string, int>::iterator ite = ft_map.end();
        std::cout<<"ft_map const_iterator: ";
        for (ft::map<std::string, int>::iterator it = ft_map.begin(); it != ite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        ft::map<std::string, int>::const_iterator cite = ft_map.end();
        std::cout<<"ft_map iterator: ";
        for (ft::map<std::string, int>::const_iterator it = ft_map.begin(); it != cite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Map reverse iterator"NC<<std::endl;

        ft::map<std::string, int>::reverse_iterator rite = ft_map.rend();
        std::cout<<"ft_map reverse_iterator: ";
        for (ft::map<std::string, int>::reverse_iterator it = ft_map.rbegin(); it != rite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        ft::map<std::string, int>::const_reverse_iterator crite = ft_map.rend();
        std::cout<<"ft_map const_reverse_iterator: ";
        for (ft::map<std::string, int>::const_reverse_iterator it = ft_map.rbegin(); it != crite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
    }
	{
        std::cout<<"----------------------------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"3"<<NC"]- Map constructor and operator ="<<std::endl<<std::endl;
		ft::map<std::string, std::string> ft_map;
        ft_map.insert(ft::make_pair<std::string, std::string>("Salut", "cv?"));
        ft_map.insert(ft::make_pair<std::string, std::string>("Moi", "oui"));
        ft_map.insert(ft::make_pair<std::string, std::string>("Tant", "mieux"));
        ft_map.insert(ft::make_pair<std::string, std::string>("Super", "cool"));
        ft_map.insert(ft::make_pair<std::string, std::string>("Trop", "bien"));
		ft::map<std::string, std::string> ft_map_cpy(ft_map);
		ft::map<std::string, std::string> ft_map_it(ft_map.begin(), ft_map.end());
		ft::map<std::string, std::string> ft_map_operator = ft_map;

        std::cout<<"ft_map "<<ft_map.size()<< " "<<ft_map.max_size()<<std::endl;
        std::cout<<"ft_map_cpy "<<ft_map_cpy.size()<< " "<<ft_map_cpy.max_size()<<std::endl;
        std::cout<<"ft_map_it "<<ft_map_it.size()<< " "<<ft_map_it.max_size()<<std::endl;
        std::cout<<"ft_map_operator "<<ft_map_operator.size()<< " "<<ft_map_operator.max_size()<<std::endl<<std::endl;

        std::cout<<CYN"Erase(key_type const &value)"NC<<std::endl<<std::endl;

        ft_map_it.erase("Tant");
        std::cout<<"ft_map_it: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_it.begin(); it != ft_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Swap()"NC<<std::endl<<std::endl;
        std::cout<<"ft_map_cpy "<<ft_map_cpy.size()<< " "<<ft_map_cpy.max_size()<<std::endl;
        std::cout<<"ft_map_it "<<ft_map_it.size()<< " "<<ft_map_it.max_size()<<std::endl;
        std::cout<<"ft_map_it before: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_it.begin(); it != ft_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::cout<<"ft_map_cpy before: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_cpy.begin(); it != ft_map_cpy.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";

        std::cout<<std::endl<<std::endl;
        ft_map_it.swap(ft_map_cpy);
        std::cout<<"ft_map_cpy "<<ft_map_cpy.size()<< " "<<ft_map_cpy.max_size()<<std::endl;
        std::cout<<"ft_map_it "<<ft_map_it.size()<< " "<<ft_map_it.max_size()<<std::endl;
        std::cout<<"ft_map_it after: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_it.begin(); it != ft_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::cout<<"ft_map_cpy after: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_cpy.begin(); it != ft_map_cpy.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
        std::cout<<CYN"Erase(InputIterator first, InputIterator last)"NC<<std::endl<<std::endl;
        ft::map<std::string, std::string>::iterator itt = ft_map_it.begin();
        ft::map<std::string, std::string>::iterator itte = ft_map_it.end();
        itt++;
        itte--;
        ft_map_it.erase(itt, itte);
        std::cout<<"ft_map_it: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_it.begin(); it != ft_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Erase(iterator position)"NC<<std::endl;

        ft_map_cpy.erase(ft_map_cpy.begin());
        std::cout<<"ft_map_cpy: ";
        for (ft::map<std::string, std::string>::iterator it = ft_map_cpy.begin(); it != ft_map_cpy.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";

        std::cout<<std::endl<<std::endl;

        ft::map<std::string, std::string>::iterator ret_it;
        ft::map<std::string, std::string>::const_iterator const_ret_it;
        ft::pair<ft::map<std::string, std::string>::iterator, ft::map<std::string, std::string>::iterator> ret_pair;
        ft::pair<ft::map<std::string, std::string>::const_iterator, ft::map<std::string, std::string>::const_iterator> const_ret_pair;

        std::cout<<CYN"Lower_bound()"NC<<std::endl<<std::endl;

        std::cout<<CYN"Test with middle key"NC<<std::endl<<std::endl;

        ret_it = ft_map.lower_bound("Super");
        const_ret_it = ft_map.lower_bound("Super");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with smallest key"NC<<std::endl<<std::endl;

        ret_it = ft_map.lower_bound("Moi");
        const_ret_it = ft_map.lower_bound("Moi");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with biggest key"NC<<std::endl<<std::endl;

        ret_it = ft_map.lower_bound("Tant");
        const_ret_it = ft_map.lower_bound("Tant");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Upper_bound()"NC<<std::endl<<std::endl;

        std::cout<<CYN"Test with middle key"NC<<std::endl<<std::endl;

        ret_it = ft_map.upper_bound("Super");
        const_ret_it = ft_map.upper_bound("Super");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with smallest key"NC<<std::endl<<std::endl;

        ret_it = ft_map.upper_bound("Moi");
        const_ret_it = ft_map.upper_bound("Moi");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with biggest key"NC<<std::endl<<std::endl;

        ret_it = ft_map.upper_bound("Tant");
        const_ret_it = ft_map.upper_bound("Tant");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;
    
        std::cout<<CYN"Equal_range()"NC<<std::endl<<std::endl;

         std::cout<<CYN"Test with middle key"NC<<std::endl<<std::endl;

        ret_pair = ft_map.equal_range("Super");
        const_ret_pair = ft_map.equal_range("Super");
        std::cout<<"ret_pair: "<< ret_pair.first->first<< " "<< ret_pair.second->first<<std::endl;
        std::cout<<"const_ret_pair: "<< const_ret_pair.first->first<< " "<< const_ret_pair.second->first<<std::endl<<std::endl;

        std::cout<<CYN"Test with smallest key"NC<<std::endl<<std::endl;

        ret_pair = ft_map.equal_range("Moi");
        const_ret_pair = ft_map.equal_range("Moi");
        std::cout<<"ret_pair: "<< ret_pair.first->first<< " "<< ret_pair.second->first<<std::endl;
        std::cout<<"const_ret_pair: "<< const_ret_pair.first->first<< " "<< const_ret_pair.second->first<<std::endl<<std::endl;

        std::cout<<CYN"Test with biggest key"NC<<std::endl<<std::endl;

        ret_pair = ft_map.equal_range("Tant");
        const_ret_pair = ft_map.equal_range("Tant");
        std::cout<<"ret_pair: "<< ret_pair.first->first<< " "<< ret_pair.second->first<<std::endl;
        std::cout<<"const_ret_pair: "<< const_ret_pair.first->first<< " "<< const_ret_pair.second->first<<std::endl<<std::endl;

        std::cout<<CYN"Clear()"NC<<std::endl<<std::endl;
        ft_map.clear();
        std::cout<<"ft_map: "<<ft_map.empty()<<std::endl<<std::endl;
	}
	{
        std::cout<<"-----------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"4"<<NC"]- Map time exec"<<std::endl<<std::endl;
        ft::map<int, int> ft_map;
        std::cout<<CYN"Insert 1 000 000 element"NC<<std::endl;
        for (int i = 0; i < 1000000; i++)
            ft_map.insert(ft::make_pair<int, int>(i, i));
        std::cout<<CYN"End Insert"NC<<std::endl;
        std::cout<<CYN"insert(InputIterator first, InputIterator last)"NC<<std::endl;
        ft::map<int, int> ft_map_cpy;
        ft_map_cpy.insert(ft_map.begin(), ft_map.end());
        std::cout<<CYN"End Insert"NC<<std::endl;
	}

    return 0;
}
