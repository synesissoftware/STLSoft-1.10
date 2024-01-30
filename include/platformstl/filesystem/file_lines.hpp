/* /////////////////////////////////////////////////////////////////////////
 * File:        platformstl/filesystem/file_lines.hpp
 *
 * Purpose:     Platform header for the file_lines components.
 *
 * Created:     25th October 2007
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES
#define PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES

/* File version */
#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_MAJOR    2
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_MINOR    0
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_REVISION 13
# define PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES_EDIT     46
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** \file platformstl/filesystem/file_lines.hpp
 *
 * \brief [C++] Definition of the platformstl::file_lines type
 *   (\ref group__library__FileSystem "File System" Library).
 *
 * When compiling on UNIX platforms, the platformstl::file_lines
 * type resolves to the unixstl::file_lines class. On Windows
 * platforms it resolves to the winstl::file_lines class. It is
 * not defined for other platforms.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL
# include <platformstl/platformstl.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_HPP_PLATFORMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_INVALID_FILE_TYPE_EXCEPTION
#  include <platformstl/exception/invalid_file_type_exception.hpp>
# endif /* !PLATFORMSTL_INCL_PLATFORMSTL_EXCEPTION_HPP_INVALID_FILE_TYPE_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE
# include <platformstl/filesystem/readonly_memory_mapped_file.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_READONLY_MEMORY_MAPPED_FILE */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_MEMORY_MAPPED_FILE_VIEW_HANDLE
# include <platformstl/filesystem/handles/memory_mapped_file_view_handle.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HANDLES_HPP_MEMORY_MAPPED_FILE_VIEW_HANDLE */
#ifndef PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED
# include <platformstl/synch/refcount_policies/refcount_policy_multi_threaded.hpp>
#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_SYNCH_REFCOUNT_POLICIES_HPP_REFCOUNT_POLICY_MULTI_THREADED */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR_CONVERSIONS
# include <stlsoft/conversion/w2m.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_CHAR_CONVERSIONS */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST
#  include <stlsoft/conversion/truncation_cast.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_TRUNCATION_CAST */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD
# include <stlsoft/shims/access/string/fwd.h>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_STRING_H_FWD */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW
# include <stlsoft/string/string_view.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_STRING_VIEW */
#ifndef STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING
# include <stlsoft/string/simple_string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_STRING_HPP_SIMPLE_STRING */

#ifndef STLSOFT_INCL_ALGORITHM
# define STLSOFT_INCL_ALGORITHM
# include <algorithm>
#endif /* !STLSOFT_INCL_ALGORITHM */
#ifndef STLSOFT_INCL_VECTOR
# define STLSOFT_INCL_VECTOR
# include <vector>
#endif /* !STLSOFT_INCL_VECTOR */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::platformstl */
namespace platformstl
{
#else
/* Define stlsoft::platformstl_project */
namespace stlsoft
{
namespace platformstl_project
{
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Maps a text file's contents and presents them as a vector of lines
 */
template<
    ss_typename_param_k C
,   ss_typename_param_k V = stlsoft::basic_string_view<C>
,   ss_typename_param_k B = stlsoft::basic_simple_string<C>
,   ss_typename_param_k R = platformstl::refcount_policy_multi_threaded
>
class basic_file_lines
{
public: // Member Types
    typedef basic_file_lines<C, V, B, R>                                class_type;
    typedef C                                                           char_type;
private:
    typedef V                                                           value_string_type_;
    typedef B                                                           base_string_type_;
    typedef R                                                           refcount_policy_type_;
    typedef std::vector<V>                                              strings_type_;
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
    typedef UNIXSTL_NS_QUAL(memory_mapped_file_view_handle)<R>          HRW_HandleAdaptor_type_;
    typedef UNIXSTL_NS_QUAL(readonly_memory_mapped_file_base)<R>        mmf_type_;
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
    typedef WINSTL_NS_QUAL(memory_mapped_file_view_handle)<R>           HRW_HandleAdaptor_type_;
    typedef WINSTL_NS_QUAL(readonly_memory_mapped_file_base)<R>         mmf_type_;
#else
# error Platform is not discriminated
#endif
public:
    typedef ss_typename_type_k strings_type_::value_type                value_type;
    typedef ss_typename_type_k strings_type_::size_type                 size_type;
    typedef ss_typename_type_k strings_type_::const_iterator            const_iterator;
    typedef ss_typename_type_k strings_type_::const_reference           const_reference;
    typedef ss_bool_t                                                   bool_type;

