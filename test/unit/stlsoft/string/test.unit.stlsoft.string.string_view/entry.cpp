/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.string.string_view.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_string_view`.
 *
 * Created: 4th November 2008
 * Updated: 30th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#ifdef _DEBUG
# define _CRT_SECURE_NO_DEPRECATE
# define _SCL_SECURE_NO_WARNINGS
#endif

#include <stlsoft/string/string_view.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xCover header files */
#ifdef STLSOFT_USE_XCOVER
# include <xcover/xcover.h>
#endif /* STLSOFT_USE_XCOVER */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <iomanip>
#include <iterator>
#include <sstream>
#include <string>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_types_exist(void);
    static void test_type_sizes(void);
    static void test_ctor_default(void);
    static void test_ctor_copy(void);
    static void test_ctor_range_1(void);
    static void test_ctor_range_2(void);
    static void test_ctor_range_3(void);
    static void test_1_9(void);
    static void test_swap_1(void);
    static void test_swap_2(void);
    static void test_swap_3(void);
    static void test_clear(void);
    static void test_1_10(void);
    static void test_get_allocator(void);
    static void test_1_14(void);
    static void test_front(void);
    static void test_back(void);
    static void test_1_19(void);
    static void test_refresh(void);
    static void test_1_22(void);
    static void test_reverse_iterators(void);
    static void test_1_23(void);
    static void test_copy(void);
#if STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR > 3 || \
    (   STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR == 3 && \
        STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MINOR >= 4)
    static void test_substr(void);
    static void test_substr_2(void);
    static void test_substr_throw(void);
    static void test_substr_throw_2(void);
#endif /* 3.4+ */
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_compare_1(void);
    static void test_compare_2(void);
    static void test_compare_3(void);
    static void test_compare_4(void);
    static void test_1_26(void);
    static void test_at_1(void);
    static void test_at_2(void);
    static void test_at_3(void);
    static void test_at_4(void);
    static void test_1_27(void);
    static void test_index_1(void);
    static void test_index_2(void);
    static void test_1_28(void);
    static void test_string_access_shims(void);
    static void test_1_29(void);
    static void test_insertion_1(void);
    static void test_insertion_2(void);
    static void test_insertion_3(void);
    static void test_insertion_4(void);
    static void test_1_30(void);
    static void test_string_traits(void);


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.stlsoft.string.string_view", verbosity))
    {
#ifdef STLSOFT_USE_XCOVER
        xcover::init();
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_RUN_CASE(test_types_exist);
        XTESTS_RUN_CASE(test_type_sizes);
        XTESTS_RUN_CASE(test_ctor_default);
        XTESTS_RUN_CASE(test_ctor_copy);
        XTESTS_RUN_CASE(test_ctor_range_1);
        XTESTS_RUN_CASE(test_ctor_range_2);
        XTESTS_RUN_CASE(test_ctor_range_3);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
        XTESTS_RUN_CASE(test_clear);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_get_allocator);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_front);
        XTESTS_RUN_CASE(test_back);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_refresh);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_reverse_iterators);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_copy);
#if STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR > 3 || \
    (   STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR == 3 && \
        STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MINOR >= 4)
        XTESTS_RUN_CASE(test_substr);
        XTESTS_RUN_CASE(test_substr_2);
        XTESTS_RUN_CASE_THAT_THROWS(test_substr_throw, std::out_of_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_substr_throw_2, std::out_of_range);
#endif /* 3.4+ */
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_compare_1);
        XTESTS_RUN_CASE(test_compare_2);
        XTESTS_RUN_CASE(test_compare_3);
        XTESTS_RUN_CASE(test_compare_4);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_at_1);
        XTESTS_RUN_CASE(test_at_2);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_3, std::out_of_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_4, std::out_of_range);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_index_1);
        XTESTS_RUN_CASE(test_index_2);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_string_access_shims);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_insertion_1);
        XTESTS_RUN_CASE(test_insertion_2);
        XTESTS_RUN_CASE(test_insertion_3);
        XTESTS_RUN_CASE(test_insertion_4);
        XTESTS_RUN_CASE(test_1_30);
        XTESTS_RUN_CASE(test_string_traits);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft*/string_view.hpp", NULL);
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_PRINT_RESULTS();

#ifdef STLSOFT_USE_XCOVER
        xcover::uninit();
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

    struct SimpleStream
    {
        std::string     contents;

        SimpleStream&
        write(
            char const*     s
        ,   std::streamsize n
        )
        {
            contents.append(s, n);

            return *this;
        }

        std::string
        str() const
        {
            return contents;
        }
    };

    SimpleStream&
    operator <<(
        SimpleStream&       stm
    ,   char const*         s
    )
    {
        std::size_t const   len = ::strlen(s);

        stm.write(s, len);

        return stm;
    }


static void test_types_exist(void)
{
    typeid(stlsoft::basic_string_view<char>);
    typeid(stlsoft::basic_string_view<wchar_t>);
    typeid(stlsoft::string_view);
    typeid(stlsoft::wstring_view);

}

    typedef stlsoft::string_view            string_v_t;
    typedef stlsoft::wstring_view           wstring_v_t;
    typedef stlsoft::basic_string_view<
        char
    ,   stlsoft::stlsoft_char_traits_safe<char>
    >                                       string_v_null_t;


static void test_type_sizes(void)
{
    STLSOFT_STATIC_ASSERT(sizeof(stlsoft::string_view) >= 3 * sizeof(void*));
    STLSOFT_STATIC_ASSERT(sizeof(stlsoft::wstring_view) >= 3 * sizeof(void*));
}

static void test_ctor_default()
{
    {
        string_v_t  s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

    {
        string_v_null_t s(static_cast<char const*>(NULL));

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
}

static void test_ctor_copy()
{
    {
        string_v_t  s1;
        string_v_t  s2(s1);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_v_t  s1("abc");
        string_v_t  s2(s1);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_v_t  s1("abc");
        string_v_t  s2(s1, 0u, s1.size());

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_v_t  s1("abc");
        string_v_t  s2(s1, 1u, s1.size() - 1u);

        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }
}

static void test_ctor_range_1()
{
    static const char   alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    string_v_t          s1(alphabet);
    string_v_t          s2(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);
    string_v_t const    s3(s1.begin(), s1.end());
    string_v_t          s4(s3.begin(), s3.end());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s4);

    XTESTS_TEST_POINTER_EQUAL(alphabet, s1.base());
    XTESTS_TEST_POINTER_EQUAL(alphabet, s2.base());
    XTESTS_TEST_POINTER_EQUAL(alphabet, s3.base());
    XTESTS_TEST_POINTER_EQUAL(alphabet, s4.base());
}

static void test_ctor_range_2()
{
    static const char   alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    string_v_t      s1(alphabet);
    string_v_t      s2(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
}

static void test_ctor_range_3()
{
    static const char   alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    string_v_t      s1(alphabet);
    string_v_t      s2(s1, 0);
    string_v_t      s3(s1, 13);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("nopqrstuvwxyz", s3);
}

static void test_1_9()
{
}

static void test_swap_1()
{
    {
        string_v_t  s1;
        string_v_t  s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        s1.swap(s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_v_t  s1("abc");
        string_v_t  s2;

        XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        s1.swap(s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_swap_2()
{
    {
        string_v_t  s1;
        string_v_t  s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        std::swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_v_t  s1("abc");
        string_v_t  s2;

        XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        std::swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_swap_3()
{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
    using stlsoft::swap;
#endif

    {
        string_v_t  s1;
        string_v_t  s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_v_t  s1("abc");
        string_v_t  s2;

        XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(s2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s2);
    }
}

static void test_clear()
{
    {
        string_v_t  s;

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_v_t  s("abc");

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}

static void test_1_10()
{
}

static void test_get_allocator()
{
    string_v_t s;

    XTESTS_TEST(s.get_allocator() == string_v_t::allocator_type());
}

static void test_1_14()
{
}

static void test_front()
{
    {
        string_v_t s1("abc");
        string_v_t s2(s1, 2);

        XTESTS_TEST_CHARACTER_EQUAL('a', s1.front());
        XTESTS_TEST_CHARACTER_EQUAL('c', s2.front());
    }
}

static void test_back()
{
    {
        string_v_t s1("abc");
        string_v_t s2(s1, 2);

        XTESTS_TEST_CHARACTER_EQUAL('c', s1.back());
        XTESTS_TEST_CHARACTER_EQUAL('c', s2.back());
    }
}

static void test_1_19(void)
{
}

static void test_refresh(void)
{
    {
        string_v_t          s1("abcdefghijklmnopqrstuvwxyz");
        string_v_t          s2("abcdefghijklmnopqrstuvwxyz");

        char const* const   p1a =   s1.c_str();

        s1.refresh();

        char const* const   p2a =   s2.c_str();

        char const* const   p1b =   s1.c_str();

        if(p2a == p1a)
        {
            XTESTS_TEST_POINTER_NOT_EQUAL(p1a, p1b);
        }
    }
}

static void test_1_22(void)
{
}

static void test_reverse_iterators(void)
{
    {
        string_v_t s("abcd");

        string_v_t::const_reverse_iterator ri = s.rbegin();

        XTESTS_TEST(s.rend() != ri);
        XTESTS_TEST_CHARACTER_EQUAL('d', *ri);

        ++ri;
        XTESTS_TEST(s.rend() != ri);
        XTESTS_TEST_CHARACTER_EQUAL('c', *ri);

        ri++;
        XTESTS_TEST(s.rend() != ri);
        XTESTS_TEST_CHARACTER_EQUAL('b', *ri);

        ++ri;
        XTESTS_TEST(s.rend() != ri);
        XTESTS_TEST_CHARACTER_EQUAL('a', *ri);

        ++ri;
        XTESTS_TEST(s.rend() == ri);
    }
}

static void test_1_23(void)
{
}

static void test_copy(void)
{
    {
        string_v_t  s;
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        string_v_t  s("abc");
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 0);

        XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    }

    {
        string_v_t  s("abc");
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 2);

        XTESTS_TEST_INTEGER_EQUAL(1u, cch);
    }

    {
        string_v_t  s("abc");
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 3);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

}

#if STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR > 3 || \
    (   STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MAJOR == 3 && \
        STLSOFT_VER_STLSOFT_STRING_HPP_STRING_VIEW_MINOR >= 4)
static void test_substr()
{
    string_v_t const    s1("abcdefghi");
    string_v_t          s2 = s1.substr(0);
    string_v_t          s3 = s1.substr(0, s1.size());
    string_v_t          s4 = s1.substr(0, s1.size() * 2);
    string_v_t          s5 = s1.substr();

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s4);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_substr_2()
{
    string_v_t const    s1("abcdefghi");
    string_v_t          s2 = s1.substr(1);
    string_v_t          s3 = s1.substr(1, 3);
    string_v_t          s4 = s1.substr(7, 2);
    string_v_t          s5 = s1.substr(7, 50);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bcdefghi", s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bcd", s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hi", s4);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("hi", s5);
}

static void test_substr_throw()
{
    string_v_t const    s1("abcdefghi");
    string_v_t          s2 = s1.substr(s1.size() + 1);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_substr_throw_2()
{
    string_v_t const    s1("abcdefghi");
    string_v_t          s2 = s1.substr(s1.size() + 1, 1);

    XTESTS_TEST_FAIL("should not get here");
}
#endif /* 3.4+ */

static void test_1_24(void)
{
}

static void test_1_25(void)
{
}

static void test_compare_1(void)
{
    string_v_t  s1("abc");
    string_v_t  s2("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() != s2);
    XTESTS_TEST_MULTIBYTE_STRING_NOT_EQUAL(s1, s2);

    XTESTS_TEST_BOOLEAN_TRUE(s1 < s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 < s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() < s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 <= s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 <= s2.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() <= s2);
    XTESTS_TEST_BOOLEAN_TRUE(s2 > s1);
    XTESTS_TEST_BOOLEAN_TRUE(s2 > s1.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s2.c_str() > s1);
    XTESTS_TEST_BOOLEAN_TRUE(s2 >= s1);
    XTESTS_TEST_BOOLEAN_TRUE(s2 >= s1.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s2.c_str() >= s1);

    XTESTS_TEST_BOOLEAN_TRUE(s1 == s1);
    XTESTS_TEST_BOOLEAN_TRUE(s1 == s1.c_str());
    XTESTS_TEST_BOOLEAN_TRUE(s1.c_str() == s1);
}

static void test_compare_2(void)
{
    string_v_t  s1("abc");
    string_v_t  s2("def");

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2.c_str()));
//  XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 4u, s2.c_str()));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2.c_str(), s2.size()));

    string_v_t  s3("c");

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 0u, s2.substr(s2.size())));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 2u, s3));
}

static void test_compare_3(void)
{
    string_v_t  s1("def");

    XTESTS_TEST_INTEGER_LESS(0, s1.compare("ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, "ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 0u, "ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, "ghi"));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, "ghi", 2u));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 2u, "ghi", 2u));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 2u, "ghi", 0u, 2u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(0u, 2u, "abc", 0u, 2u));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(3u, 2u, "abc", 0u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "ghi", 3u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "ghi", 3u, 2u));


    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 0u, "def", 0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 0u, "def", 1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 0u, "def", 2u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 0u, "def", 3u, 0u));

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 1u, "def", 0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 1u, "def", 1u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 1u, "def", 2u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 1u, "def", 3u, 1u));

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 2u, "def", 0u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 2u, "def", 1u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 2u, "def", 2u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "def", 3u, 2u));

    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 3u, "def", 0u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 3u, "def", 1u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 3u, "def", 2u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 3u, "def", 3u, 3u));


    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(0u, 0u, "fed", 0u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 0u, "fed", 1u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(2u, 0u, "fed", 2u, 0u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 0u, "fed", 3u, 0u));

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 1u, "fed", 0u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(1u, 1u, "fed", 1u, 1u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(2u, 1u, "fed", 2u, 1u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 1u, "fed", 3u, 1u));

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 2u, "fed", 0u, 2u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(1u, 2u, "fed", 1u, 2u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(2u, 2u, "fed", 2u, 2u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 2u, "fed", 3u, 2u));

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, "fed", 0u, 3u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(1u, 3u, "fed", 1u, 3u));
    XTESTS_TEST_INTEGER_GREATER(0, s1.compare(2u, 3u, "fed", 2u, 3u));
    XTESTS_TEST_INTEGER_EQUAL(0, s1.compare(3u, 3u, "fed", 3u, 3u));
}

static void test_compare_4(void)
{
    {
        string_v_t  s1("mno");
        string_v_t  s2("mnopqr");

        XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2));
        XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2.c_str()));
        XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, s1.size(), s2));
    }
}


static void test_1_26(void)
{
}

static void test_at_1(void)
{
    string_v_t  s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
    XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
    XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
}

static void test_at_2(void)
{
    string_v_t const    s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
    XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
    XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
}

static void test_at_3(void)
{
    string_v_t  s;

    s.at(0u);
}

static void test_at_4(void)
{
    string_v_t const    s("abc");

    s.at(3u);
}


static void test_1_27(void)
{
}

static void test_index_1(void)
{
    string_v_t  s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s[0u]);
    XTESTS_TEST_CHARACTER_EQUAL('b', s[1u]);
    XTESTS_TEST_CHARACTER_EQUAL('c', s[2u]);
}

static void test_index_2(void)
{
    string_v_t const    s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s[0u]);
    XTESTS_TEST_CHARACTER_EQUAL('b', s[1u]);
    XTESTS_TEST_CHARACTER_EQUAL('c', s[2u]);
    XTESTS_TEST_CHARACTER_EQUAL('\0', s[3u]);
}


static void test_1_28(void)
{
}

static void test_string_access_shims(void)
{
    {
        string_v_t  s;

        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_a(s));
        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data_a(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_data_a(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_data(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr_a(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr_a(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr(s));
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::c_str_ptr(s));

        XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null_a(s));

        XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null(s));
    }

    {
        wstring_v_t s;

        XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len_w(s));
//      XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft::c_str_len(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data_w(s));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_data_w(s));

//      XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_data(s));
//      XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_data(s));

        XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr_w(s));
        XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr_w(s));

//      XTESTS_TEST_POINTER_NOT_EQUAL(NULL, stlsoft::c_str_ptr(s));
//      XTESTS_TEST_WIDE_STRING_EQUAL(L"", stlsoft::c_str_ptr(s));

        XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null_w(s));

//      XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft::c_str_ptr_null(s));
    }

}

static void test_1_29(void)
{
}

static void test_insertion_1(void)
{
    string_v_t  s1;
    string_v_t  s2("abc");
    string_v_t  s3("def");

    {
        std::stringstream ss;

        ss
            << std::left
            << s1
            << s2
            << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", ss.str());
    }

    {
        SimpleStream ss;

        ss
            << s1
            << s2
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", ss.str());
    }
}

static void test_insertion_2(void)
{
    string_v_t  s2("abc");
    string_v_t  s3("def");

    {
        std::stringstream ss;

        ss
            << std::setw(2)
            << std::left
            << s2
            << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", ss.str());
    }
}

static void test_insertion_3(void)
{
    string_v_t  s1;
    string_v_t  s2("abc");
    string_v_t  s3("def");

    {
        std::stringstream ss;

        ss
            << std::setfill('_')
            << std::setw(4)
            << s1
            << std::setw(4) << std::left
            << s2
            << std::setw(4) << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("____abc__def", ss.str());
    }
}


static void test_insertion_4(void)
{
    const std::size_t FIELD_WIDTH = 2000;

    string_v_t const    s1;
    string_v_t const    s2("abc");
    string_v_t const    s3("defg");

    std::stringstream   ss;

    ss
        << std::setfill('_')
        << std::setw(FIELD_WIDTH)
        << s1
        << std::setw(FIELD_WIDTH) << std::left
        << s2
        << std::setw(FIELD_WIDTH) << std::right
        << s3
        ;


#if __cplusplus >= 201402L
    std::string expected = ([&s2, &s3]() {
#else
    struct Expected
    {
        static
        std::string
        fn(
            string_v_t const&   s2
        ,   string_v_t const&   s3
        )
#endif

        {
            std::string r;

            r.append(FIELD_WIDTH, '_');

            r.append(s2.data(), s2.size());
            r.append(FIELD_WIDTH - s2.size(), '_');

            r.append(FIELD_WIDTH - s3.size(), '_');
            r.append(s3.data(), s3.size());

            return r;
        }
#if __cplusplus >= 201402L
    })();
#else
    };

    std::string const expected = Expected::fn(s2, s3);
#endif

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(
        expected
        , ss.str());
}

static void test_1_30(void)
{
}

static void test_string_traits(void)
{
    {
        string_v_t  s = stlsoft::string_traits<string_v_t>::empty_string();

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

    {
        string_v_t  s1;
        string_v_t  s2("abc");
        string_v_t  s3("def");

        string_v_t  s4 = stlsoft::string_traits<string_v_t>::construct(s1, 0u, s1.size());
        string_v_t  s5 = stlsoft::string_traits<string_v_t>::construct(s2, 0u, s2.size());
        string_v_t  s6 = stlsoft::string_traits<string_v_t>::construct(s3, 0u, s3.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s4);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s2, s5);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s3, s6);
    }

    {
        string_v_t  s1;
        string_v_t  s2("abc");

        stlsoft::string_traits<string_v_t>::assign_inplace(s1, s2.begin(), s2.end());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
