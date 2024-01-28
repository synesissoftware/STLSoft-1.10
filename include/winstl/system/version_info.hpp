/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/system/version_info.hpp (originally in MWVerInf.h, ::SynesisWin)
 *
 * Purpose:     Helper for accessing version information.
 *
 * Created:     16th February 1998
 * Updated:     22nd January 2024
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/system/version_info.hpp
 *
 * \brief [C++] Definition of the winstl::version_info class
 *  template
 *   (\ref group__library__System "System" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_VERSION_INFO
#define WINSTL_INCL_WINSTL_SYSTEM_HPP_VERSION_INFO

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SYSTEM_HPP_VERSION_INFO_MAJOR    5
# define WINSTL_VER_WINSTL_SYSTEM_HPP_VERSION_INFO_MINOR    3
# define WINSTL_VER_WINSTL_SYSTEM_HPP_VERSION_INFO_REVISION 17
# define WINSTL_VER_WINSTL_SYSTEM_HPP_VERSION_INFO_EDIT     152
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
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS
# include <winstl/system/system_traits.hpp>
#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_SYSTEM_TRAITS */
#ifndef STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_CONVERSION_HPP_SAP_CAST */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES
# include <stlsoft/memory/util/allocator_features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_FEATURES */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING
# include <stlsoft/shims/access/string.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ACCESS_HPP_STRING */
#ifndef STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER
# include <stlsoft/util/std/iterator_helper.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_STD_HPP_ITERATOR_HELPER */
#ifndef STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS
# include <stlsoft/collections/util/collections.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_COLLECTIONS_UTIL_HPP_COLLECTIONS */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# include <stdexcept>                           // for std::exception
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */

#ifndef STLSOFT_INCL_H_WCHAR
# define STLSOFT_INCL_H_WCHAR
# include <wchar.h>
#endif /* !STLSOFT_INCL_H_WCHAR */

#ifndef WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary
# include <winstl/api/external/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_DynamicLinkLibrary */
#ifndef WINSTL_INCL_WINSTL_API_external_h_ErrorHandling
# include <winstl/api/external/ErrorHandling.h>
#endif /* !WINSTL_INCL_WINSTL_API_external_h_ErrorHandling */
#ifndef WINSTL_INCL_WINSTL_API_internal_h_DynamicLinkLibrary
# include <winstl/api/internal/DynamicLinkLibrary.h>
#endif /* !WINSTL_INCL_WINSTL_API_internal_h_DynamicLinkLibrary */

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
 * structure headers
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_OPEN_WORKER_NS_(ximpl_winstl_version_info_)


// The following bizarre construction is solely to avoid an ICE in VC6
// that only raises its ugly head in large, non-trivial, compilation
// contexts.

template<ss_typename_param_k T>
struct hdr
{
    template<int N>
    struct hdr_
    {
        WORD    wLength;
        WORD    wValueLength;
        WORD    wType;
        WCHAR   szKey[1];
    };

}; /* namespace hdr */

typedef hdr<int>::hdr_<1>                                   VS_VERSIONINFO_hdr;
typedef hdr<int>::hdr_<2>                                   StringFileInfo_hdr;
typedef hdr<int>::hdr_<3>                                   VarFileInfo_hdr;
typedef hdr<int>::hdr_<4>                                   Var_hdr;
typedef hdr<int>::hdr_<5>                                   StringTable_hdr;
typedef hdr<int>::hdr_<6>                                   String_hdr;

template<ss_typename_param_k T>
T*
rounded_ptr(
    T*          p
,   ss_size_t   n
)
{
    union
    {
        T*          p;
        ss_size_t   cb;
    } u;

    u.p = p;

    u.cb = ((n - 1) + u.cb) & ~(n- 1);

    WINSTL_ASSERT(ptr_byte_diff(u.p, p) >= 0);

    return u.p;
}

template<ss_typename_param_k T>
T*
rounded_ptr(
    T*              p
,   ss_ptrdiff_t    byteOffset
,   ss_size_t       n
)
{
    // 1. This has to be done in a ridiculously long-hand fashion because Borland is a *very* stupid compiler!
#if defined(STLSOFT_COMPILER_IS_BORLAND)
    void const* pv  =   &byteOffset[(char*)p];
#else /* ? compiler */
    void const* pv  =   ptr_byte_offset(p, byteOffset);
#endif /* compiler */

    WINSTL_ASSERT(((char*)pv - (char*)p) == byteOffset);

    T*          p_  =   static_cast<T*>(pv);
    T*          r   =   rounded_ptr(p_, n);

#ifdef STLSOFT_COMPILER_IS_BORLAND
    STLSOFT_SUPPRESS_UNUSED(p);
    STLSOFT_SUPPRESS_UNUSED(byteOffset);
#endif /* compiler */

    WINSTL_ASSERT(ptr_byte_diff(r, p_) >= 0);

    return r;
}

STLSOFT_CLOSE_WORKER_NS_(ximpl_winstl_version_info_)
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

/** Exception thrown by the version_info class.
 *
 * \ingroup group__library__System
 */
class version_info_exception
    : public winstl_exception
{
public: // types
    /// The parent class type
    typedef winstl_exception                                parent_class_type;
    /// The class type
    typedef version_info_exception                          class_type;

public: // construction
    version_info_exception(char const* reason, status_code_type sc)
        : parent_class_type(reason, sc)
    {}
};
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

/** Represents the fixed part of a version information block
 *
 * \ingroup group__library__System
 */
class fixed_file_info
{
public: // types
    typedef fixed_file_info                                 class_type;
private:
public:
    typedef VS_FIXEDFILEINFO                                resource_type_;

public: // construction
    /// Conversion constructor
    ///
    /// \note This is public solely for practical reasons. It should not be
    ///   called directly from client code
    ss_explicit_k
    fixed_file_info(resource_type_ const*);
private:
    class_type& operator =(class_type const&);  // copy-assignment proscribed

public: // accessors
    ws_uint16_t ApiVerHigh() const;
    ws_uint16_t ApiVerLow() const;

    /// The major part of the file version
    ws_uint16_t FileVerMajor() const;
    /// The minor part of the file version
    ws_uint16_t FileVerMinor() const;
    /// The revision part of the file version
    ws_uint16_t FileVerRevision() const;
    /// The build increment part of the file version
    ws_uint16_t FileVerBuild() const;

    /// The major part of the product version
    ws_uint16_t ProductVerMajor() const;
    /// The minor part of the product version
    ws_uint16_t ProductVerMinor() const;
    /// The revision part of the product version
    ws_uint16_t ProductVerRevision() const;
    /// The build increment part of the product version
    ws_uint16_t ProductVerBuild() const;

    /// The file flags mask
    ws_uint32_t FileFlagsMask() const;
    /// The file flags
    ws_uint32_t FileFlags() const;

    /// The file operating system
    ws_uint32_t FileOS() const;

    /// The file type
    ws_uint32_t FileType() const;
    /// The file subtype
    ws_uint32_t FileSubtype() const;

    /// The timestamp of the file
    FILETIME const& FileDateTime() const;

private: // implementation
    static FILETIME calc_FileDateTime_(VS_FIXEDFILEINFO const* ffi);

private: // fields
    VS_FIXEDFILEINFO const* const   m_ffi;
    FILETIME const                  m_fileDateTime;
};

/** Represents a variable file part of a version information block
 *
 * \ingroup group__library__System
 */
class VsVar
{
public: // types
    /// This type
    typedef VsVar                                           class_type;

    /// Represents a language/code-page pair
    struct LangCodePage
    {
        /// The language
        ss_uint16_t language;
        /// The code-page
        ss_uint16_t codePage;
    };
private:
public:
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, Var_hdr)
                                                            resource_type_;

public: // construction
    /// Conversion constructor
    ///
    /// \note This is public solely for practical reasons. It should not be
    ///   called directly from client code
    ss_explicit_k
    VsVar(resource_type_ const*);

    /// The length of the variable
    ss_size_t   length() const;

    /// Subscript operator
    LangCodePage const& operator [](ss_size_t index) const;

private: // fields
    resource_type_ const*   m_p;
    LangCodePage const*     m_values;
};

