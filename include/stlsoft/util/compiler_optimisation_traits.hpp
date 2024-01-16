/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/util/compiler_optimisation_traits.hpp (was stlsoft_compiler_traits.h)
 *
 * Purpose:     compiler_optimisation_traits class.
 *
 * Created:     15th November 2003
 * Updated:     17th January 2024
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


/** \file stlsoft/util/compiler_optimisation_traits.hpp
 *
 * \brief [C++] Definition of the stlsoft::compiler_optimisation_traits
 *   traits class
 *   (\ref group__library__Utility "Utility" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_UTIL_HPP_COMPILER_OPTIMISATION_TRAITS
#define STLSOFT_INCL_STLSOFT_UTIL_HPP_COMPILER_OPTIMISATION_TRAITS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_COMPILER_OPTIMISATION_TRAITS_MAJOR       4
# define STLSOFT_VER_H_STLSOFT_COMPILER_OPTIMISATION_TRAITS_MINOR       0
# define STLSOFT_VER_H_STLSOFT_COMPILER_OPTIMISATION_TRAITS_REVISION    5
# define STLSOFT_VER_H_STLSOFT_COMPILER_OPTIMISATION_TRAITS_EDIT        32
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

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
/** The base class, and the comparand for empty cases
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits_ebo_parent
{};

/* EBO - Empty Base Optimisation
 */

/** The result of Case 1, and the intermediate parent for Cases 3 & 4.
 *
 * \ingroup group__library__Utility
 *
 *       compiler_optimisation_traits_ebo_parent
 *                |
 *                V
 *     compiler_optimisation_traits_ebo_thin_child
 *
 */
struct compiler_optimisation_traits_ebo_thin_child
    : compiler_optimisation_traits_ebo_parent
{};

/** The result of Case 2
 *
 * \ingroup group__library__Utility
 *
 *       compiler_optimisation_traits_ebo_parent
 *                |
 *                V
 *     compiler_optimisation_traits_ebo_thick_child
 *
 */
struct compiler_optimisation_traits_ebo_thick_child
    : compiler_optimisation_traits_ebo_parent
{
    int i;
};

/** Used in Cases 2, 4, 6 & 8
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits_ebo_thick_peer
{
    int i;
};

/** The result of Case 3
 *
 * \ingroup group__library__Utility
 *
 *       compiler_optimisation_traits_ebo_parent
 *                |
 *                V
 *     compiler_optimisation_traits_ebo_thin_child
 *                |
 *                V
 *   compiler_optimisation_traits_ebo_thin_grandchild
 *
 */
struct compiler_optimisation_traits_ebo_thin_grandchild
    : compiler_optimisation_traits_ebo_thin_child
{};

/** The result of Case 4
 *
 * \ingroup group__library__Utility
 *
 *       compiler_optimisation_traits_ebo_parent
 *                |
 *                V
 *     compiler_optimisation_traits_ebo_thin_child
 *                |
 *                V
 *   compiler_optimisation_traits_ebo_thick_grandchild
 *
 */
struct compiler_optimisation_traits_ebo_thick_grandchild
    : compiler_optimisation_traits_ebo_thin_child
{
    int i;
};

/** Used in Case 5
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits_ebo_parent2
{};

/** The result of Case 5
 *
 * \ingroup group__library__Utility
 *
 *   compiler_optimisation_traits_ebo_parent      compiler_optimisation_traits_ebo_parent2
 *                |                        |
 *                V                        V
 *            compiler_optimisation_traits_ebo_mi_thin_child
 *
 */
struct compiler_optimisation_traits_ebo_mi_thin_child
    : compiler_optimisation_traits_ebo_parent, compiler_optimisation_traits_ebo_parent2
{};

/** The result of Case 6
 *
 * \ingroup group__library__Utility
 *
 *   compiler_optimisation_traits_ebo_parent      compiler_optimisation_traits_ebo_parent2
 *                |                        |
 *                V                        V
 *            compiler_optimisation_traits_ebo_mi_thick_child
 *
 */
struct compiler_optimisation_traits_ebo_mi_thick_child
    : compiler_optimisation_traits_ebo_parent, compiler_optimisation_traits_ebo_parent2
{
    int i;
};

/** The result of Case 7
 *
 * \ingroup group__library__Utility
 *
 *   compiler_optimisation_traits_ebo_parent      compiler_optimisation_traits_ebo_thick_peer
 *                |                        |
 *                V                        V
 *            compiler_optimisation_traits_ebo_mi_mixin_child
 *
 */
struct compiler_optimisation_traits_ebo_mi_mixin_child
    : compiler_optimisation_traits_ebo_parent, compiler_optimisation_traits_ebo_thick_peer
{};


/* EDO - Empty Derived Optimisation
 */

/** Used in Case 1
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits_edo_thin_base
{};

/** Used in Case 2
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits_edo_thick_base
{
    int i;
};

/** Used in Case 3
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits_edo_thin_base2
{};

/** Used in Cases 3 & 4
 *
 * \ingroup group__library__Utility
 *
 */
template <ss_typename_param_k T>
struct compiler_optimisation_traits_edo_child
    : T
{};

/** Result of case 3
 *
 * \ingroup group__library__Utility
 *
 *       compiler_optimisation_traits_edo_thick_base
 *                    |
 *                    V
 *    compiler_optimisation_traits_edo_child_of_thick_base
 *
 */
struct compiler_optimisation_traits_edo_child_of_thick_base
    : compiler_optimisation_traits_edo_thick_base
{};


/** Used in Cases 7 & 8
 *
 * \ingroup group__library__Utility
 *
 */
template<   ss_typename_param_k T1
        ,   ss_typename_param_k T2
        >
struct compiler_optimisation_traits_edo_mi_child
    : T1, T2
{};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/** traits class for (current) compiler
 *
 * \ingroup group__library__Utility
 *
 */
struct compiler_optimisation_traits
{
public:
    // Empty Base Optimisation (EBO)
    //
    /// 1. With empty base and empty child
    enum { supportsEBO1 = sizeof(compiler_optimisation_traits_ebo_thin_child) == sizeof(compiler_optimisation_traits_ebo_parent) };
    /// 2. With empty base and non-empty child
    enum { supportsEBO2 = sizeof(compiler_optimisation_traits_ebo_thick_child) == sizeof(compiler_optimisation_traits_ebo_thick_peer) };
    /// 3. With empty base, empty intermediate, and empty child
    enum { supportsEBO3 = sizeof(compiler_optimisation_traits_ebo_thin_grandchild) == sizeof(compiler_optimisation_traits_ebo_parent) };
    /// 4. With empty base, empty intermediate, and non-empty child
    enum { supportsEBO4 = sizeof(compiler_optimisation_traits_ebo_thick_grandchild) == sizeof(compiler_optimisation_traits_ebo_thick_peer) };
    /// 5. With two empty bases and empty child
    enum { supportsEBO5 = sizeof(compiler_optimisation_traits_ebo_mi_thin_child) == sizeof(compiler_optimisation_traits_ebo_parent) };
    /// 6. With two empty bases and non-empty child
    enum { supportsEBO6 = sizeof(compiler_optimisation_traits_ebo_mi_thick_child) == sizeof(compiler_optimisation_traits_ebo_thick_peer) };
    /// 7. With one empty base (the mixin), one non-empty base and empty child
    enum { supportsEBO7 = sizeof(compiler_optimisation_traits_ebo_mi_mixin_child) == sizeof(compiler_optimisation_traits_ebo_thick_peer) };

    enum { supportsEBO = int(supportsEBO1) & int(supportsEBO2) & int(supportsEBO3) & int(supportsEBO4) };
    enum { supportsMIEBO = int(supportsEBO5) & int(supportsEBO6) & int(supportsEBO7) /* & int(supportsEBO8) */ };
    enum { supportsExtendedEBO = int(supportsEBO) & int(supportsMIEBO) };

    // Empty Derived Optimisation (EDO)
    //
    /// 1. With empty base (same as EBO1)
    enum { supportsEDO1 = supportsEBO1 };
    /// 2. With empty base (same as EBO1); child is template
    enum { supportsEDO2 = sizeof(compiler_optimisation_traits_edo_child<compiler_optimisation_traits_edo_thin_base>) == sizeof(compiler_optimisation_traits_edo_thin_base) };
    /// 3. With non-empty base
    enum { supportsEDO3 = sizeof(compiler_optimisation_traits_edo_child_of_thick_base) == sizeof(compiler_optimisation_traits_edo_thick_base) };
    /// 4. With non-empty base; child is template
    enum { supportsEDO4 = sizeof(compiler_optimisation_traits_edo_child<compiler_optimisation_traits_edo_thick_base>) == sizeof(compiler_optimisation_traits_edo_thick_base) };

    /// 5. With two empty bases
    enum { supportsEDO5 = supportsEBO5 };
    /// 6. With two empty bases; child is template
    enum { supportsEDO6 = sizeof(compiler_optimisation_traits_edo_mi_child<compiler_optimisation_traits_edo_thin_base, compiler_optimisation_traits_edo_thin_base2>) == sizeof(compiler_optimisation_traits_edo_thin_base) };
    /// 7. With one empty base (the mixin), one non-empty base
    enum { supportsEDO7 = supportsEBO7 };
    /// 8. With one empty base (the mixin), one non-empty base; child is template
    enum { supportsEDO8 = sizeof(compiler_optimisation_traits_edo_mi_child<compiler_optimisation_traits_edo_thick_base, compiler_optimisation_traits_edo_thin_base>) == sizeof(compiler_optimisation_traits_edo_thick_base) };

    enum { supportsEDO = int(supportsEDO1) & int(supportsEDO2) & int(supportsEDO3) & int(supportsEDO4) };
    enum { supportsMIEDO = int(supportsEDO5) & int(supportsEDO6) & int(supportsEDO7) & int(supportsEDO8) };
    enum { supportsExtendedEDO = int(supportsEDO) & int(supportsMIEDO) };
};

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

#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_COMPILER_OPTIMISATION_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

