/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 04:11:36 by yun               #+#    #+#             */
/*   Updated: 2021/11/03 10:07:28 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class	reverse_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::difference_type		diff_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

		private:
			iterator_type	ptr;
		public:
			/* Constructor */
			reverse_iterator(): ptr(NULL) {}
			explicit reverse_iterator(iterator_type it): ptr(it) {};

			template <class U>
			reverse_iterator(reverse_iterator<U> const &u) { this->ptr = u.base(); }

			template <class U>
			reverse_iterator &operator = (reverse_iterator<U> const &u)
			{
				this->ptr = u.base();
				return *this;
			}

			iterator_type	base(void) const { return this->ptr; }

			reference			operator * () const
			{
				return this->ptr.operator*();
			}

			pointer				operator -> () const
			{
				return &this->operator * ();
			}

			reference			operator [] (diff_type n) const
			{
				return *(this->ptr - n);
			}

			reverse_iterator	&operator ++ ()
			{
				this->ptr.operator--();
				return *this;
			}

			reverse_iterator	operator ++ (int)
			{
				return reverse_iterator(this->ptr.operator--(0));
			}

			reverse_iterator	&operator -- ()
			{
				this->ptr.operator++();
				return *this;
			}

			reverse_iterator	operator -- (int)
			{
				return reverse_iterator(this->ptr.operator++(0));
			}

			reverse_iterator	&operator += (diff_type n)
			{
				this->ptr.operator-=(n);
				return *this;
			}

			reverse_iterator	&operator-=(diff_type n)
			{
				this->ptr.operator+=(n);
				return *this;
			}

			/* Operation + && - */

			reverse_iterator	operator + (diff_type n) const { return reverse_iterator(ptr - n); }
			reverse_iterator	operator - (diff_type n) const { return reverse_iterator(ptr + n); }

	};

			/* ==, !=, <>... operator */
			template <class Iterator>
			bool operator == (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() == rhs.base()); }
			template <class Iterator>
			bool operator != (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() != rhs.base()); }
			template <class Iterator>
			bool operator < (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() < rhs.base()); }
			template <class Iterator>
			bool operator > (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() > rhs.base()); }
			template <class Iterator>
			bool operator <= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() <= rhs.base()); }
			template <class Iterator>
			bool operator >= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() >= rhs.base()); }

			/* Operation + && - */
			template <class Iterator>
			reverse_iterator<Iterator>	operator + (typename reverse_iterator<Iterator>::diff_type n, const reverse_iterator<Iterator> &rev_it) { return reverse_iterator<Iterator>(rev_it.base() - n); }
	
			template <class Iterator>
			typename reverse_iterator<Iterator>::diff_type		operator - (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs) { return (lhs.base() - rhs.base()); }

}

#endif