/** Represents a string part of a version information block
 *
 * \ingroup group__library__System
 */
class VsString
{
public: // types
    /// This type
    typedef VsString                                        class_type;
private:
public:
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, String_hdr)
                                                            resource_type_;

public: // construction
    /// Conversion constructor
    ///
    /// \note This is public solely for practical reasons. It should not be
    ///   called directly from client code
    ss_explicit_k
    VsString(resource_type_ const*);

    /// The name of the variable
    wchar_t const* name() const;

    /// The value of the variable
    wchar_t const* value() const;

private: // fields
    wchar_t const*  m_name;
    wchar_t const*  m_value;
};

/** Represents a string table
 *
 * \ingroup group__library__System
 */
class VsStringTable
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
public: // types
    /// This type
    typedef VsStringTable                                   class_type;
    /// The value type
    typedef VsString                                        value_type;
private:
public:
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, StringTable_hdr)
                                                            resource_type_;

public: // construction
    /// Conversion constructor
    ///
    /// \note This is public solely for practical reasons. It should not be
    ///   called directly from client code
    ss_explicit_k
    VsStringTable(resource_type_ const*);

    /// The key
    wchar_t const* Key() const;

    /// The non-mutating (const) iterator
    class const_iterator
        : public STLSOFT_NS_QUAL(iterator_base)<
                STLSOFT_NS_QUAL_STD(forward_iterator_tag)
            ,   value_type
            ,   ws_ptrdiff_t
            ,   void        // By-Value Temporary reference
            ,   value_type  // By-Value Temporary reference
            >
    {
    public: // types
        /// This type
        typedef const_iterator                              class_type;
        /// The value type
        typedef VsString                                    value_type;

    public: // construction
        /// Conversion constructor
        ss_explicit_k
        const_iterator(void const*);

    public: // input iterator operators
        /// Pre-increment operator
        class_type& operator ++();

        /// Post-increment operator
        class_type operator ++(int);

        value_type operator *() const;

        ws_bool_t operator ==(class_type const& rhs) const;

        ws_bool_t operator !=(class_type const& rhs) const;

    private: // fields
        void const* m_p;
    };

    const_iterator begin() const;

    const_iterator end() const;

