/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yun <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:44:55 by yun               #+#    #+#             */
/*   Updated: 2021/10/18 07:35:59 by yun              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{
	/* enable if */

	template <bool B, class T = void>
	struct enable_if
	{

	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	/* is integral */
	
	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};
	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<long int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<long long int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<short int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned short int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long long int>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};
	template <>
	struct is_integral<bool>
	{
	static const bool value = true;
	};

}

#endif