    typedef ss_typename_type_k HRW_HandleAdaptor_type_::HRW_Ref_type    HRW_Ref_type;

public: // Construction
    template <ss_typename_param_k S>
    ss_explicit_k
    basic_file_lines(S const& path)
        : m_mmf()
        , m_contents()
        , m_strings()
    {
        create_(path);
    }

    ~basic_file_lines() STLSOFT_NOEXCEPT
    {}

private:
    basic_file_lines(class_type const&);        // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed

    // Prevents the conversion constructor from being invoked on an instance
    // of a different specialisation
    template<
        ss_typename_param_k C2
    ,   ss_typename_param_k V2
    ,   ss_typename_param_k B2
    ,   ss_typename_param_k R2
    >
    basic_file_lines(basic_file_lines<C2, V2, B2, R2> const&);

public: // Accessors
    /// Returns the number of lines in the file
    size_type size() const
    {
        return m_strings.size();
    }

    /// Indicates whethere there are any lines in the file
    bool_type empty() const
    {
        return 0u == size();
    }

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    HRW_Ref_type mmf() const
    {
        return m_mmf;
    }
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /// Returns a non-mutable (const) reference to the line at \c index
    ///
    /// \note The behaviour is undefined if index >= size()
    const_reference operator [](size_type index) const
    {
        STLSOFT_MESSAGE_ASSERT("index out of range", index < size());

        return m_strings[index];
    }

    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator begin() const
    {
        return m_strings.begin();
    }

    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator end() const
    {
        return m_strings.end();
    }

public: // Comparison
#if !defined(STLSOFT_COMPILER_IS_DMC)
    template<
        ss_typename_param_k V2
    ,   ss_typename_param_k B2
    ,   ss_typename_param_k R2
    >
    bool_type equal(basic_file_lines<char_type, V2, B2, R2> const& rhs) const
#else /* ? compiler */
    bool_type equal(class_type const& rhs) const
#endif /* compiler */
    {
        if (size() != rhs.size())
        {
            return false;
        }

        return STLSOFT_NS_QUAL_STD(equal)(begin(), end(), rhs.begin());
    }

private: // Implementation
    template <ss_typename_param_k S>
    void create_(S const& path)
    {
        // General creation algorithm:
        //
        // 1. Memory-map the file, if not a memory-mapped file
        // 2. Create the contents string
        // 3. Parse the file, and populate the strings collection

        // options:
        //
        // 1. Use has_member_type (HRW_Handle_type), select (via yesno_t()) it into another function, then invoke get_memory_mapped_file_view_handle() on it
        // 2. Have Wrapper types derive from hrw_wrapper<'specific-HRW_Handle_type'>, then select (via overload) into another function, then invoke get_memory_mapped_file_view_handle() on it
        // 3. Use traits
        // 4. Use local overloads of shim(s), and then select on return type(s).

        create_2_(path, &path);
    }

    // Overloads for 3 specific types:
    //
    // - multibyte strings
    // - wide strings
    // - Ref
    //
    // also:
    //
    // - mutating multibyte strings
    // - mutating wide strings

    void create_2_(ss_char_a_t const* path, ss_char_a_t const* const volatile * )
    {
        create_from_path_(path);
    }
    void create_2_(ss_char_w_t const* path, ss_char_w_t const* const volatile * )
    {
        create_from_path_(path);
    }

