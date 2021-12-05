/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:49:51 by yun               #+#    #+#             */
/*   Updated: 2021/10/15 09:20:56 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include <iostream>

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			T1	first;
			T2	second;

			/* Constructors */
			pair(void): first(), second() {}
			pair(T1 const &f, T2 const &s): first(f), second(s) {}
			template <class T1_cpy, class T2_cpy>
			pair<T1, T2>(pair<T1_cpy, T2_cpy> const &cpy): first(cpy.first), second(cpy.second) {}
			pair(pair const &cpy): first(cpy.first), second(cpy.second) {}
			/* Destructor*/
			~pair<T1, T2>(void) {}
			/* Operators */
			template <class T1_cpy, class T2_cpy>
			pair<T1, T2>	&operator = (pair<T1_cpy, T2_cpy> const &cpy)
			{
				first = cpy.first;
				second = cpy.second;
				return *this;
			}
			/* Comparator */
			bool	operator == (pair const &cmp) const
			{
				if (first == cmp.first && second == cmp.second)
					return true;
				return false;
			}
			bool	operator != (pair const &cmp) const
			{
				if (first != cmp.first || second != cmp.second)
					return true;
				return false;
			}
			bool	operator <= (pair const &cmp) const
			{
				return !(*this > cmp);
			}
			bool	operator >= (pair const &cmp) const
			{
				return !(*this < cmp);
			}
			bool	operator > (pair const &cmp) const
			{
				if (first > cmp.first)
					return true;
				else if (cmp.first > first)
					return false;
				else if (second > cmp.second)
					return true;
				return false;
			}
			bool	operator < (pair const &cmp) const
			{
				if (first < cmp.first)
					return true;
				else if (cmp.first < first)
					return false;
				else if (second < cmp.second)
					return true;
				return false;
			}
	};

	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 const first, T2 const second) { return ft::pair<T1, T2>(first, second); }
}

#endif
