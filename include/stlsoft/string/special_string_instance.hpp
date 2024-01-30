/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/string/special_string_instance.hpp
 *
 * Purpose:     Special string instance class template.
 *
 * Created:     3rd June 2006
 * Updated:     22nd January 2024
 *
 * Thanks to:   Pablo Aguilar for spotting my omission of string access shims
 *              for special_string_instance_1.
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


/** \file stlsoft/string/special_string_instance.hpp
 *
 * \brief [C++] Definition of the stlsoft::special_string_instance
 *  class template
 *   (\ref group__library__String "String" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE
#define STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_MAJOR       1
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_MINOR       5
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_REVISION    4
# define STLSOFT_VER_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE_EDIT        43
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

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE
# include <stlsoft/meta/is_fundamental_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE
# include <stlsoft/meta/is_same_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_SAME_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE
# include <stlsoft/meta/is_void_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF
# include <stlsoft/meta/select_first_type_if.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE
# include <stlsoft/synch/lock_scope.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SYNCH_HPP_LOCK_SCOPE */

#ifndef STLSOFT_INCL_STLSOFT_API_external_h_string
# include <stlsoft/api/external/string.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_external_h_string */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

struct ssi_initex_default
{
public:
    static
    size_t
    initial_size()
    {
        return 0;
    }
};

template<
    ss_typename_param_k T_character
,   ss_size_t           N
,   ss_typename_param_k T_allocator
,   ss_typename_param_k T_arg0
>
struct ssi_buffer
{
/// \name Member Types
/// @{
public:
    /// The character type
    typedef T_character                                     char_type;
    /// The allocator type
    typedef T_allocator                                     allocator_type;
    /// The size type
    typedef ss_size_t                                       size_type;
    /// The argument type
    typedef T_arg0                                          argument_0_type;
    /// The class type
    typedef ssi_buffer<T_character, N, T_allocator, T_arg0> class_type;
private:
    /// The buffer type
    typedef stlsoft::auto_buffer<
        char_type
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    ,   128
#else /* ? compiler */
    ,   N
#endif /* compiler */
    ,   allocator_type
    >                                                       buffer_type_;
/// @}

/// \name Construction
/// @{
public:
    ssi_buffer()
        : m_len(0)
        , m_buffer(0)
    {}
#if 0 || \
    defined(STLSOFT_COMPILER_IS_CLANG) || \
    defined(STLSOFT_COMPILER_IS_GCC) || \
    0
    ssi_buffer(class_type const& rhs)
        : m_len(rhs.m_len)
        , m_buffer(rhs.m_len + 1)
    {
        STLSOFT_API_INTERNAL_memfns_memcpy(&m_buffer[0], &rhs.m_buffer[0], sizeof(char_type) * (1u + m_len));
    }
#endif /* compiler */

    void
    init(
        size_type   initial
    ,   size_type (*pfn)(char_type*, size_type)
    )
    {
        m_buffer.resize(initial);

#if 1
        size_type cch = pfn(&m_buffer[0], m_buffer.size());

        if (cch < m_buffer.size())
        {
            m_len = cch;

            m_buffer[m_len] = '\0';

            return;
        }
#else
        // We don't pass NULL here, just in case
        char_type empty =   '\0';
        size_type cch   =   pfn(&empty, 0);
#endif

        if (m_buffer.resize(1 + cch))
        {
            for (;;)
            {
                cch = pfn(&m_buffer[0], m_buffer.size());

                if (cch < m_buffer.size())
                {
                    m_len = cch;
                    break;
                }
                else
                {
                    if (!m_buffer.resize(2 * m_buffer.size()))
                    {
                        m_buffer.resize(0);
                        break;
                    }
                }
            }
        }

        m_buffer[m_len] = '\0';
    }

