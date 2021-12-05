/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:11:46 by yun               #+#    #+#             */
/*   Updated: 2021/11/04 09:54:59 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator
	{
		public:
			typedef std::random_access_iterator_tag	iterator_category;
			typedef T				value_type;
			typedef T				&reference;
			typedef T				*pointer;
			typedef std::ptrdiff_t			difference_type;
			typedef vector_iterator<T>		iterator;
			typedef vector_iterator<const T>	is_const_iterator;
		private:
			pointer ptr;
		public:
			/* Constructor */
			vector_iterator(void): ptr(NULL) {}
			vector_iterator(pointer value): ptr(value) {}
			vector_iterator(vector_iterator const &cpy): ptr(cpy.ptr) {}

			/* Destructor */
			~vector_iterator(void) {}

			/* Overload = operator */
			vector_iterator<value_type> &operator = (vector_iterator<value_type> const &old)
			{
				this->ptr = old.ptr;
				return (*this);
			}

			/* Convert const */

			operator is_const_iterator() const { return is_const_iterator(this->ptr); }

			/* Overload operator functions */

			/* Increment iterator */

			/* ++ operator */
			vector_iterator<T> &operator ++ (void)	//++it
			{
				ptr++;
				return (*this);
			}

			vector_iterator<T> operator ++ (int) //it++
			{
				vector_iterator<T> it = *this;
				ptr++;
				return (it);
			}

			/* -- operator */
			vector_iterator<T> &operator -- (void) //--it
			{
				ptr--;
				return (*this);
			}

			vector_iterator<T> operator -- (int) //it--
			{
				vector_iterator<T> it = *this;
				ptr--;
				return (it);
			}

			vector_iterator operator += (int n)	//it+=
			{
				for (int i =0; i < n; i++)
					ptr++;
				return *this;
			}

			vector_iterator operator -= (int n)	//it-=;
			{
				for (int i=0; i < n; i++)
						ptr--;
				return *this;
			}

			/* Comparaison iterator */

			/* ==, !=, <>... operator */
			bool operator == (const vector_iterator &rhs) { return (this->ptr == rhs.ptr); }
			bool operator != (const vector_iterator &rhs) { return (this->ptr != rhs.ptr); }
			bool operator < (const vector_iterator &rhs) { return (this->ptr < rhs.ptr); }
			bool operator > (const vector_iterator &rhs) { return (this->ptr > rhs.ptr); }
			bool operator <= (const vector_iterator &rhs) { return (this->ptr <= rhs.ptr); }
			bool operator >= (const vector_iterator &rhs) { return (this->ptr >= rhs.ptr); }


			/* Value iterator */

			/* '*' && []  && -> */
			reference operator * (void) const { return *(ptr); }
			reference operator [] (difference_type index) { return *(ptr + index); }
			pointer operator -> (void) const { return ptr; }

			/* Operation iterator */

			/* + operator */
			vector_iterator<T> operator + (int const n) const { return vector_iterator<value_type>(this->ptr + n); }
			friend vector_iterator<T> operator + (int n, vector_iterator<value_type> x) { return vector_iterator<value_type>(x.ptr + n); }
			/* - operator */
			vector_iterator<T> operator - (const difference_type &n) const { return vector_iterator<value_type>(this->ptr - n); }
			difference_type operator - (vector_iterator<value_type> const &x) const { return (this->ptr - x.ptr); }

	};

}

#endif