private: // fields
    resource_type_ const*   m_p;
    void const*             m_strings;
};

/** Represents a variable file info part of a version information block
 *
 * \ingroup group__library__System
 */
class VsVarFileInfo
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
public: // types
    /// This type
    typedef VsVarFileInfo                                   class_type;
    /// The value type
    typedef VsVar                                           value_type;
private:
public:
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, VarFileInfo_hdr)
                                                            resource_type_;

public: // construction
    /// Conversion constructor
    ///
    /// \note This is public solely for practical reasons. It should not be
    ///   called directly from client code
    ss_explicit_k
    VsVarFileInfo(resource_type_ const*);

    /// The Key property
    wchar_t const* Key() const;

    /// Iterator class
    class const_iterator
        : public STLSOFT_NS_QUAL(iterator_base)<
                STLSOFT_NS_QUAL_STD(forward_iterator_tag)
            ,   value_type
            ,   ws_ptrdiff_t
            ,   void        // By-Value Temporary reference
            ,   value_type  // By-Value Temporary reference
            >
    {
    public: // types
        /// This type
        typedef const_iterator                              class_type;

    public: // construction
        /// Conversion constructor
        ss_explicit_k
        const_iterator(void const*);

    public: // input iterator operators
        /// Pre-increment operator
        class_type& operator ++();

        /// Post-increment operator
        class_type operator ++(int);

        value_type operator *() const;

        ws_bool_t operator ==(class_type const& rhs) const;

        ws_bool_t operator !=(class_type const& rhs) const;

    private: // fields
        void const* m_p;
    };

    const_iterator begin() const;

    const_iterator end() const;

private: // fields
    resource_type_ const*   m_p;
    void const*             m_vars;
};

/** Represents a variable string part of a version information block
 *
 * \ingroup group__library__System
 */
class VsStringFileInfo
    : public STLSOFT_NS_QUAL(stl_collection_tag)
{
public: // types
    /// This type
    typedef VsStringFileInfo                                class_type;
    /// The value type
    typedef VsStringTable                                   value_type;
private:
public:
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, StringFileInfo_hdr)
                                                            resource_type_;

public: // construction
    /// Conversion constructor
    ///
    /// \note This is public solely for practical reasons. It should not be
    ///   called directly from client code
    ss_explicit_k
    VsStringFileInfo(resource_type_ const*);

    /// The key of the StringFileInfo block
    wchar_t const* Key() const;

    /// Non-mutating (const) iterator type for the StringFileInfo block
    ///
    /// \note The value type is \c VsStringTable
    class const_iterator
        : public STLSOFT_NS_QUAL(iterator_base)<
                STLSOFT_NS_QUAL_STD(forward_iterator_tag)
            ,   value_type
            ,   ws_ptrdiff_t
            ,   void        // By-Value Temporary reference
            ,   value_type  // By-Value Temporary reference
            >
    {
    public: // types
        /// The class type
        typedef const_iterator                              class_type;
        /// The value type
        typedef VsStringTable                               value_type;

    public: // construction
        /// Conversion constructor
        ss_explicit_k
        const_iterator(void const*);

    public: // input iterator operators
        /// Pre-increment operator
        class_type& operator ++();

        /// Post-increment operator
        class_type operator ++(int);

        value_type operator *() const;

        ws_bool_t operator ==(class_type const& rhs) const;

        ws_bool_t operator !=(class_type const& rhs) const;

    private: // fields
        void const* m_p;
    };

    const_iterator begin() const;

    const_iterator end() const;

private: // fields
    resource_type_ const*   m_p;
    void const*             m_vars;
};


/** Provides convenient access to aspects of a module's version information
 *
 * \ingroup group__library__System
 */
class version_info
{
private: // types
    typedef processheap_allocator<
        ws_byte_t
    >                                                       allocator_type;
    typedef processheap_allocator<
        ws_char_a_t
    >                                                       allocator_a_type_;
    typedef processheap_allocator<
        ws_char_w_t
    >                                                       allocator_w_type_;
public:
    /// This type
    typedef version_info                                    class_type;
    /// The size type
    typedef ws_size_t                                       size_type;
private:
    typedef std::pair<void*, size_t>                        mem_block_type_;
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, StringFileInfo_hdr)
                                                            StringFileInfo_hdr;
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, VarFileInfo_hdr)
                                                            VarFileInfo_hdr;
    typedef STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, VS_VERSIONINFO_hdr)
                                                            VS_VERSIONINFO_hdr;
