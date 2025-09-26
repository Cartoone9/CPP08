/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:03:05 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 17:40:35 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("Value not found in container.");
	}
};

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator it_begin = container.begin();
	typename T::iterator it_end = container.end();

	typename T::iterator it = std::find(it_begin, it_end, value);

	if (it == it_end)
		throw (NotFoundException());
	else
		return (it);
}

#endif // #ifndef EASYFIND_TPP
