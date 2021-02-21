#ifndef EXPONANTIATION_OPERATOR_HPP
#define EXPONANTIATION_OPERATOR_HPP

#include <cmath>

namespace expon
{

class NumberWrapper
{
public:
    class InternalNumberWrapper
    {
    public:
        InternalNumberWrapper ( long double number )
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

    InternalNumberWrapper operator* () const
    {
        return InternalNumberWrapper( m_number );
    }

    //auto operator<=> ( NumberWrapper const & ) const noexcept = default;

    auto operator+ () const noexcept { return m_number; }
    auto operator- () const noexcept { return -m_number; }

    auto operator+ ( NumberWrapper const & n ) const noexcept { return n.m_number + m_number; }
    auto operator- ( NumberWrapper const & n ) const noexcept { return n.m_number - m_number; }
    auto operator* ( NumberWrapper const & n ) const noexcept { return n.m_number * m_number; }
    auto operator/ ( NumberWrapper const & n ) const noexcept { return n.m_number / m_number; }

    operator bool () const noexcept
    {
        return m_number;
    }

    operator long double () const noexcept
    {
        return m_number;
    }

private:
    long double m_number;
};

// left ^ right == left ** right == left * (*right)
auto operator* ( auto const n1, NumberWrapper::InternalNumberWrapper const n2 )
{
    return std::pow( n1, n2.get() );
}

NumberWrapper operator "" _n ( long double n )
{
    return NumberWrapper( n );
}

} // namespace expon

#endif // EXPONANTIATION_OPERATOR_HPP //