    void
    init(
        size_type       initial
    ,   size_type     (*pfn)(argument_0_type, char_type*, size_type)
    ,   argument_0_type arg0
    )
    {
        m_buffer.resize(initial);

#if 1
        size_type cch = pfn(arg0, &m_buffer[0], m_buffer.size());

        if (cch < m_buffer.size())
        {
            m_len = cch;

            m_buffer[m_len] = '\0';

            return;
        }
#else
        // We don't pass NULL here, just in case
        char_type   empty   =   '\0';
        size_type   cch     =   pfn(arg0, &empty, 0);
#endif

        if (m_buffer.resize(1 + cch))
        {
            for (;;)
            {
                cch = pfn(arg0, &m_buffer[0], m_buffer.size());

                if (cch < m_buffer.size())
                {
                    m_len = cch;
                    break;
                }
                else
                {
                    if (!m_buffer.resize(2 * m_buffer.size()))
                    {
                        m_buffer.resize(0);
                        break;
                    }
                }
            }
        }

        m_buffer[m_len] = '\0';
    }
/// @}

/// \name Accessors
/// @{
public:
    char_type const* data() const
    {
        return m_buffer.data();
    }
    size_type       length() const
    {
        return m_len;
    }
/// @}

/// \name Members
/// @{
private:
    size_type       m_len;
    buffer_type_    m_buffer;
/// @}
};

template<
    ss_typename_param_k T_character
,   ss_size_t           N
,   ss_typename_param_k T_allocator
,   ss_typename_param_k T_arg0
>
struct ssi_buffer_non_static
    : public ssi_buffer<T_character, N, T_allocator, T_arg0>
{
/// \name Member Types
/// @{
public:
    typedef ssi_buffer<T_character, N, T_allocator, T_arg0> ssi_buffer_type;
    typedef ssi_buffer<T_character, N, T_allocator, T_arg0> parent_class_type;
    typedef ssi_buffer_non_static<
        T_character
    ,   N
    ,   T_allocator
    ,   T_arg0
    >                                                       class_type;

    typedef ss_typename_type_k ssi_buffer_type::char_type   char_type;
    typedef ss_typename_type_k ssi_buffer_type::size_type   size_type;
/// @}

/// \name Construction
/// @{
public:
    ssi_buffer_non_static(size_type initial, size_type (*pfn)(char_type*, size_type))
    {
        parent_class_type::init(initial, pfn);
    }
    ssi_buffer_non_static(size_type initial, size_type (*pfn)(T_arg0, char_type*, size_type), T_arg0 a0)
    {
        parent_class_type::init(initial, pfn, a0);
    }
#if 0 || \
    defined(STLSOFT_COMPILER_IS_CLANG) || \
    defined(STLSOFT_COMPILER_IS_GCC) || \
    0
    ssi_buffer_non_static(class_type const& rhs)
        : parent_class_type(rhs)
    {}
#endif /* compiler */
/// @}

/// \name Accessors
/// @{
public:
    char_type const* data() const
    {
        return parent_class_type::data();
    }
    size_type       length() const
    {
        return parent_class_type::length();
    }
/// @}

/// \name Not to be implemented
/// @{
private:
#if 1 && \
    !defined(STLSOFT_COMPILER_IS_CLANG) && \
    !defined(STLSOFT_COMPILER_IS_GCC) && \
    1
    ssi_buffer_non_static(class_type const&);
#endif /* compiler */
    class_type& operator =(class_type const&);
/// @}
};

template<
    ss_typename_param_k T_character
,   ss_size_t           N
,   ss_typename_param_k T_allocator
,   ss_typename_param_k T_arg0
,   ss_typename_param_k T_policy   // Passes policy type, from which spin_mutex_type is elicited, so non-statics do not need to specify it
>
struct ssi_buffer_static
{
/// \name Member Types
/// @{
public:
    typedef ssi_buffer<T_character, N, T_allocator, T_arg0> ssi_buffer_type;
    typedef ssi_buffer_static<
        T_character
    ,   N
    ,   T_allocator
    ,   T_arg0
    ,   T_policy
    >                                                       class_type;

