/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramiro <jramiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:43:14 by jramiro           #+#    #+#             */
/*   Updated: 2025/09/27 17:31:13 by jramiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "colors.hpp"
#include "Span.class.hpp"

void	addTryTest(Span& sp, int value)
{
	try
	{
		sp.addNumber(value);
	}
	catch (const std::exception& e)
	{
		std::cout << RED "Error: " RESET;
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	Span sp = Span(5);

	std::cout << std::endl;

	addTryTest(sp, 6);
	addTryTest(sp, 3);
	addTryTest(sp, 17);
	addTryTest(sp, 9);
	addTryTest(sp, 11);

	addTryTest(sp, 42); // out of bound

	// std::cout << sp.shortestSpan() << std::endl;

	std::cout << std::endl;

	return (0);
}
