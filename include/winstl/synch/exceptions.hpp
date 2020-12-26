/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/synch/exceptions.hpp
 *
 * Purpose:     Synchronisation library exception(s).
 *
 * Created:     30th May 2006
 * Updated:     26th December 2020
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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

/** \file winstl/synch/exceptions.hpp
 *
 * \brief [C++] Definition of winstl::synchronisation_exception class
 *   (\ref group__library__Synch "Synchronisation" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS
#define WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_MAJOR     2
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_MINOR     5
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_REVISION  2
# define WINSTL_VER_WINSTL_SYNCH_HPP_EXCEPTIONS_EDIT      29
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

#ifndef WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE
# include <winstl/synch/Synchronisation_status_code.h>
#endif /* !WINSTL_INCL_WINSTL_SYNCH_H_SYNCHRONISATION_STATUS_CODE */

#ifndef WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION
# include <winstl/exception/winstl_exception.hpp>
#endif /* !WINSTL_INCL_WINSTL_EXCEPTION_HPP_WINSTL_EXCEPTION */

#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT
# include <stlsoft/quality/contract.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_CONTRACT */
#ifndef STLSOFT_INCL_STLSOFT_QUALITY_H_COVER
# include <stlsoft/quality/cover.h>
#endif /* !STLSOFT_INCL_STLSOFT_QUALITY_H_COVER */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# include <stdexcept>
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT */

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

#if 0

    // TODO: Questions:
    //
    // 1. should synchronisation_logic_exception derive from std::logic_error?
    // 2. Should synchronisation_logic_exception derive only from std::logic_error?
    // 3. Should wait_failed_logic_exception derive from std::invalid_argument?

    [winstl::winstl_exception]

        <-  synchronisation_exception [A]

                /* should not happen (in a well-designed program) */
            <-  synchronisation_logic_exception [A]

                <-  wait_failed_logic_exception [A]

                    <-  invalid_wait_handle_exception

                        <-  null_wait_handle_exception

                    <-  duplicate_wait_handle_exception

                    <-  too_many_wait_handles_exception

                    <-  invalid_state_exception

                /* may happen (in a well-designed program) */
            <-  synchronisation_runtime_exception [A]

                    /* (likely to be) unrecoverable */
                <-  synchronisation_runtime_failure_exception [A]

                    <-  synchronisation_procurement_exception [A]

                        <-  synchronisation_creation_exception

                        <-  synchronisation_open_exception

                        <-  thread_creation_exception

                    <-  synchronisation_object_state_change_failed_exception

                    <-  wait_failed_runtime_exception [A]

                        <-  wait_abandoned_exception

                    /* (may be) recoverable */
                <-  wait_operation_interrupted_exception [A]

                    <-  wait_operation_priority_preemption_exception

#endif /* 0 */

/* ///////////////////////////
 * abstract classes
 */

/** Root exception thrown by
 *   the \ref group__library__Synch "Synchronisation" library.
 */
class synchronisation_exception
    : public winstl_exception
{
public: // Member Types
    /// The parent exception type
    typedef winstl_exception                                parent_class_type;
    /// This type
    typedef synchronisation_exception                       class_type;
    /// The system condition code type
    typedef parent_class_type::status_code_type             system_status_code_type;
    /// The subsystem-specific status code type
    typedef Synchronisation_status_code_t                   subsystem_status_code_type;

protected: // Construction
    synchronisation_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(message, sc)
        , SubsystemStatusCode(subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The subsystem-specific status code associated with the condition
    /// that resulted in the exception being thrown.
    subsystem_status_code_type const    SubsystemStatusCode;
};


/** Root exception for classes of synchronisation logic errors
 */
class synchronisation_logic_exception
    : public synchronisation_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_exception                       parent_class_type;
    /// This type
    typedef synchronisation_logic_exception                 class_type;
    /// The condition code type
    typedef parent_class_type::status_code_type             system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type   subsystem_status_code_type;

protected: // Construction
    synchronisation_logic_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    // copy assignment is proscribed
    class_type& operator =(class_type const&);
};

/** Root exception for classes of synchronisation runtime conditions
 */
class synchronisation_runtime_exception
    : public synchronisation_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_exception                       parent_class_type;
    /// This type
    typedef synchronisation_runtime_exception               class_type;
    /// The condition code type
    typedef parent_class_type::status_code_type             system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type   subsystem_status_code_type;

protected: // Construction
    synchronisation_runtime_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    // copy assignment is proscribed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that a wait operation has failed
 */
class wait_failed_logic_exception
    : public synchronisation_logic_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_logic_exception             parent_class_type;
    /// This type
    typedef wait_failed_logic_exception                 class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    wait_failed_logic_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_WaitFailed)
    {}
protected:
    wait_failed_logic_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Root exception for classes of synchronisation runtime failures
 */
