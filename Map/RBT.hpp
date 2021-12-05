/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:06:36 by yun               #+#    #+#             */
/*   Updated: 2021/10/19 08:26:46 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include "../Tools/pair.hpp"

/* Define color value */

# define BLACK 0;
# define RED 1;

namespace ft
{
	template <class Key, class T>
	class Node
	{
		public:
			/* Variable */
			ft::pair<const Key, T>	data;
			Node			*parent;
			Node			*right;
			Node			*left;
			int			color;
			int			is_null;

			/* Constructor */
			Node<Key, T>(void)
			{
				parent = NULL;
				right = NULL;
				left = NULL;
				color = 0;
			}

			/* Destructor */
			~Node<Key, T>(void) {}

	};
}

#endif
