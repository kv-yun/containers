#include "map.hpp"
#include <iostream>

/* Constructors */

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map(key_compare const &cmp, allocator_type const &alloc)
{
	this->allocator = alloc;
	this->m_cmp = cmp;
	this->m_size = 0;
	this->m_null_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_null_node->data, value_type());
	this->m_null_node->color = BLACK;
	this->m_null_node->right = NULL;
	this->m_null_node->left = NULL;
	this->m_null_node->parent = NULL;
	this->m_null_node->is_null = 1;
	this->m_root_node = this->m_null_node;

	this->m_end_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_end_node->data, value_type());
	this->m_end_node->color = 3;
	this->m_end_node->right = NULL;
	this->m_end_node->left = NULL;
	this->m_end_node->is_null = 0;
	this->m_end_node->parent = this->m_root_node;

	this->m_begin_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_begin_node->data, value_type());
	this->m_begin_node->color = 3;
	this->m_begin_node->right = NULL;
	this->m_begin_node->left = NULL;
	this->m_begin_node->is_null = 0;
	this->m_begin_node->parent = this->m_root_node;
}

template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
ft::map<Key, T, Compare, Allocator>::map(InputIterator first, InputIterator last, key_compare const &cmp, allocator_type const &alloc)
{
	this->allocator = alloc;
	this->m_cmp = cmp;
	this->m_size = 0;
	this->m_null_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_null_node->data, value_type());
	this->m_null_node->color = BLACK;
	this->m_null_node->right = NULL;
	this->m_null_node->left = NULL;
	this->m_null_node->parent = NULL;
	this->m_null_node->is_null = 1;
	this->m_root_node = this->m_null_node;

	this->m_end_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_end_node->data, value_type());
	this->m_end_node->color = 3;
	this->m_end_node->right = NULL;
	this->m_end_node->left = NULL;
	this->m_end_node->is_null = 0;
	this->m_end_node->parent = this->m_root_node;

	this->m_begin_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_begin_node->data, value_type());
	this->m_begin_node->color = 3;
	this->m_begin_node->right = NULL;
	this->m_begin_node->left = NULL;
	this->m_begin_node->is_null = 0;
	this->m_begin_node->parent = this->m_root_node;

	insert(first, last);
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map(const map &cpy)
{
	this->allocator = cpy.allocator;
	this->m_cmp = cpy.m_cmp;
	this->m_size = 0;

	this->m_null_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_null_node->data, value_type());
	this->m_null_node->color = BLACK;
	this->m_null_node->right = NULL;
	this->m_null_node->left = NULL;
	this->m_null_node->parent = NULL;
	this->m_null_node->is_null = 1;
	this->m_root_node = this->m_null_node;

	this->m_end_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_end_node->data, value_type());
	this->m_end_node->color = 3;
	this->m_end_node->right = NULL;
	this->m_end_node->left = NULL;
	this->m_end_node->is_null = 0;
	this->m_end_node->parent = this->m_root_node;

	this->m_begin_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_begin_node->data, value_type());
	this->m_begin_node->color = 3;
	this->m_begin_node->right = NULL;
	this->m_begin_node->left = NULL;
	this->m_begin_node->is_null = 0;
	this->m_begin_node->parent = this->m_root_node;

	if (cpy.m_root_node != cpy.m_null_node)
		insert(cpy.begin(), cpy.end());
}

/* Destructor */
template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::~map(void)
{
	this->clear();
	this->allocator.destroy(&this->m_null_node->data);
	this->allocator.destroy(&this->m_end_node->data);
	this->allocator.destroy(&this->m_begin_node->data);
	this->node_allocator.deallocate(this->m_null_node, 1);
	this->node_allocator.deallocate(this->m_end_node, 1);
	this->node_allocator.deallocate(this->m_begin_node, 1);
}

