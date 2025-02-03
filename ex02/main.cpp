#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}

// std::cout << "\nMy Personal Tests" << std::endl;
// Fixed const c(Fixed(1.33f) / Fixed(2));
// std::cout << c << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::min(b, c) << std::endl;
// Fixed const d(Fixed(3.56f) * Fixed(2.2f));
// std::cout << d << std::endl;
// Fixed const e(Fixed(3.56f) - Fixed(2.2f));
// std::cout << e << std::endl;
// Fixed const f(Fixed(2.1f) + Fixed(2.2f));
// std::cout << f << std::endl;
// std::cout << (e > f) << std::endl;
// std::cout << (e < f) << std::endl;
// std::cout << (e != f) << std::endl;
// std::cout << (e == e) << std::endl;