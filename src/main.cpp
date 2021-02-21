#include "exponantiation_operator.hpp"

#include <iostream>
#include <cassert>

using namespace expon;

int main ()
{
    auto num1 = 2 ** 3.0_n;
    assert( num1 == 8 );

    NumberWrapper num2 = 0;
    if ( !num2 )
        std::cout << std::endl;//assert( num2 == 0.0 );

    return 0;
}