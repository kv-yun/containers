/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:54:38 by yun               #+#    #+#             */
/*   Updated: 2021/10/31 10:07:16 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../Map/RBT.hpp"
#include "../Tools/pair.hpp"
#include <iostream>
#include "iterator_traits.hpp"

namespace ft
{
	template <class Key, class T>
	class map_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef ft::pair<const Key, T>		value_type;
			typedef value_type			&reference;
			typedef value_type			*pointer;
			typedef std::ptrdiff_t			difference_type;
			typedef map_iterator<Key, T>			iterator;
			typedef map_iterator<const Key, T>	is_const_iterator;

		private:
			typedef Node<const Key, T>	node_type;
			node_type			*ptr;

		public:
			/* Constructors */
			map_iterator<Key, T>(void): ptr(NULL) {}
			map_iterator<Key, T>(node_type *node): ptr(node) {}
			map_iterator<Key, T>(map_iterator<Key, T> const &cpy) { ptr = cpy.ptr; }

			/* Destructor */
			~map_iterator<Key, T>(void) {}

			/* Overload operator = */
			map_iterator<Key, T>	&operator = (map_iterator<Key, T> const &old)
			{
				ptr = old.ptr;
				return *this;
			}

			/* Convert const */
			operator is_const_iterator() const
			{
				return is_const_iterator(this->ptr);
			}

			/* Operator * && -> */
			reference	operator * (void) const
			{
				return (this->ptr->data);
			}

			pointer		operator-> (void) const
			{
				return (&this->ptr->data);
			}

			/* Increment operator */

			map_iterator<Key, T> &operator ++ (void)	//++it
			{
				node_type	*p;

				if (ptr->right && ptr->right->color == 3)
				{
					this->ptr  = ptr->right;
					return *this;
				}
				if (!is_null_node(ptr->right))
				{
					return minimum(ptr->right);
				}
				p = ptr->parent;
				while (!is_null_node(p) && p->color != 3 && this->ptr == p->right)
				{
					this->ptr = p;
					p = p->parent;
				}
				this->ptr = p;
                return *this;
			}

			map_iterator<Key, T> &operator -- (void)	//--it
			{
				node_type	*p;

				if (ptr->left && ptr->left->color == 3)
				{
					this->ptr = ptr->left;
					return *this;
				}
				if (!is_null_node(ptr->left))
				{
					return maximum(ptr->left);
				}
				p = this->ptr->parent;
				while (!(is_null_node(p)) && p->color !=3 && this->ptr == p->left)
				{
					this->ptr = p;
					p = p->parent;
				}
				this->ptr = p;
				return *this;
			}

			map_iterator<Key, T> operator ++ (int)		//it++;
			{
				node_type	*p;

				if (ptr->right && ptr->right->color == 3)
				{
					this->ptr  = ptr->right;
					return *this;
				}
				if (!is_null_node(ptr->right))
				{
					return minimum(ptr->right);
				}
				p = ptr->parent;
				while (!is_null_node(p) && p->color != 3 && this->ptr == p->right)
				{
					this->ptr = p;
					p = p->parent;
				}
				this->ptr = p;
                return *this;
			}

			map_iterator<Key, T> operator -- (int)		//it--
			{
				node_type	*p;

				if (ptr->left && ptr->left->color == 3)
				{
					this->ptr = ptr->left;
					return *this;
				}
				if (!is_null_node(ptr->left))
				{
					return maximum(ptr->left);
				}
				p = this->ptr->parent;
				while (!(is_null_node(p)) && p->color !=3 && this->ptr == p->left)
				{
					this->ptr = p;
					p = p->parent;
				}
				this->ptr = p;
				return *this;
			}

			/* Comparator operator */

			bool	operator == (map_iterator<Key, T> const &cmp)
			{
				return (this->ptr == cmp.ptr);
			}

			bool	operator != (map_iterator<Key, T> const &cmp)
			{
				return (this->ptr != cmp.ptr);
			}


		private:
			map_iterator<Key, T>	&minimum(node_type *node)
			{
				while (!(is_null_node(node->left)) && node->left->color != 3)
					node = node->left;
				this->ptr = node;
				return *this;
			}

			map_iterator<Key, T>	&maximum(node_type *node)
			{
				while (!(is_null_node(node->right)) && node->right->color != 3)
					node = node->right;
				this->ptr = node;
				return *this;
			}

			bool	is_null_node(node_type *node)
			{
				if (node == NULL || node->is_null == 1)
					return true;
				return false;
			}


	};

}

#endif
