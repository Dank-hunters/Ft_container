/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:32:02 by frdescam          #+#    #+#             */
/*   Updated: 2022/11/03 14:44:56 by cguiot           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <class T1, class T2>
	struct pair {

		typedef T1 first_type;
		typedef T2 second_type;

		first_type 	first;
		second_type second;

		pair(void): first(), second()
		{
			/* NOP */
		}

		pair(const first_type& a, const second_type& b): first(a), second(b)
		{
			/* NOP */
		}

		template<class U, class V>
		pair(const pair<U,V> &pr): first(pr.first), second(pr.second)
		{
			/* NOP */
		}

		pair<T1,T2> &operator = (const pair<T1,T2> &other)
		{
			if (*this == other)
				return *this;
			this->first = other.first;
			this->second = other.second;
			return *this;
		}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return pair<T1,T2>(x,y);
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs > lhs;
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs < lhs;
	}
}

#endif