    typedef ss_typename_type_k ssi_buffer_type::char_type   char_type;
    typedef ss_typename_type_k ssi_buffer_type::size_type   size_type;
private:
    typedef T_policy                                        policy_type;
    typedef ss_typename_type_k policy_type::spin_mutex_type spin_mutex_type;
    typedef ss_typename_type_k policy_type::atomic_int_type atomic_int_type;
/// @}

/// \name Construction
/// @{
public:
    ssi_buffer_static(size_type initial, size_type (*pfn)(char_type*, size_type))
        : m_buffer(get_buffer(initial, pfn))
    {}
    ssi_buffer_static(size_type initial, size_type (*pfn)(T_arg0, char_type*, size_type), T_arg0 a0)
        : m_buffer(get_buffer(initial, pfn, a0))
    {}
#if 0 || \
    defined(STLSOFT_COMPILER_IS_CLANG) || \
    defined(STLSOFT_COMPILER_IS_GCC) || \
    0
    ssi_buffer_static(class_type const& rhs)
        : m_buffer(rhs.m_buffer)
    {}
#endif /* compiler */
/// @}

/// \name Accessors
/// @{
public:
    char_type const* data() const
    {
        return m_buffer.data();
    }
    size_type       length() const
    {
        return m_buffer.length();
    }
/// @}

/// \name Implementation
/// @{
private:
    static ssi_buffer_type& get_buffer(size_type initial, size_type (*pfn)(char_type*, size_type))
    {
        static atomic_int_type                  s_count =   0;
        static bool                             s_bInit =   false;
        spin_mutex_type                         mx(&s_count);
        stlsoft::lock_scope<spin_mutex_type>    lock(mx);

        static ssi_buffer_type                  s_buffer;

        if (!s_bInit)
        {
            s_buffer.init(initial, pfn);

            s_bInit = true;
        }

        return s_buffer;
    }
    static ssi_buffer_type& get_buffer(size_type initial, size_type (*pfn)(T_arg0, char_type*, size_type), T_arg0 a0)
    {
        static atomic_int_type                  s_count =   0;
        static bool                             s_bInit =   false;
        spin_mutex_type                         mx(&s_count);
        stlsoft::lock_scope<spin_mutex_type>    lock(mx);

        static ssi_buffer_type                  s_buffer;

        if (!s_bInit)
        {
            s_buffer.init(initial, pfn, a0);

            s_bInit = true;
        }

        return s_buffer;
    }
/// @}

/// \name Members
/// @{
private:
    ssi_buffer_type&    m_buffer;
/// @}

/// \name Not to be implemented
/// @{
private:
#if 1 && \
    !defined(STLSOFT_COMPILER_IS_CLANG) && \
    !defined(STLSOFT_COMPILER_IS_GCC) && \
    1
    ssi_buffer_static(class_type const&);
#endif /* compiler */
    class_type& operator =(class_type const&);
/// @}
};

template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_ssi
>
struct special_string_instance_base
{
public: // types
    /// The policy type.
    typedef T_policy                                        policy_type;
    /// The SSI type
    typedef T_ssi                                           ssi_type;
    /// The character type
    typedef ss_typename_type_k policy_type::char_type       char_type;
    /// The size type
    typedef ss_typename_type_k policy_type::size_type       size_type;

private: // constants
    enum { caseSensitive = policy_type::caseSensitive };

public: // operations
    template <ss_typename_param_k T_string>
    bool
    equal(
        T_string const&   s
    ) const
    {
        T_ssi const& ssi = static_cast<T_ssi const&>(*this);

        return equal_n_(
            ssi.data(), ssi.size()
        ,   stlsoft::c_str_data(s), stlsoft::c_str_len(s)
        );
    }

private: // implementation
    bool
    equal_n_(
        char_type const*  s1
    ,   size_type         cch1
    ,   char_type const*  s2
    ,   size_type         cch2
    ) const
    {
        typedef ss_typename_type_k value_to_yesno_type<caseSensitive>::type   yesno_t;

        if (cch1 != cch2)
        {
            return false;
        }

        return equal_iscasesensitive_(
            s1, cch1
        ,   s2, cch2
        ,   yesno_t()
        );
    }

