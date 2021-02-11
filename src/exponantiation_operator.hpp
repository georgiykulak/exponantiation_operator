#ifndef EXPONANTIATION_OPERATOR_HPP
#define EXPONANTIATION_OPERATOR_HPP

#include <cmath>

namespace expon
{

class NumberWrapper
{
public:
    class AnotherNumberWrapper
    {
    public:
        AnotherNumberWrapper ( long double number )
            :   m_number{ number }
        {}

        long double get () const
        {
            return m_number;
        }

    private:
        long double m_number;
    };

    NumberWrapper ( long double number )
        :   m_number{ number }
    {}

    AnotherNumberWrapper operator* () const
    {
        return AnotherNumberWrapper( m_number );
    }

private:
    long double m_number;
};

// left ^ right == left ** right == left * (*right)
auto operator* ( auto const n1, NumberWrapper::AnotherNumberWrapper const n2 ) // n1 should be concept
{
    return std::pow( n1, n2.get() );
}

NumberWrapper operator "" _n ( long double n )
{
    return NumberWrapper( n );
}

} // namespace expon

#endif // EXPONANTIATION_OPERATOR_HPP //