/* Overload operator = */

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>	&ft::map<Key, T, Compare, Allocator>::operator = (map const &old)
{
	this->allocator = old.allocator;
	this->m_cmp = old.cmp;
	this->m_size = 0;
	this->m_null_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_null_node->data, value_type());
	this->m_null_node->color = BLACK;
	this->m_null_node->right = NULL;
	this->m_null_node->left = NULL;
	this->m_null_node->parent = NULL;
	this->m_null_node->is_null = 1;
	this->m_root_node = this->m_null_node;

	this->m_end_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_end_node->data, value_type());
	this->m_end_node->color = 3;
	this->m_end_node->right = NULL;
	this->m_end_node->left = NULL;
	this->m_end_node->is_null = 0;
	this->m_end_node->parent = this->m_root_node;

	this->m_begin_node = this->node_allocator.allocate(1);
	this->allocator.construct(&this->m_begin_node->data, value_type());
	this->m_begin_node->color = 3;
	this->m_begin_node->right = NULL;
	this->m_begin_node->left = NULL;
	this->m_begin_node->is_null = 0;
	this->m_begin_node->parent = this->m_root_node;

	if (old.m_root_node != old.m_null_node)
		insert(old.begin(), old.end());
}

/*----------*/
/* Capacity */
/*----------*/

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::size(void) const
{
	return this->m_size;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::max_size(void) const
{
	return this->node_allocator.max_size();
}

template <class Key, class T, class Compare, class Allocator>
bool	ft::map<Key, T, Compare, Allocator>::empty(void) const
{
	if (this->m_size == 0)
		return true;
	return false;
}

/*---------------*/
/* Element Access*/
/*---------------*/

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::mapped_type &ft::map<Key, T, Compare, Allocator>::operator [] (key_type const &k)
{
	return (*((this->insert(ft::make_pair(k,mapped_type()))).first)).second;
}

/*-----------*/
/* Modifiers */
/*-----------*/

/* insert */
template< class Key, class T, class Compare, class Allocator >
ft::pair<typename ft::map<Key, T, Compare, Allocator>::iterator, bool>	ft::map<Key, T, Compare, Allocator>::insert(value_type const &val)
{
	ft::pair<iterator, bool> ret;
	node_type *node;

	node = this->node_allocator.allocate(1);
	this->allocator.construct(&node->data, val);
	node->parent = NULL;
	node->left = this->m_null_node;
	node->right = this->m_null_node;
	node->color = RED;
	node->is_null = 0;

	node_type *root_node = this->m_root_node;
	node_type *path_node = NULL;
	replace_end_node();
	if (this->m_size > 0)
	{
		while (root_node != this->m_null_node)
		{
			path_node = root_node;
			if (this->m_cmp(node->data.first, root_node->data.first))
			{
				root_node = root_node->left;
			}
			else if (this->m_cmp(root_node->data.first, node->data.first))
			{
				root_node = root_node->right;
			}
			else
			{
				this->allocator.destroy(&node->data);
				this->node_allocator.deallocate(node, 1);
				setup_end_node();
				return ft::make_pair<iterator, bool>(iterator(path_node), false);
			}
		}
	}
	else
		path_node = root_node;
	if (path_node == this->m_null_node)
	{
		this->m_root_node = node;
		node->parent = NULL;
	}
	else if (this->m_cmp(node->data.first, path_node->data.first))
	{
		node->parent = path_node;
		path_node->left = node;
	}
	else
	{
		node->parent = path_node;
		path_node->right = node;
	}
	this->m_size++;
	if (node->parent == NULL)		// If node is root, return
	{
		node->color = BLACK;
		setup_end_node();
		return ft::make_pair<iterator, bool>(iterator(node), true);
	}
	if (node->parent->parent == NULL)	// If node grand parent is root, reutrn
	{
		setup_end_node();
		return ft::make_pair<iterator, bool>(iterator(node), true);
	}
	ret =  ft::make_pair<iterator, bool>(iterator(node), true);
	equilibrate_rbt(node);
	setup_end_node();
	return ret;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::insert(iterator position, value_type const &val)
{
	(void)position;
	return (insert(val).first);
}

template <class Key, class T, class Compare, class Allocator>
template <class InputIterator>
void	ft::map<Key, T, Compare, Allocator>::insert(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		insert(*first);
		first++;
	}
}

/* erase */
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::erase(key_type const &val)
{
	return delete_node(this->m_root_node ,val);
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator pos)
{
	delete_node(this->m_root_node, pos->first);
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::erase(iterator first, iterator last)
{
	iterator save;

	save = first;
	while (first != last)
	{
		save++;
		delete_node(this->m_root_node, first->first);
		first = save;
	}
}
/* swap */
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::swap(map &x)
{
	swap_map(this->m_root_node, x.m_root_node);
	swap_map(this->m_end_node, x.m_end_node);
	swap_map(this->m_begin_node, x.m_begin_node);
	swap_map(this->m_null_node, x.m_null_node);
	swap_map(this->m_cmp, x.m_cmp);
	swap_map(this->allocator, x.allocator);
	swap_map(this->m_size, x.m_size);
}

template <class Key, class T, class Compare, class Allocator>
template <class X>
void	ft::map<Key, T, Compare, Allocator>::swap_map(X &x, X &y)
{
	X	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

/* clear */
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::clear(void)
{
	if (!(this->empty()))
		erase(this->begin(), this->end());
}

/*-----------*/
/* Observers */
/*-----------*/
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::key_compare	ft::map<Key, T, Compare, Allocator>::key_comp(void) const
{
	return key_compare();
}
//Value comp

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::value_compare ft::map<Key, T, Compare, Allocator>::value_comp(void) const
{
	return value_compare(key_compare());
}
/*------------*/
/* Operations */
/*------------*/

/* find */
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator ft::map<Key, T, Compare, Allocator>::find(key_type const &k)
{
	node_type	*node;

	node = this->m_root_node;
	while (node->data.first != k && node != this->m_null_node)
	{
		if (this->m_cmp(k, node->data.first))
		{
			node = node->left;
		}
		else if (this->m_cmp(node->data.first, k))
		{
			node = node->right;
		}
		else
		{
			return iterator(node);
		}
	}
	return (iterator(node));
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator ft::map<Key, T, Compare, Allocator>::find(key_type const &k) const
{
	node_type	*node;

	node = this->m_root_node;
	while (node->data.first != k && node != this->m_null_node)
	{
		if (this->m_cmp(k, node->data.first))
		{
			node = node->left;
		}
		else if (this->m_cmp(node->data.first, k))
		{
			node = node->right;
		}
		else
		{
			return iterator(node);
		}
	}
	return (iterator(node));
}

/* count */
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::count(key_type const &k) const
{
	const_iterator ite = end();
	for (const_iterator it = begin(); it != ite; it++)
	{
		if (it->first == k)
			return 1;
	}
	return 0;
}

/* lower_bound */
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(key_type const &k)
{
	iterator	ite = end();
	iterator	ret(find_min_node(this->m_root_node));

	while (ret != ite && ret->first < k)
		ret++;
	if (ret == ite)
		return iterator(NULL);
	return ret;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::lower_bound(key_type const &k) const
{
	const_iterator	ite = end();
	const_iterator	ret(find_min_node(this->m_root_node));

	while (ret != ite && ret->first < k)
		ret++;
	if (ret == ite)
		return const_iterator(NULL);
	return ret;
}

/* upper_bound */
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(key_type const &k)
{
	iterator	ite = iterator(this->m_begin_node);
	iterator	ret = iterator(find_max_node(this->m_root_node));

	if (ret->first <= k)
		return iterator(NULL);
	while (ret != ite && ret->first > k)
		ret--;
	ret++;
	return ret;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::upper_bound(key_type const &k) const
{
	iterator	ite = const_iterator(this->m_begin_node);
	iterator	ret = const_iterator(find_max_node(this->m_root_node));

	if (ret->first <= k)
		return const_iterator(NULL);
	while (ret != ite && ret->first > k)
		ret--;
	ret++;
	return ret;
}

/* equal range */
template <class K, class T, class C, class A>
ft::pair<typename ft::map<K, T, C, A>::const_iterator, typename ft::map<K, T, C, A>::const_iterator>	ft::map<K, T, C, A>::equal_range(key_type const &k) const
{
	const_iterator	first;
	const_iterator	second;
	
	first = lower_bound(k);
	second = upper_bound(k);
	return	ft::make_pair<const_iterator, const_iterator>(first, second);
}

template <class K, class T, class C, class A>
ft::pair<typename ft::map<K, T, C, A>::iterator, typename ft::map<K, T, C, A>::iterator>	ft::map<K, T, C, A>::equal_range(key_type const &k)
{
	iterator	first;
	iterator	second;
	
	first = lower_bound(k);
	second = upper_bound(k);
	return	ft::make_pair<iterator, iterator>(first, second);
}

/* Allocator */
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::allocator_type	ft::map<Key, T, Compare, Allocator>::get_allocator(void) const
{
	return this->allocator;
}

/*---------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------*/
/* Private Functions */
/*-------------------*/


/* RBT Functions */

/* Rotate */

/* Left */
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::left_rotate(node_type *node)
{
	node_type *ptr;

	ptr = node->right;
	node->right = ptr->left;
	if (ptr->left != this->m_null_node)
		ptr->left->parent = node;
	ptr->parent = node->parent;
	if (node->parent == NULL)
		this->m_root_node = ptr;
	else if (node == node->parent->left)
		node->parent->left = ptr;
	else
		node->parent->right = ptr;
	ptr->left = node;
	node->parent = ptr;
}

/* Right */
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::right_rotate(node_type *node)
{
	node_type *ptr;

	ptr = node->left;
	node->left = ptr->right;
	if (ptr->right != this->m_null_node) 
		ptr->right->parent = node;
	ptr->parent = node->parent;
	if (node->parent == NULL)
		this->m_root_node = ptr;
	else if (node == node->parent->right)
		node->parent->right = ptr;
	else
		node->parent->left = ptr;
	ptr->right = node;
	node->parent = ptr;
}

/* Help */
template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::set_parents(node_type *x, node_type *y)
{
	if (x->parent == NULL)
		this->m_root_node = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->parent = x->parent;
}

/* Find */
// Min
template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::node_type *ft::map<Key, T, Compare, Allocator>::find_min_node(node_type *node)
{
	while (node->left != this->m_null_node && node->left != this->m_begin_node)
		node = node->left;
	return node;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::node_type *ft::map<Key, T, Compare, Allocator>::find_min_node(node_type *node) const
{
	while (node->left != this->m_null_node && node->left != this->m_begin_node)
		node = node->left;
	return node;
}

//Max
template<class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::node_type *ft::map<Key, T, Compare, Allocator>::find_max_node(node_type *node)
{
	while (node->right != this->m_null_node && node->right != this->m_end_node)
		node = node->right;
	return node;
}

template<class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::node_type *ft::map<Key, T, Compare, Allocator>::find_max_node(node_type *node) const
{
	while (node->right != this->m_null_node && node->right != this->m_end_node)
		node = node->right;
	return node;
}

/* Equilibrate */

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::equilibrate_rbt(node_type *node)
{
	node_type *ptr;

	while (node->parent->color == 1)			// While node->parent->color is RED
	{
		if (node->parent == node->parent->parent->right)
		{
			ptr = node->parent->parent->left;
			if (ptr->color == 1)
			{
				ptr->color = BLACK;
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					right_rotate(node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				left_rotate(node->parent->parent);
			}
		}
		else
		{
			ptr = node->parent->parent->right;
			if (ptr->color == 1)
			{
				ptr->color = BLACK;
				node->parent->color = BLACK
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					left_rotate(node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				right_rotate(node->parent->parent);
			}
		}
		if (node == this->m_root_node)
			break;
	}
	this->m_root_node->color = BLACK;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::equilibrate_delete_rbt(node_type *node)
{
	node_type *s;

	while (node != this->m_root_node && node->color == 0)
	{
		if (node == node->parent->left)
		{
			s = node->parent->right;
			if (s->color == 1)
			{
				s->color = BLACK;
				node->parent->color = RED;
				left_rotate(node->parent);
				s = node->parent->right;
			}
			if (s->left->color == 0 && s->right->color == 0)
			{
				s->color = RED;
				node = node->parent;
			}
			else
			{
				if (s->right->color == 0)
				{
					s->left->color = BLACK;
					s->color = RED;
					right_rotate(s);
					s = node->parent->right;
				}
				s->color = node->parent->color;
				node->parent->color = BLACK;
				s->right->color = BLACK;
				left_rotate(node->parent);
				node = this->m_root_node;
			}
		}
		else
		{
			s = node->parent->left;
			if (s->color == 1)
			{
				s->color = BLACK;
				node->parent->color = RED;
				right_rotate(node->parent);
				s = node->parent->left;
			}
			if (s->right->color == 0 && s->right->color == 0)
			{
				s->color = RED;
				node = node->parent;
			}
			else
			{
				if (s->left->color == 0)
				{
					s->right->color = BLACK;
					s->color = RED;
					left_rotate(s);
					s = node->parent->left;
				}
				s->color = node->parent->color;
				node->parent->color = BLACK;
				s->left->color = BLACK;
				right_rotate(node->parent);
				node = this->m_root_node;
			}
		}
	}
	node->color = BLACK;
}

/* Erase */

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::size_type	ft::map<Key, T, Compare, Allocator>::delete_node(node_type *node_path, key_type const &val)
{
	node_type	*node;
	node_type	*x;
	node_type	*y;
	int		y_save_color;

	replace_end_node();
	node = this->m_null_node;
	while (node_path != this->m_null_node)
	{
		if (node_path->data.first == val)
			node = node_path;
		if (node_path->data.first <= val)
			node_path = node_path->right;
		else
			node_path = node_path->left;
	}

	if (node == this->m_null_node)
		return 0;
	y = node;
	y_save_color = y->color;
	if (node->left == this->m_null_node)
	{
		x = node->right;
		set_parents(node, node->right);
	}
	else if (node->right == this->m_null_node)
	{
		x = node->left;
		set_parents(node, node->left);
	}
	else
	{
		y = find_min_node(node->right);
		y_save_color = y->color;
		x = y->right;
		if (y->parent == node)
			x->parent = y;
		else
		{
			set_parents(y, y->right);
			y->right = node->right;
			y->right->parent = y;
		}
		set_parents(node, y);
		y->left = node->left;
		y->left->parent = y;
		y->color = node->color;
	}
	this->allocator.destroy(&node->data);
	this->node_allocator.deallocate(node, 1);
	if (y_save_color == 0)
		equilibrate_delete_rbt(x);
	this->m_size--;
	setup_end_node();
	return 1;
}

/* Setup end and begin node */

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::setup_end_node(void)
{
	node_type	*node_right;
	node_type	*node_left;

	node_right = find_max_node(this->m_root_node);
	node_left = find_min_node(this->m_root_node);
	node_right->right = this->m_end_node;
	node_left->left = this->m_begin_node;
	this->m_end_node->parent = node_right;
	this->m_begin_node->parent = node_left;
	this->m_end_node->color = 3;
	this->m_begin_node->color = 3;
}

template <class Key, class T, class Compare, class Allocator>
void	ft::map<Key, T, Compare, Allocator>::replace_end_node(void)
{
	this->m_end_node->parent->right = this->m_null_node;
	this->m_end_node->parent = NULL;
	this->m_begin_node->parent->left = this->m_null_node;
	this->m_begin_node->parent = NULL;
}
