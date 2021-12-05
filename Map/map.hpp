/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:50:51 by yun               #+#    #+#             */
/*   Updated: 2021/11/03 14:56:27 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "RBT.hpp"
#include <cstddef>
#include <functional>
#include "../Tools/pair.hpp"
#include "../Iterators/map_iterator.hpp"
#include "../Iterators/reverse_iterator.hpp"

namespace ft
{

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			/* Container Caracteristique */
			typedef Key						key_type;
			typedef T						mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef std::ptrdiff_t					difference_type;
			typedef Compare						key_compare;
			typedef Allocator					allocator_type;
			typedef typename allocator_type::size_type		size_type;
			typedef typename allocator_type::reference		reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer		pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			/* Map Iterators */
			typedef map_iterator<Key, T>				iterator;
			typedef map_iterator<const Key, T>			const_iterator;
			typedef reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef reverse_iterator<iterator>			reverse_iterator;

			/* Constructors */
			explicit map(key_compare const &cmp = key_compare(), allocator_type const &alloc = allocator_type());

			template <class InputIterator>
			map(InputIterator first, InputIterator last, key_compare const &cmp = key_compare(), allocator_type const &alloc = allocator_type());
			map(const map &cpy);

			/* Destructor */
			~map<Key, T, Compare, Allocator>(void);

			/* Overload operator = */
			map	&operator = (map const &old);

			/* Iterators Functions */
			iterator					begin(void);
			iterator					end(void);
			const_iterator				begin(void) const;
			const_iterator				end(void) const;
			reverse_iterator			rbegin(void);
			reverse_iterator			rend(void);
			const_reverse_iterator		rbegin(void) const;
			const_reverse_iterator		rend(void) const;

			/* Capacity */
			size_type					size(void) const;
			size_type					max_size(void) const;
			bool						empty(void) const;

			/* Element Access */
			mapped_type &operator [] (key_type const &k);

			/* Modifiers */
			/* insert */
			ft::pair<iterator, bool>	insert(value_type const &value);
			iterator					insert(iterator position, value_type const &val);
			template <class InputIterator>
			void						insert(InputIterator first, InputIterator last);
			/* erase */
			size_type					erase(key_type const &val);
			void						erase(iterator pos);
			void						erase(iterator first, iterator last);
			/* swap */
			void						swap(map &x);
			/* clear */
			void						clear(void);

			/* Observers */
			key_compare					key_comp(void) const;
			/* Value comp */
			class value_compare
			{
				friend class map;

				protected:
					Compare comp;
					value_compare(Compare c): comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator () (value_type const &x, value_type const &y) const
					{
						return comp(x.first, y.first);
					}
			};
			value_compare				value_comp(void) const;

			/* Operations */
			/* find */
			iterator					find(key_type const &k);
			const_iterator				find(key_type const &k) const;
			/* count */
			size_type					count(key_type const &k) const;
			/* lower bound */
			iterator					lower_bound(key_type const &k);
			const_iterator				lower_bound(key_type const &k) const;
			/* upper bound */
			iterator					upper_bound(key_type const &k);
			const_iterator				upper_bound(key_type const &k) const;
			/* equal range */
			ft::pair<const_iterator, const_iterator>	equal_range(key_type const &k) const;
			ft::pair<iterator, iterator>				equal_range(key_type const &k);

			/* Allocator */
			allocator_type				get_allocator(void) const;
			
		private:
			typedef Node<const Key, T>	node_type;
			node_type			*m_root_node;	//map
			node_type			*m_end_node;
			node_type			*m_begin_node;
			node_type			*m_null_node;	//null node
			size_type			m_size;
			key_compare			m_cmp;
			allocator_type			allocator;
			std::allocator<node_type>	node_allocator;

			/* BST Functions */

			/* Rotate */
			void	left_rotate(node_type *node);
			void	right_rotate(node_type *node);
			/* Help */
			void	set_parents(node_type *x, node_type *y);
			/* Find */
			node_type	*find_min_node(node_type *node);
			node_type	*find_max_node(node_type *node);
			node_type	*find_min_node(node_type *node) const;
			node_type	*find_max_node(node_type *node) const;
			/* Equilibrate */
			void	equilibrate_rbt(node_type *node);
			void	equilibrate_delete_rbt(node_type *node);
			/* Erase */
			size_type	delete_node(node_type *node_path, key_type const &val);
			/* Modify end and begin node */
			void	setup_end_node(void);
			void	replace_end_node(void);
			/* Other */
			template <class X>
			void	swap_map(X &x, X &y);
	};
	
}

/* Include RBT Functions */

/* Include Map Functions */
#include "map.ipp"
/* Include Iterator Functions */
#include "map_iterator.ipp"

#endif
