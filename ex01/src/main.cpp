/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:56:38 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 13:14:40 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "Span.hpp"
#include <exception>
#include <iostream>

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

static void subjectTest(void)
{
	printTest("subject test");
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printValues();
		std::cout << "\n" << sp << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "caught exception: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test2(void)
{
	printTest("filling Span");
	try
	{
		int span_size = 10;

		Span s(span_size);

		for (int i = 0; i < (span_size / 2); ++i)
			s.addNumber(i);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test3(void)
{
	printTest("ovefilling Span");
	try
	{
		int span_size = 5;

		Span s(span_size);

		for (int i = 0; i <= span_size; ++i)
			s.addNumber(i);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test4(void)
{
	printTest("appending with valid range");
	try
	{
		Span s(5);

		s.append_range(-10, -5);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test5(void)
{
	printTest("appending to failure");
	try
	{
		const int span_size = 5;

		Span s(span_size);

		s.append_range(0, span_size + 1);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test6(void)
{
	printTest("append to partially filled Span");
	try
	{
		const int span_size = 10;

		Span s(span_size);

		s.addNumber(1000);
		s.append_range(0, span_size - 2);
		s.addNumber(-1000);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test7(void)
{
	printTest("append to partially filled Span to failure");
	try
	{
		const int span_size = 10;

		Span s(span_size);

		s.addNumber(-1);
		s.addNumber(-2);

		s.append_range(0, span_size - 1);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test8(void)
{
	printTest("duplicate numbers Span");
	try
	{
		const int span_size = 5;

		Span s(span_size);

		s.addNumber(1);
		s.addNumber(10);
		s.addNumber(10);
		s.addNumber(100);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test9(void)
{
	printTest("HUGE span!");
	try
	{
		const int span_size = 100000;

		Span s(span_size);

		s.append_range(-(span_size/2), (span_size/2));

		std::cout << s << std::endl;
		std::cout << GREEN << "\nno exception caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test10(void)
{
	printTest("sort one element");
	try
	{
		Span s(2);
		s.addNumber(1);

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test11(void)
{
	printTest("valid vector append");
	try
	{
		Span s(5);
		std::vector<int> vec(5, 5);

		s.append(vec.begin(), vec.end());

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

static void test12(void)
{
	printTest("too large range append");
	try
	{
		Span s(5);
		std::vector<int> vec(6, 6);

		s.append(vec.begin(), vec.end());

		s.printValues();
		std::cout << "\n" << s << std::endl;
		std::cout << GREEN << "no exceptions caught!" << RESET << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << RED << "exception caught: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	subjectTest();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	return (0);
}