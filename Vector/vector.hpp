/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:40:24 by yun               #+#    #+#             */
/*   Updated: 2021/11/15 12:54:53 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <cmath>
#include <algorithm>
#include "../Iterators/vector_iterator.hpp"
#include "../Iterators/reverse_iterator.hpp"
#include "../Tools/tools.hpp"
#include "../Tools/enable_if.hpp"

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			/* Container Caracteristique */
			typedef T						value_type;
			typedef Allocator					allocator_type;
			typedef typename allocator_type::size_type		size_type;
			typedef std::ptrdiff_t					difference_type;
			typedef typename allocator_type::reference 		reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			/* Vector Iterators */
			typedef vector_iterator<T>				iterator;
			typedef vector_iterator<const T>			const_iterator;
			typedef reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef reverse_iterator<iterator>			reverse_iterator;

			/* Constructors */
			vector<T, Allocator>(allocator_type const &allocation = allocator_type());
			vector<T, Allocator>(size_type n, value_type const &val = value_type(), allocator_type const &allocation = allocator_type());
			vector<T, Allocator>(ft::vector<T, Allocator> const &cpy);
			template <class InputIterator>
			vector<T, Allocator>(InputIterator first, InputIterator last, allocator_type const &allocation = allocator_type());
			/* Destructor */
			~vector<T, Allocator>();
			/* Overload Operator */
			ft::vector<T, Allocator>	&operator = (ft::vector<T, Allocator> const &old); //To do

			/* Iterators */
			iterator		begin(void) const;
			iterator		end(void) const;
			reverse_iterator	rbegin(void) const;
			reverse_iterator	rend(void) const;

			/* Capacity */
			size_type		size(void) const;
			size_type		max_size(void) const;
			void			resize(size_type n, value_type val = value_type()); //To do
			size_type		capacity(void) const;
			bool			empty(void) const;
			void			reserve(size_type n);

			/* Element access */
			value_type			&operator [] (size_type index);
			/* at */
			reference			at(size_type index);
			const_reference		at(size_type index) const;
			/* front */
			reference			front(void);
			const_reference		front(void) const;
			/* back */
			reference			back(void);
			const_reference		back(void) const;

			/* Modifiers */

			/* assign */
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0);
			void			assign(size_type n, value_type const & val);
			/* push_back */
			void			push_back(value_type const &value);
			/* pop_back */
			void			pop_back(void);
			/* insert */
			iterator		insert(iterator position, value_type const &value);
			void			insert(iterator position, size_type n, value_type const &value);
			template <class InputIterator>
			void			insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0);
			/* erase */
			iterator		erase(iterator position);
			iterator		erase(iterator first, iterator last);
			/* swap */
			void			swap(vector &v);
			/* clear */
			void			clear(void);

			/* Allocator */
			allocator_type	get_allocator(void) const;

		private:
			value_type		*m_vector;
			allocator_type		allocator; //Name to call allocator function
			size_type		m_size;
			size_type		m_max_size;
			size_type		m_capacity;

			/* Private function */
			void			realloc(size_type new_capacity); //realloc m_vector
			size_type		new_capacity(size_type n);	// change capacity
			size_type		linux_new_capacity(size_type n); //linux capacity fct
	};

	/* Non-member fuction overloads */

	/* relationnal operators */
	template <class T, class Alloc>
	bool	operator == (vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
	{
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool	operator != (vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator < (vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator <= (vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
	{
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool	operator > (vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	bool	operator >= (vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs)
	{
		return (!(lhs < rhs));
	}

	/* swap */
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}

/* Include Vector Functions */
#include "vector.ipp"
/* Include Iterator Functions */
#include "vector_iterator.ipp"

#endif
