#include "exponantiation_operator.hpp"

#include <iostream>
#include <cassert>

using namespace expon;

int main ()
{
    auto num1 = 2 ** 3.0_n;
    assert( num1 == 8.0_n );

    NumberWrapper num2 = 0;
    assert( num2 == 0.0_n );

    NumberWrapper num3 = 4;
    NumberWrapper num4 = 3;
    assert( ( num3 ** num4 ) == 64.0_n );

    num3 += 5;
    assert( num3 == 9.0_n );

    return 0;
}