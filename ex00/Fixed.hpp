#ifndef FIXED_HPP
# define FIXED_HPP

# include <cctype>
# include <iomanip>
# include <ios>
# include <iostream>
# include <sstream>
# include <string>

class FixedPointNum
{
  private:
	int value;
	static const int fractionalBits = 8;

  public:
	FixedPointNum();
	FixedPointNum(const FixedPointNum &copy);
};

#endif