    bool
    equal_iscasesensitive_(
        char_type const*      s1
    ,   size_type             cch1
    ,   char_type const*      s2
    ,   size_type             cch2
    ,   yes_type
    ) const
    {
        return equal_casesensitive_(s1, cch1, s2, cch2);
    }

    bool
    equal_iscasesensitive_(
        char_type const*      s1
    ,   size_type             cch1
    ,   char_type const*      s2
    ,   size_type             cch2
    ,   no_type
    ) const
    {
        return equal_caseinsensitive_(s1, cch1, s2, cch2);
    }

    bool
    equal_casesensitive_(
        ss_char_a_t const*    s1
    ,   size_type             cch1
    ,   ss_char_a_t const*    s2
    ,   size_type          /* cch2 */
    ) const
    {
        return 0 == ::strncmp(s1, s2, cch1);
    }

    bool
    equal_casesensitive_(
        ss_char_w_t const*    s1
    ,   size_type             cch1
    ,   ss_char_w_t const*    s2
    ,   size_type          /* cch2 */
    ) const
    {
        return 0 == ::wcsncmp(s1, s2, cch1);
    }

    bool
    equal_caseinsensitive_(
        ss_char_a_t const*    s1
    ,   size_type             cch1
    ,   ss_char_a_t const*    s2
    ,   size_type          /* cch2 */
    ) const
#ifdef STLSOFT_API_EXTERNAL_string_strnicmp
    {
        return 0 == STLSOFT_API_EXTERNAL_string_strnicmp(s1, s2, cch1);
    }
#else
    ;
#endif

    bool
    equal_caseinsensitive_(
        ss_char_w_t const*    s1
    ,   size_type             cch1
    ,   ss_char_w_t const*    s2
    ,   size_type          /* cch2 */
    ) const
#ifdef STLSOFT_API_EXTERNAL_string_wcsnicmp
    {
        return 0 == STLSOFT_API_EXTERNAL_string_wcsnicmp(s1, s2, cch1);
    }
#else
    ;
#endif
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** Base type for policies
 *
 * \tparam T_character The character type
 * \tparam T_arg0 The argument type for 1-parameter special string instances
 * \tparam T_allocator The allocator type. Defaults to the appropriate
 *   allocator specialisation provided by stlsoft::allocator_selector
 */
template<
    ss_typename_param_k T_character
,   ss_typename_param_k T_arg0 = ss_template_void_k
,   ss_typename_param_k T_allocator = ss_typename_type_def_k allocator_selector<T_character>::allocator_type
>
struct special_string_instance_policy_base
{
// types
public:
    /// The character type
    typedef T_character                                     char_type;
    /// The type of argument
    typedef T_arg0                                          argument_0_type;
    /// The allocator type
    typedef T_allocator                                     allocator_type;
    /// The size type
    typedef ss_size_t                                       size_type;

// types that must be overridden by inheriting types
private:
    typedef void                                            pfn_type;

// constants
public:
    enum { allowImplicitConversion = 0 };

    enum { caseSensitive = 0 };

    enum { sharedState = 0 };

