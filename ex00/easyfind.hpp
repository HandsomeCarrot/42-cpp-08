/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:11:30 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/17 14:56:39 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
#include <stdexcept>


template <typename T>
void easyfind(T& container, int value)
{
	typename T::iterator iterator;

	iterator = std::find(container.begin(), container.end(), value);

	if (iterator == container.end())
		throw std::runtime_error("runtime_error: easyfind: value not found");
}

#endif /* EASYFIND_HPP */
