#include "exponantiation_operator.hpp"

#include <iostream>
#include <cassert>

using namespace expon;

int main ()
{
    auto num = 2 ** 3.0_n;
    assert( num == 8 );

    return 0;
}