    void create_2_(ss_char_a_t* path, ss_char_a_t* const volatile * )
    {
        create_from_path_(path);
    }
    void create_2_(ss_char_w_t* path, ss_char_w_t* const volatile * )
    {
        create_from_path_(path);
    }

    void create_2_(HRW_Ref_type const& ref, HRW_Ref_type const volatile*)
    {
        create_from_ref_(ref, "");
    }

    template <ss_typename_param_k S>
    void create_2_(S const& path, ...)
    {
        create_from_path_(STLSOFT_NS_QUAL(c_str_ptr)(path));
    }

    template <ss_typename_param_k C2>
    void create_from_path_(C2 const* path)
    {
        // 1. Memory-map the file

        HRW_Ref_type ref = mmf_type_(path).get();

        create_from_ref_(ref, path);
    }

    void create_from_ref_(HRW_Ref_type mmf, ss_char_w_t const* path)
    {
        create_from_ref_(mmf, stlsoft::w2m(path));
    }

    void create_from_ref_(HRW_Ref_type mmf, ss_char_a_t const* path)
    {
        STLSOFT_ASSERT(NULL != path);

        void const* const       memory  =   mmf->handle.memory;
        size_t const            cb      =   mmf->handle.size;
        char_type const* const  base    =   static_cast<C const*>(memory);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        size_t                  cch     =   STLSOFT_NS_QUAL(truncation_cast)<size_type>(cb / sizeof(char_type));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        size_t                  cch     =   static_cast<size_type>(cb / sizeof(char_type));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        // check if it looks like a binary file
        if (base + cch != std::find(base, base + cch, '\0'))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(invalid_file_type_exception("file is binary (or unsupported text encoding)", 0, path));
#else /* STLSOFT_CF_EXCEPTION_SUPPORT */
            return;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        // 2. Create the contents string

        m_contents = base_string_type_(base, cch);

        STLSOFT_ASSERT(cch == m_contents.size());

        // 3. Parse the file, and populate the strings collection

        m_strings.reserve(1u + (cch / 10u));

        // This can work with EOL of CRLF or of LF, or a combination of the
        // two.

        char_type const* const  base1   =   m_contents.data();
        char_type const*        begin   =   base1;
        char_type const* const  end     =   begin + cch;
        char_type const*        s0      =   begin;
        char_type               prev    =   '\0';
//        bool const              hasLF   =   (base + cch != std::find(base, base + cch, '\n'));

#if 1
        { for (; begin != end; ++begin)
        {
            char_type const     c   =   *begin;
            char_type const*    eol =   begin;

            switch (c)
            {
            case '\r':
                if ('\r' == prev)
                {
                    --eol;

                    m_strings.push_back(value_string_type_(s0, eol));

                    s0 = begin;
                }
                break;
            case '\n':
                if ('\r' == prev)
                {
                    --eol;
                }

                m_strings.push_back(value_string_type_(s0, eol));

                s0 = begin + 1;
                break;
            default:
                if ('\r' == prev)
                {
                    --eol;

                    m_strings.push_back(value_string_type_(s0, eol));

                    s0 = begin;
                }
                break;
            }

            prev = c;
        }}
        if (s0 != end)
        {
            char_type const* eol = begin;

            if ('\r' == prev)
            {
                --eol;
            }

            m_strings.push_back(value_string_type_(s0, eol));
        }
#endif

        // Now determine whether we require the ongoing presence of the
        // underlying mapping. We can discard it if:
        //
        //  - there are no lines, or
        //  - the string type copies. This is determined by checking whether
        //    the first non-empty string's contents point within the mapping.
        bool canDiscardMapping = false;

        if (!canDiscardMapping)
        {
            canDiscardMapping = m_strings.empty();
        }

        if (!canDiscardMapping)
        {
            { for (ss_typename_type_k strings_type_::const_iterator i = m_strings.begin(); i != m_strings.end(); ++i)
            {
                if (0u != (*i).size())
                {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                    void const* end2    =   ptr_byte_offset(base, STLSOFT_NS_QUAL(truncation_cast)<ss_ptrdiff_t>(cb));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
                    void const* end2    =   ptr_byte_offset(base, static_cast<ss_ptrdiff_t>(cb));
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
                    void const* p       =   (*i).data();

                    canDiscardMapping = p < base || p >= end2;

                    break;
                }
            }}
        }

        if (!canDiscardMapping)
        {
            m_mmf = mmf;
        }
    }

private: // Fields
    HRW_Ref_type        m_mmf;
    base_string_type_   m_contents;
    strings_type_       m_strings;
};

/* /////////////////////////////////////////////////////////////////////////
 * typedefs for commonly encountered types
 */

/** Specialisation of the basic_file_lines template for the ANSI character type \c char
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_lines<ss_char_a_t>       file_lines_a;

/** Specialisation of the basic_file_lines template for the Unicode character type \c wchar_t
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_lines<ss_char_w_t>       file_lines_w;

#ifdef TCHAR
/** Specialisation of the basic_file_lines template for the Win32 character type \c TCHAR
 *
 * \ingroup group__library__FileSystem
 */
typedef basic_file_lines<TCHAR>             file_lines;
#else /* ? TCHAR */
typedef file_lines_a                        file_lines;
#endif /* TCHAR */

/** Alias for platformstl::file_lines_w;
 *
 * \ingroup group__library__FileSystem
 */
typedef file_lines_w                        wfile_lines;

/* /////////////////////////////////////////////////////////////////////////
 * operators
 */

#if !defined(STLSOFT_COMPILER_IS_DMC)
template<
    ss_typename_param_k C
,   ss_typename_param_k V1
,   ss_typename_param_k B1
,   ss_typename_param_k R1
,   ss_typename_param_k V2
,   ss_typename_param_k B2
,   ss_typename_param_k R2
>
inline
ss_typename_type_ret_k basic_file_lines<C, V1, B1, R1>::bool_type
operator ==(
    basic_file_lines<C, V1, B1, R1> const&  lhs
,   basic_file_lines<C, V2, B2, R2> const&  rhs
)
#else /* ? compiler */
template<
    ss_typename_param_k C
,   ss_typename_param_k V
,   ss_typename_param_k B
,   ss_typename_param_k R
>
inline
ss_typename_type_ret_k basic_file_lines<C, V, B, R>::bool_type
operator ==(
    basic_file_lines<C, V, B, R> const& lhs
,   basic_file_lines<C, V, B, R> const& rhs
)
#endif /* compiler */
{
    return lhs.equal(rhs);
}

#if !defined(STLSOFT_COMPILER_IS_DMC)
template<
    ss_typename_param_k C
,   ss_typename_param_k V1
,   ss_typename_param_k B1
,   ss_typename_param_k R1
,   ss_typename_param_k V2
,   ss_typename_param_k B2
,   ss_typename_param_k R2
>
inline
ss_typename_type_ret_k basic_file_lines<C, V1, B1, R1>::bool_type
operator !=(
    basic_file_lines<C, V1, B1, R1> const&  lhs
,   basic_file_lines<C, V2, B2, R2> const&  rhs
)
#else /* ? compiler */
template<
    ss_typename_param_k C
,   ss_typename_param_k V
,   ss_typename_param_k B
,   ss_typename_param_k R
>
inline
ss_typename_type_ret_k basic_file_lines<C, V, B, R>::bool_type
operator !=(
    basic_file_lines<C, V, B, R> const& lhs
,   basic_file_lines<C, V, B, R> const& rhs
)
#endif /* compiler */
{
    return !lhs.equal(rhs);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if defined(STLSOFT_NO_NAMESPACE) || \
    defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace platformstl */
#else
} /* namespace platformstl_project */
} /* namespace stlsoft */
#endif /* STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !PLATFORMSTL_INCL_PLATFORMSTL_FILESYSTEM_HPP_FILE_LINES */

/* ///////////////////////////// end of file //////////////////////////// */

