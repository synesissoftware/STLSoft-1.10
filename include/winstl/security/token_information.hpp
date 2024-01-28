/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/security/token_information.hpp
 *
 * Purpose:     Helper for accessing token information.
 *
 * Created:     20th June 2003
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/security/token_information.hpp
 *
 * \brief [C++] Definition of the winstl::token_information class
 *   (\ref group__library__Security "Security" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SECURITY_HPP_TOKEN_INFORMATION
#define WINSTL_INCL_WINSTL_SECURITY_HPP_TOKEN_INFORMATION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_MAJOR     4
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_MINOR     4
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_REVISION  5
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_EDIT      77
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

#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE
# include <winstl/error/last_error_scope.hpp>
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES
#  include <winstl/exception/throw_policies.hpp>
# endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_THROW_POLICIES */
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
# ifndef STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES
#  include <stlsoft/exception/throw_policies.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_EXCEPTION_HPP_THROW_POLICIES */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */

#ifndef WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_
# include <winstl/api/winstl_win32_winnt_.h>
#endif /* !WINSTL_INCL_WINSTL_API_H_winstl_win32_winnt_ */

#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */

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
 * types
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

enum
{
        TokenRestrictedSids         =   1 + TokenStatistics
    ,   TokenSessionId
    ,   TokenGroupsAndPrivileges
    ,   TokenSessionReference
    ,   TokenSandBoxInert
    ,   TokenAuditPolicy
    ,   TokenOrigin

    ,   TokenElevationType
    ,   TokenLinkedToken
    ,   TokenElevation
    ,   TokenHasRestrictions
    ,   TokenAccessInformation
    ,   TokenVirtualizationAllowed
    ,   TokenVirtualizationEnabled
    ,   TokenIntegrityLevel
    ,   TokenUIAccess
    ,   TokenMandatoryPolicy
    ,   TokenLogonSid

    ,   TokenIsAppContainer
    ,   TokenCapabilities
    ,   TokenAppContainerSid
    ,   TokenAppContainerNumber
    ,   TokenUserClaimAttributes
    ,   TokenDeviceClaimAttributes
    ,   TokenRestrictedUserClaimAttributes
    ,   TokenRestrictedDeviceClaimAttributes
    ,   TokenDeviceGroups
    ,   TokenRestrictedDeviceGroups
    ,   TokenSecurityAttributes
    ,   TokenIsRestricted
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * traits
 */

/** traits type used to determine the data type for a given \c TOKEN_INFORMATION_CLASS
 *
 * \ingroup group__library__Security
 *
 */
template <TOKEN_INFORMATION_CLASS C>
struct token_information_traits;

/* ///////////////////////////////////////////////
 * specialisations
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

# define WINSTL_SEC_T_I_SPECIALISE_TIT_(tic, dt)    \
                                                    \
    STLSOFT_TEMPLATE_SPECIALISATION                 \
    struct token_information_traits<                \
        static_cast<TOKEN_INFORMATION_CLASS>((tic)) \
    >                                               \
    {                                               \
        typedef dt  data_type;                      \
    }


/* ///////////////////////////////////////////////
 * specialisations - pre-XP
 */

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenUser, TOKEN_USER);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenGroups, TOKEN_GROUPS);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenPrivileges, TOKEN_PRIVILEGES);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenOwner, TOKEN_OWNER);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenPrimaryGroup, TOKEN_PRIMARY_GROUP);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenDefaultDacl, TOKEN_DEFAULT_DACL);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenSource, TOKEN_SOURCE);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenType, TOKEN_TYPE);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenImpersonationLevel, SECURITY_IMPERSONATION_LEVEL);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenStatistics, TOKEN_STATISTICS);

/* ///////////////////////////////////////////////
 * specialisations - XP+
 */

# if WINSTL_WIN32_WINNT >= 0x0501

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenRestrictedSids, TOKEN_GROUPS);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenSessionId, DWORD);

