/* /////////////////////////////////////////////////////////////////////////
 * File:        comstl/collections/enumeration_policies.hpp
 *
 * Purpose:     Policies for enumerator interface handling.
 *
 * Created:     20th December 2003
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


/** \file comstl/collections/enumeration_policies.hpp
 *
 * \brief [C++] Policies for enumerator interface handling
 *   (\ref group__library__Collection "Collection" Library).
 */

#ifndef COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES
#define COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES_MAJOR       6
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES_MINOR       1
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES_REVISION    13
# define COMSTL_VER_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES_EDIT        69
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef COMSTL_INCL_COMSTL_H_COMSTL
# include <comstl/comstl.h>
#endif /* !COMSTL_INCL_COMSTL_H_COMSTL */
#ifdef STLSOFT_TRACE_INCLUDE
# pragma message(__FILE__)
#endif /* STLSOFT_TRACE_INCLUDE */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# ifndef COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION
#  include <comstl/exception/comstl_exception.hpp>
# endif /* !COMSTL_INCL_COMSTL_EXCEPTION_HPP_COMSTL_EXCEPTION */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef STLSOFT_INCL_STLSOFT_API_internal_h_memfns
# include <stlsoft/api/internal/memfns.h>
#endif /* !STLSOFT_INCL_STLSOFT_API_internal_h_memfns */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::comstl */
namespace comstl
{
# else
/* Define stlsoft::comstl_project */
namespace stlsoft
{
namespace comstl_project
{
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

/** Exception class thrown when Clone() method fails
 *
 * \ingroup group__library__Collection
 */
// [[synesis:class:exception: comstl::clone_failure]]
class clone_failure
    : public comstl_exception
{
/// \name Member Types
/// @{
public:
    /// The parent class type
    typedef comstl_exception                                parent_class_type;
    /// The type of this class
    typedef clone_failure                                   class_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance from the given HRESULT code
    ss_explicit_k
    clone_failure(HRESULT hr)
        : parent_class_type(hr)
    {}
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed
/// @}

/// \name Accessors
/// @{
public:
    /// Returns a human-readable description of the exceptional condition
#if defined(STLSOFT_COMPILER_IS_DMC)
    char const* what() const throw()
#else /* ? compiler */
    char const* what() const STLSOFT_NOEXCEPT
#endif /* compiler */
    {
        return "Request to clone enumerator failed";
    }
/// @}
};

#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */


/** Policy tag type that indicates an enumerator's Clone() method
 *    will fail.
 *
 * \ingroup group__library__Collection
 */
struct noncloneable_enumerator_tag
{};

/** Policy tag type that indicates an enumerator's Clone() method
 *    will succeed.
 *
 * \ingroup group__library__Collection
 */
struct cloneable_enumerator_tag
{};

/** Policy tag type that indicates an enumerator's Clone() method
 *    will succeed, and return an enumerator that will provide the same
 *    sequence of items as the source instance.
 *
 * \ingroup group__library__Collection
 */
struct repeatable_enumerator_tag
    : public cloneable_enumerator_tag
{};



/** Policy type that causes COM enumerator cloning according the STL Input Iterator concept
 *
 * \ingroup group__library__Collection
 *
 * \param I The enumeration interface
 */
template<ss_typename_param_k I>
struct input_cloning_policy
    : public noncloneable_enumerator_tag
{
public:
    typedef I                                       interface_type;
    typedef interface_type*                         value_type;
    typedef STLSOFT_NS_QUAL_STD(input_iterator_tag)  iterator_tag_type;

public:
    /// Gets a working "copy" of the given enumerator root
    ///
    /// \remarks For this policy, this simply calls AddRef()
    static interface_type *get_working_instance(interface_type *root)
    {
        COMSTL_ASSERT(NULL != root);

        root->AddRef();

        return root;
    }

    /// "Clones" the given COM enumerator interface according to the Input Iterator concept
    static interface_type *share(interface_type *src)
    {
        COMSTL_ASSERT(NULL != src);

        src->AddRef();

        return src;
    }
    static cs_bool_t clone(interface_type *src, interface_type **pdest)
    {
        COMSTL_ASSERT(NULL != src);
        COMSTL_ASSERT(NULL != pdest);
        STLSOFT_SUPPRESS_UNUSED(src);

        *pdest = NULL;

        return false;
    }
};

/** Policy type that causes COM enumerator cloning according the STL Input Iterator concept
 *
 * \ingroup group__library__Collection
 *
 * \param I The enumeration interface
 */
template<ss_typename_param_k I>
struct cloneable_cloning_policy
    : public cloneable_enumerator_tag
{
public:
    typedef I                                       interface_type;
    typedef interface_type*                         value_type;
    typedef STLSOFT_NS_QUAL_STD(input_iterator_tag)  iterator_tag_type;

public:
    /// Gets a working "copy" of the given enumerator root
    ///
    /// \remarks For this policy, this calls Clone(), and returns NULL
    ///   if that fails.
    static interface_type *get_working_instance(interface_type *root)
    {
        COMSTL_ASSERT(NULL != root);

        interface_type  *ret;
        HRESULT         hr  =   const_cast<interface_type*>(root)->Clone(&ret);

        if (FAILED(hr))
        {
            ret = NULL;
        }

        return ret;
    }

    static interface_type *share(interface_type *src)
    {
        COMSTL_ASSERT(NULL != src);

        interface_type  *ret;
        HRESULT         hr  =   const_cast<interface_type*>(src)->Clone(&ret);

        if (FAILED(hr))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(clone_failure(hr));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            ret = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return ret;
    }
    static cs_bool_t clone(interface_type *src, interface_type **pdest)
    {
        COMSTL_ASSERT(NULL != src);
        COMSTL_ASSERT(NULL != pdest);

        *pdest = share(src);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        COMSTL_ASSERT(NULL != *pdest);

        return true;
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        return NULL != *pdest;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
};

/** Policy type that causes COM enumerator cloning according the STL Forward Iterator concept
 *
 * \ingroup group__library__Collection
 *
 * \param I The enumeration interface
 */
template<ss_typename_param_k I>
struct forward_cloning_policy
    : public repeatable_enumerator_tag
{
public:
    typedef I                                           interface_type;
    typedef interface_type*                             value_type;
    typedef STLSOFT_NS_QUAL_STD(forward_iterator_tag)    iterator_tag_type;

public:
    /// Gets a working "copy" of the given enumerator root
    ///
    /// \remarks For this policy, this calls Clone(), and throws an
    ///   instance of comstl::clone_failure if that fails (or returns
    ///   NULL if exception support is disabled).
    static interface_type *get_working_instance(interface_type *root)
    {
        COMSTL_ASSERT(NULL != root);

        interface_type  *ret;
        HRESULT         hr  =   const_cast<interface_type*>(root)->Clone(&ret);

        if (FAILED(hr))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(clone_failure(hr));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            ret = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return ret;
    }

    /// "Clones" the given COM enumerator interface according to the Forward Iterator concept
    static interface_type *share(interface_type *src)
    {
        COMSTL_ASSERT(NULL != src);

        interface_type  *ret;
        HRESULT         hr  =   const_cast<interface_type*>(src)->Clone(&ret);

        if (FAILED(hr))
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            STLSOFT_THROW_X(clone_failure(hr));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
            ret = NULL;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return ret;
    }
    static cs_bool_t clone(interface_type *src, interface_type **pdest)
    {
        COMSTL_ASSERT(NULL != src);
        COMSTL_ASSERT(NULL != pdest);

        *pdest = share(src);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        COMSTL_ASSERT(NULL != *pdest);

        return true;
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
        return NULL != *pdest;
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }
};

/** Adapts a value policy to a function class based interface
 *
 * \ingroup group__library__Collection
 *
 * \param P The value policy (e.g. BSTR_policy, VARIANT_policy, FORMATETC_policy)
 */
template <ss_typename_param_k P>
struct value_policy_adaptor
    : public P
{
public:
    typedef ss_typename_type_k P::value_type    value_type;

public:
    /// The initialisation function class
    struct init_element
    {
        /// The function call operator, which causes the value to be initialised
        void operator ()(value_type &v) const
        {
            P::init(&v);
        }
    };
    /// The copy function class
    struct copy_element
    {
        /// The function call operator, which causes the destination to be copied from the source
        void operator ()(value_type &dest, value_type const& src) const
        {
            P::copy(&dest, &src);
        }
    };
    /// The clear function class
    struct clear_element
    {
        /// The function call operator, which causes the value to be cleared
        void operator ()(value_type &v) const
        {
            P::clear(&v);
        }
    };
};

/** [DEPRECATED] Adapts a value policy to a function class based interface
 *
 * \deprecated Equivalent to value_policy_adaptor
 *
 * \ingroup group__library__Collection
 */
template <ss_typename_param_k P>
struct policy_adaptor
    : public value_policy_adaptor<P>
{
public:
    typedef ss_typename_type_k P::value_type    value_type;
};

/** Acquires an enumerator from a collection assuming _NewEnum property
 *
 * \ingroup group__library__Collection
 *
 * \remarks Invokes the the get__NewEnum() method
 */
template <ss_typename_param_k CI>
struct new_enum_property_policy
{
public:
    typedef CI          collection_interface;

public:
    static HRESULT acquire(collection_interface *pcoll, LPUNKNOWN *ppunkEnum)
    {
        COMSTL_ASSERT(NULL != pcoll);
        COMSTL_ASSERT(NULL != ppunkEnum);

        // If the compiler complains here that your interface does not have the
        // get__NewEnum method, then:
        //
        // - you're passing a pure IDispatch interface, so you need to use
        //    new_enum_by_dispid_policy
        // - you're passing a collection interface that defines _NeWEnum as a
        //    method, so you need to use new_enum_method_policy
        // - you're passing the wrong interface. Check your code to ensure
        //    you've not used the wrong interface to specialise
        //    comstl::collection_sequence.
        return pcoll->get__NewEnum(ppunkEnum);
    }
};

/** Acquires an enumerator from a collection assuming _NewEnum method
 *
 * \ingroup group__library__Collection
 *
 * \remarks Invokes the the _NewEnum() method
 */
template <ss_typename_param_k CI>
struct new_enum_method_policy
{
public:
    typedef CI          collection_interface;

public:
    static HRESULT acquire(collection_interface *pcoll, LPUNKNOWN *ppunkEnum)
    {
        COMSTL_ASSERT(NULL != pcoll);
        COMSTL_ASSERT(NULL != ppunkEnum);

        return pcoll->_NewEnum(ppunkEnum);
    }
};

/** Acquires an enumerator from a collection by looking up the DISPID_NEWENUM on the collection's IDispatch interface
 *
 * \ingroup group__library__Collection
 *
 * \remarks Calls IDispatch::Invoke(DISPID_NEWENUM, . . . , DISPATCH_METHOD | DISPATCH_PROPERTYGET, . . . );
 */
template <ss_typename_param_k CI>
struct new_enum_by_dispid_policy
{
public:
    typedef CI          collection_interface;

public:
    static HRESULT acquire(collection_interface *pcoll, LPUNKNOWN *ppunkEnum)
    {
        COMSTL_ASSERT(NULL != pcoll);
        COMSTL_ASSERT(NULL != ppunkEnum);

        LPDISPATCH  pdisp;
        HRESULT     hr  =   pcoll->QueryInterface(IID_IDispatch, reinterpret_cast<void**>(&pdisp));

        if (SUCCEEDED(hr))
        {
            DISPPARAMS  params;
            UINT        argErrIndex;
            VARIANT     result;

            STLSOFT_API_INTERNAL_memfns_memset(&params, 0, sizeof(params));
            ::VariantInit(&result);

            hr = pdisp->Invoke( DISPID_NEWENUM
                            ,   IID_NULL
                            ,   LOCALE_USER_DEFAULT
                            ,   DISPATCH_METHOD | DISPATCH_PROPERTYGET
                            ,   &params
                            ,   &result
                            ,   NULL
                            ,   &argErrIndex);

            pdisp->Release();

            if (SUCCEEDED(hr))
            {
                hr = ::VariantChangeType(&result, &result, 0, VT_UNKNOWN);

                if (SUCCEEDED(hr))
                {
                    if (NULL == result.punkVal)
                    {
                        hr = E_UNEXPECTED;
                    }
                    else
                    {
                        *ppunkEnum = result.punkVal;

                        (*ppunkEnum)->AddRef();
                    }
                }

                ::VariantClear(&result);
            }
        }

        return hr;
    }
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef COMSTL_NO_NAMESPACE
# if defined(STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace comstl */
# else
} /* namespace stlsoft::comstl_project */
} /* namespace stlsoft */
# endif /* STLSOFT_NO_NAMESPACE */
#endif /* !COMSTL_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !COMSTL_INCL_COMSTL_COLLECTIONS_HPP_ENUMERATION_POLICIES */

/* ///////////////////////////// end of file //////////////////////////// */