class synchronisation_runtime_failure_exception
    : public synchronisation_runtime_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_runtime_exception               parent_class_type;
    /// This type
    typedef synchronisation_runtime_failure_exception       class_type;
    /// The condition code type
    typedef parent_class_type::status_code_type             system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type   subsystem_status_code_type;

protected: // Construction
    synchronisation_runtime_failure_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    // copy assignment is proscribed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that a wait operation has failed.
 */
class wait_failed_runtime_exception
    : public synchronisation_runtime_failure_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_runtime_failure_exception   parent_class_type;
    /// This type
    typedef wait_failed_runtime_exception               class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

protected: // Construction
    wait_failed_runtime_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_WaitFailed)
    {}
    wait_failed_runtime_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that a wait operation has been interrupted.
 */

class wait_operation_interrupted_exception
    : public synchronisation_runtime_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_runtime_exception               parent_class_type;
    /// This type
    typedef wait_operation_interrupted_exception            class_type;
    /// The condition code type
    typedef parent_class_type::status_code_type             system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type   subsystem_status_code_type;

protected: // Construction
    wait_operation_interrupted_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_WaitOperationInterrupted)
    {}
private:
    // copy assignment is proscribed
    class_type& operator =(class_type const&);
};

/* ///////////////////////////
 * concrete classes - logic
 */

/** Exception thrown to indicate invalid wait handle(s)
 */
class invalid_wait_handle_exception
    : public wait_failed_logic_exception
{
public: // Member Types
    /// The parent exception type
    typedef wait_failed_logic_exception                 parent_class_type;
    /// This type
    typedef invalid_wait_handle_exception               class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param waitIndex The index of the handle in a vector wait
    ///   operation. Specify -1 if scalar wait
    invalid_wait_handle_exception(
        system_status_code_type sc
    ,   int                     waitIndex
    )
        : parent_class_type(sc, "invalid wait handle")
        , WaitIndex(waitIndex)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The index of the handle in a vector wait operation. -1 if scalar
    /// wait operation
    const int WaitIndex;
};

/** Exception thrown to indicate one or more NULL wait handles
 */
class null_wait_handle_exception
    : public invalid_wait_handle_exception
{
public: // Member Types
    /// The parent exception type
    typedef invalid_wait_handle_exception               parent_class_type;
    /// This type
    typedef null_wait_handle_exception                  class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param waitIndex The index of the handle in a vector wait
    ///   operation. Specify -1 if scalar wait
    null_wait_handle_exception(
        system_status_code_type sc
    ,   int                     waitIndex
    )
        : parent_class_type(sc, waitIndex)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate duplicate wait handles
 */
class duplicate_wait_handle_exception
    : public wait_failed_logic_exception
{
public: // Member Types
    /// The parent exception type
    typedef wait_failed_logic_exception                 parent_class_type;
    /// This type
    typedef duplicate_wait_handle_exception             class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param firstIndex The first index of the first duplicated handle in
    ///   a vector wait operation
    /// \param secondIndex The second index of the first duplicated handle
    ///   in a vector wait operation
    duplicate_wait_handle_exception(
        system_status_code_type sc
    ,   ws_size_t               firstIndex
    ,   ws_size_t               secondIndex
    )
        : parent_class_type(sc, "duplicate wait handles")
        , FirstIndex(firstIndex)
        , SecondIndex(secondIndex)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The first index of the first duplicated handle in a vector wait
    /// operation
    const ws_size_t FirstIndex;
    /// The second index of the first duplicated handle in a vector wait
    /// operation
    const ws_size_t SecondIndex;
};

/** Exception thrown to indicate duplicate too many wait handles
 */
class too_many_wait_handles_exception
    : public wait_failed_logic_exception
{
public: // Member Types
    /// The parent exception type
    typedef wait_failed_logic_exception                 parent_class_type;
    /// This type
    typedef too_many_wait_handles_exception             class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param numWaitHandles The number of wait handles specified to the
    ///   operation raising the exception.
    too_many_wait_handles_exception(
        system_status_code_type sc
    ,   ws_size_t               numWaitHandles
    )
        : parent_class_type(sc, "too many wait handles")
        , NumWaitHandles(numWaitHandles)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The number of wait handles specified to the operation raising the
    /// exception.
    ws_size_t const NumWaitHandles;
};

/** Exception thrown to indicate object is in an invalid state for the
 * requested operation
 */
class invalid_state_exception
    : public wait_failed_logic_exception
{
public: // Member Types
    /// The parent exception type
    typedef wait_failed_logic_exception                 parent_class_type;
    /// This type
    typedef invalid_state_exception                     class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    ss_explicit_k
    invalid_state_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
};

/* ///////////////////////////
 * concrete classes - runtime
 */

/** Exception thrown to indicate that the creation of a synchronisation
 * object has failed.
 */
class synchronisation_procurement_exception
    : public synchronisation_runtime_failure_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_runtime_failure_exception   parent_class_type;
    /// This type
    typedef synchronisation_procurement_exception       class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
protected:
    synchronisation_procurement_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that the creation of a synchronisation
 * object has failed.
 */
class synchronisation_creation_exception
    : public synchronisation_procurement_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_procurement_exception       parent_class_type;
    /// This type
    typedef synchronisation_creation_exception          class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param message The message associated with the exception
    synchronisation_creation_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_SynchronisationObjectCreationFailed)
    {}