#  if 0
#  elif !defined(__MINGW32_) && \
        !defined(__MINGW64_)

#  else

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenGroupsAndPrivileges, TOKEN_GROUPS_AND_PRIVILEGES);
#  endif

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenSandBoxInert, DWORD);

# endif /* XP+ */

/* ///////////////////////////////////////////////
 * specialisations - Svr03+
 */

# if WINSTL_WIN32_WINNT >= 0x0502

#  if 0
#  elif !defined(__MINGW32_) && \
        !defined(__MINGW64_)

#  else

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenOrigin, TOKEN_ORIGIN);
#  endif

# endif /* Svr03+ */

/* ///////////////////////////////////////////////
 * specialisations - Vista+
 */

# if WINSTL_WIN32_WINNT >= 0x0600

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenElevationType, TOKEN_ELEVATION_TYPE);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenLinkedToken, TOKEN_LINKED_TOKEN);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenElevation, TOKEN_ELEVATION);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenHasRestrictions, DWORD);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenAccessInformation, TOKEN_ACCESS_INFORMATION);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenVirtualizationAllowed, DWORD);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenVirtualizationEnabled, DWORD);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenIntegrityLevel, TOKEN_MANDATORY_LABEL);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenUIAccess, DWORD);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenMandatoryPolicy, TOKEN_MANDATORY_POLICY);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenLogonSid, TOKEN_GROUPS);

# endif /* Vista+ */

/* ///////////////////////////////////////////////
 * specialisations - W8+
 */

# if WINSTL_WIN32_WINNT >= 0x0602

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenIsAppContainer, DWORD);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenCapabilities, TOKEN_GROUPS);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenAppContainerSid, TOKEN_APPCONTAINER_INFORMATION);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenAppContainerNumber, DWORD);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenUserClaimAttributes, CLAIM_SECURITY_ATTRIBUTES_INFORMATION);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenDeviceClaimAttributes, CLAIM_SECURITY_ATTRIBUTES_INFORMATION);

#if 0 // This value is reserved
WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenRestrictedUserClaimAttributes, void);
#endif

#if 0 // This value is reserved
WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenRestrictedDeviceClaimAttributes, void);
#endif

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenDeviceGroups, TOKEN_GROUPS);

WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenRestrictedDeviceGroups, TOKEN_GROUPS);

#if 0 // This value is reserved
WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenSecurityAttributes, void);
#endif

#if 0 // This value is reserved
WINSTL_SEC_T_I_SPECIALISE_TIT_(TokenIsRestricted, void);
#endif

# endif /* W8+ */

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// token_information
/** Provides typed access to token information.
 *
 * \ingroup group__library__Security
 *
 * \tparam C [TOKEN_INFORMATION_CLASS] The token information class
 * \tparam X The exception policy type. Defaults to security_exception_policy
 *    when compiling with exception-support; otherwise defaults to
 *    null_exception_policy and callers must be ready for get() to return
 *    nullptr
 * \tparam D The data type. Defaults to token_information_traits<C>::data_type
 * \tparam A The allocator type. Defaults to processheap_allocator<stlsoft::byte_t>
 */
template<
    TOKEN_INFORMATION_CLASS C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
# ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
#  pragma message(_sscomp_fileline_message("Note that we have to have data_type as a parameter, otherwise VC5&6 have a cow"))
# endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
,   ss_typename_param_k     X   =   security_exception_policy
# else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
,   ss_typename_param_k     X   =   STLSOFT_NS_QUAL(null_exception_policy)
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
,   ss_typename_param_k     D   =   ss_typename_type_def_k token_information_traits<C>::data_type
,   ss_typename_param_k     A   =   processheap_allocator<ss_byte_t>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k     X /* = STLSOFT_NS_QUAL(null_exception_policy) */
,   ss_typename_param_k     D /* = token_information_traits<C>::data_type */
,   ss_typename_param_k     A /* = processheap_allocator<ss_byte_t> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class token_information
{
/// \name Member Types
/// @{
public:
    typedef token_information<C, X, D, A>                       class_type;
    typedef token_information_traits<C>                         traits_type;
    typedef X                                                   exception_thrower_type;
    typedef D                                                   data_type;
    typedef A                                                   allocator_type;
    typedef data_type*                                          pointer;
    typedef data_type const*                                    const_pointer;
    typedef ss_size_t                                           size_type;
/// @}
private:
    typedef allocator_type                                      raw_allocator_type_;
    typedef ss_typename_param_k raw_allocator_type_::pointer    raw_pointer_type_;
    typedef std::pair<
        pointer
    ,   size_type
    >                                                           mem_block_type_;

/// \name Construction
/// @{
public:
    /// Constructs an instance from the given access token
    ///
    /// \param hToken The token from which information will be elicited
    ///
    /// \note The class does not acquire ownership of \c hToken
    ss_explicit_k
    token_information(HANDLE hToken)
        : m_data(init_(hToken))
    {}

private:
    static
    mem_block_type_
    init_(
        HANDLE hToken
    )
    {
        DWORD   cbRequired;
        DWORD   dwError;

        ::GetTokenInformation(hToken, C, NULL, 0, &cbRequired);
        dwError = WINSTL_API_EXTERNAL_ErrorHandling_GetLastError();
        if (ERROR_INSUFFICIENT_BUFFER != dwError)
        {
            // Report error
            exception_thrower_type()(dwError);
        }
        else
        {
            raw_pointer_type_ const raw     =   raw_allocator_type_().allocate(cbRequired);
            pointer const           data    =   static_cast<pointer>(static_cast<void*>(raw));

            if (NULL == data)
            {
                // Report error
                exception_thrower_type()(ERROR_NOT_ENOUGH_MEMORY);

                // Set the last error, in case the client code is not using exception reporting
                WINSTL_API_EXTERNAL_ErrorHandling_SetLastError(ERROR_NOT_ENOUGH_MEMORY);
            }
            else
            {
                if (!::GetTokenInformation(hToken, C, data, cbRequired, &cbRequired))
                {
                    // Scope the last error, in case the client code is not using exception reporting
                    last_error_scope scope;

#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
                    raw_allocator_type_().deallocate(raw, cbRequired);
#else /* ? STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
                    raw_allocator_type_().deallocate(raw);
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */

                    // Report error
                    exception_thrower_type()(DWORD((scope)));
                }

                return mem_block_type_(data, cbRequired);
            }
        }

        return mem_block_type_(static_cast<pointer>(NULL), 0);
    }
public:
    ~token_information() STLSOFT_NOEXCEPT
    {
        raw_pointer_type_ const raw = static_cast<raw_pointer_type_>(static_cast<void*>(m_data.first));

#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
        raw_allocator_type_().deallocate(raw, m_data.second);
#else /* ? STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
        raw_allocator_type_().deallocate(raw);
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
    }
private:
    token_information(class_type const&);       // copy-construction proscribed
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Conversion
/// @{
public:
    pointer get() const
    {
        return m_data.first;
    }
    size_type size() const
    {
        return m_data.second;
    }

    operator pointer()
    {
        return get();
    }
    operator const_pointer() const
    {
        return get();
    }

    pointer operator ->()
    {
        return get();
    }
    const_pointer operator ->() const
    {
        return get();
    }
/*
    operator ws_bool_t () const
    {
        return 0 != m_data;
    }
*/
    ws_bool_t operator !() const
    {
        return 0 == m_data.second;
    }
/// @}

/// \name Implementation
/// @{
private:
/// @}

/// \name Members
/// @{
private:
    mem_block_type_ const   m_data;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !WINSTL_INCL_WINSTL_SECURITY_HPP_TOKEN_INFORMATION */

/* ///////////////////////////// end of file //////////////////////////// */

