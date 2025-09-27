/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:01:26 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/27 17:20:40 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <exception>
#include <iostream>

class Span
{
	public:
		// constructors - destructors
		Span();
		Span(unsigned int N);
		Span(const Span& old_obj);
		Span& operator=(const Span& old_obj);
		~Span();

		// methods
		void	addNumber(int value);

		// exceptions
		class FullArrayException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		unsigned int	_size;
		unsigned int	_stored;
		int*			_array;
};

#endif // #ifndef SPAN_CLASS_HPP