private:
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        ws_char_a_t
    ,   1 + WINSTL_CONST_MAX_PATH
    ,   allocator_a_type_
    >                                                       buffer_a_t;
    typedef STLSOFT_NS_QUAL(auto_buffer)<
        ws_char_w_t
    ,   1 + WINSTL_CONST_MAX_PATH
    ,   allocator_w_type_
    >                                                       buffer_w_t;
    typedef system_traits<
        ws_char_a_t
    >                                                       sys_traits_a_t;
    typedef system_traits<
        ws_char_w_t
    >                                                       sys_traits_w_t;

public: // construction
    /// Creates an instance corresponding to the version information from the given module
    ///
    /// \param moduleName The name of the module (.exe, .dll, etc.) to load
    ss_explicit_k
    version_info(
        ws_char_a_t const* moduleName
    );

    /// Creates an instance corresponding to the version information from the given module
    ///
    /// \param moduleName The name of the module (.exe, .dll, etc.) to load
    ss_explicit_k
    version_info(
        ws_char_w_t const* moduleName
    );

    /// Releases any allocated resources
    ~version_info() STLSOFT_NOEXCEPT;
private:
    version_info(class_type const&);    // copy-construction proscribed
    void operator =(class_type const&); // copy-assignment proscribed

public: // accessors
    /// The length of the version information
    ws_size_t Length() const;

    /// The length of the value part of the version block
    ws_size_t ValueLength() const;

    /// The type field in the version block
    ws_size_t Type() const;

    /// The key of the version block
    wchar_t const* Key() const;

    /// The FixedFileInfo part of the block
    fixed_file_info FixedFileInfo() const;

    /// Indicates whether the module contains a VarFileInfo block
    ws_bool_t HasVarFileInfo() const;

    /// The VarFileInfo part of the block
    VsVarFileInfo VarFileInfo() const;

    /// Indicates whether the module contains a StringFileInfo block
    ws_bool_t HasStringFileInfo() const;

    /// The StringFileInfo part of the block
    VsStringFileInfo    StringFileInfo() const;

private: // implemementation
    static mem_block_type_ const        retrieve_module_info_block_(ws_char_a_t const* moduleName);

    static mem_block_type_ const        retrieve_module_info_block_(ws_char_w_t const* moduleName);

    static VS_VERSIONINFO_hdr const*    calc_hdr_(mem_block_type_ const& mem);

    static wchar_t const*               calc_key_(void const* pv);

    static VS_FIXEDFILEINFO const*      calc_ffi_(wchar_t const* key);

    static WORD const*                  calc_children_(VS_FIXEDFILEINFO const* ffi);

private: // implementation
    void init_();

private: // fields
    mem_block_type_ const           m_mem;
    VS_VERSIONINFO_hdr const* const m_hdr;
    wchar_t const* const            m_key;
    VS_FIXEDFILEINFO const* const   m_ffi;
    WORD const* const               m_children;
    StringFileInfo_hdr const*       m_sfi;
    VarFileInfo_hdr const*          m_vfi;
};

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

inline /* static */ FILETIME fixed_file_info::calc_FileDateTime_(VS_FIXEDFILEINFO const* ffi)
{
    FILETIME    ft = {  ffi->dwFileDateLS, ffi->dwFileDateMS };

    return ft;
}

inline fixed_file_info::fixed_file_info(VS_FIXEDFILEINFO const* ffi)
    : m_ffi(ffi)
    , m_fileDateTime(calc_FileDateTime_(ffi))
{}

inline ws_uint16_t fixed_file_info::ApiVerHigh() const
{
    return HIWORD(m_ffi->dwStrucVersion);
}

inline ws_uint16_t fixed_file_info::ApiVerLow() const
{
    return LOWORD(m_ffi->dwStrucVersion);
}

inline ws_uint16_t fixed_file_info::FileVerMajor() const
{
    return HIWORD(m_ffi->dwFileVersionMS);
}

inline ws_uint16_t fixed_file_info::FileVerMinor() const
{
    return LOWORD(m_ffi->dwFileVersionMS);
}

inline ws_uint16_t fixed_file_info::FileVerRevision() const
{
    return HIWORD(m_ffi->dwFileVersionLS);
}

inline ws_uint16_t fixed_file_info::FileVerBuild() const
{
    return LOWORD(m_ffi->dwFileVersionLS);
}

inline ws_uint16_t fixed_file_info::ProductVerMajor() const
{
    return HIWORD(m_ffi->dwProductVersionMS);
}

inline ws_uint16_t fixed_file_info::ProductVerMinor() const
{
    return LOWORD(m_ffi->dwProductVersionMS);
}

inline ws_uint16_t fixed_file_info::ProductVerRevision() const
{
    return HIWORD(m_ffi->dwProductVersionLS);
}

inline ws_uint16_t fixed_file_info::ProductVerBuild() const
{
    return LOWORD(m_ffi->dwProductVersionLS);
}

