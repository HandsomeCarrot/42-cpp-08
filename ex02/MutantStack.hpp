/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:23:46 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 14:48:55 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void);
	MutantStack(const MutantStack<T, Container> & other);
	~MutantStack(void);

	MutantStack<T, Container> & operator=(const MutantStack<T, Container> & other);

	typedef typename Container::iterator iterator;

	iterator	begin(void);
	iterator	end(void);
};

# include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
