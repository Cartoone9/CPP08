/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/26 18:01:42 by jramiro          ###   ########.fr       */
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

int	main(void)
{
	int	arr1[] = {1, 9, 2, 8, 3, 7, 42};
	std::vector<int> v_vect;
	populateContainer(v_vect, arr1, sizeof(arr1) / sizeof(arr1[0]));

	int	arr2[] = {-12, 12, 42, -42};
	std::list<int> v_list;
	populateContainer(v_list, arr2, sizeof(arr2) / sizeof(arr2[0]));

	int	arr3[] = {42, 1, 2, 3, 123};
	std::deque<int> v_deq;
	populateContainer(v_deq, arr3, sizeof(arr3) / sizeof(arr3[0]));

	try
	{
		std::vector<int>::iterator it_v = easyfind(v_vect, 42);
		std::cout << "Value found in vector: " << *it_v << std::endl;

		std::list<int>::iterator it_l = easyfind(v_list, 42);
		std::cout << "Value found in list: " << *it_l << std::endl;

		std::deque<int>::iterator it_d = easyfind(v_deq, 42);
		std::cout << "Value found in deque: " << *it_d << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED "Error: " RESET;
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it_v = easyfind(v_list, -42);
		std::cout << "Value found in vector: " << *it_v << std::endl;

		std::deque<int>::iterator it_d = easyfind(v_deq, -42);
		std::cout << "Value found in deque: " << *it_d << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << RED "Error: " RESET;
		std::cout << e.what() << std::endl;
	}

	return (0);
}