    enum { internalBufferSize = -1 };
};


/** Special string instance class template.
 *
 * \ingroup group__library__String
 *
 * \tparam T_policy The SSI policy type.
 * \tparam T_initex An additional initialisation type
 *
 * The policy type provides the following:
 *
 * - A member constant <code>internalBufferSize</code> that determines the
 *   size of the SSI's internal
 *   \link stlsoft::auto_buffer auto_buffer\endlink's internal buffer size.
 * - A static method <code>get_value(char_type* buffer, size_type cchBuffer)</code>
 *   that has the
 * - A member constant <code>allowImplicitConversion</code> that determines
 *   whether an implicit conversion operator (to
 *   <code>char_type const*</code>) is to be provided.
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex = ss_template_void_k
>
class special_string_instance_0
    : public special_string_instance_base<T_policy, special_string_instance_0<T_policy, T_initex> >
{
/// \name Member Types
/// @{
public:
    /// The policy type
    typedef T_policy                                        policy_type;
    /// The initialisation policy type
    typedef T_initex                                        initex_policy_type;
    /// The current instantiation of the template.
    typedef special_string_instance_0<T_policy, T_initex>   class_type;
    /// The character type
    typedef ss_typename_type_k policy_type::char_type       char_type;
    /// The size type
    typedef ss_typename_type_k policy_type::size_type       size_type;

    /// The character type for ANSI specialisations
    ///
    /// \note This is used in the specification of the string access shim
    ///  functions.
private:
    enum { charTypeIsAnsi = is_same_type<ss_char_a_t, char_type>::value };
public:
    typedef ss_typename_type_k select_first_type_if<
        ss_char_a_t const*
    ,   void
    ,   charTypeIsAnsi
    >::type                                                 cstring_a_type;
    /// The character type for Unicode specialisations
    ///
    /// \note This is used in the specification of the string access shim
    ///  functions.
private:
    enum { charTypeIsWide = is_same_type<ss_char_w_t, char_type>::value };
public:
    typedef ss_typename_type_k select_first_type_if<
        ss_char_w_t const*
    ,   void
    ,   charTypeIsWide
    >::type                                                 cstring_w_type;
private:
    typedef ss_typename_type_k policy_type::pfn_type        pfn_type;
private:
    // This section allows for the case where the policy does not define an
    // allocator, which it indicates by defining its member type
    // allocator_type to be void.
    typedef ss_typename_type_k policy_type::allocator_type  putative_allocator_type;
    enum
    {
        policy_has_allocator_type       =   (0 != size_of<putative_allocator_type>::value)
    };
    typedef ss_typename_type_k allocator_selector<
        char_type
    >::allocator_type                                       backup_allocator_type;
public:
    /// The allocator type
    typedef ss_typename_type_k select_first_type_if<
        putative_allocator_type
    ,   backup_allocator_type
    ,   policy_has_allocator_type
    >::type                                                 allocator_type;
private:
    enum { allowImplicitConversion = policy_type::allowImplicitConversion };
public:
    /// The implicit conversion operator type
    typedef ss_typename_type_k select_first_type_if<
        char_type const*
    ,   void
    ,   allowImplicitConversion
    >::type                                                 implicit_conversion_type;
private:
    // This section accounts for whether the policy indicates shared state.
    // If so, then the buffer type resolves to the appropriate
    // specialisation of ssi_buffer_static, which stores a threadsafe buffer
    // shared by all instances. If not, then the buffer type resolves to
    // ssi_buffer_non_static, which stores a buffer per instance.
    enum
    {
        policy_indicates_shared_state   =   (0 != policy_type::sharedState)
    };

    enum
    {
        initex_policy_type_provided     =   !is_void_type<initex_policy_type>::value
    };

    enum
    {
        initex_policy_use_policy_type   =   is_fundamental_type<initex_policy_type>::value
    };

    struct null_argument
    {};

    enum { internalBufferSize = policy_type::internalBufferSize };
    typedef ssi_buffer_static<
        char_type
    ,   internalBufferSize
    ,   allocator_type
    ,   null_argument
    ,   policy_type // Passes policy type, from which spin_mutex_type is elicited, so non-statics do not need to specify it
    >                                                       ssi_buffer_static_type;
    typedef ssi_buffer_non_static<
        char_type
    ,   internalBufferSize
    ,   allocator_type
    ,   null_argument
    >                                                       ssi_buffer_non_static_type;

    typedef ss_typename_type_k select_first_type_if<
        ssi_buffer_static_type
    ,   ssi_buffer_non_static_type
    ,   policy_indicates_shared_state
    >::type                                                 buffer_type_;

    typedef ss_typename_type_k select_first_type_if<
        policy_type
    ,   initex_policy_type
    ,   initex_policy_use_policy_type
    >::type                                                 initex_provided_policy_type_;

    typedef ss_typename_type_k select_first_type_if<
        initex_provided_policy_type_
    ,   ssi_initex_default
    ,   initex_policy_type_provided
    >::type                                                 initex_effective_type_;
/// @}

/// \name Construction
/// @{
public:
    special_string_instance_0()
        : m_buffer(initex_effective_type_::initial_size(), policy_type::get_fn())
    {}
/// @}

/// \name Accessors
/// @{
public:
    size_type       length() const
    {
        return m_buffer.length();
    }
    size_type       size() const
    {
        return length();
    }

    char_type const* data() const
    {
        return m_buffer.data();
    }
    char_type const* c_str() const
    {
        return data();
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    cstring_a_type  c_str_a() const
    {
        return c_str();
    }
    cstring_w_type  c_str_w() const
    {
        return c_str();
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Operators
/// @{
public:
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
    operator implicit_conversion_type () const
    {
        return this->c_str();
    }
#endif /* compiler */
/// @}

/// \name Operations
/// @{
public:
    static size_type get(char_type* buffer, size_type cchBuffer)
    {
        return (policy_type::get_fn())(buffer, cchBuffer);
    }
/// @}

/// \name Members
/// @{
private:
    buffer_type_ m_buffer;
/// @}
};

