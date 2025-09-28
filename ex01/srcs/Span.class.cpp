/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:03:41 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/28 13:54:23 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Span.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

Span::Span()
	: _size(0)
	, _stored(0)
	, _array(NULL)
{
	std::cout << "Span default constructor called." << std::endl;
}

Span::Span(unsigned int N)
	: _size(N)
	, _stored(0)
	, _array(N ? new int[N]() : NULL)
{
	std::cout << "Span size constructor called." << std::endl;
}

Span::Span(const Span& old_obj)
	: _size(old_obj._size)
	, _stored(old_obj._stored)
	, _array(old_obj._size ? new int[old_obj._size]() : NULL)
{
	std::cout << "Span copy constructor called." << std::endl;

	if (old_obj._size)
	{
		for (unsigned int i = 0; i < old_obj._size; i++)
			this->_array[i] = old_obj._array[i];
	}
}

Span&	Span::operator=(const Span& old_obj)
{
	std::cout << "Span assignement operator called." << std::endl;

	if (this != &old_obj)
	{
		this->_size = old_obj._size;
		this->_stored = old_obj._stored;

		if (this->_array)
		{
			delete[] (this->_array);
			this->_array = NULL;
		}

		if (this->_size)
		{
			this->_array = new int[this->_size];

			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = old_obj._array[i];
		}
	}

	return (*this);
}

Span::~Span()
{
	std::cout << "Span destructor called." << std::endl;

	if (_array)
		delete[] (_array);
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// methods --------------------------------

void	Span::addNumber(int value)
{
	if (_size == 0)
		throw (EmptyArrayException());
	if (_stored >= _size)
		throw (FullArrayException());

	std::cout << "Value (" << value 
		<< ") has been stored in array at index [" 
		<< _stored << "]" << std::endl;
	
	_array[_stored] = value;
	_stored++;
}

void	Span::addNumber(int* begin, int* end)
{
	if (std::distance(begin, end) > _size - _stored)
		throw (FullArrayException());

	while (begin != end)
	{
		_array[_stored] = *begin;
		_stored++;
		begin++;
	}
}

int		Span::shortestSpan() const
{
	if (_size == 0 || _stored == 0)
		throw (EmptyArrayException());
	if (_stored == 1)
		throw (SingleArrayException());

	int	copy_arr[_stored];
	for (std::size_t i = 0; i < _stored; i++)
		copy_arr[i] = this->_array[i];

	std::sort(copy_arr, &copy_arr[_stored]);

	long long	short_span = copy_arr[1] - copy_arr[0];
	long long	curr_span;

	for (unsigned int i = 1; i < _stored - 1; i++)
	{
		curr_span = copy_arr[i + 1] - copy_arr[i];
		if (curr_span < short_span)
			short_span = curr_span;
		if (short_span == 0)
			return (0);
	}

	if (short_span > INT_MAX)
		return (INT_MAX);
	else
		return (static_cast<int>(short_span));
}

int		Span::longestSpan() const
{
	if (_size == 0 || _stored == 0)
		throw (EmptyArrayException());
	if (_stored == 1)
		throw (SingleArrayException());

	int	smallest = _array[0];
	int	biggest = _array[0];

	for (unsigned int i = 1; i < _stored; i++)
	{
		if (_array[i] < smallest)
			smallest = _array[i];
		if (_array[i] > biggest)
			biggest = _array[i];
	}
	
	long long ret = static_cast<long long>(biggest - smallest);

	if (ret > INT_MAX)
		return (INT_MAX);
	else
		return (static_cast<int>(ret));
}

void	Span::printSpan(bool sort) const
{
	std::cout << UNDERLINE "Span values:" RESET << std::endl;

	int	copy_arr[_stored];
	for (std::size_t i = 0; i < _stored; i++)
		copy_arr[i] = this->_array[i];

	if (sort == true)
		std::sort(copy_arr, &copy_arr[_stored]);

	for (std::size_t i = 0; i < _stored; i++)
	{
		std::cout << copy_arr[i];

		if (i + 1 < _stored)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

// methods --------------------------------
// ----------------------------------------


// ----------------------------------------
// getters / setters ----------------------

// getters / setters ----------------------
// ----------------------------------------


// ----------------------------------------
// operators overload ---------------------

// operators overload ---------------------
// ----------------------------------------

// ----------------------------------------
// operators overload ---------------------

const char*	Span::FullArrayException::what() const throw()
{
	return ("Array is already full.");
}

const char*	Span::EmptyArrayException::what() const throw()
{
	return ("Array is empty.");
}

const char*	Span::SingleArrayException::what() const throw()
{
	return ("Array has a single value stored.");
}

// operators overload ---------------------
// ----------------------------------------
