/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/conversion/truncation_test.hpp
 *
 * Purpose:     Runtime checking for numeric conversions.
 *
 * Created:     10th August 2006
 * Updated:     16th February 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/conversion/truncation_test.hpp
 *
 * \brief [C++] Definition of the stlsoft::truncation_test functions
 *   (\ref group__library__Conversion "Conversion" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST
#define STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST_MAJOR      1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST_MINOR      1
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST_REVISION   11
# define STLSOFT_VER_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST_EDIT       68
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

#ifndef STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS
# include <stlsoft/limits/integral_limits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_LIMITS_HPP_INTEGRAL_LIMITS */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS
# include <stlsoft/util/sign_traits.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_SIGN_TRAITS */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE
# include <stlsoft/meta/is_signed_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SIGNED_TYPE */

#ifndef STLSOFT_INCL_TYPEINFO
# define STLSOFT_INCL_TYPEINFO
# include <typeinfo>
#endif /* !STLSOFT_INCL_TYPEINFO */

#if !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION) &&\
    defined(STLSOFT_DEBUG) &&\
    defined(_MSC_VER) &&\
    !defined(STLSOFT_INCL_H_CRTDBG)
#  define STLSOFT_INCL_H_CRTDBG
#  include <crtdbg.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper classes
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

class stlsoft_INTERNAL_truncation_test_CrtDbg_scoper
{
# if defined(STLSOFT_DEBUG) && \
     defined(_MSC_VER)
public:
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper()
        : flags(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG))
    {
        _CrtSetDbgFlag(flags & ~(_CRTDBG_ALLOC_MEM_DF));
    }
    ~stlsoft_INTERNAL_truncation_test_CrtDbg_scoper() STLSOFT_NOEXCEPT
    {
        _CrtSetDbgFlag(flags);
    }
private:
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper(stlsoft_INTERNAL_truncation_test_CrtDbg_scoper const&);
    void operator =(stlsoft_INTERNAL_truncation_test_CrtDbg_scoper const&);

private:
    int const   flags;
#else
public:
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper()
    {}
# endif
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 *
 *
 * Assume 11 types:
 *     char, signed char, unsigned char
 *     short, unsigned short
 *     int, unsigned int
 *     long, unsigned long
 *     long long, unsigned long long
 *
 * That gives 121 permutations:
 *     (a) 11 where the type is the same
 *     (b) 20 where the sign is the same and sizeof(FROM) <= sizeof(TO); superset of (a)
 *     (c) 10 where FROM is unsigned and sizeof(FROM) < sizeof(TO)
 *     (d) 80 that must be determined dynamically
 *
 *
 * The strategy is as follows:
 *

if (signof(FROM) == signof(TO) &&       // Compile-time test 1
    sizeof(FROM) <= sizeof(TO))
{
    return true;
}
else if (unsigned == signof(FROM) &&     // Compile-time test 2
        sizeof(FROM) < sizeof(TO))
{
    return true;
}
else
{
    return runtime_test<TO>(from);
}

 *
 * The runtime test evaluates to the following:
 *
 *  If the FROM type is signed, then

 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    // The permutations are:
    //
    // 1a FROM signed | TO signed | sizeof(FROM) < sizeof(TO)       =>  Always yes
    // 1b FROM signed | TO signed | sizeof(FROM) = sizeof(TO)       =>  Always yes
    // 1c FROM signed | TO signed | sizeof(FROM) > sizeof(TO)       =>  Runtime test
    //
    // 2a FROM unsigned | TO signed | sizeof(FROM) < sizeof(TO)     =>  Always yes
    // 2b FROM unsigned | TO signed | sizeof(FROM) = sizeof(TO)     =>  Runtime test
    // 2c FROM unsigned | TO signed | sizeof(FROM) > sizeof(TO)     =>  Runtime test
    //
    // 3a FROM signed | TO unsigned | sizeof(FROM) < sizeof(TO)     =>  Runtime test
    // 3b FROM signed | TO unsigned | sizeof(FROM) = sizeof(TO)     =>  Runtime test
    // 3c FROM signed | TO unsigned | sizeof(FROM) > sizeof(TO)     =>  Runtime test
    //
    // 4a FROM unsigned | TO unsigned | sizeof(FROM) < sizeof(TO)   =>  Always yes
    // 4b FROM unsigned | TO unsigned | sizeof(FROM) = sizeof(TO)   =>  Always yes
    // 4c FROM unsigned | TO unsigned | sizeof(FROM) > sizeof(TO)   =>  Runtime test

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_different_sign_FROM_is_signed_FROM_largerthan_TO(
    T_from  from
,   yes_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    STLSOFT_STATIC_ASSERT(sizeof(T_from) > sizeof(T_to));
    STLSOFT_STATIC_ASSERT(0 != int(FROM_is_signed));
    STLSOFT_STATIC_ASSERT(0 == int(TO_is_signed));

    T_from toMax = static_cast<T_from>(integral_limits<T_to>::maximum());

    if (from > toMax)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_different_sign_FROM_is_signed_FROM_largerthan_TO(
    T_from  from
,   no_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    STLSOFT_STATIC_ASSERT(sizeof(T_from) == sizeof(T_to));
    STLSOFT_STATIC_ASSERT(0 != int(FROM_is_signed));
    STLSOFT_STATIC_ASSERT(0 == int(TO_is_signed));

    T_to const toMax = integral_limits<T_to>::maximum();

    if (toMax < static_cast<T_to>(from))
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_different_sign_FROM_is_signed_FROM_smallerthan_TO(
    T_from
,   yes_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    STLSOFT_STATIC_ASSERT(sizeof(T_from) < sizeof(T_to));
    STLSOFT_STATIC_ASSERT(0 != int(FROM_is_signed));
    STLSOFT_STATIC_ASSERT(0 == int(TO_is_signed));

    return true;
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_different_sign_FROM_is_signed_FROM_smallerthan_TO(
    T_from  from
,   no_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    STLSOFT_STATIC_ASSERT(sizeof(T_from) >= sizeof(T_to));
    STLSOFT_STATIC_ASSERT(0 != int(FROM_is_signed));
    STLSOFT_STATIC_ASSERT(0 == int(TO_is_signed));

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    STLSOFT_SUPPRESS_UNUSED(sizeofFROM);
    STLSOFT_SUPPRESS_UNUSED(sizeofTO);

    typedef ss_typename_type_k value_to_yesno_type<sizeofTO < sizeofFROM>::type FROM_largerthan_TO_yesno_t;

    return truncation_test_helper_runtime_test_different_sign_FROM_is_signed_FROM_largerthan_TO(from, FROM_largerthan_TO_yesno_t(), T_to());
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_different_sign_FROM_is_signed(
    T_from  from
,   yes_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    STLSOFT_SUPPRESS_UNUSED(sizeofFROM);
    STLSOFT_SUPPRESS_UNUSED(sizeofTO);

    STLSOFT_STATIC_ASSERT((0 == int(TO_is_signed)) != (0 == int(FROM_is_signed)));
    STLSOFT_STATIC_ASSERT(0 != int(FROM_is_signed));
    STLSOFT_STATIC_ASSERT(0 == int(TO_is_signed));

    // T_from is signed
    // T_to is unsigned
    //
    // Truncation occurs if:
    //
    // - from < 0
    // - from > toMax
    // - from

    if (from < 0)
    {
        return false;
    }

    typedef ss_typename_type_k value_to_yesno_type<sizeofFROM < sizeofTO>::type FROM_smallerthan_TO_yesno_t;

    return truncation_test_helper_runtime_test_different_sign_FROM_is_signed_FROM_smallerthan_TO(from, FROM_smallerthan_TO_yesno_t(), T_to());
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_different_sign_FROM_is_signed(
    T_from  from
,   no_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    STLSOFT_SUPPRESS_UNUSED(sizeofFROM);
    STLSOFT_SUPPRESS_UNUSED(sizeofTO);

    STLSOFT_STATIC_ASSERT((0 == int(TO_is_signed)) != (0 == int(FROM_is_signed)));
    STLSOFT_STATIC_ASSERT(0 == int(FROM_is_signed));
    STLSOFT_STATIC_ASSERT(0 != int(TO_is_signed));

    // T_from is unsigned
    // T_to is signed
    //
    // Truncation occurs if from > toMax

    T_from const toMax = static_cast<T_from>(integral_limits<T_to>::maximum());

    if (from > toMax)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_same_sign(
    T_from  from
,   yes_type
,   T_to      // The use of the dummy variable is to work around a defect int VC++ 5-7.0
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    STLSOFT_STATIC_ASSERT(sizeofTO < sizeofFROM);
    STLSOFT_SUPPRESS_UNUSED(sizeofTO);
    STLSOFT_SUPPRESS_UNUSED(sizeofFROM);

    // This is a fully runtime test: does T_from fit into T_to's limits?
    //
    // To do this we elicit T_to's min and max. The values are held in
    // T_from, which involves no truncation because sizeof(T_from) > sizeof(T_to)

    T_from const    toMax   =   static_cast<T_from>(integral_limits<T_to>::maximum());
    T_from const    toMin   =   static_cast<T_from>(integral_limits<T_to>::minimum());

    if (from < toMin ||
        from > toMax)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test_same_sign(
    T_from  from
,   no_type
,   T_to
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    enum {  TO_is_signed        =   is_signed_type<T_to>::value     };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value   };

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    STLSOFT_SUPPRESS_UNUSED(sizeofFROM);
    STLSOFT_SUPPRESS_UNUSED(sizeofTO);

    STLSOFT_STATIC_ASSERT((0 == int(TO_is_signed)) != (0 == int(FROM_is_signed)));

    typedef ss_typename_type_k value_to_yesno_type<FROM_is_signed>::type    same_sign_yesno_t;

    return truncation_test_helper_runtime_test_different_sign_FROM_is_signed<T_to>(from, same_sign_yesno_t(), T_to());
}



template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_helper_runtime_test(
    T_from  from
,   no_type
,   T_to    // The use of the dummy variable is to fix a defect in VC++ 5-7.0
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    // Types are different

    // Next test for same sign
    enum {  TO_is_signed            =   is_signed_type<T_to>::value                 };
    enum {  FROM_is_signed          =   is_signed_type<T_from>::value               };

    enum {  types_have_same_sign    =   int(TO_is_signed) == int(FROM_is_signed)    };

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    STLSOFT_STATIC_ASSERT(sizeofFROM >= sizeofTO || FROM_is_signed);
    STLSOFT_SUPPRESS_UNUSED(sizeofTO);
    STLSOFT_SUPPRESS_UNUSED(sizeofFROM);

    typedef ss_typename_type_k value_to_yesno_type<types_have_same_sign>::type  same_sign_yesno_t;

    return truncation_test_helper_runtime_test_same_sign<T_to>(from, same_sign_yesno_t(), T_to());
}

template<
    typename T
>
inline
bool
truncation_test_helper_runtime_test(
    T
,   yes_type
,   ...
)
{
    return true;
}

template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test_(
    T_from  from
,   T_to    dummy = T_to()  // The use of the dummy variable is to fix a defect in VC++ 5-7.0
)
{
#ifdef STLSOFT_DEBUG
    stlsoft_INTERNAL_truncation_test_CrtDbg_scoper  scoper;

    char const* const   TO_     =   typeid(T_to).name();
    char const* const   FROM_   =   typeid(T_from).name();

    STLSOFT_SUPPRESS_UNUSED(TO_);
    STLSOFT_SUPPRESS_UNUSED(FROM_);
#endif /* STLSOFT_DEBUG */

    // First, we must check that the types are compatible, with constraints

    // Both types must be integral
    STLSOFT_STATIC_ASSERT(0 != is_integral_type<T_to>::value);
    STLSOFT_STATIC_ASSERT(0 != is_integral_type<T_from>::value);

    // Now calculate the sizes

    ss_size_t const sizeofFROM  =   sizeof(T_from);
    ss_size_t const sizeofTO    =   sizeof(T_to);

    // Now determine the signs

    enum {  TO_is_signed        =   is_signed_type<T_to>::value           };
    enum {  FROM_is_signed      =   is_signed_type<T_from>::value         };

    // We know at compile time that T_from fits into T_to if:
    //
    // - they have the same sign, and sizeof(T_from) <= sizeof(T_to), OR
    // - T_from is unsigned (and T_to is signed), and sizeof(T_from) < sizeof(T_to)
    //
    // If either of these hold, then the answer is true: the yes_type overload
    //  of truncation_test_helper_runtime_test() is selected.
    //
    // If not, then a runtime test is required: the no_type overload
    //  of truncation_test_helper_runtime_test() is selected.

    enum { types_are_statically_compatible  =
                                                (   int(TO_is_signed) == int(FROM_is_signed) &&
                                                    sizeofFROM <= sizeofTO)
                                            ||
                                                (   !FROM_is_signed &&
                                                    sizeofFROM < sizeofTO)  };

    typedef ss_typename_type_k value_to_yesno_type<types_are_statically_compatible>::type   yesno_t;

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     defined(_Wp64) && \
     !defined(_WIN64)
#  pragma warning(push)
#  pragma warning(disable : 4267)
# endif /* VC++ + Win32 + _Wp32 */

    return truncation_test_helper_runtime_test<T_to>(from, yesno_t(), dummy);

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     defined(_Wp64) && \
     !defined(_WIN64)
#  pragma warning(pop)
# endif /* VC++ + Win32 + _Wp32 */
}


#if 0
template<
    ss_typename_param_k T_to
>
class truncation_test
{
public:
    template<
        ss_typename_param_k T_from
    >
    truncation_test(T_from from)
        : m_b(truncation_test_(from, get_to_()))
    {}

public:
    operator bool () const
    {
        return m_b;
    }

private:
    static T_to get_to_()
    {
        return T_to();
    }

private:
    bool const m_b;
};
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** Indicates whether a given value can be cast to a given type without
 * truncation
 *
 * \ingroup group__library__Conversion
 *
 * Example:
<pre>
  truncation_cast&lt;unsigned>(-1); // Will return false, since negatives cannot fit in unsigned
  truncation_cast&lt;short>(30000); // Will return true, since 30000 will fit inside short (assuming short has >= 16-bits)
</pre>
 *
 * \param from The value to be tested
 *
 * \retval false The value will experience truncation
 * \retval true The value will not be truncated
 */
template<
    ss_typename_param_k T_to
,   ss_typename_param_k T_from
>
inline
bool
truncation_test(
    T_from  from
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
,   T_to    dummy = T_to() // The use of the dummy variable is to fix a defect in VC++ 5-7.0
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
)
{
    return truncation_test_(from, dummy);
}

#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_TEST */

/* ///////////////////////////// end of file //////////////////////////// */

