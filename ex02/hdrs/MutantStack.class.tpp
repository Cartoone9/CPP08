/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.class.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:07:53 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/28 14:23:11 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_CLASS_TPP
#define MUTANTSTACK_CLASS_TPP

#include <iostream>
#include <vector>

template <typename T, typename C = std::vector<T>>
class MutantStack
{
	public:
		// constructors - destructors
		MutantStack();
		MutantStack(const MutantStack& old_obj);
		MutantStack& operator=(const MutantStack& old_obj);
		~MutantStack();

		// methods
		bool		empty() const;
		std::size_t	size() const;
		T&			top() const;
		void		push(const T& value);
		// void		emplace(std::string arg); // TODO
		void		pop();
		void		swap(MutantStack& other_obj);

		// getters - setters

	private:
		C	_container;
		
};

#endif // MUTANTSTACK_CLASS_TPP

#include "MutantStack.class.cpp"