inline ws_uint32_t fixed_file_info::FileFlagsMask() const
{
    return m_ffi->dwFileFlagsMask;
}

inline ws_uint32_t fixed_file_info::FileFlags() const
{
    return m_ffi->dwFileFlags;
}

inline ws_uint32_t fixed_file_info::FileOS() const
{
    return m_ffi->dwFileOS;
}

inline ws_uint32_t fixed_file_info::FileType() const
{
    return m_ffi->dwFileType;
}

inline ws_uint32_t fixed_file_info::FileSubtype() const
{
    return m_ffi->dwFileSubtype;
}

inline FILETIME const& fixed_file_info::FileDateTime() const
{
    return m_fileDateTime;
}

inline VsVar::VsVar(resource_type_ const* p)
    : m_p(p)
{
    WINSTL_ASSERT(0 == ::wcsncmp(p->szKey, L"Translation", 12));

    m_values = sap_cast<LangCodePage const*>(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&p->szKey[1 + ::wcslen(p->szKey)], 4));
}

inline ss_size_t VsVar::length() const
{
    return m_p->wValueLength / sizeof(LangCodePage);
}

inline VsVar::LangCodePage const& VsVar::operator [](ss_size_t index) const
{
    return m_values[index];
}

inline VsString::VsString(resource_type_ const* p)
    : m_name(p->szKey)
{
    m_value =   sap_cast<wchar_t const*>(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&p->szKey[1 + ::wcslen(p->szKey)], 4));
}

inline wchar_t const* VsString::name() const
{
    return m_name;
}

inline wchar_t const* VsString::value() const
{
    return m_value;
}

inline VsStringTable::VsStringTable(resource_type_ const* p)
    : m_p(p)
{
    m_strings = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&p->szKey[1 + ::wcslen(p->szKey)], 4);
}

inline wchar_t const* VsStringTable::Key() const
{
    WINSTL_ASSERT(NULL != m_p);

    return m_p->szKey;
}

inline VsStringTable::const_iterator::const_iterator(void const* p)
    : m_p(p)
{}

inline VsStringTable::const_iterator::class_type& VsStringTable::const_iterator::operator ++()
{
    resource_type_ const* str = static_cast<resource_type_ const*>(m_p);

    m_p = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_p, str->wLength, 4);

    return *this;
}

inline VsStringTable::const_iterator::class_type VsStringTable::const_iterator::operator ++(int)
{
    const_iterator  ret(*this);

    operator ++();

    return ret;
}

inline VsString VsStringTable::const_iterator::operator *() const
{
    VsString::resource_type_ const* str = static_cast<VsString::resource_type_ const*>(m_p);

    return VsString(str);
}

inline ws_bool_t VsStringTable::const_iterator::operator ==(VsStringTable::const_iterator::class_type const& rhs) const
{
    return m_p == rhs.m_p;
}

inline ws_bool_t VsStringTable::const_iterator::operator !=(VsStringTable::const_iterator::class_type const& rhs) const
{
    return !operator ==(rhs);
}

inline VsStringTable::const_iterator VsStringTable::begin() const
{
    return const_iterator(m_strings);
}

inline VsStringTable::const_iterator VsStringTable::end() const
{
    return const_iterator(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_p, m_p->wLength, 4));
}

inline VsVarFileInfo::VsVarFileInfo(resource_type_ const* p)
    : m_p(p)
{
    WINSTL_ASSERT(0 == ::wcsncmp(p->szKey, L"VarFileInfo", 12));

    m_vars = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&p->szKey[1 + ::wcslen(p->szKey)], 4);
}

inline wchar_t const* VsVarFileInfo::Key() const
{
    WINSTL_ASSERT(NULL != m_p);

    return m_p->szKey;
}

inline VsVarFileInfo::const_iterator::const_iterator(void const* p)
    : m_p(p)
{}

inline VsVarFileInfo::const_iterator::class_type& VsVarFileInfo::const_iterator::operator ++()
{
    resource_type_ const* var = static_cast<resource_type_ const*>(m_p);

    m_p = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_p, var->wLength, 4);

    return *this;
}

inline VsVarFileInfo::const_iterator::class_type VsVarFileInfo::const_iterator::operator ++(int)
{
    const_iterator  ret(*this);

    operator ++();

    return ret;
}

inline VsVar VsVarFileInfo::const_iterator::operator *() const
{
    VsVar::resource_type_ const* var = static_cast<VsVar::resource_type_ const*>(m_p);

    return VsVar(var);
}

inline ws_bool_t VsVarFileInfo::const_iterator::operator ==(class_type const& rhs) const
{
    return m_p == rhs.m_p;
}

inline ws_bool_t VsVarFileInfo::const_iterator::operator !=(class_type const& rhs) const
{
    return !operator ==(rhs);
}

inline VsVarFileInfo::const_iterator VsVarFileInfo::begin() const
{
    return const_iterator(m_vars);
}

