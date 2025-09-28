/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:01:26 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/28 13:54:31 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <climits>

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
		void	addNumber(int* begin, int* end);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printSpan(bool sort) const;

		// exceptions
		class FullArrayException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class EmptyArrayException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class SingleArrayException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		unsigned int	_size;
		unsigned int	_stored;
		int*			_array;
};

#endif // #ifndef SPAN_CLASS_HPP
