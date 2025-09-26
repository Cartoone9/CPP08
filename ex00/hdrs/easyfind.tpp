/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:03:05 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 18:33:38 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <sstream>

class NotFoundContException : public std::exception
{
	public:
		// constructors - destructor
		NotFoundContException(int value)
			: _value(value)
		{
			std::ostringstream os;
			os << _value << " not found.";
			_msg = os.str();
		}
		virtual ~NotFoundContException() throw() {}

		// method
		virtual const char* what() const throw()
		{
			return (_msg.c_str());
		}

	private:
		std::string	_msg;
		int			_value;
};

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator it_begin = container.begin();
	typename T::iterator it_end = container.end();

	typename T::iterator it = std::find(it_begin, it_end, value);

	if (it == it_end)
		throw (NotFoundContException(value));
	else
		return (it);
}

#endif // #ifndef EASYFIND_TPP
