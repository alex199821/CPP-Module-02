#include "Fixed.hpp"

Fixed::Fixed() : value(0){};

Fixed::Fixed(const Fixed &copy) : value(copy.value)
{
	*this = copy;
};
Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		value = copy.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits() const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::Fixed(const int num)
{
	value = num << fractionalBits;
}

Fixed::Fixed(const float num)
{
	value = static_cast<int>(roundf(num * (1 << fractionalBits)));
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

// Arithmetic operators

float Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + (fixed.toFloat()));
}

float Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - (fixed.toFloat()));
}

float Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * (fixed.toFloat()));
}

float Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / (fixed.toFloat()));
}

// Increment / Decrement Operators

Fixed Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->value++;
	return (temp);
}

Fixed Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &fixed_num, Fixed &fixed_num2)
{
	if (fixed_num.toFloat() <= fixed_num2.toFloat())
	{
		return (fixed_num);
	}
	else
	{
		return (fixed_num2);
	}
}

const Fixed &Fixed::min(Fixed const &fixed_num, Fixed const &fixed_num2)
{
	if (fixed_num.toFloat() <= fixed_num2.toFloat())
	{
		return (fixed_num);
	}
	else
	{
		return (fixed_num2);
	}
}

Fixed &Fixed::max(Fixed &fixed_num, Fixed &fixed_num2)
{
	if (fixed_num.toFloat() >= fixed_num2.toFloat())
	{
		return (fixed_num);
	}
	else
	{
		return (fixed_num2);
	}
}

const Fixed &Fixed::max(Fixed const &fixed_num, Fixed const &fixed_num2)
{
	if (fixed_num.toFloat() >= fixed_num2.toFloat())
	{
		return (fixed_num);
	}
	else
	{
		return (fixed_num2);
	}
}