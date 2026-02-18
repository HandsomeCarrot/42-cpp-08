/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:59:29 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 13:12:29 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.hpp"
#include "Span.hpp"
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <vector>

/**
 * @brief default constructor
*/
Span::Span(void) :
	data_(),
	max_size_(0),
	sorted_(false)
{
	DEBUG_MSG("Span default constructor called");
}

/**
 * @brief parameterized constructor
*/
Span::Span(unsigned int max_size) :
	data_(),
	max_size_(max_size),
	sorted_(false)
{
	DEBUG_MSG("Span parameterized constructor called");
	data_.reserve(max_size);
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
Span::Span(const Span &other) :
	data_(other.data_),
	max_size_(other.max_size_),
	sorted_(other.sorted_)
{
	DEBUG_MSG("Span copy constructor called");
}

/**
 * @brief destructor
*/
Span::~Span(void)
{
	DEBUG_MSG("Span destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
*/
Span	&Span::operator=(const Span &other)
{
	DEBUG_MSG("Span assignment operator called");
	if (this != &other)
	{
		data_ = other.data_;
		max_size_ = other.max_size_;
		sorted_ = other.sorted_;
	}
	return (*this);
}

/**
 * @brief get size of the span
 * 
 * @return unsigned int size of the span
*/
unsigned int Span::getSize(void) const
{
	return (data_.size());
}

/**
 * @brief get biggest possible size of the span
 * 
 * @return unsigned int size of the span
*/
unsigned int Span::getMaxSize(void) const
{
	return (max_size_);
}

/**
 * @brief get sorted status of the span
 *
 * @return bool, if sorted or not
*/
bool Span::getSorted(void) const
{
	return (sorted_);
}

/**
 * @brief get pointer to the data array
 * 
 * @return const unsigned int* pointer to the data array
*/
const std::vector<int>	Span::getData(void) const
{
	return (data_);
}

/**
 * @brief push back 'new_num' to Span
 *
 * Checks if this Span has enough space for another number. If it has enough space,
 * then it will push it to the back of the list. If the Span does not have enough
 * space, then it will throw a std::runtime_error.
 *
 * @param new_num int, new number to add to the list
 *
 * @throw std::runtime_error() if Span is full
 *
 * @note sets 'sorted_' flag to 'false'
 *
 * @return void
 */
void Span::addNumber(int new_num)
{
	DEBUG_MSG("Span::addNumber() called");

	if (data_.size() >= max_size_)
		throw std::runtime_error("runtime_error: Span::addNumber(): Span already full!");

	data_.push_back(new_num);
	sorted_ = false;
}

/**
 * @brief adds a range of numbers to this Span starting from start
 *
 * First it checks if start is 'smaller' then 'end' and if the range (end - start)
 * is too large (> max_size_ - span::getSize()). If any of that applies, this
 * function will throw a std::runtime_error(). If the range is valid then it will 
 * push back all the values of the range, including 'start' excluding 'end',
 * starting with 'start' and incrementing the value by one each time.
 * Because this pushes the values back, any valuse that where previously added
 * will stay there.
 *
 * @param start int, start of the range (the smaller number, included)
 * @param end int, end of the range (the larger number, excluded)
 *
 * @throw std::runtime_error, if start >= end,
 * or end - start > max size - size
 *
 * @note sets 'sorted_' flag to 'false'
 *
 * @return void
 */
void Span::append_range(int start, int end)
{
	DEBUG_MSG("Span::fill_range() called");

	unsigned int range = end - start;
	unsigned int free_span_space = getMaxSize() - getSize();

	if (start >= end || range > free_span_space)
		throw std::runtime_error("runtime_error: Span::fill(): range not valid!");

	for (unsigned int i = 0; i < range; ++i)
		data_.push_back(start++);
	sorted_ = false;
}

/**
 * @brief sorts the elements, lowest->highest
 *
 * First checks if the size of the data set is > 2. If the Span has
 * < 2 elements, it will throw a std::runtime_error(). Otherwise it will continue
 * to check if the elements are already sorted, by checking the 'sorted_' flag.
 * If it is sorted, it will cancel the execution of this function. If it is not
 * sorted it will use the std::sort() function from the <algorithm> header to
 * sort the elements from lowest to highest numbers and set the 'sorted_' flag
 * to 'true'.
 *
 * @throw std::runtime_error(), if Span::getSize() < 2
 *
 * @note sets 'sorted_' flag to 'true'
 *
 * @return void
 */
void Span::sortData(void)
{
	DEBUG_MSG("Span::sortData() called");

	if (getSize() < 2)
		throw std::runtime_error("runtime_error: Span: not enough elements to calculate span!");

	if (sorted_)
		return ;

	std::sort(data_.begin(), data_.end());
	sorted_ = true;

	DEBUG_MSG("Span::sortData() data sorted");
}

/**
 * @brief Finds the shortest span between any two elements in the Span.
 * 
 * Computes the minimum absolute difference between any two elements in the data.
 * The data is first sorted to enable efficient comparison of adjacent elements.
 *
 * @throw std::runtime_error If the Span contains fewer than 2 elements.
 * 
 * @return unsigned int The shortest span (minimum difference) between two elements.
 * - Returns 0 if two identical elements exist.
 * 
 * @note The data is sorted before comparison.
 *
 * @see sortData()
 */
unsigned int Span::shortestSpan(void)
{
	DEBUG_MSG("Span::shortestSpan() called");

	sortData();

	std::vector<int>::const_iterator i = data_.begin();
	unsigned int shortest_span = static_cast<unsigned int>(*(i++) - *i);

	while ((i + 1) != data_.end())
	{
		unsigned int span = static_cast<unsigned int>(*(i + 1) - *i);

		if (span < shortest_span)
			shortest_span = span;

		if (shortest_span == 0)
			return (0);

		++i;
	}
	return (shortest_span);
}

/**
 * @brief Calculates the longest span between the largest and smallest elements in the Span.
 * 
 * This function sorts the data and computes the difference between
 * the maximum and minimum values.
 *
 * @throws std::runtime_error() If the Span contains fewer than 2 elements.
 * 
 * @return unsigned int The difference between the largest and smallest element.
 *
 * @see sortData()
 */
unsigned int Span::longestSpan(void)
{
	DEBUG_MSG("Span::longestSpan() called");

	sortData();

	return (static_cast<unsigned int>(*(data_.rbegin()) - *(data_.begin())));
}

void Span::printValues(void)
{
	std::cout << "Span values:";

	for (unsigned int i = 0; i < this->getSize(); ++i)
	{
		if (i % 5 == 0)
			std::cout << "\n" << std::setw(2) << std::setfill(' ') << "";
		std::cout << "'" << this->getData()[i] << "' ";
	}
	std::cout << std::endl;
}

/** 
 * @brief output stream operator
 *
 * Outputs the size, max size, longest span, shortest span and all the values
 * in a formatted string over multiple lines.
 * 
 * @param os reference to the outputstream
 * @param class reference to the class object
 *
 * @throw std::runtime_error()
 * 
 * @return reference to the output stream
 *
 * @see longestSpan(), shortestSpan()
*/
std::ostream	&operator<<(std::ostream &os, Span &c)
{
	DEBUG_MSG("Span output stream operator called");

	unsigned int longest_span = c.longestSpan();
	unsigned int shortest_span = c.shortestSpan();

	os << "Span: " \
	<< "\n  - size: " << c.getSize() \
	<< "\n  - max size: " << c.getMaxSize() \
	<< "\n  - longest span: " << longest_span \
	<< "\n  - shortest span: " << shortest_span \
	<< std::endl;

	return (os);
}
