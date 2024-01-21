/* /////////////////////////////////////////////////////////////////////////
 * File:        unixstl/filesystem/file_path_buffer.hpp
 *
 * Purpose:     Contains the basic_file_path_buffer template class.
 *
 * Created:     24th May 2004
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/* STLSOFT:FILE_DEPRECATED */

/** \file unixstl/filesystem/file_path_buffer.hpp
 *
 * \brief [C++] Definition of the unixstl::basic_file_path_buffer class
 *  template
 *   (\ref group__library__FileSystem "File System" Library).
 */

#ifndef UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER
#define UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_MAJOR      4
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_MINOR      3
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_REVISION   10
# define UNIXSTL_VER_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER_EDIT       85
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# include <unixstl/unixstl.h>
#endif /* !UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifdef STLSOFT_PPF_pragma_message_SUPPORT
# pragma message(STLSOFT_FILELINE_MESSAGE("This file and the (basic_)file_path_buffer<> component are deprecated, and will be removed from a future version"))
#endif /* STLSOFT_PPF_pragma_message_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
# include <stlsoft/memory/util/allocator_selector.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
#ifndef UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_HPP_STRING
# include <unixstl/shims/access/string.hpp>
#endif /* !UNIXSTL_INCL_UNIXSTL_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS
# include <stlsoft/string/copy_functions.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_COPY_FUNCTIONS */

#ifndef STLSOFT_INCL_H_UNISTD
# define STLSOFT_INCL_H_UNISTD
# include <unistd.h>
#endif /* !STLSOFT_INCL_H_UNISTD */

#ifdef STLSOFT_DEBUG
# include <stlsoft/algorithms/pod.hpp>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::unixstl */
namespace unixstl
{
# else
/* Define stlsoft::unixstl_project */

namespace stlsoft
{
namespace unixstl_project
{

# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class basic_file_path_buffer
/** Acts as a buffer with sufficient size for any drive on the host machine
 *
 * \ingroup group__library__FileSystem
 *
 * This class is a non-template class primarily so that separate instantiations
 * are not created for each instantiation of the basic_file_path_buffer.
 *
 * This class provides a simple function, which is to provide the maximum path
 * length for the host. This information is then cached due to the static nature
 * of the get_drivesvar_() method, although it can be reset by calling the
 * refresh() method on the buffer class.
 *
 * \param C The character type
 * \param A The allocator type
 */
template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        >
class basic_file_path_buffer
{
/// \name Member Constants
/// @{
private:
    enum
    {
#ifdef PATH_MAX
        internalBufferSize  =   1 + PATH_MAX
#else /* ? PATH_MAX */
        internalBufferSize  =   1 + 512
#endif /* PATH_MAX */
    };

    enum
    {
        indeterminateMaxPathGuess   =   2048
    };

