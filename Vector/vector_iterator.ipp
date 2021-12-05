/* Iterator functions */

/* Iterator */

template < class T, class Allocator >
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::begin(void) const
{
	iterator it(this->m_vector);
	return it;
}

template < class T, class Allocator >
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::end(void) const
{
	iterator ite(&this->m_vector[m_size]);
	return ite;
}

/*template < class T, class Allocator >
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::cbegin(void) const
{
	const_iterator it(&this->m_vector[0]);
	return it;
}

template < class T, class Allocator >
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::cend(void) const
{
	const_iterator ite(&this->m_vector[m_size]);
	return ite;
}*/

/* Reverse Iterator */

template< class T, class Allocator >
typename ft::vector<T, Allocator>::reverse_iterator ft::vector<T, Allocator>::rbegin(void) const
{
	reverse_iterator it(&this->m_vector[this->m_size - 1]);
	return it;
}

template < class T, class Allocator >
typename ft::vector<T, Allocator>::reverse_iterator ft::vector<T, Allocator>::rend(void) const
{
	reverse_iterator ite(&this->m_vector[ - 1]);
	return ite;
}

/*template< class T, class Allocator >
typename ft::vector<T, Allocator>::const_reverse_iterator ft::vector<T, Allocator>::crbegin(void) const
{
	const_reverse_iterator it(&this->m_vector[this->m_size - 1]);
	return it;
}

template < class T, class Allocator >
typename ft::vector<T, Allocator>::const_reverse_iterator ft::vector<T, Allocator>::crend(void) const
{
	const_reverse_iterator ite(&this->m_vector[ - 1]);
	return ite;
}*/
