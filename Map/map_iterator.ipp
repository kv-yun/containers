template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator	ft::map<Key, T, Compare, Allocator>::rbegin(void)
{
	reverse_iterator it(find_max_node(this->m_root_node));
	return it;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::reverse_iterator	ft::map<Key, T, Compare, Allocator>::rend(void)
{
	reverse_iterator ite(this->m_begin_node);
	return ite;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rbegin(void) const
{
	const_reverse_iterator it(find_max_node(this->m_root_node));
	return it;
}

template <class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_reverse_iterator	ft::map<Key, T, Compare, Allocator>::rend(void) const
{
	const_reverse_iterator ite(this->m_begin_node);
	return ite;
}

/* Iterator && Const Iterator */

template<class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::begin(void)
{
	iterator it(find_min_node(this->m_root_node));
	return it;
}

template<class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::iterator	ft::map<Key, T, Compare, Allocator>::end(void)
{
	iterator ite(this->m_end_node);
	return ite;
}

template<class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::begin(void) const
{
	const_iterator it(find_min_node(this->m_root_node));
	return it;
}

template<class Key, class T, class Compare, class Allocator>
typename ft::map<Key, T, Compare, Allocator>::const_iterator	ft::map<Key, T, Compare, Allocator>::end(void) const
{
	const_iterator ite(this->m_end_node);
	return ite;
}

/* Reverse Iterator && Const Reverse Iterator */
