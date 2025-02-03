#ifndef FIXED_HPP
# define FIXED_HPP

# include <cctype>
# include <iomanip>
# include <ios>
# include <iostream>
# include <sstream>
# include <string>

class Fixed
{
  private:
	int value;
	static const int fractionalBits = 8;

  public:
	Fixed();
	Fixed(int num);
	Fixed(const Fixed &copy);
	Fixed(Fixed &&copy) noexcept;
	~Fixed();
	Fixed &operator=(const Fixed &copy);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif