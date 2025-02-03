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
	Fixed(Fixed &&copy) noexcept; 
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
	// Arithmetic Operators
	float operator+(Fixed fixed) const;
	float operator-(Fixed fixed) const;
	float operator*(Fixed fixed) const;
	float operator/(Fixed fixed) const;
	// Increment / Decrement Operators
	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);
	// Methods
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &fixed_num, Fixed &fixed_num2);
	static const Fixed &min(Fixed const &fixed_num, Fixed const &fixed_num2);
	static Fixed &max(Fixed &fixed_num, Fixed &fixed_num2);
	static const Fixed &max(Fixed const &fixed_num, Fixed const &fixed_num2);
	// Getter - Setters
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif