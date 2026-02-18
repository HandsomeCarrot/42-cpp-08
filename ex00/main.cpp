/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:11:42 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/17 15:37:42 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

void	printTest(const std::string & message)
{
	static int test_index = 1;

	const int width = 10;
	const char fill = '=';

	for (int i = 0; i < width; i++)
		std::cout << fill;

	std::cout \
	<< " TEST " << test_index << ": '" << message << "' ";

	for (int i = 0; i < width; i++)
		std::cout << fill;

	std::cout << std::endl;
	test_index++;
}

static void test1(void)
{
	printTest("valid int search");
	std::vector<int> vec;
	
	for (int i = 0; i < 5; ++i)
		vec.push_back(i);

	std::cout << "new INT vector: ";
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	try
	{
		easyfind(vec, 3);
		std::cout << "found 3 in vector" << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void test2(void)
{
	printTest("invalid int search");
	std::vector<int> vec;
	
	for (int i = 1; i <= 3; ++i)
		vec.push_back(i * 10);

	std::cout << "new INT vector: ";
	for (std::vector<int>::iterator i = vec.begin(); i != vec.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	try
	{
		easyfind(vec, 3);
		std::cout << "found 3 in vector" << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	test1();
	test2();
	return (0);
}
