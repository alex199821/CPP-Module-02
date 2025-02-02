#include "Fixed.hpp"

FixedPointNum::FixedPointNum() : value(0){};

FixedPointNum::FixedPointNum(const FixedPointNum &copy) : value(copy.value)
{
}