/** Special string instance class template.
 *
 * \ingroup group__library__String
 *
 * \tparam T_policy The SSI policy type.
 * \tparam T_initex An additional initialisation type
 *
 * The policy type provides the following:
 *
 * - A member constant <code>internalBufferSize</code> that determines the
 *   size of the SSI's internal
 *   \link stlsoft::auto_buffer auto_buffer\endlink's internal buffer size.
 * - A static method <code>get_value(char_type* buffer, size_type cchBuffer)</code>
 *   that has the
 * - A member constant <code>allowImplicitConversion</code> that determines
 *   whether an implicit conversion operator (to
 *   <code>char_type const*</code>) is to be provided.
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex = ss_template_void_k
>
class special_string_instance_1
    : public special_string_instance_base<T_policy, special_string_instance_1<T_policy, T_initex> >
{
/// \name Member Types
/// @{
public:
    /// The policy type.
    typedef T_policy                                        policy_type;
    /// The initialisation policy type
    typedef T_initex                                        initex_policy_type;
    /// The current instantiation of the template.
    typedef special_string_instance_1<T_policy, T_initex>   class_type;
    /// The character type
    typedef ss_typename_type_k policy_type::char_type       char_type;
    /// The size type
    typedef ss_typename_type_k policy_type::size_type       size_type;
    /// The argument type
    typedef ss_typename_type_k policy_type::argument_0_type argument_0_type;

    /// The character type for ANSI specialisations
    ///
    /// \note This is used in the specification of the string access shim
    ///  functions.
private:
    enum { charTypeIsAnsi = is_same_type<ss_char_a_t, char_type>::value };
public:
    typedef ss_typename_type_k select_first_type_if<
        ss_char_a_t const*
    ,   void
    ,   charTypeIsAnsi
    >::type                                                 cstring_a_type;
    /// The character type for Unicode specialisations
    ///
    /// \note This is used in the specification of the string access shim
    ///  functions.
private:
    enum { charTypeIsWide = is_same_type<ss_char_w_t, char_type>::value };
public:
    typedef ss_typename_type_k select_first_type_if<
        ss_char_w_t const*
    ,   void
    ,   charTypeIsWide
    >::type                                                 cstring_w_type;
private:
    typedef ss_typename_type_k policy_type::pfn_type        pfn_type;
private:
    // This section allows for the case where the policy does not define an
    // allocator, which it indicates by defining its member type
    // allocator_type to be void.
    typedef ss_typename_type_k policy_type::allocator_type  putative_allocator_type;
    enum
    {
        policy_has_allocator_type       =   (0 != size_of<putative_allocator_type>::value)
    };
    typedef ss_typename_type_k allocator_selector<
        char_type
    >::allocator_type                                       backup_allocator_type;
public:
    /// The allocator type
    typedef ss_typename_type_k select_first_type_if<
        putative_allocator_type
    ,   backup_allocator_type
    ,   policy_has_allocator_type
    >::type                                                 allocator_type;

    /// The implicit conversion operator type
private:
    enum { allowImplicitConversion = policy_type::allowImplicitConversion };
public:
    typedef ss_typename_type_k select_first_type_if<
        char_type const*
    ,   void
    ,   allowImplicitConversion
    >::type                                                 implicit_conversion_type;
private:
    // This section accounts for whether the policy indicates shared state.
    // If so, then the buffer type resolves to the appropriate
    // specialisation of ssi_buffer_static, which stores a threadsafe buffer
    // shared by all instances. If not, then the buffer type resolves to
    // ssi_buffer_non_static, which stores a buffer per instance.
    enum
    {
        policy_indicates_shared_state   =   (0 != policy_type::sharedState)
    };

    enum
    {
        initex_policy_type_provided     =   !is_void_type<initex_policy_type>::value
    };

    enum { internalBufferSize = policy_type::internalBufferSize };
    typedef ssi_buffer_static<
        char_type
    ,   internalBufferSize
    ,   allocator_type
    ,   argument_0_type
    ,   policy_type // Passes policy type, from which spin_mutex_type is elicited, so non-statics do not need to specify it
    >                                                       ssi_buffer_static_type;
    typedef ssi_buffer_non_static<
        char_type
    ,   internalBufferSize
    ,   allocator_type
    ,   argument_0_type
    >                                                       ssi_buffer_non_static_type;

    typedef ss_typename_type_k select_first_type_if<
        ssi_buffer_static_type
    ,   ssi_buffer_non_static_type
    ,   policy_indicates_shared_state
    >::type                                                 buffer_type_;

    typedef ss_typename_type_k select_first_type_if<
        initex_policy_type
    ,   ssi_initex_default
    ,   initex_policy_type_provided
    >::type                                                 initex_effective_type_;

/// @}

/// \name Construction
/// @{
public:
    special_string_instance_1(argument_0_type argument)
        : m_buffer(initex_effective_type_::initial_size(), policy_type::get_fn(), argument)
    {}
/// @}

/// \name Operations
/// @{
public:
    static size_type get(argument_0_type argument, char_type* buffer, size_type cchBuffer)
    {
        return (policy_type::get_fn())(argument, buffer, cchBuffer);
    }
/// @}

/// \name Attributes
/// @{
public:
    char_type const* c_str() const
    {
        return m_buffer.data();
    }
    char_type const* data() const
    {
        return m_buffer.data();
    }
    size_type       length() const
    {
        return m_buffer.length();
    }
    size_type       size() const
    {
        return length();
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    cstring_a_type  c_str_a() const
    {
        return c_str();
    }
    cstring_w_type  c_str_w() const
    {
        return c_str();
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
/// @}

/// \name Operators
/// @{
public:
#if !defined(STLSOFT_COMPILER_IS_BORLAND)
    operator implicit_conversion_type () const
    {
        return this->c_str();
    }
#endif /* compiler */
/// @}

