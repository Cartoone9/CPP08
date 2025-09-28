/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/28 14:02:34 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "colors.hpp"
#include "Span.class.hpp"

#define BIG_ARR 10000

void	addTryTest(Span& sp, int* begin, int* end)
{
	try
	{
		sp.addNumber(begin, end);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " RESET;
		std::cerr << e.what() << std::endl;
	}
}

void	addTryTest(Span& sp, int value)
{
	try
	{
		sp.addNumber(value);
	}
	catch (const std::exception& e)
	{
		std::cerr << RED "Error: " RESET;
		std::cerr << e.what() << std::endl;
	}
}

int	main(int ac, char** av)
{
	// if (ac != 2 && ac != 3)
	// {
	// 	std::cerr << RED "Error: " RESET;
	// 	std::cerr << "./span seed_value [print_array]" << std::endl;
	// 	return (1);
	// }

	Span empty_sp = Span();
	Span sp = Span(5);

	std::cout << std::endl;


	// ----------------------------------------------------------
	std::cout << REVERSED "--- ADD TEST ---\n" RESET << std::endl;

	addTryTest(sp, 6);
	addTryTest(sp, 3);
	addTryTest(sp, 17);
	addTryTest(sp, 9);
	addTryTest(sp, 11);

	addTryTest(sp, 42); // out of bound
	addTryTest(empty_sp, 42); // empty array


	// ----------------------------------------------------------
	std::cout << REVERSED "\n--- SPAN TEST ---\n" RESET << std::endl;

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	if (ac == 1)
	{
		std::cout << std::endl;
		return (0);
	}


	// ----------------------------------------------------------
	std::cout << REVERSED "\n--- BIG ARRAY TEST ---\n" RESET << std::endl;

	std::srand(std::strtol(av[1], NULL, 10));

	int			array[BIG_ARR];
	std::size_t	i = 0;

	while (i < BIG_ARR)
	{
		array[i] = std::rand() % (BIG_ARR * 10);
		i++;
	}

	Span big_sp = Span(BIG_ARR);

	std::cout << std::endl;

	addTryTest(big_sp, array, &array[i]);

	std::cout << TEAL "Shortest" RESET << " span: "
		<< big_sp.shortestSpan() << std::endl;
	std::cout << ORANGE "Longest" RESET << " span: "
		<< big_sp.longestSpan() << std::endl;

	std::cout << std::endl;

	if (ac == 3)
	{
		big_sp.printSpan(false);
		std::cout << std::endl;
	}

	return (0);
}
