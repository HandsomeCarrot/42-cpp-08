/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:29:15 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 13:05:47 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
# define SPAN_TPP

# include <iterator>
# include <stdexcept>

/**
 * @brief appends values from given range of iterators
 *
 * Calculates the range of 'first' and 'last' and if the range fits into
 * the Span, then it will append/copy the data into Span.
 * 
 * @param first typename Iter, starting iterator of the range
 * @param last typename Iter, the end iterator of the range
 *
 * @return void
 *
 * @throw std::runtime_error
 *			- if range is 0 (first == last), or if std::distance consumes first iterator
 *			- if range between (first, last) > (max_size_ - size_)
 *
 * @note sets 'sorted_' state to false
 * @see std::distance(), std::vector<int>.insert()
 */
template <typename Iter>
void Span::append(Iter first, Iter last)
{
	unsigned int range = std::distance(first, last);

	if (first == last)
		throw std::runtime_error("runtime_error: Span::insert(): range of 0 is invalid!");

	if (range > static_cast<unsigned int>(this->getMaxSize() - this->getSize()))
		throw std::runtime_error("runtime_error: Span::insert(): range is too large!");

	this->data_.insert(this->data_.end(), first, last);
	sorted_ = false;
}

#endif /* SPAN_TPP */