/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:46:06 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/18 15:02:12 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) :
	std::stack<T, Container>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> & other) :
	std::stack<T, Container>(other)
{}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{}

template <typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator=(const MutantStack<T, Container> & other)
{
	if (this != other)
	{
		std::stack<T, Container>::operator=(other);
	}
	return (*this);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

#endif /* MUTANTSTACK_TPP */