protected:
    synchronisation_creation_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that the open of a synchronisation
 * object has failed.
 */
class synchronisation_open_exception
    : public synchronisation_procurement_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_procurement_exception       parent_class_type;
    /// This type
    typedef synchronisation_open_exception              class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param message The message associated with the exception
    synchronisation_open_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_SynchronisationObjectOpenFailed)
    {}
protected:
    synchronisation_open_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that the creation of a thread has failed.
 */
class thread_creation_exception
    : public synchronisation_procurement_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_procurement_exception       parent_class_type;
    /// This type
    typedef thread_creation_exception                   class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type  system_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param message The message associated with the exception
    thread_creation_exception(
        system_status_code_type sc
    ,   ws_char_a_t const*      message
    )
        : parent_class_type(sc, message, Synchronisation_ThreadCreateFailed)
    {}
protected:
    thread_creation_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that an operation to change the state of a
 * synchronisation object has failed.
 */
class synchronisation_object_state_change_failed_exception
    : public synchronisation_runtime_failure_exception
{
public: // Member Types
    /// The parent exception type
    typedef synchronisation_runtime_failure_exception               parent_class_type;
    /// This type
    typedef synchronisation_object_state_change_failed_exception    class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type             system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type           subsystem_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param message The message associated with the exception
    /// \param subsystemStatusCode The subsystem-specific status code to be
    ///   associated with the exception
    synchronisation_object_state_change_failed_exception(
        system_status_code_type     sc
    ,   ws_char_a_t const*          message
    ,   subsystem_status_code_type  subsystemStatusCode
    )
        : parent_class_type(sc, message, subsystemStatusCode)
    {
        WINSTL_ASSERT(Synchronisation_SynchronisationObjectCreationFailed != subsystemStatusCode);
        WINSTL_ASSERT(Synchronisation_WaitFailed != subsystemStatusCode);
        WINSTL_ASSERT(Synchronisation_WaitOperationInterrupted != subsystemStatusCode);
    }
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that a wait operation has been interrupted
 * by the signalling of a synchronisation object of higher-priority (lower
 * order) in the wait array.
 */
class wait_abandoned_exception
    : public wait_failed_runtime_exception
{
public: // Member Types
    /// The parent exception type
    typedef wait_failed_runtime_exception                       parent_class_type;
    /// This type
    typedef wait_abandoned_exception                            class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type          system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type       subsystem_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param message The message associated with the exception
    ss_explicit_k
    wait_abandoned_exception(
        system_status_code_type     sc      =   ERROR_SUCCESS
    ,   ws_char_a_t const*          message =   "wait abandoned"
    )
        : parent_class_type(sc, message, Synchronisation_WaitAbandoned)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);
};

/** Exception thrown to indicate that a wait operation has been interrupted
 * by the signalling of a synchronisation object of higher-priority (lower
 * order) in the wait array.
 */
class wait_operation_priority_preemption_exception
    : public wait_operation_interrupted_exception
{
public: // Member Types
    /// The parent exception type
    typedef wait_operation_interrupted_exception                parent_class_type;
    /// This type
    typedef wait_operation_priority_preemption_exception        class_type;
    /// The condition code type
    typedef parent_class_type::system_status_code_type          system_status_code_type;
    /// The subsystem-specific status code type
    typedef parent_class_type::subsystem_status_code_type       subsystem_status_code_type;

public: // Construction
    /// Constructs an instance
    ///
    /// \param sc The system condition code associated with the condition
    ///   that resulted in the exception being thrown
    /// \param indexOfSignalledSynchronisationObject The index of the
    ///   signalled synchronisation object that preempted the wait
    ///   operation
    /// \param message The message associated with the exception
    wait_operation_priority_preemption_exception(
        system_status_code_type sc
    ,   int                     indexOfSignalledSynchronisationObject
    ,   ws_char_a_t const*      message =   "wait operation priority-preempted"
    )
        : parent_class_type(sc, message)
        , IndexOfSignalledSynchronisationObject(indexOfSignalledSynchronisationObject)
    {}
private:
    /// Copy assignment is not allowed
    class_type& operator =(class_type const&);

public: // Fields
    /// The index of the signalled synchronisation object (that preempted
    /// the overall wait operation)
    int const   IndexOfSignalledSynchronisationObject;
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

#endif /* !WINSTL_INCL_WINSTL_SYNCH_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

