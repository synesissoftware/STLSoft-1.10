/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/quality/contract.h
 *
 * Purpose:     Defines the contract enforcement constructs used in the
 *              STLSoft libraries.
 *
 * Created:     13th October 2008
 * Updated:     22nd January 2024
 *
 * Home:        http://www.stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


/** \file stlsoft/quality/contract.h
 *
 * \brief [C, C++] Defines the contract enforcement constructs used in the
 *   \ref group__library__ContractEnforcement "Contract Enforcement"
 *   library.
 */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
#define STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_QUALITY_H_CONTRACT_MAJOR       1
# define STLSOFT_VER_STLSOFT_QUALITY_H_CONTRACT_MINOR       1
# define STLSOFT_VER_STLSOFT_QUALITY_H_CONTRACT_REVISION    3
# define STLSOFT_VER_STLSOFT_QUALITY_H_CONTRACT_EDIT        15
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

#ifdef STLSOFT_USE_XCONTRACT
# include <xcontract/xcontract.h>
#endif /* STLSOFT_USE_XCONTRACT */

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef STLSOFT_USE_XCONTRACT

# ifndef STLSOFT_CONTRACT_LEVEL_EXTERNAL
#  define STLSOFT_CONTRACT_LEVEL_EXTERNAL                   (21)
# endif /* !STLSOFT_CONTRACT_LEVEL_EXTERNAL */

# ifndef STLSOFT_CONTRACT_LEVEL_INTERNAL
#  define STLSOFT_CONTRACT_LEVEL_INTERNAL                   (31)
# endif /* !STLSOFT_CONTRACT_LEVEL_INTERNAL */

# ifndef STLSOFT_CONTRACT_LEVEL_API
#  define STLSOFT_CONTRACT_LEVEL_API                        (35)
# endif /* !STLSOFT_CONTRACT_LEVEL_API */

# define STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL(msg)            XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_unexpectedCondition), STLSOFT_CONTRACT_LEVEL_INTERNAL, NULL, msg)
# define STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_API(msg)                 XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_unexpectedCondition), STLSOFT_CONTRACT_LEVEL_API, NULL, msg)

# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(expr, msg)        XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_precondition_logic), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_API(expr, msg)             XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_precondition_logic), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(expr, msg)       XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_precondition_parameters), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(expr, msg)            XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_precondition_parameters), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(expr, msg)      XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_returnValue), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_EXTERNAL(expr, msg)      XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_returnValue), STLSOFT_CONTRACT_LEVEL_EXTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(expr, msg)           XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_returnValue), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE_INTERNAL(expr, msg)       XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_logic), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE_API(expr, msg)            XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_logic), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_INTERNAL(expr, msg)      XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_parameters), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_EXTERNAL(expr, msg)      XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_parameters), STLSOFT_CONTRACT_LEVEL_EXTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API(expr, msg)           XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_postcondition_parameters), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(expr, msg)           XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_invariant_class), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_API(expr, msg)                XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_invariant_class), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_INTERNAL(expr, msg)          XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_invariant_global), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_API(expr, msg)               XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_invariant_global), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_STATIC_DATA_INTERNAL(expr, msg)               XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_staticData), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)
# define STLSOFT_CONTRACT_ENFORCE_STATIC_DATA_API(expr, msg)                    XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_staticData), STLSOFT_CONTRACT_LEVEL_API, expr, msg)

# define STLSOFT_CONTRACT_ENFORCE_ASSUMPTION(expr)                              XCONTRACT_ENFORCE_CONDITION_TYPE_LEVEL_(XCONTRACT_NS_QUAL(xContract_intermediateAssumption), STLSOFT_CONTRACT_LEVEL_INTERNAL, expr, msg)

#else /* ? STLSOFT_USE_XCONTRACT */

# define STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL(msg)            STLSOFT_MESSAGE_ASSERT(msg, 0)
# define STLSOFT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_API(msg)                 STLSOFT_MESSAGE_ASSERT(msg, 0)

# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(expr, msg)        STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_STATE_API(expr, msg)             STLSOFT_MESSAGE_ASSERT(msg, expr)

# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(expr, msg)       STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(expr, msg)            STLSOFT_MESSAGE_ASSERT(msg, expr)

# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(expr, msg)      STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_EXTERNAL(expr, msg)      STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_API(expr, msg)           STLSOFT_MESSAGE_ASSERT(msg, expr)

# if 1
#  define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE(expr, msg)               STLSOFT_MESSAGE_ASSERT(msg, expr)
# else /* ? 1 */
#  error rename STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE_INTERNAL() to STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE()
#  error remove STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE_API()
#  define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE_INTERNAL(expr, msg)      STLSOFT_MESSAGE_ASSERT(msg, expr)
#  define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_STATE_API(expr, msg)           STLSOFT_MESSAGE_ASSERT(msg, expr)
# endif /* 1 */

# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_INTERNAL(expr, msg)      STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_EXTERNAL(expr, msg)      STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_POSTCONDITION_PARAMS_API(expr, msg)           STLSOFT_MESSAGE_ASSERT(msg, expr)

# define STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_INTERNAL(expr, msg)           STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_CLASS_INVARIANT_API(expr, msg)                STLSOFT_MESSAGE_ASSERT(msg, expr)

# define STLSOFT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_INTERNAL(expr, msg)          STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_API(expr, msg)               STLSOFT_MESSAGE_ASSERT(msg, expr)

# define STLSOFT_CONTRACT_ENFORCE_STATIC_DATA_INTERNAL(expr, msg)               STLSOFT_MESSAGE_ASSERT(msg, expr)
# define STLSOFT_CONTRACT_ENFORCE_STATIC_DATA_API(expr, msg)                    STLSOFT_MESSAGE_ASSERT(msg, expr)

# define STLSOFT_CONTRACT_ENFORCE_ASSUMPTION(expr)                              STLSOFT_ASSERT(expr)

#endif /* STLSOFT_USE_XCONTRACT */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */

/* ///////////////////////////// end of file //////////////////////////// */

