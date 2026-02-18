/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:23:09 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 15:25:57 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <ostream>
#include <string>
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

static void subjectTest1(void)
{
	printTest("subject test - MutantStack");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << std::endl;
}

static void subjectTest2(void)
{
	printTest("subject test - std::list");

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();

	std::cout << "size: " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

static void test3(void)
{
	printTest("deep-copy test");
	try
	{
		MutantStack<int> m;

		std::cout << "m-size before population: " << m.size() << std::endl;
		for (int i = 1; i < 15; ++i)
			m.push(i);
		std::cout << "m-size after population: " << m.size() << std::endl;

		MutantStack<int> m2(m);
		std::cout << "m2-size after copy: " << m2.size() << std::endl;

		std::cout << std::endl;

		for (int i = 0; i < static_cast<int>(m.size()); ++i)
		{
			std::cout << "m-poped: " << m.top() << std::endl;
			m.pop();
		}

		std::cout << std::endl;

		std::cout << "m-size: " << m.size() << std::endl;
		std::cout << "m2-size: " << m2.size() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << "caught exception: " << e.what() << std::endl;
	}
}

int main(void)
{
	subjectTest1();
	subjectTest2();
	test3();
	return (0);
}