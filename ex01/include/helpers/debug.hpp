#ifndef DEBUG_HPP
# define DEBUG_HPP

# include "colors.h"
# include <iostream>

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << BOLDYELLOW << "[DEBUG]" << RESET << x << std::endl
# else
#  define DEBUG_MSG(x)
# endif

#endif /* DEBUG_HPP */