inline VsVarFileInfo::const_iterator VsVarFileInfo::end() const
{
    return const_iterator(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_p, m_p->wLength, 4));
}

inline VsStringFileInfo::VsStringFileInfo(resource_type_ const* p)
    : m_p(p)
{
    WINSTL_ASSERT(0 == ::wcsncmp(p->szKey, L"StringFileInfo", 15));

    m_vars = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&p->szKey[1 + ::wcslen(p->szKey)], 4);
}

inline wchar_t const* VsStringFileInfo::Key() const
{
    WINSTL_ASSERT(NULL != m_p);

    return m_p->szKey;
}

inline VsStringFileInfo::const_iterator::const_iterator(void const* p)
    : m_p(p)
{}

inline VsStringFileInfo::const_iterator::class_type& VsStringFileInfo::const_iterator::operator ++()
{
    resource_type_ const* strtbl = static_cast<resource_type_ const*>(m_p);

    m_p = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_p, strtbl->wLength, 4);

    return *this;
}

inline VsStringFileInfo::const_iterator::class_type VsStringFileInfo::const_iterator::operator ++(int)
{
    const_iterator  ret(*this);

    operator ++();

    return ret;
}

inline VsStringTable VsStringFileInfo::const_iterator::operator *() const
{
    VsStringTable::resource_type_ const* strtbl = static_cast<VsStringTable::resource_type_ const*>(m_p);

    return VsStringTable(strtbl);
}

inline ws_bool_t VsStringFileInfo::const_iterator::operator ==(class_type const& rhs) const
{
    return m_p == rhs.m_p;
}

inline ws_bool_t VsStringFileInfo::const_iterator::operator !=(class_type const& rhs) const
{
    return !operator ==(rhs);
}

inline VsStringFileInfo::const_iterator VsStringFileInfo::begin() const
{
    return const_iterator(m_vars);
}

inline VsStringFileInfo::const_iterator VsStringFileInfo::end() const
{
    return const_iterator(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_p, m_p->wLength, 4));
}

inline /* ss_explicit_k */ version_info::version_info(ws_char_a_t const* moduleName)
    : m_mem(retrieve_module_info_block_(moduleName))
    , m_hdr(calc_hdr_(m_mem))
    , m_key(calc_key_(m_hdr))
    , m_ffi(calc_ffi_(m_key))
    , m_children(calc_children_(m_ffi))
    , m_sfi(NULL)
    , m_vfi(NULL)
{
    init_();
}

inline /* ss_explicit_k */ version_info::version_info(ws_char_w_t const* moduleName)
    : m_mem(retrieve_module_info_block_(moduleName))
    , m_hdr(calc_hdr_(m_mem))
    , m_key(calc_key_(m_hdr))
    , m_ffi(calc_ffi_(m_key))
    , m_children(calc_children_(m_ffi))
    , m_sfi(NULL)
    , m_vfi(NULL)
{
    init_();
}

inline version_info::~version_info() STLSOFT_NOEXCEPT
{
    allocator_type  allocator;

#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
    allocator.deallocate(static_cast<ws_byte_t*>(m_mem.first), m_mem.second);
#else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
    allocator.deallocate(m_mem.first);
#endif /* !STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
}

inline ws_size_t version_info::Length() const
{
#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    if (NULL == m_hdr)
    {
        return 0;
    }
#else /* ? exceptions */
    WINSTL_ASSERT(NULL != m_hdr);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT || !STLSOFT_CF_THROW_BAD_ALLOC */

    return *(sap_cast<WORD const*>(m_hdr) + 0);
}

inline ws_size_t version_info::ValueLength() const
{
#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    if (NULL == m_hdr)
    {
        return 0;
    }
#else /* ? exceptions */
    WINSTL_ASSERT(NULL != m_hdr);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT || !STLSOFT_CF_THROW_BAD_ALLOC */

    return *(sap_cast<WORD const*>(m_hdr) + 1);
}

inline ws_size_t version_info::Type() const
{
    WINSTL_ASSERT(NULL != m_hdr);

    return *(sap_cast<WORD const*>(m_hdr) + 2);
}

inline wchar_t const* version_info::Key() const
{
    WINSTL_ASSERT(NULL != m_hdr);

    return m_key;
}

inline fixed_file_info version_info::FixedFileInfo() const
{
    WINSTL_ASSERT(NULL != m_hdr);

    return fixed_file_info(m_ffi);
}

inline ws_bool_t version_info::HasVarFileInfo() const
{
    return NULL != m_vfi;
}

inline VsVarFileInfo version_info::VarFileInfo() const
{
    WINSTL_ASSERT(NULL != m_vfi);

    return VsVarFileInfo(m_vfi);
}

inline ws_bool_t version_info::HasStringFileInfo() const
{
    return NULL != m_sfi;
}

inline VsStringFileInfo version_info::StringFileInfo() const
{
    WINSTL_ASSERT(NULL != m_sfi);

    return VsStringFileInfo(m_sfi);
}