    typedef STLSOFT_NS_QUAL(auto_buffer)<
        C
    ,   internalBufferSize
    ,   A
    >                                                       buffer_type_;
/// @}

/// \name Member Types
/// @{
public:
    /// The character type
    typedef C                                               char_type;
    /// The allocator type
    typedef A                                               allocator_type;
    /// The current specialisation of the type
    typedef basic_file_path_buffer<C, A>                    class_type;
    /// The value type
    typedef ss_typename_type_k buffer_type_::value_type     value_type;
    /// The reference type
    typedef value_type&                                     reference;
    /// The non-mutating (const) reference type
    typedef value_type const&                               const_reference;
    /// The size type
    typedef ss_typename_type_k buffer_type_::size_type      size_type;
/// @}

/// \name Construction
/// @{
public:
    /// Default constructor
    STLSOFT_DEPRECATED_("basic_file_path_buffer is deprecated, and will be removed from a future release") // applied here rather than on template because above class_type precipitates
    basic_file_path_buffer()
        : m_buffer(1 + calc_path_max_())
    {
#ifdef STLSOFT_DEBUG
        STLSOFT_NS_QUAL(pod_fill_n)(&m_buffer[0], m_buffer.size(), static_cast<char_type>('?'));
        m_buffer[m_buffer.size() - 1] = '\0';
#endif /* STLSOFT_DEBUG */
    }
    /// Copy constructor
    basic_file_path_buffer(class_type const& rhs)
        : m_buffer(rhs.size())
    {
        STLSOFT_NS_QUAL(pod_copy_n)(data(), rhs.data(), m_buffer.size());
    }
    /// Copy assignment operator
    class_type& operator =(class_type const& rhs)
    {
        m_buffer.resize(rhs.size());
        STLSOFT_NS_QUAL(pod_copy_n)(data(), rhs.data(), m_buffer.size());

        return *this;
    }
/// @}

/// \name Operations
/// @{
public:
    /// Swaps the contents with those of another instance
    ///
    /// \param rhs The instance whose contents will be swapped with the
    ///  callee
    ///
    /// \note The complexity of this operation is not guaranteed
    ///  to be constant-time. See the documentation for
    ///  \link stlsoft::auto_buffer auto_buffer\endlink for
    ///  further details.
    void swap(class_type& rhs) STLSOFT_NOEXCEPT
    {
        m_buffer.swap(rhs.m_buffer);
    }
    /// Resizes the buffer to the given size.
    us_bool_t grow(size_type newSize)
    {
        return m_buffer.resize(newSize);
    }
    /// Doubles the size of the buffer
    us_bool_t grow()
    {
        return grow(2 * size());
    }
/// @}

/// \name Accessors
/// @{
public:
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    value_type const*   data() const
    {
        return m_buffer.data();
    }
    value_type*         data()
    {
        return m_buffer.data();
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /// Returns a pointer to a nul-terminated string
    value_type const* c_str() const
    {
        return this->data();
    }

    /// Returns a mutable (non-const) pointer to the internal buffer
    reference operator [](us_size_t index)
    {
        buffer_type_& this_ = m_buffer;

        return this_[index];
    }
#if !defined(STLSOFT_COMPILER_IS_COMO) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)
    /// Returns a non-mutable (const) pointer to the internal buffer
    const_reference operator [](us_size_t index) const
    {
        UNIXSTL_MESSAGE_ASSERT("Index out of range", !(size() < index));

        return data()[index];
    }
#endif /* compiler */

    /// Returns the size of the internal buffer
    size_type size() const
    {
        return m_buffer.size();
    }

    /// Returns the maximum size of the internal buffer
    static size_type max_size()
    {
        return calc_path_max_();
    }

    /// Copies the contents into a caller supplied buffer
    ///
    /// \param buffer Pointer to character buffer to receive the contents.
    ///  May be NULL, in which case the method returns size().
    /// \param cchBuffer Number of characters of available space in \c buffer.
    size_type copy(char_type* buffer, size_type cchBuffer) const
    {
        return STLSOFT_NS_QUAL(copy_contents)(buffer, cchBuffer, m_buffer.data(), m_buffer.size());
    }
/// @}

/// \name Operations
/// @{
public:
    /// Causes the drives to be examined again for the next instance.
    ///
    /// \deprecated
    static void refresh() STLSOFT_NOEXCEPT
    {}
/// @}

/// \name Implementation
/// @{
private:
    static size_type calc_path_max_()
    {
#ifdef PATH_MAX
        return PATH_MAX;
#else /* ? PATH_MAX */
        int pathMax = ::pathconf("/", _PC_PATH_MAX);

        if (pathMax < 0)
        {
            pathMax = indeterminateMaxPathGuess;
        }
        else
        {
            ++pathMax;
        }

        return static_cast<size_type>(pathMax);
#endif /* PATH_MAX */
    }
/// @}

/// \name Members
/// @{
private:
    buffer_type_ m_buffer;
/// @}
};

/* Typedefs to commonly encountered types. */
/** Specialisation of the basic_file_path_buffer template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_path_buffer<us_char_a_t, STLSOFT_NS_QUAL(allocator_selector)<us_char_a_t>::allocator_type>   file_path_buffer_a;
/** Specialisation of the basic_file_path_buffer template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_path_buffer<us_char_w_t, STLSOFT_NS_QUAL(allocator_selector)<us_char_w_t>::allocator_type>   file_path_buffer_w;
/** Specialisation of the basic_file_path_buffer template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_path_buffer<us_char_a_t, STLSOFT_NS_QUAL(allocator_selector)<us_char_a_t>::allocator_type>   file_path_buffer;

/* /////////////////////////////////////////////////////////////////////////
 * Support for PlatformSTL redefinition by inheritance+namespace, for confused
 * compilers (e.g. VC++ 6)
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

    template<   ss_typename_param_k C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
        ,   ss_typename_param_k A = ss_typename_type_def_k allocator_selector<C>::allocator_type
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
        ,   ss_typename_param_k A /* = ss_typename_type_def_k allocator_selector<C>::allocator_type */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
            >
    class basic_file_path_buffer__
        : public UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A>
    {
    private:
        typedef UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A>           parent_class_type;
    public:
        typedef basic_file_path_buffer__<C, A>                          class_type;
        typedef ss_typename_type_k parent_class_type::value_type        value_type;
        typedef ss_typename_type_k parent_class_type::reference         reference;
        typedef ss_typename_type_k parent_class_type::const_reference   const_reference;
        typedef ss_typename_type_k parent_class_type::size_type         size_type;
    };

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * swapping
 */

template<
    ss_typename_param_k C
,   ss_typename_param_k A
>
inline
void
swap(
    basic_file_path_buffer<C, A>& lhs
,   basic_file_path_buffer<C, A>& rhs
)
{
    lhs.swap(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline us_char_a_t const* c_str_data_a(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_a_t, A> const& b)
{
    return b.c_str();
}
template <ss_typename_param_k A>
inline us_char_w_t const* c_str_data_w(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_w_t, A> const& b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_data for unixstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const* c_str_data(UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return b.c_str();
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline us_size_t c_str_len_a(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_a_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_len_a)(b.c_str());
}
template <ss_typename_param_k A>
inline us_size_t c_str_len_w(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_w_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_len_w)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_len for unixstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline us_size_t c_str_len(UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_len)(b.c_str());
}


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline us_char_a_t const* c_str_ptr_a(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_a_t, A> const& b)
{
    return b.c_str();
}
template <ss_typename_param_k A>
inline us_char_w_t const* c_str_ptr_w(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_w_t, A> const& b)
{
    return b.c_str();
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr for unixstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const* c_str_ptr(UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return b.c_str();
}



#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

template <ss_typename_param_k A>
inline us_char_a_t const* c_str_ptr_null_a(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_a_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_a)(b.c_str());
}
template <ss_typename_param_k A>
inline us_char_w_t const* c_str_ptr_null_w(UNIXSTL_NS_QUAL(basic_file_path_buffer)<us_char_w_t, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null_w)(b.c_str());
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \ref group__concept__Shim__string_access__c_str_ptr_null for unixstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__string_access
 */
template<   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline C const* c_str_ptr_null(UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    return STLSOFT_NS_QUAL(c_str_ptr_null)(b.c_str());
}




/** \ref group__concept__Shim__stream_insertion "stream insertion shim" for unixstl::basic_file_path_buffer
 *
 * \ingroup group__concept__Shim__stream_insertion
 */
template<   ss_typename_param_k S
        ,   ss_typename_param_k C
        ,   ss_typename_param_k A
        >
inline S& operator <<(S& s, UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A> const& b)
{
    s << b.c_str();

    return s;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef UNIXSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace unixstl */
# else
} /* namespace unixstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* In the special case of Intel behaving as VC++ 7.0 or earlier on Win32, we
 * illegally insert into the std namespace.
 */
#if defined(STLSOFT_CF_std_NAMESPACE)
# if ( ( defined(STLSOFT_COMPILER_IS_INTEL) && \
         defined(_MSC_VER))) && \
     _MSC_VER < 1310
namespace std
{
    template<   ss_typename_param_k C
            ,   ss_typename_param_k A
            >
    inline void swap(UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A>& lhs, UNIXSTL_NS_QUAL(basic_file_path_buffer)<C, A>& rhs)
    {
        lhs.swap(rhs);
    }
} /* namespace std */
# endif /* INTEL && _MSC_VER < 1310 */
#endif /* STLSOFT_CF_std_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 *
 * The string access shims exist either in the stlsoft namespace, or in the
 * global namespace. This is required by the lookup rules.
 *
 */

#ifndef UNIXSTL_NO_NAMESPACE
# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
namespace stlsoft
{
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */

using ::unixstl::c_str_data;
using ::unixstl::c_str_data_a;
using ::unixstl::c_str_data_w;

using ::unixstl::c_str_len;
using ::unixstl::c_str_len_a;
using ::unixstl::c_str_len_w;

using ::unixstl::c_str_ptr;
using ::unixstl::c_str_ptr_a;
using ::unixstl::c_str_ptr_w;

using ::unixstl::c_str_ptr_null;
using ::unixstl::c_str_ptr_null_a;
using ::unixstl::c_str_ptr_null_w;

# if !defined(STLSOFT_NO_NAMESPACE) && \
     !defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace stlsoft */
# else /* ? STLSOFT_NO_NAMESPACE */
/* There is no stlsoft namespace, so must define in the global namespace */
# endif /* !STLSOFT_NO_NAMESPACE */
#endif /* !UNIXSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !UNIXSTL_INCL_UNIXSTL_FILESYSTEM_HPP_FILE_PATH_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */

