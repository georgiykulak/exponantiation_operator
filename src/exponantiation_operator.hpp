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
        InternalNumberWrapper ( long double const number ) noexcept
            :   m_number{ number }
        {}

        long double get () const noexcept
        {
            return m_number;
        }

    private:
        long double const m_number;
    };

    NumberWrapper ( long double number ) noexcept
        :   m_number{ number }
    {}

    InternalNumberWrapper operator* () const noexcept
    {
        return InternalNumberWrapper( m_number );
    }

    auto operator<=> ( NumberWrapper const & ) const noexcept = default;

    NumberWrapper operator+ () const noexcept { return m_number; }
    NumberWrapper operator- () const noexcept { return -m_number; }

    NumberWrapper operator+ ( NumberWrapper const & n ) const noexcept { return m_number + n.m_number; }
    NumberWrapper operator- ( NumberWrapper const & n ) const noexcept { return m_number - n.m_number; }
    NumberWrapper operator* ( NumberWrapper const & n ) const noexcept { return m_number * n.m_number; }
    NumberWrapper operator/ ( NumberWrapper const & n ) const noexcept { return m_number / n.m_number; }

    NumberWrapper & operator+= ( NumberWrapper const & n ) noexcept { m_number += n.m_number; return *this; }
    NumberWrapper & operator-= ( NumberWrapper const & n ) noexcept { m_number -= n.m_number; return *this; }
    NumberWrapper & operator*= ( NumberWrapper const & n ) noexcept { m_number *= n.m_number; return *this; }
    NumberWrapper & operator/= ( NumberWrapper const & n ) noexcept { m_number /= n.m_number; return *this; }

    operator bool () const noexcept
    {
        return m_number;
    }

    operator long double () const noexcept
    {
        return m_number;
    }

private:
    long double m_number = 0;
};

// left ^ right == left ** right == left * (*right)
NumberWrapper operator* ( NumberWrapper const & n1, NumberWrapper::InternalNumberWrapper const n2 )
{
    return std::pow( n1, n2.get() );
}

NumberWrapper operator "" _n ( long double n ) noexcept
{
    return NumberWrapper( n );
}

} // namespace expon

#endif // EXPONANTIATION_OPERATOR_HPP //