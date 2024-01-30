/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/dl/module.hpp (MWModule.h, ::SynesisWin)
 *
 * Purpose:     Contains the module class.
 *
 * Created:     30th October 1997
 * Updated:     22nd January 2024
 *
 * Thanks to:   Pablo Aguilar for the idea of a template-based get_symbol().
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1997-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/dl/module.hpp
 *
 * \brief [C++] Definition of the unixstl::module class
 *   (\ref group__library__DL "DL" Library).
 */

#ifndef WINSTL_INCL_WINSTL_DL_HPP_MODULE
#define WINSTL_INCL_WINSTL_DL_HPP_MODULE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_DL_HPP_MODULE_MAJOR      6
# define WINSTL_VER_WINSTL_DL_HPP_MODULE_MINOR      6
# define WINSTL_VER_WINSTL_DL_HPP_MODULE_REVISION   1
# define WINSTL_VER_WINSTL_DL_HPP_MODULE_EDIT       250
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
# include <winstl/exception/winstl_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */

#ifndef WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary
# include <winstl/api/external/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary */
#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */
namespace stlsoft
{
namespace winstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Class for manipulating dynamically loaded libraries
 *
 * \ingroup group__library__DL
 */
class module
{
public:
    /// The handle type
    typedef HINSTANCE   module_handle_type;
    /// The handle type
    ///
    /// \note This member type is required to make it compatible with
    ///  the STLSoft get_module_handle access shim
    typedef HINSTANCE   handle_type;
    /// The class type
    typedef module      class_type;
    /// The entry point type
    typedef void        (*proc_pointer_type)();
private:
    typedef void        (*degenerate_feedback_proc_type)();
    typedef void        (*untyped_feedback_proc_type)(void const*, handle_type, void*);
public:
    typedef handle_type resource_type;

/// \name Construction
/// @{
public:
    /// Constructs by loading the named module
    ///
    /// \param moduleName The file name of the executable module to be loaded.
    ///
    /// \note If exception-handling is being used, then this throws a
    ///  \link winstl::winstl_exception winstl_exception\endlink
    ///  if the module cannot be loaded
    ss_explicit_k module(ws_char_a_t const* moduleName);

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    ss_explicit_k module(ws_char_a_t const* moduleName, void (*pfn)(ws_char_a_t const*, handle_type, void*), void* param);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

