/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_map_test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 07:50:40 by yun               #+#    #+#             */
/*   Updated: 2021/10/26 07:50:41 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>
#include <string>
#include <map>

#define NC "\e[0m"
#define RD "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RDB "\e[41m"

int std_map_test()
{
	std::cout<<"===== TEST std::"<<GRN"MAP "<<NC"====="<<std::endl<<std::endl;
    {
		std::cout<<"[TEST "<<RD"1"<<NC"]- Map member functiomns"<<std::endl<<std::endl;

		std::map<std::string, int>	std_map;

        std::cout<<CYN"map_name size empty max_size"NC<<std::endl;
        std::cout<<"std_map<std::string, int>: "<<std_map.size()<<" "<<std_map.empty()<<" "<<std_map.max_size()<<std::endl<<std::endl;

        std::cout<<CYN"Insert()"NC<<std::endl<<std::endl;
        std::cout<<CYN"insert(value_type const &value)"NC<<std::endl<<std::endl;
        std::pair<std::map<std::string, int>::iterator, bool> ret_insert;
        ret_insert = std_map.insert(std::make_pair<std::string, int>("pkevin", 5));
        std::cout<<"ret_insert: "<<ret_insert.first->first<< " "<<ret_insert.first->second<< " "<<ret_insert.second<<std::endl;
        std::cout<<"std_map<std::string, int>: "<<std_map.size()<<" "<<std_map.empty()<<" "<<std_map.max_size()<<std::endl;
        std_map.insert(std::make_pair<std::string, int>("roger", 42));
        std_map.insert(std::make_pair<std::string, int>("yolo", 42));
        std::cout<<"std_map<std::string, int>: "<<std_map.size()<<" "<<std_map.empty()<<" "<<std_map.max_size()<<std::endl<<std::endl;
        std::cout<<"std_map: ";
        for (std::map<std::string, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
        std::cout<<CYN"Try insert key already present"NC<<std::endl<<std::endl;
        ret_insert = std_map.insert(std::make_pair<std::string, int>("pkevin", 5));
        std::cout<<"ret_insert: "<<ret_insert.first->first<< " "<<ret_insert.first->second<< " "<<ret_insert.second<<std::endl<<std::endl;
        std::cout<<CYN"insert(iterator position, value_type &val)"NC<<std::endl;
        std::cout<<CYN"Insert element with key already present"NC<<std::endl;
        std_map.insert(std_map.begin(), std::make_pair<std::string, int>("roger", 53));
        std::cout<<"std_map<std::string, int>: "<<std_map.size()<<" "<<std_map.empty()<<" "<<std_map.max_size()<<std::endl;
        std::cout<<"std_map: ";
        for (std::map<std::string, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::cout<<CYN"Try insert new key"NC<<std::endl;
        std_map.insert(std_map.begin(), std::make_pair<std::string, int>("mamamia", 58));
        std::cout<<"std_map: ";
        for (std::map<std::string, int>::iterator it = std_map.begin(); it != std_map.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Count(key_type val)"NC<<std::endl<<std::endl;

        std::cout<<"std_map.count(roger): "<<std_map.count("roger")<<std::endl;
        std::cout<<"std_map.count(not_present_key): "<<std_map.count("not_present_key")<<std::endl;
        std::cout<<std::endl;

        std::cout<<CYN"Operator []"NC<<std::endl<<std::endl;
        std::cout<<"std_map[yolo] "<<std_map["yolo"]<<std::endl;
        std::cout<<"std_map[not_present_key] "<<std_map["not_present_key"]<<" //not present so [] == insert(not_present_key, 0)"<<std::endl<<std::endl;

        std::cout<<CYN"Find()"NC<<std::endl<<std::endl;
        std::map<std::string, int>::iterator ret_find;
        std::map<std::string, int>::iterator const_ret_find;
        ret_find = std_map.find("not_present_key");
        std::cout<<"std_map.find(not_present_key): "<<ret_find->first<<" "<<ret_find->second<<std::endl;
        ret_find = std_map.find("pkevin");
         std::cout<<"std_map.find(pkevin): "<<ret_find->first<<" "<<ret_find->second<<std::endl<<std::endl;
        const_ret_find = std_map.find("not_present_key");
        std::cout<<"std_map.find(not_present_key): "<<const_ret_find->first<<" "<<const_ret_find->second<<std::endl;
        const_ret_find = std_map.find("pkevin");
        std::cout<<"std_map.find(pkevin): "<<const_ret_find->first<<" "<<const_ret_find->second<<std::endl<<std::endl;
        std::cout<<CYN"Get_allocator()"NC<<std::endl<<std::endl;

        std::pair<const std::string, int> *pair_tab;

        pair_tab = std_map.get_allocator().allocate(8);
        for (int i =0; i < 8; i++)
        {
            pair_tab[i].second = i;
        }
        std::cout<<"pair_tab: ";
        for (int i =0; i < 8; i++)
        {
            std::cout<<pair_tab[i].second<<" ";
        }
    
        std_map.get_allocator().deallocate(pair_tab, 8);
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Key_comp()"NC<<std::endl<<std::endl;

        std::map<std::string, int>::key_compare std_cmp = std_map.key_comp();

        std::string first_str = "Hey";
        std::string second_str = "Hah";

        std::cout<<"std_cmp(first_str, second_str): "<<std_cmp(first_str, second_str)<<std::endl;
        std::cout<<"std_cmp(second_str, first_str): "<<std_cmp(second_str, first_str);
    
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Value_comp()"NC<<std::endl<<std::endl;

        std::map<std::string, int>::value_compare std_val_cmp = std_map.value_comp();
        std::map<std::string, int>::iterator it1 = std_map.find("pkevin");
        std::map<std::string, int>::iterator it2 = std_map.find("yolo");

        std::cout<<"std_value_cmp(pkevin, yolo): "<<std_val_cmp(*it1, *it2)<<std::endl;
        std::cout<<"std_value_cmp(yolo, pkevin): "<<std_val_cmp(*it2, *it1)<<std::endl<<std::endl;

        std::cout<<"----------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"2"<<NC"]- Map iterator"<<std::endl<<std::endl;
		std::cout<<CYN"Map iterator && const_iterator"NC<<std::endl;

        std::map<std::string, int>::iterator ite = std_map.end();
        std::cout<<"std_map const_iterator: ";
        for (std::map<std::string, int>::iterator it = std_map.begin(); it != ite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::map<std::string, int>::const_iterator cite = std_map.end();
        std::cout<<"std_map iterator: ";
        for (std::map<std::string, int>::const_iterator it = std_map.begin(); it != cite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
		std::cout<<CYN"Map reverse iterator"NC<<std::endl;

        std::map<std::string, int>::reverse_iterator rite = std_map.rend();
        std::cout<<"std_map reverse_iterator: ";
        for (std::map<std::string, int>::reverse_iterator it = std_map.rbegin(); it != rite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::map<std::string, int>::const_reverse_iterator crite = std_map.rend();
        std::cout<<"std_map const_reverse_iterator: ";
        for (std::map<std::string, int>::const_reverse_iterator it = std_map.rbegin(); it != crite; it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
        
	}
	{
        std::cout<<"----------------------------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"3"<<NC"]- Map constructor and operator ="<<std::endl<<std::endl;
		std::map<std::string, std::string> std_map;
        std_map.insert(std::make_pair<std::string, std::string>("Salut", "cv?"));
        std_map.insert(std::make_pair<std::string, std::string>("Moi", "oui"));
        std_map.insert(std::make_pair<std::string, std::string>("Tant", "mieux"));
        std_map.insert(std::make_pair<std::string, std::string>("Super", "cool"));
        std_map.insert(std::make_pair<std::string, std::string>("Trop", "bien"));
		std::map<std::string, std::string> std_map_cpy(std_map);
		std::map<std::string, std::string> std_map_it(std_map.begin(), std_map.end());
		std::map<std::string, std::string> std_map_operator = std_map;

        std::cout<<"std_map "<<std_map.size()<< " "<<std_map.max_size()<<std::endl;
        std::cout<<"std_map_cpy "<<std_map_cpy.size()<< " "<<std_map_cpy.max_size()<<std::endl;
        std::cout<<"std_map_it "<<std_map_it.size()<< " "<<std_map_it.max_size()<<std::endl;
        std::cout<<"std_map_operator "<<std_map_operator.size()<< " "<<std_map_operator.max_size()<<std::endl<<std::endl;

        std::cout<<CYN"Erase(key_type const &value)"NC<<std::endl<<std::endl;

        std_map_it.erase("Tant");
        std::cout<<"std_map_it: ";
        for (std::map<std::string, std::string>::iterator it = std_map_it.begin(); it != std_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Swap()"NC<<std::endl<<std::endl;
        std::cout<<"std_map_cpy "<<std_map_cpy.size()<< " "<<std_map_cpy.max_size()<<std::endl;
        std::cout<<"std_map_it "<<std_map_it.size()<< " "<<std_map_it.max_size()<<std::endl;
        std::cout<<"std_map_it before: ";
        for (std::map<std::string, std::string>::iterator it = std_map_it.begin(); it != std_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::cout<<"std_map_cpy before: ";
        for (std::map<std::string, std::string>::iterator it = std_map_cpy.begin(); it != std_map_cpy.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";

        std::cout<<std::endl<<std::endl;
        std_map_it.swap(std_map_cpy);
        std::cout<<"std_map_cpy "<<std_map_cpy.size()<< " "<<std_map_cpy.max_size()<<std::endl;
        std::cout<<"std_map_it "<<std_map_it.size()<< " "<<std_map_it.max_size()<<std::endl;
        std::cout<<"std_map_it astder: ";
        for (std::map<std::string, std::string>::iterator it = std_map_it.begin(); it != std_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl;
        std::cout<<"std_map_cpy astder: ";
        for (std::map<std::string, std::string>::iterator it = std_map_cpy.begin(); it != std_map_cpy.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;
        std::cout<<CYN"Erase(InputIterator first, InputIterator last)"NC<<std::endl<<std::endl;
        std::map<std::string, std::string>::iterator itt = std_map_it.begin();
        std::map<std::string, std::string>::iterator itte = std_map_it.end();
        itt++;
        itte--;
        std_map_it.erase(itt, itte);
        std::cout<<"std_map_it: ";
        for (std::map<std::string, std::string>::iterator it = std_map_it.begin(); it != std_map_it.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";
        std::cout<<std::endl<<std::endl;

        std::cout<<CYN"Erase(iterator position)"NC<<std::endl;

        std_map_cpy.erase(std_map_cpy.begin());
        std::cout<<"std_map_cpy: ";
        for (std::map<std::string, std::string>::iterator it = std_map_cpy.begin(); it != std_map_cpy.end(); it++)
            std::cout<<"["<<it->first<<", "<<it->second<<"] ";

        std::cout<<std::endl<<std::endl;
        std::map<std::string, std::string>::iterator ret_it;
        std::map<std::string, std::string>::const_iterator const_ret_it;
        std::pair<std::map<std::string, std::string>::iterator, std::map<std::string, std::string>::iterator> ret_pair;
        std::pair<std::map<std::string, std::string>::const_iterator, std::map<std::string, std::string>::const_iterator> const_ret_pair;

        std::cout<<CYN"Lower_bound()"NC<<std::endl<<std::endl;

        std::cout<<CYN"Test with middle key"NC<<std::endl<<std::endl;

        ret_it = std_map.lower_bound("Super");
        const_ret_it = std_map.lower_bound("Super");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with smallest key"NC<<std::endl<<std::endl;

        ret_it = std_map.lower_bound("Moi");
        const_ret_it = std_map.lower_bound("Moi");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with biggest key"NC<<std::endl<<std::endl;

        ret_it = std_map.lower_bound("Tant");
        const_ret_it = std_map.lower_bound("Tant");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Upper_bound()"NC<<std::endl<<std::endl;

        std::cout<<CYN"Test with middle key"NC<<std::endl<<std::endl;

        ret_it = std_map.upper_bound("Super");
        const_ret_it = std_map.upper_bound("Super");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with smallest key"NC<<std::endl<<std::endl;

        ret_it = std_map.upper_bound("Moi");
        const_ret_it = std_map.upper_bound("Moi");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;

        std::cout<<CYN"Test with biggest key"NC<<std::endl<<std::endl;

        ret_it = std_map.upper_bound("Tant");
        const_ret_it = std_map.upper_bound("Tant");
        std::cout<<"ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl;
        std::cout<<"const_ret_it: "<<ret_it->first<<" "<<ret_it->second<<std::endl<<std::endl;
    
        std::cout<<CYN"Equal_range()"NC<<std::endl<<std::endl;

         std::cout<<CYN"Test with middle key"NC<<std::endl<<std::endl;

        ret_pair = std_map.equal_range("Super");
        const_ret_pair = std_map.equal_range("Super");
        std::cout<<"ret_pair: "<< ret_pair.first->first<< " "<< ret_pair.second->first<<std::endl;
        std::cout<<"const_ret_pair: "<< const_ret_pair.first->first<< " "<< const_ret_pair.second->first<<std::endl<<std::endl;

        std::cout<<CYN"Test with smallest key"NC<<std::endl<<std::endl;

        ret_pair = std_map.equal_range("Moi");
        const_ret_pair = std_map.equal_range("Moi");
        std::cout<<"ret_pair: "<< ret_pair.first->first<< " "<< ret_pair.second->first<<std::endl;
        std::cout<<"const_ret_pair: "<< const_ret_pair.first->first<< " "<< const_ret_pair.second->first<<std::endl<<std::endl;

        std::cout<<CYN"Test with biggest key"NC<<std::endl<<std::endl;

        ret_pair = std_map.equal_range("Tant");
        const_ret_pair = std_map.equal_range("Tant");
        std::cout<<"ret_pair: "<< ret_pair.first->first<< " "<< ret_pair.second->first<<std::endl;
        std::cout<<"const_ret_pair: "<< const_ret_pair.first->first<< " "<< const_ret_pair.second->first<<std::endl<<std::endl;
        std::cout<<CYN"Clear()"NC<<std::endl<<std::endl;
        std_map.clear();
        std::cout<<"std_map: "<<std_map.empty()<<std::endl<<std::endl;
	}
	{
        std::cout<<"-----------------------------------"<<std::endl;
		std::cout<<"[TEST "<<RD"4"<<NC"]- Map time exec"<<std::endl<<std::endl;
        std::map<int, int> std_map;
        std::cout<<CYN"Insert 1 000 000 element"NC<<std::endl;
        for (int i = 0; i < 1000000; i++)
            std_map.insert(std::make_pair<int, int>(i, i));
        std::cout<<CYN"End Insert"NC<<std::endl;
        std::cout<<CYN"insert(InputIterator first, InputIterator last)"NC<<std::endl;
        std::map<int, int> std_map_cpy;
        std_map_cpy.insert(std_map.begin(), std_map.end());
        std::cout<<CYN"End Insert"NC<<std::endl;
	}

    return 0;
}

