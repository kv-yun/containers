/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:51:44 by yun               #+#    #+#             */
/*   Updated: 2021/10/29 06:44:23 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T											value_type;
			typedef Container									container_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;
		private:
			container_type	m_stack;
		public:
			/* Constructor */
			explicit stack(container_type const & v = container_type()) { this->m_stack = v; }
			stack(stack const &cpy) { *this = cpy; }

			/* Destructor */
			~stack(void) {}

			/* Overload Operator = */
			stack	&operator = (stack const &old)
			{
				this->m_stack = old.m_stack;
				return (*this);
			}

			/* Member function */
			bool		empty(void) const { return this->m_stack.empty(); }
			size_type	size(void) const { return this->m_stack.size(); }
			reference	top(void) { return this->m_stack.back(); }
			const_reference	const top(void) const { return this->m_stack.back(); }
			void		push(value_type const &val) { this->m_stack.push_back(val); }
			void		pop(void) { this->m_stack.pop_back(); }

			/* Non-member function overloads */
			friend bool	operator == (stack<T, Container> const &lhs, stack<T, Container> const &rhs)
			{
				return lhs.m_stack == rhs.m_stack;
			}
			friend bool	operator < (stack<T, Container> const &lhs, stack<T, Container> const &rhs)
			{
				return lhs.m_stack < rhs.m_stack;
			}
	};

	template <class T, class Container>
	bool	operator != (stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool	operator <= (stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		if (lhs == rhs || lhs < rhs)
			return true;
		return false;
	}

	template <class T, class Container>
	bool	operator > (stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (!(lhs <= rhs));
	}

	template <class T, class Container>
	bool	operator >= (stack<T, Container> const &lhs, stack<T, Container> const &rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif
