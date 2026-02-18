/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:00:11 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 13:12:56 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
private:
	std::vector<int>	data_;
	unsigned int		max_size_;
	bool				sorted_;

	void	sortData(void);
public:
	Span(void);
	Span(unsigned int N);
	Span(const Span &other);
	~Span(void);

	Span	&operator=(const Span &other);

	unsigned int			getSize(void) const;
	unsigned int			getMaxSize(void) const;
	bool					getSorted(void) const;
	const std::vector<int>	getData(void) const;

	void			addNumber(int new_num);

	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	void			append_range(int start, int end);
	template <typename Iter>
	void			append(Iter first, Iter last);

	void	printValues(void);
};

std::ostream	&operator<<(std::ostream &os, Span &c);

# include "Span.tpp"

#endif /* SPAN_HPP */