/// \name Member Types
/// @{
private:
    buffer_type_ m_buffer;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_ssi
,   ss_typename_param_k T_string
>
bool
operator ==(
    special_string_instance_base<T_policy, T_ssi> const&  lhs
,   T_string const&                                       rhs
)
{
    return lhs.equal(rhs);
}

template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_ssi
,   ss_typename_param_k T_string
>
bool
operator ==(
    T_string const&                                       lhs
,   special_string_instance_base<T_policy, T_ssi> const&  rhs
)
{
    return rhs.equal(lhs);
}

template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_ssi
,   ss_typename_param_k T_string
>
bool
operator !=(
    special_string_instance_base<T_policy, T_ssi> const&  lhs
,   T_string const&                                       rhs
)
{
    return !lhs.equal(rhs);
}

template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_ssi
,   ss_typename_param_k T_string
>
bool
operator !=(
    T_string const&                                       lhs
,   special_string_instance_base<T_policy, T_ssi> const&  rhs
)
{
    return !rhs.equal(lhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for stlsoft::special_string_instance_0
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::char_type const*
c_str_ptr_null(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return (0 != ssi.length()) ? ssi.c_str() : NULL;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::cstring_a_type
c_str_ptr_null_a(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return (0 != ssi.length()) ? ssi.c_str_a() : NULL;
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::cstring_w_type
c_str_ptr_null_w(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return (0 != ssi.length()) ? ssi.c_str_w() : NULL;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for stlsoft::special_string_instance_0
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::char_type const*
c_str_ptr(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::cstring_a_type
c_str_ptr_a(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_a();
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::cstring_w_type
c_str_ptr_w(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_w();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for stlsoft::special_string_instance_0
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::char_type const*
c_str_data(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::cstring_a_type
c_str_data_a(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_a();
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_0<T_policy, T_initex>::cstring_w_type
c_str_data_w(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_w();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for stlsoft::special_string_instance_0
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_size_t
c_str_len(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    return ssi.length();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_size_t
c_str_len_a(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    // If this fires, you're trying to invoke c_str_len_w() on an SSI
    // whose policy defines the character type to be something other
    // than char.
    ss_char_a_t const* const special_string_instance_must_use_narrow_character = ssi.c_str_a();

    STLSOFT_SUPPRESS_UNUSED(special_string_instance_must_use_narrow_character);

    return ssi.length();
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_size_t
c_str_len_w(
    STLSOFT_NS_QUAL(special_string_instance_0)<T_policy, T_initex> const& ssi
)
{
    // If this fires, you're trying to invoke c_str_len_w() on an SSI
    // whose policy defines the character type to be something other
    // than wchar_t.
    ss_char_w_t const* const special_string_instance_must_use_wide_character = ssi.c_str_w();

    STLSOFT_SUPPRESS_UNUSED(special_string_instance_must_use_wide_character);

    return ssi.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for stlsoft::special_string_instance_1
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::char_type const*
c_str_ptr_null(STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi)
{
    return (0 != ssi.length()) ? ssi.c_str() : NULL;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::cstring_a_type
c_str_ptr_null_a(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return (0 != ssi.length()) ? ssi.c_str_a() : NULL;
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::cstring_w_type
c_str_ptr_null_w(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return (0 != ssi.length()) ? ssi.c_str_w() : NULL;
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for stlsoft::special_string_instance_1
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::char_type const*
c_str_ptr(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return
    ssi.c_str()
;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::cstring_a_type
c_str_ptr_a(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_a();
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::cstring_w_type
c_str_ptr_w(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_w();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for stlsoft::special_string_instance_1
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::char_type const*
c_str_data(STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi)
{
    return
    ssi.c_str()
;
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::cstring_a_type
c_str_data_a(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_a();
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_typename_type_ret_k special_string_instance_1<T_policy, T_initex>::cstring_w_type
c_str_data_w(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return ssi.c_str_w();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for stlsoft::special_string_instance_1
 *
 * \ingroup group__concept__Shim__string_access
 */
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_size_t
c_str_len(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    return ssi.length();
}
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_size_t
c_str_len_a(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    // If this fires, you're trying to invoke c_str_len_w() on an SSI
    // whose policy defines the character type to be something other
    // than char.
    ss_char_a_t const* const special_string_instance_must_use_narrow_character = ssi.c_str_a();

    STLSOFT_SUPPRESS_UNUSED(special_string_instance_must_use_narrow_character);

    return ssi.length();
}
template<
    ss_typename_param_k T_policy
,   ss_typename_param_k T_initex
>
inline
ss_size_t
c_str_len_w(
    STLSOFT_NS_QUAL(special_string_instance_1)<T_policy, T_initex> const& ssi
)
{
    // If this fires, you're trying to invoke c_str_len_w() on an SSI
    // whose policy defines the character type to be something other
    // than wchar_t.
    ss_char_w_t const* const special_string_instance_must_use_wide_character = ssi.c_str_w();

    STLSOFT_SUPPRESS_UNUSED(special_string_instance_must_use_wide_character);

    return ssi.length();
}
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

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

#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SPECIAL_STRING_INSTANCE */

/* ///////////////////////////// end of file //////////////////////////// */

