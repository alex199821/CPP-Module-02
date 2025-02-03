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
	// Constructor
	Fixed();
	explicit Fixed(const int num);
	explicit Fixed(const float num);
	Fixed(const Fixed &copy);
	// Deconstructor
	~Fixed();
	// Overloaded Operator
	Fixed &operator=(const Fixed &copy);
	// Comparison Operators
	bool operator>(Fixed fixed) const;
	bool operator!=(Fixed fixed) const;
	bool operator==(Fixed fixed) const;
	bool operator<=(Fixed fixed) const;
	bool operator>=(Fixed fixed) const;
	bool operator<(Fixed fixed) const;
	// Methods
	float toFloat(void) const;
	int toInt(void) const;
	// Getter - Setters
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif