#ifndef FIXED_HPP
# define FIXED_HPP

# include <cctype>
# include <iomanip>
# include <ios>
# include <iostream>
# include <ostream>
# include <sstream>
# include <string>

class Fixed
{
  private:
	int value;
	static const int fractionalBits = 8;

  public:
	Fixed();
	explicit Fixed(const int num);
	explicit Fixed(const float num);
	Fixed(const Fixed &copy);
	~Fixed();
	Fixed &operator=(const Fixed &copy);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif