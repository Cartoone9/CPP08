/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 18:35:52 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

#include "colors.hpp"
#include "easyfind.tpp"

template <typename T>
void	populateContainer(T& container, int *array, int ar_size)
{
	for (int i = 0; i < ar_size; i++)
		container.push_back(array[i]);
}

template <typename T>
void	testFind(T& container, int value, const std::string& name)
{
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "Value found in " << name << ": " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED "Error in " << name << ": " RESET << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << REVERSED TEAL "--- SUCCESSFUL TESTS ---\n" RESET << std::endl;

	std::vector<int> v_vect;
	int	arr1[] = {1, 9, 2, 8, 3, 7, 42};
	populateContainer(v_vect, arr1, sizeof(arr1) / sizeof(arr1[0]));

	std::list<int> v_list;
	int	arr2[] = {-12, 12, 42, -42};
	populateContainer(v_list, arr2, sizeof(arr2) / sizeof(arr2[0]));

	std::deque<int> v_deq;
	int	arr3[] = {42, 1, 2, 3, 123};
	populateContainer(v_deq, arr3, sizeof(arr3) / sizeof(arr3[0]));

	testFind(v_vect, 42, "vector");
	testFind(v_list, 42, "list");
	testFind(v_deq, 42, "deque");

	std::cout << REVERSED RED "\n--- FAILURE TESTS ---\n" RESET << std::endl;

	testFind(v_vect, 1234, "vector");
	testFind(v_list, 1234, "list");
	testFind(v_deq, 1234, "deque");

	return (0);
}
