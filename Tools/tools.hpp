/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:45:19 by yun               #+#    #+#             */
/*   Updated: 2021/10/28 10:39:56 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_HPP
# define TOOLS_HPP

namespace ft
{
	/*-------*/
	/* Equal */
	/*-------*/

	/* equality */
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}
	/* preidcate */
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (pred(first1, first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	/*-------------------------*/
	/* Lexicographical_compare */
	/*-------------------------*/

	/* default */
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
 		while (first1!=last1)
		{
			if (first2 == last2 || *first2<*first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
  		return (first2!=last2);
	}

	/* custom */
	template <class InputIterator1, class InputIterator2, class Compare>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
 		while (first1!=last1)
		{
			if (first2 == last2 || *first2<*first1)
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
  		return (first2!=last2);
	}

}

#endif
