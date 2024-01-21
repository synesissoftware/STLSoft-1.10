/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/64bit_integers.hpp
 *
 * Purpose:     Byte-order independent large integer (aggregate) classes.
 *
 * Created:     15th October 2000
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file stlsoft/util/64bit_integers.hpp
 *
 * \brief [C++] Definition of the stlsoft::sinteger64 class
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_64BIT_INTEGERS
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_64BIT_INTEGERS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_UTIL_HPP_64BIT_INTEGERS_MAJOR     5
# define STLSOFT_VER_STLSOFT_UTIL_HPP_64BIT_INTEGERS_MINOR     1
# define STLSOFT_VER_STLSOFT_UTIL_HPP_64BIT_INTEGERS_REVISION  5
# define STLSOFT_VER_STLSOFT_UTIL_HPP_64BIT_INTEGERS_EDIT      142
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace sinteger64_util
{
#endif /* STLSOFT_NO_NAMESPACE */

/** Signed 64-bit integer class
 *
 * \ingroup group__library__Utility
 */
class sinteger64
{
public:
    typedef sinteger64  class_type;

public:
    sinteger64();
    sinteger64(ss_sint8_t i);
    sinteger64(ss_sint16_t i);
    sinteger64(ss_sint32_t i);
    sinteger64(ss_sint32_t high, ss_sint32_t low);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    sinteger64(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    sinteger64(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

    class_type& operator =(class_type const& rhs);
    class_type& operator =(ss_sint8_t i);
    class_type& operator =(ss_sint16_t i);
    class_type& operator =(ss_sint32_t i);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    class_type& operator =(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    class_type& operator =(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

    class_type& operator +=(class_type const& rhs);
    class_type& operator +=(ss_sint8_t i);
    class_type& operator +=(ss_sint16_t i);
    class_type& operator +=(ss_sint32_t i);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    class_type& operator +=(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    class_type& operator +=(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

    class_type& operator -=(class_type const& rhs);
    class_type& operator -=(ss_sint8_t i);
    class_type& operator -=(ss_sint16_t i);
    class_type& operator -=(ss_sint32_t i);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    class_type& operator -=(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    class_type& operator -=(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

    class_type& operator *=(class_type const& rhs);
    class_type& operator *=(ss_sint8_t i);
    class_type& operator *=(ss_sint16_t i);
    class_type& operator *=(ss_sint32_t i);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    class_type& operator *=(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    class_type& operator *=(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

    class_type& operator /=(class_type const& rhs);
    class_type& operator /=(ss_sint8_t i);
    class_type& operator /=(ss_sint16_t i);
    class_type& operator /=(ss_sint32_t i);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    class_type& operator /=(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    class_type& operator /=(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

    class_type& operator %=(class_type const& rhs);
    class_type& operator %=(ss_sint8_t i);
    class_type& operator %=(ss_sint16_t i);
    class_type& operator %=(ss_sint32_t i);
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    class_type& operator %=(int i);
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    class_type& operator %=(long i);
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

public:
    ss_sint_t compare(class_type const& rhs) const;
    ss_sint_t compare(ss_sint8_t i) const;
    ss_sint_t compare(ss_sint16_t i) const;
    ss_sint_t compare(ss_sint32_t i) const;
#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
    ss_sint_t compare(int i) const;
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */
#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
    ss_sint_t compare(long i) const;
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

// Members
private:
    ss_sint32_t m_low;
    ss_sint32_t m_high;
};

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace sinteger64_util */

using ::stlsoft::sinteger64_util::sinteger64;
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace sinteger64_util
{
#endif /* STLSOFT_NO_NAMESPACE */

// operator ==

inline ss_bool_t operator ==(sinteger64 const& lhs, sinteger64 const& rhs)
{
    return 0 == lhs.compare(rhs);
}

// operator !=

inline ss_bool_t operator !=(sinteger64 const& lhs, sinteger64 const& rhs)
{
    return 0 != lhs.compare(rhs);
}

// operator <

inline ss_bool_t operator <(sinteger64 const& lhs, sinteger64 const& rhs)
{
    return lhs.compare(rhs) < 0;
}

// operator >

inline ss_bool_t operator >(sinteger64 const& lhs, sinteger64 const& rhs)
{
    return lhs.compare(rhs) > 0;
}

// operator <=

inline ss_bool_t operator <=(sinteger64 const& lhs, sinteger64 const& rhs)
{
    return lhs.compare(rhs) <= 0;
}

// operator >=

inline ss_bool_t operator >=(sinteger64 const& lhs, sinteger64 const& rhs)
{
    return lhs.compare(rhs) >= 0;
}

// operator +

inline sinteger64 operator +(sinteger64 const& lhs, sinteger64 const& rhs)
{
    sinteger64  result(lhs);

    result += rhs;

    return result;
}

// operator -

inline sinteger64 operator -(sinteger64 const& lhs, sinteger64 const& rhs)
{
    sinteger64  result(lhs);

    result -= rhs;

    return result;
}

// operator *

inline sinteger64 operator *(sinteger64 const& lhs, sinteger64 const& rhs)
{
    sinteger64  result(lhs);

    result *= rhs;

    return result;
}

// operator /

inline sinteger64 operator /(sinteger64 const& lhs, sinteger64 const& rhs)
{
    sinteger64  result(lhs);

    result /= rhs;

    return result;
}

// operator %

inline sinteger64 operator %(sinteger64 const& lhs, sinteger64 const& rhs)
{
    sinteger64  result(lhs);

    result %= rhs;

    return result;
}

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace sinteger64_util */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#ifndef STLSOFT_NO_NAMESPACE
namespace sinteger64_util
{
#endif /* STLSOFT_NO_NAMESPACE */

inline sinteger64::sinteger64()
{}

inline sinteger64::sinteger64(ss_sint8_t i)
    : m_low(i)
    , m_high(0)
{}

inline sinteger64::sinteger64(ss_sint16_t i)
    : m_low(i)
    , m_high(0)
{}

inline sinteger64::sinteger64(ss_sint32_t i)
    : m_low(i)
    , m_high(0)
{}

inline sinteger64::sinteger64(ss_sint32_t high, ss_sint32_t low)
    : m_low(low)
    , m_high(high)
{}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::sinteger64(int i)
    : m_low(i)
    , m_high(0)
{}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::sinteger64(long i)
    : m_low(i)
    , m_high(0)
{}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

inline sinteger64::class_type& sinteger64::operator =(class_type const& rhs)
{
    m_high  =   rhs.m_high;
    m_low   =   rhs.m_low;

    return *this;
}

inline sinteger64::class_type& sinteger64::operator =(ss_sint8_t i)
{
    m_high  =   0;
    m_low   =   i;

    return *this;
}

inline sinteger64::class_type& sinteger64::operator =(ss_sint16_t i)
{
    m_high  =   0;
    m_low   =   i;

    return *this;
}

inline sinteger64::class_type& sinteger64::operator =(ss_sint32_t i)
{
    m_high  =   0;
    m_low   =   i;

    return *this;
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator =(int i)
{
    m_high  =   0;
    m_low   =   i;

    return *this;
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator =(long i)
{
    m_high  =   0;
    m_low   =   i;

    return *this;
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

inline sinteger64::class_type& sinteger64::operator +=(class_type const& rhs)
{
    m_low   +=  rhs.m_low;
    m_high  +=  rhs.m_high;

    if (rhs.m_low > 0 &&
        m_low < rhs.m_low)
    {
        ++m_high;
    }
    else if (rhs.m_low < 0 &&
            m_low > rhs.m_low)
    {
        --m_high;
    }

    return *this;
}

inline sinteger64::class_type& sinteger64::operator +=(ss_sint8_t i)
{
    return operator +=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator +=(ss_sint16_t i)
{
    return operator +=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator +=(ss_sint32_t i)
{
    return operator +=(class_type(i));
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator +=(int i)
{
    return operator +=(class_type(i));
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator +=(long i)
{
    return operator +=(class_type(i));
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

inline sinteger64::class_type& sinteger64::operator -=(class_type const& rhs)
{
    m_low   -=  rhs.m_low;
    m_high  -=  rhs.m_high;

    if (rhs.m_low > 0 &&
        m_low < rhs.m_low)
    {
        ++m_high;
    }
    else if (rhs.m_low < 0 &&
            m_low > rhs.m_low)
    {
        --m_high;
    }

    return *this;
}

inline sinteger64::class_type& sinteger64::operator -=(ss_sint8_t i)
{
    return operator -=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator -=(ss_sint16_t i)
{
    return operator -=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator -=(ss_sint32_t i)
{
    return operator -=(class_type(i));
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator -=(int i)
{
    return operator -=(class_type(i));
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator -=(long i)
{
    return operator -=(class_type(i));
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

inline sinteger64::class_type& sinteger64::operator *=(class_type const& rhs)
{
    m_low   *=  rhs.m_low;
    m_high  *=  rhs.m_high;

    if (rhs.m_low > 0 &&
        m_low < rhs.m_low)
    {
        ++m_high;
    }
    else if (rhs.m_low < 0 &&
            m_low > rhs.m_low)
    {
        --m_high;
    }

    return *this;
}

inline sinteger64::class_type& sinteger64::operator *=(ss_sint8_t i)
{
    return operator *=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator *=(ss_sint16_t i)
{
    return operator *=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator *=(ss_sint32_t i)
{
    return operator *=(class_type(i));
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator *=(int i)
{
    return operator *=(class_type(i));
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator *=(long i)
{
    return operator *=(class_type(i));
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

//inline sinteger64::class_type& sinteger64::operator /=(class_type const& rhs);

inline sinteger64::class_type& sinteger64::operator /=(ss_sint8_t i)
{
    return operator /=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator /=(ss_sint16_t i)
{
    return operator /=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator /=(ss_sint32_t i)
{
    return operator /=(class_type(i));
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator /=(int i)
{
    return operator /=(class_type(i));
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator /=(long i)
{
    return operator /=(class_type(i));
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */


//inline sinteger64::class_type& sinteger64::operator %=(class_type const& rhs);

inline sinteger64::class_type& sinteger64::operator %=(ss_sint8_t i)
{
    return operator %=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator %=(ss_sint16_t i)
{
    return operator %=(class_type(i));
}

inline sinteger64::class_type& sinteger64::operator %=(ss_sint32_t i)
{
    return operator %=(class_type(i));
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator %=(int i)
{
    return operator %=(class_type(i));
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline sinteger64::class_type& sinteger64::operator %=(long i)
{
    return operator %=(class_type(i));
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */


inline ss_sint_t sinteger64::compare(class_type const& rhs) const
{
    ss_sint_t   res =   m_high - rhs.m_high;

    if (0 == res)
    {
        res = m_low - rhs.m_low;
    }

    return res;
}

inline ss_sint_t sinteger64::compare(ss_sint8_t i) const
{
    return compare(class_type(0, i));
}

inline ss_sint_t sinteger64::compare(ss_sint16_t i) const
{
    return compare(class_type(0, i));
}

inline ss_sint_t sinteger64::compare(ss_sint32_t i) const
{
    return compare(class_type(0, i));
}

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline ss_sint_t sinteger64::compare(int i) const
{
    return compare(class_type(0, i));
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

#ifdef STLSOFT_CF_LONG_DISTINCT_INT_TYPE
inline ss_sint_t sinteger64::compare(long i) const
{
    return compare(class_type(0, i));
}
#endif /* STLSOFT_CF_LONG_DISTINCT_INT_TYPE */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace sinteger64_util */
#endif /* STLSOFT_NO_NAMESPACE */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_64BIT_INTEGERS */

/* ///////////////////////////// end of file //////////////////////////// */