    /// Constructs by loading the named module
    ///
    /// \param moduleName The file name of the executable module to be loaded.
    ///
    /// \note If exception-handling is being used, then this throws a
    ///  \link winstl::winstl_exception winstl_exception\endlink
    ///  if the module cannot be loaded
    ss_explicit_k module(ws_char_w_t const* moduleName);

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
    ss_explicit_k module(ws_char_w_t const* moduleName, void (*pfn)(ws_char_w_t const*, handle_type, void*), void* param);
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    /// Constructs by loading the named module
    ///
    /// \param moduleName The file name of the executable module to be
    ///   loaded. The argument may be of any type for which the
    ///   \ref group__concept__Shim__string_access "string access shim"
    ///   stlsoft::c_str_ptr is defined.
    ///
    /// \note If exception-handling is being used, then this throws a
    ///  \link winstl::winstl_exception winstl_exception\endlink
    ///  if the module cannot be loaded
    template <ss_typename_param_k S>
    ss_explicit_k module(S const& moduleName)
        : m_hmodule(load(moduleName))
        , m_param(NULL)
        , m_proc(NULL)
    {
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if (NULL == m_hmodule)
        {
            STLSOFT_THROW_X(winstl_exception("Cannot load module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
        }
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT */
    /// Constructs by taking ownership of the given handle
    ///
    /// \note If exception-handling is being used, then this throws a
    ///  \link winstl::winstl_exception winstl_exception\endlink
    ///  if the handle is NULL.
    ss_explicit_k module(module_handle_type hmodule);
    /// Copy constructor
    ///
    /// \note Both copies hold independent handles to the underlying module.
    module(class_type const& rhs);

#ifdef STLSOFT_CF_RVALUE_REFERENCES_SUPPORT

    /// Constructs a module instance by taking over the state of the
    /// instance \c rhs
    ///
    /// \param rhs The instance whose state will be taken over. Upon return
    ///   \c rhs <code>get_module_handle()()</code> will obtain \c nullptr
    module(class_type&& rhs) STLSOFT_NOEXCEPT
        : m_hmodule(rhs.detach())
        , m_param(rhs.m_param)
        , m_proc(rhs.m_proc)
    {}
#endif /* STLSOFT_CF_RVALUE_REFERENCES_SUPPORT */
    /// Closes the module handle
    ~module() STLSOFT_NOEXCEPT;

private:
    void operator =(class_type const&); // copy-assignment proscribed
/// @}

/// \name Static operations
/// @{
public:
    /// Loads the named module, returning its handle, which the
    ///   caller must close with unload().
    ///
    /// \param moduleName The file name of the executable module to be loaded.
    ///
    /// \return The module handle, or NULL if no matching module found.
    static module_handle_type   load(ws_char_a_t const* moduleName);
    /// Loads the named module, returning its handle, which the
    ///   caller must close with unload().
    ///
    /// \param moduleName The file name of the executable module to be loaded.
    ///
    /// \return The module handle, or NULL if no matching module found.
    static module_handle_type   load(ws_char_w_t const* moduleName);
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    /// Loads the named module, returning its handle, which the
    ///   caller must close with unload().
    ///
    /// \param moduleName The file name of the executable module to be
    ///   loaded. The argument may be of any type for which the
    ///   \ref group__concept__Shim__string_access "string access shim"
    ///   stlsoft::c_str_ptr is defined.
    ///
    /// \return The module handle, or NULL if no matching module found.
    template <ss_typename_param_k S>
    static module_handle_type   load(S const& moduleName)
    {
        return class_type::load(STLSOFT_NS_QUAL(c_str_ptr)(moduleName));
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    /// Closes the given module handle
    static void                 unload(module_handle_type hmodule) STLSOFT_NOEXCEPT;
    /// Looks up a named symbol from the given module.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    static proc_pointer_type    get_symbol(module_handle_type hmodule, ws_char_a_t const* symbolName);
    /// Looks up a symbol by ordinal from the given module.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    static proc_pointer_type    get_symbol(module_handle_type hmodule, ws_uint32_t symbolOrdinal);

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    /// Looks up a named symbol from the given module into a typed function pointer variable.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    template <ss_typename_param_k F>
    static proc_pointer_type    get_symbol(module_handle_type hmodule, ws_char_a_t const* symbolName, F &f)
    {
        proc_pointer_type proc = class_type::get_symbol(hmodule, symbolName);

        f = reinterpret_cast<F>(proc);

        return proc;
    }
    /// Looks up a symbol by ordinal from the given module into a typed function pointer variable.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    template <ss_typename_param_k F>
    static proc_pointer_type    get_symbol(module_handle_type hmodule, ws_uint32_t symbolOrdinal, F &f)
    {
        proc_pointer_type proc = class_type::get_symbol(hmodule, symbolOrdinal);

        f = reinterpret_cast<F>(proc);

        return proc;
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
/// @}

/// \name Operations
/// @{
public:
    /// Closes the module handle
    void unload() STLSOFT_NOEXCEPT;

    /// Yields the module handle to the caller
    module_handle_type detach();
/// @}

/// \name Lookup Operations
/// @{
public:
    /// Looks up a named symbol.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    proc_pointer_type   get_symbol(ws_char_a_t const* symbolName);
    /// Looks up a symbol by ordinal.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    proc_pointer_type   get_symbol(ws_uint32_t symbolOrdinal);

#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT) && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200)
    /// Looks up a named symbol into a typed function pointer variable.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    template <ss_typename_param_k F>
    proc_pointer_type   get_symbol(ws_char_a_t const* symbolName, F &f)
    {
        return class_type::get_symbol(m_hmodule, symbolName, f);
    }
    /// Looks up a symbol by ordinal into a typed function pointer variable.
    ///
    /// \return A pointer to the named symbol, or NULL if not found.
    template <ss_typename_param_k F>
    proc_pointer_type   get_symbol(ws_uint32_t symbolOrdinal, F &f)
    {
        return class_type::get_symbol(m_hmodule, symbolOrdinal, f);
    }
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
/// @}

/// \name Accessors
/// @{
public:
    /// Provides access to the underlying module handle
    module_handle_type  get_module_handle() const;

    /// Provides access to the underlying module handle
    module_handle_type  get() const;
/// @}

/// \name Implementation
/// @{
private:
    static module_handle_type   load(ws_char_a_t const* moduleName, void (*pfn)(ws_char_a_t const*, handle_type, void*), void* param);
    static module_handle_type   load(ws_char_w_t const* moduleName, void (*pfn)(ws_char_w_t const*, handle_type, void*), void* param);
    static void                 unload(module_handle_type hmodule, degenerate_feedback_proc_type, void* param) /* STLSOFT_NOEXCEPT */;
/// @}

/// \name Member Variables
/// @{
private:
    module_handle_type                  m_hmodule;
    void* const                         m_param;
    const degenerate_feedback_proc_type m_proc;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * access shims
 */

/** Returns the module handle for the given module
 *
 * \ingroup group__concept__Shim__module_attribute
 */
inline HINSTANCE get_module_handle(WINSTL_NS_QUAL(module) const& m)
{
    return m.get_module_handle();
}

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline module::module(ws_char_a_t const* moduleName)
    : m_hmodule(load(moduleName))
    , m_param(NULL)
    , m_proc(NULL)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if (NULL == m_hmodule)
    {
        STLSOFT_THROW_X(winstl_exception("Cannot load module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(ws_char_a_t const* moduleName, void (*pfn)(ws_char_a_t const*, handle_type, void*), void* param)
    : m_hmodule(load(moduleName, pfn, param))
    , m_param(param)
    , m_proc(reinterpret_cast<degenerate_feedback_proc_type>(pfn))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if (NULL == m_hmodule)
    {
        STLSOFT_THROW_X(winstl_exception("Cannot load module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(ws_char_w_t const* moduleName)
    : m_hmodule(load(moduleName))
    , m_param(NULL)
    , m_proc(NULL)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if (NULL == m_hmodule)
    {
        STLSOFT_THROW_X(winstl_exception("Cannot load module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(ws_char_w_t const* moduleName, void (*pfn)(ws_char_w_t const*, handle_type, void*), void* param)
    : m_hmodule(load(moduleName, pfn, param))
    , m_param(param)
    , m_proc(reinterpret_cast<degenerate_feedback_proc_type>(pfn))
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if (NULL == m_hmodule)
    {
        STLSOFT_THROW_X(winstl_exception("Cannot load module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(module::module_handle_type hmodule)
    : m_hmodule(hmodule)
    , m_param(NULL)
    , m_proc(NULL)
{
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    if (NULL == m_hmodule)
    {
        STLSOFT_THROW_X(winstl_exception("Cannot load module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
}

inline module::module(module const& rhs)
    : m_param(NULL)
    , m_proc(NULL)
{
    if (NULL == rhs.get_module_handle())
    {
        m_hmodule = NULL;
    }
    else
    {
        typedef system_traits<ws_char_a_t>      traits_a_t;

        ws_size_t const                             cchRequired =   traits_a_t::get_module_filename(rhs.get_module_handle(), ss_nullptr_k, 0);
        STLSOFT_NS_QUAL(auto_buffer)<ws_char_a_t>   buffer(1 + cchRequired);
        ws_size_t const                             cch =   system_traits<ws_char_a_t>::get_module_filename(rhs.get_module_handle(), &buffer[0], buffer.size());

        if (0 == cch)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(winstl_exception("Cannot get module path", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* STLSOFT_CF_EXCEPTION_SUPPORT */
            m_hmodule = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            m_hmodule = load(buffer.data());
        }
    }
}

inline module::~module() STLSOFT_NOEXCEPT
{
    unload();
}

inline void module::unload() STLSOFT_NOEXCEPT
{
    if (NULL != m_hmodule)
    {
        if (NULL != m_proc)
        {
            class_type::unload(m_hmodule, m_proc, m_param);
        }
        else
        {
            class_type::unload(m_hmodule);
        }
        m_hmodule = NULL;
    }
}

inline module::module_handle_type module::detach()
{
    module_handle_type  h;

    h = m_hmodule;
    m_hmodule = NULL;

    return h;
}

inline /* static */ module::module_handle_type module::load(ws_char_a_t const* moduleName)
{
    return WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryA(moduleName);
}

inline /* static */ module::module_handle_type module::load(ws_char_a_t const* moduleName, void (*pfn)(ws_char_a_t const*, handle_type, void*), void* param)
{
    HINSTANCE hinst = WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryA(moduleName);

    if (NULL != pfn)
    {
        (*pfn)(moduleName, hinst, param);
    }

    return hinst;
}

inline /* static */ module::module_handle_type module::load(ws_char_w_t const* moduleName)
{
    return WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryW(moduleName);
}

inline /* static */ void module::unload(module::module_handle_type hmodule) STLSOFT_NOEXCEPT
{
    if (NULL != hmodule)
    {
        WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(hmodule);
    }
}

inline /* static */ void module::unload(module::module_handle_type hmodule, module::degenerate_feedback_proc_type pfn, void* param) /* STLSOFT_NOEXCEPT */
{
    if (NULL != hmodule)
    {
        if (NULL != pfn)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            try
            {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

                untyped_feedback_proc_type  fn  =   reinterpret_cast<untyped_feedback_proc_type>(pfn);

                (*fn)(NULL, hmodule, param);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            }
            catch(...)
            {
                STLSOFT_MESSAGE_ASSERT("Module feedback procedure threw an exception", 0);

                throw; // This will, hopefully, precipitate unexpected()
            }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(hmodule);
    }
}


inline /* static */ module::proc_pointer_type module::get_symbol(module::module_handle_type hmodule, ws_char_a_t const* symbolName)
{
    return reinterpret_cast<proc_pointer_type>(WINSTL_API_EXTERNAL_DynamicLinkLibrary_GetProcAddress(hmodule, symbolName));
}

inline /* static */ module::proc_pointer_type module::get_symbol(module::module_handle_type hmodule, ws_uint32_t symbolOrdinal)
{
    ws_char_a_t const* s = MAKEINTRESOURCEA(symbolOrdinal);

    return get_symbol(hmodule, s);
}

inline module::proc_pointer_type module::get_symbol(ws_char_a_t const* symbolName)
{
    return get_symbol(m_hmodule, symbolName);
}

inline module::proc_pointer_type module::get_symbol(ws_uint32_t symbolOrdinal)
{
    return get_symbol(m_hmodule, symbolOrdinal);
}

inline module::module_handle_type module::get_module_handle() const
{
    return m_hmodule;
}

inline module::module_handle_type module::get() const
{
    return m_hmodule;
}

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef WINSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !WINSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !WINSTL_INCL_WINSTL_DL_HPP_MODULE */

/* ///////////////////////////// end of file //////////////////////////// */

