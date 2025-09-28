/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:22:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/28 14:22:14 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.class.hpp"

// ----------------------------------------
// constructors / destructors -------------

MutantStack::MutantStack()
{
	// std::cout << "MutantStack default constructor called" << std::endl;
}

MutantStack::MutantStack(const MutantStack& old_obj)
{
	// std::cout << "MutantStack copy constructor called" << std::endl;
}

MutantStack&	MutantStack::operator=(const MutantStack& old_obj)
{
	// std::cout << "MutantStack assignement operator called" << std::endl;

	if (this != &old_obj)
	{
			
	}
	return (*this);
}

MutantStack::~MutantStack()
{
	// std::cout << "MutantStack destructor called" << std::endl;
}

// constructors / destructors -------------
// ----------------------------------------


// ----------------------------------------
// methods --------------------------------

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
