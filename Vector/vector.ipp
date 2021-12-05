/*# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector.ipp                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yun <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 11:10:03 by yun               #+#    #+#              #
#    Updated: 2021/11/17 16:15:07 by yun              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #*/

#include "vector.hpp"

/*-------------*/
/* Constructor */
/*-------------*/

template < class T, class Allocator >
ft::vector<T, Allocator>::vector(allocator_type const &allocation)
{
	this->allocator = allocation;
	this->m_size = 0;
	this->m_capacity = 0;
	this->m_vector = NULL;
}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(size_type c, value_type const &val, allocator_type const &allocation)
{
	this->allocator = allocation;
	this->m_size = 0;
	this->m_capacity = c;
	/* Alloc Vector */
	this->m_vector = allocator.allocate(this->m_capacity);
	/* Add value in Vector */
	this->assign(c, val);
}

template <class T, class Allocator>
template <class InputIterator>
ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, allocator_type const &allocation)
{
	this->allocator = allocation;
	this->m_size = 0;
	this->m_capacity = last - first;
	this->m_vector = allocator.allocate(this->m_capacity);
	this->assign(first, last);
}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(ft::vector<T, Allocator> const &cpy)
{
	this->allocator = cpy.allocator;
	this->m_size = 0;
	this->m_capacity = cpy.m_size;
	this->m_vector = allocator.allocate(this->m_capacity);
	this->assign(cpy.begin(), cpy.end());
}

/* Destructor */

template <class T, class Allocator>
ft::vector<T, Allocator>::~vector(void)
{
	allocator.deallocate(this->m_vector, this->m_capacity);
}

/* Overload operator = */

template <class T, class Allocator>
ft::vector<T, Allocator>	&ft::vector<T, Allocator>::operator = (ft::vector<T, Allocator> const &old)
{
	this->allocator = old.allocator;
	this->m_size = 0;
	this->m_capacity = old.m_size;
	this->m_vector = allocator.allocate(this->m_capacity);
	this->assign(old.begin(), old.end());
	return *this;
}

/*----------*/
/* Capacity */
/*----------*/
template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::size(void) const { return this->m_size; }

template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::max_size(void) const { return this->allocator.max_size(); }