inline
/* static */
version_info::mem_block_type_ const
version_info::retrieve_module_info_block_(
    ws_char_a_t const* moduleName
)
{
    buffer_a_t  buffer(1);
    bool        named = true;

    if (NULL == moduleName ||
        '\0' == moduleName[0])
    {
        size_type const cch = sys_traits_a_t::get_module_filename(NULL, buffer);

        named = false;

        if (0 == cch)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

            STLSOFT_THROW_X(version_info_exception("Could not obtain executing module path", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            return mem_block_type_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        moduleName = buffer.data();
    }

    if (named)
    {
        // Must verify it can be loaded, i.e. is a 32-bit resource
        //
        // TODO: Work out how to support 16-bit versions
        HINSTANCE hinst = WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryExA(moduleName, NULL, LOAD_LIBRARY_AS_DATAFILE);

        if (NULL == hinst)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

            STLSOFT_THROW_X(version_info_exception("Could not elicit version information from module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            return mem_block_type_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(hinst);
        }
    }

    allocator_type      allocator;
    ws_dword_t const    cb  =   ::GetFileVersionInfoSizeA(const_cast<ws_char_a_t*>(moduleName), NULL);
    void* const         pv  =   (0 == cb) ? NULL : allocator.allocate(cb);

#if !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    // If bad_alloc will not be thrown, then we need to check for NULL, but only act on it
    // if cb is non-zero
    if (0 != cb &&
        pv == NULL)
    {
        return version_info::mem_block_type_();
    }
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */

    WINSTL_ASSERT(0 == cb || pv != NULL);

    if (0 == cb ||
        !::GetFileVersionInfoA(const_cast<ws_char_a_t*>(moduleName), 0, cb, pv))
    {
        allocator.deallocate(static_cast<ws_byte_t*>(pv), cb);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        STLSOFT_THROW_X(version_info_exception("Could not elicit version information from module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        return version_info::mem_block_type_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    WINSTL_ASSERT(pv != NULL);

    return version_info::mem_block_type_(pv, cb);
}

inline
/* static */
version_info::mem_block_type_ const
version_info::retrieve_module_info_block_(
    ws_char_w_t const* moduleName
)
{
    buffer_w_t  buffer(1);
    bool        named = true;

    if (NULL == moduleName ||
        '\0' == moduleName[0])
    {
        size_type const cch = sys_traits_w_t::get_module_filename(NULL, buffer);

        named = false;

        if (0 == cch)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

            STLSOFT_THROW_X(version_info_exception("Could not obtain executing module path", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            return mem_block_type_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        moduleName = buffer.data();
    }

    if (named)
    {
        // Must verify it can be loaded, i.e. is a 32-bit resource
        //
        // TODO: Work out how to support 16-bit versions
        HINSTANCE hinst = WINSTL_API_EXTERNAL_DynamicLinkLibrary_LoadLibraryExW(moduleName, NULL, LOAD_LIBRARY_AS_DATAFILE);

        if (NULL == hinst)
        {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

            STLSOFT_THROW_X(version_info_exception("Could not elicit version information from module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError()));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

            return mem_block_type_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }
        else
        {
            WINSTL_API_EXTERNAL_DynamicLinkLibrary_FreeLibrary(hinst);
        }
    }

    allocator_type      allocator;
    ws_dword_t const    cb  =   ::GetFileVersionInfoSizeW(const_cast<ws_char_w_t*>(moduleName), NULL);
    void* const         pv  =   (0 == cb) ? NULL : allocator.allocate(cb);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if (0 != cb &&
        pv == NULL)
    {
        return version_info::mem_block_type_();
    }
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */

    if (0 == cb ||
        !::GetFileVersionInfoW(const_cast<ws_char_w_t*>(moduleName), 0, cb, pv))
    {
        allocator.deallocate(static_cast<ws_byte_t*>(pv), cb);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

        STLSOFT_THROW_X((version_info_exception("Could not elicit version information from module", WINSTL_API_EXTERNAL_ErrorHandling_GetLastError())));
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */

        return version_info::mem_block_type_();
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return version_info::mem_block_type_(pv, cb);
}

inline
/* static */
version_info::VS_VERSIONINFO_hdr const*
version_info::calc_hdr_(
    version_info::mem_block_type_ const& mem
)
{
    return static_cast<VS_VERSIONINFO_hdr const*>(mem.first);
}

inline
/* static */
wchar_t const*
version_info::calc_key_(
    void const* pv
)
{
#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    if (NULL == pv)
    {
        return NULL;
    }
#else /* ? exceptions */
    WINSTL_ASSERT(NULL != pv);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT || !STLSOFT_CF_THROW_BAD_ALLOC */

#ifdef STLSOFT_DEBUG
    // Bit of 16-bit resource code here
    //
    // This is reasonably safe, because if it is unicode, then the n-limited string comparison
    // will simply return non-0, rather than potentially going off and crashing
    {
        char const* keyA = reinterpret_cast<char const*>(static_cast<WORD const*>(pv) + 2);

        if (0 == ::strncmp("VS_VERSION_INFO", keyA, 16))
        {
            keyA = NULL;
        }
    }
#endif /* STLSOFT_DEBUG */

    wchar_t const* key = reinterpret_cast<wchar_t const*>(static_cast<WORD const*>(pv) + 3);

    WINSTL_ASSERT(0 == ::wcsncmp(L"VS_VERSION_INFO", key, 16));

    return key;
}

inline /* static */ VS_FIXEDFILEINFO const* version_info::calc_ffi_(wchar_t const* key)
{
#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    if (NULL == key)
    {
        return NULL;
    }
#else /* ? exceptions */
    WINSTL_ASSERT(NULL != key);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT || !STLSOFT_CF_THROW_BAD_ALLOC */

    return sap_cast<VS_FIXEDFILEINFO const*>(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&key[1 + ::wcslen(key)], 4));
}

inline /* static */ WORD const* version_info::calc_children_(VS_FIXEDFILEINFO const* ffi)
{
#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    if (NULL == ffi)
    {
        return NULL;
    }
#else /* ? exceptions */
    WINSTL_ASSERT(NULL != ffi);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT || !STLSOFT_CF_THROW_BAD_ALLOC */

    return sap_cast<WORD const*>(STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(&ffi[1], 4));
}

inline void version_info::init_()
{
#if !defined(STLSOFT_CF_EXCEPTION_SUPPORT) || \
    !defined(STLSOFT_CF_THROW_BAD_ALLOC)
    if (NULL == m_hdr)
    {
        return;
    }
#else /* ? exceptions */
    WINSTL_ASSERT(NULL != m_hdr);
#endif /* !STLSOFT_CF_EXCEPTION_SUPPORT || !STLSOFT_CF_THROW_BAD_ALLOC */

#ifdef STLSOFT_DEBUG
    // Check that ffi is the same as the pointer returned from VerQueryValue("\\");
    VS_FIXEDFILEINFO    *ffi    =   NULL;
    UINT                cchInfo =   0;

    WINSTL_ASSERT(::VerQueryValueA(const_cast<VS_VERSIONINFO_hdr*>(m_hdr), "\\", reinterpret_cast<void**>(&ffi), &cchInfo));
    WINSTL_ASSERT(ffi == m_ffi);
#endif /* STLSOFT_DEBUG */

    // Now we must parse the children.

    void const*         pv  =   m_children;
    void const* const   end =   STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(m_hdr, m_hdr->wLength, 4);

    WINSTL_ASSERT(ptr_byte_diff(end, pv) >= 0);

    for (; pv != end; )
    {
        union
        {
            void const*                 pv_;
            StringFileInfo_hdr const*   psfi;
            VarFileInfo_hdr const*      pvfi;
        } u;

        u.pv_ = pv;

        WINSTL_ASSERT(ptr_byte_diff(pv, m_hdr) < m_hdr->wLength);

        if (0 == ::wcsncmp(u.psfi->szKey, L"StringFileInfo", 15))
        {
            WINSTL_ASSERT(NULL == m_sfi);

            m_sfi = u.psfi;

            pv = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(pv, u.psfi->wLength, 4);
        }
        else if (0 == ::wcsncmp(u.psfi->szKey, L"VarFileInfo", 12))
        {
            WINSTL_ASSERT(NULL == m_vfi);

            m_vfi = u.pvfi;

            pv = STLSOFT_WORKER_NS_QUAL_(ximpl_winstl_version_info_, rounded_ptr)(pv, u.pvfi->wLength, 4);
        }
        else
        {
            WINSTL_MESSAGE_ASSERT("Unexpected contents of VS_VERSIONINFO children", NULL == m_vfi);

            break;
        }

        WINSTL_ASSERT(ptr_byte_diff(pv, end) <= 0);
    }

    WINSTL_ASSERT(ptr_byte_diff(pv, m_hdr) == m_hdr->wLength);

#ifdef STLSOFT_DEBUG
    fixed_file_info fixedInfo = FixedFileInfo();

    ws_uint16_t    j   =   fixedInfo.FileVerMajor();
    ws_uint16_t    n   =   fixedInfo.FileVerMinor();
    ws_uint16_t    r   =   fixedInfo.FileVerRevision();
    ws_uint16_t    b   =   fixedInfo.FileVerBuild();

    STLSOFT_SUPPRESS_UNUSED(j);
    STLSOFT_SUPPRESS_UNUSED(n);
    STLSOFT_SUPPRESS_UNUSED(r);
    STLSOFT_SUPPRESS_UNUSED(b);
#endif /* STLSOFT_DEBUG */
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

#endif /* !WINSTL_INCL_WINSTL_SYSTEM_HPP_VERSION_INFO */

/* ///////////////////////////// end of file //////////////////////////// */

