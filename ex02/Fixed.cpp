#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
};
Fixed::Fixed(const Fixed &copy) : value(copy.value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		value = copy.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

Fixed::Fixed(const int num)
{
	value = num << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	value = static_cast<int>(roundf(num * (1 << fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return (value / static_cast<float>(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

// Comparison Operators
bool Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == (fixed.toFloat()));
}

bool Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != (fixed.toFloat()));
}