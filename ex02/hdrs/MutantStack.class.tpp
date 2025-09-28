/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.class.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:07:53 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/28 16:35:08 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_TPP
#define MUTANTSTACK_CLASS_TPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		// constructors - destructors
		MutantStack();
		MutantStack(const MutantStack& old_obj);
		MutantStack& operator=(const MutantStack& old_obj);
		~MutantStack();

		// iterators 
		typedef typename std::stack<T>::container_type container;

		typedef typename container::iterator iterator;
		typedef typename container::const_iterator const_iterator;
		typedef typename container::reverse_iterator reverse_iterator;
		typedef typename container::const_reverse_iterator const_reverse_iterator;

		iterator				begin();
		const_iterator			begin() const;

		iterator				end();
		const_iterator			end() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;

		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

	private:
};

#endif // MUTANTSTACK_CLASS_TPP


// ----------------------------------------
// constructors / destructors -------------

	template <typename T>
MutantStack<T>::MutantStack()
{
	// std::cout << "MutantStack default constructor called" << std::endl;
}

	template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& old_obj)
	: std::stack<T>(old_obj)
{
	// std::cout << "MutantStack copy constructor called" << std::endl;
}

	template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& old_obj)
{
	// std::cout << "MutantStack assignement operator called" << std::endl;

	if (this != &old_obj)
	{
		std::stack<T>::operator=(old_obj);
	}
	return (*this);
}

	template <typename T>
MutantStack<T>::~MutantStack()
{
	// std::cout << "MutantStack destructor called" << std::endl;
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// iterators ------------------------------

	template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const
{
	return (this->c.begin());
}

	template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const
{
	return (this->c.end());
}

	template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

	template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend()
{
	return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend() const
{
	return (this->c.rend());
}

// iterators ------------------------------
// ----------------------------------------