template<class T, class Allocator>
void	ft::vector<T, Allocator>::resize(size_type n, value_type val)
{
	if (n > this->m_capacity)
		reserve(linux_new_capacity(n));
	if (n > this->m_size)
		for (size_type i = this->m_size; i < n; i++)
			push_back(val);
	else
		this->erase(this->begin() + n, this->end());
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::capacity(void) const { return this->m_capacity; }

template<class T, class Allocator>
bool	ft::vector<T, Allocator>::empty(void) const { return (this->m_size <= 0 ? true : false); }

template < class T, class Allocator >
void	ft::vector<T, Allocator>::reserve(size_type n)
{
	if (n > this->m_capacity)
	{
		if (n > this->max_size())
			throw std::bad_alloc();
		else
			this->realloc(n);
	}
}

/*----------------*/
/* Element access */
/*----------------*/

template <class T, class Allocator>
typename ft::vector<T, Allocator>::value_type &ft::vector<T, Allocator>::operator [] (size_type index)
{
	iterator it = this->begin();
	return (*(it + index));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::at(size_type index)
{
	if (index >= this->m_size || index < 0)
	{
		throw std::out_of_range("Out of range");
	}
	return (*(this->m_vector + index));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::at(size_type index) const
{
	if (index >= this->m_size || index < 0)
	{
		throw std::out_of_range("Out of range");
	}
	return (*(this->m_vector + index));
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::front(void) { return (this->at(0)); }

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::front(void) const { return (this->at(0)); }

template <class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::back(void) { return (this->at(this->m_size - 1)); }

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::back(void) const { return (this->at(this->m_size - 1)); }

/*-----------*/
/* Modifiers */
/*-----------*/

/* assign */
template < class T, class Allocator >
void	ft::vector<T, Allocator>::assign(size_type n, value_type const &val)
{
	this->resize(0);
	reserve(n);
	for (size_type i = 0; i < n; i++)
		push_back(val);
}

template <class T, class Allocator>
template <class InputIterator>
void	ft::vector<T, Allocator>::assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type*)
{
	size_type new_size = last - first;

	this->resize(0);
	if (new_size > this->m_capacity)
		reserve(new_capacity(new_size));
	while (first != last)
	{
		this->push_back(*first);
		first++;
	}
}

/* push_back */
template <class T, class Allocator>
void ft::vector<T, Allocator>::push_back(value_type const &val)
{
	if (this->m_size + 1 > this->m_capacity)
		this->reserve(new_capacity(this->m_size + 1));
	allocator.construct(&this->m_vector[this->m_size], val);	//Add val in end vector
	this->m_size++;							//Increase size vector
}

/* pop_back */
template < class T, class Allocator >
void ft::vector<T, Allocator>::pop_back(void) { this->erase(this->end()); }

/* insert */
template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::insert(iterator position, value_type const &val)
{
	size_type	index;

	index = position - this->begin();
	if (this->m_size == this->m_capacity)
		this->reserve(new_capacity(this->m_capacity + 1));

	for (size_type i = this->m_size ; i > index; i--)
		this->allocator.construct(&this->m_vector[i], this->m_vector[i - 1]);
	this->m_size++;
	this->allocator.construct(&this->m_vector[index], val);
	return (this->begin() + index);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::insert(iterator position, size_type n, value_type const &val)
{
	size_type	index;

	index = position - this->begin();
	if (this->m_size + n > this->m_capacity)
		this->reserve(this->m_size + n);
	this->m_size += n;
	for (size_type i = this->m_size - 1; i > index + n - 1; i--)
		this->allocator.construct(&this->m_vector[i], this->m_vector[i - n]);
	for (size_type i = index; i < n; i++)
		this->allocator.construct(&this->m_vector[i], val);
}

template <class T, class Allocator>
template <class InputIterator>
void	ft::vector<T, Allocator>::insert(iterator position ,InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type*)
{
	size_type range;
	size_type index;

	range = last - first;
	index = position - this->begin();
	if (range <= 0)
		return;
	if (this->m_size + range > this->m_capacity)
		this->reserve(new_capacity(this->m_size + range));
	for (size_type i = this->m_size + range; i >= range; i--)
		this->allocator.construct(&m_vector[i], m_vector[i - range]);
	this->m_size += range;
	for (size_type i = index; i < (index + range); ++i)
		m_vector[i] = *(first++);
}

/* erase */
template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase(iterator position)
{
	size_type n;

	n = position - begin();
	this->m_size--;
	for (size_type i = n; i < this->m_size; i++)
		this->allocator.construct(&this->m_vector[i], this->m_vector[i + 1]);
	return iterator(begin() + n);
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase(iterator first, iterator last)
{
	size_type index;
	size_type n;

	n = last - first;
	index = first - begin();
	this->m_size -= n;
	for (size_type i = index; i < this->m_size; i++)
		this->allocator.construct(&this->m_vector[i], this->m_vector[i + n]);
	return iterator(begin() + index);
}

/* swap */
template <class T, class Allocator>
void	ft::vector<T, Allocator>::swap(vector &v)
{
	value_type	*tmp_vector = this->m_vector;
	size_type	tmp_size = this->m_size;
	size_type	tmp_capacity = this->m_capacity;
	allocator_type	tmp_alloc = this->allocator;
	
	this->m_size = v.m_size;
	this->m_capacity = v.m_capacity;
	this->allocator = v.allocator;
	this->m_vector = v.m_vector;

	v.m_size = tmp_size;
	v.m_capacity = tmp_capacity;
	v.allocator = tmp_alloc;
	v.m_vector = tmp_vector;
}

/* clear */
template <class T, class Allocator>
void	ft::vector<T, Allocator>::clear(void)
{
	this->allocator.destroy(this->m_vector);
	this->m_size = 0;
}

/*-----------*/
/* Allocator */
/*-----------*/

template <class T, class Allocator>
typename ft::vector<T, Allocator>::allocator_type	ft::vector<T, Allocator>::get_allocator(void) const { return this->allocator; }

/*-----------------------------------------------------------------------------------------------------------------------------------*/
/* Private function */

template <class T, class Allocator>
void	ft::vector<T, Allocator>::realloc(size_type new_capacity)
{
	value_type	*new_vector;					//New Vector with new capacity

	new_vector = NULL;
	new_vector = allocator.allocate(new_capacity, &m_vector);			//Alloc memory to new vector
	for (size_type i = 0; i < this->m_size; i++)
		allocator.construct(&new_vector[i], m_vector[i]);	//Copy m_vector in new vector
	this->allocator.deallocate(this->m_vector, this->m_size);			//Free all m_vector
	this->m_vector = new_vector;
	this->m_capacity = new_capacity;
}

template <class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::new_capacity(size_type n)
{
	size_type	new_capacity;

	new_capacity = this->m_capacity;
	if (new_capacity == 0)
		new_capacity++;
	while (new_capacity < n)
		new_capacity = new_capacity * 2;
	return new_capacity;
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::linux_new_capacity(size_type n)
{
	size_type new_capacity;

	new_capacity = this->m_size;
	if (new_capacity < n)
		new_capacity = new_capacity * 2;
	if (new_capacity < n)
		new_capacity = n;
	return (new_capacity);
}
