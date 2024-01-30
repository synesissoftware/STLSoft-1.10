/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.string.string.simple_string.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_simple_string`.
 *
 * Created: 4th November 2008
 * Updated: 30th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#define USING_STLSOFT_SIMPLE_STRING

#ifdef _DEBUG
# define _CRT_SECURE_NO_DEPRECATE
# define _SCL_SECURE_NO_WARNINGS
#endif

#ifdef USING_STLSOFT_SIMPLE_STRING
# include <stlsoft/string/simple_string.hpp>
#else /* ? USING_STLSOFT_SIMPLE_STRING */
# include <stlsoft/string/string_traits.hpp>
#endif /* USING_STLSOFT_SIMPLE_STRING */

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

    static void test_ctor_default(void);
    static void test_ctor_repeat(void);
    static void test_ctor_repeat_2(void);
    static void test_ctor_repeat_3(void);
    static void test_ctor_repeat_4(void);
    static void test_ctor_copy(void);
    static void test_ctor_range_1(void);
#ifdef USING_STLSOFT_SIMPLE_STRING
    static void test_ctor_range_2(void);
#endif /* USING_STLSOFT_SIMPLE_STRING */
    static void test_concatenation_1(void);
    static void test_concatenation_2(void);
#ifndef USING_STLSOFT_SIMPLE_STRING
    static void test_concatenation_3(void);
    static void test_concatenation_4(void);
    static void test_concatenation_5(void);
#endif
    static void test_concatenation_6(void);
    static void test_append_1(void);
    static void test_append_2(void);
    static void test_append_3(void);
    static void test_1_9(void);
    static void test_swap_1(void);
    static void test_swap_2(void);
    static void test_resize(void);
    static void test_reserve(void);
#ifdef USING_STLSOFT_SIMPLE_STRING
    static void test_clear(void);
#endif /* USING_STLSOFT_SIMPLE_STRING */
#ifndef USING_STLSOFT_SIMPLE_STRING
    static void test_erase_0_param(void);
    static void test_erase_1_pos(void);
    static void test_erase_pos_and_cch(void);
#endif
    static void test_1_10(void);
#ifndef USING_STLSOFT_SIMPLE_STRING
    static void test_find_char(void);
    static void test_find_c_string(void);
    static void test_find_string(void);
    static void test_1_14(void);
    static void test_rfind_char(void);
    static void test_rfind_c_string(void);
    static void test_rfind_string(void);
    static void test_1_15(void);
    static void test_find_first_of_char(void);
    static void test_find_first_of_c_string(void);
    static void test_find_first_of_string(void);
    static void test_1_18(void);
    static void test_find_last_of_char(void);
    static void test_find_last_of_c_string(void);
    static void test_find_last_of_string(void);
    static void test_1_19(void);
    static void test_find_first_not_of_char(void);
    static void test_find_first_not_of_c_string(void);
    static void test_find_first_not_of_string(void);
    static void test_1_21(void);
    static void test_find_last_not_of_char(void);
    static void test_find_last_not_of_c_string(void);
    static void test_find_last_not_of_string(void);
#endif
    static void test_1_22(void);
#ifdef USING_STLSOFT_SIMPLE_STRING
    static void test_push_back(void);
#endif /* USING_STLSOFT_SIMPLE_STRING */
    static void test_1_23(void);
    static void test_copy(void);
    static void test_substr(void);
    static void test_substr_throw(void);
    static void test_1_24(void);
    static void test_assign_1(void);
    static void test_assign_2(void);
    static void test_assign_3(void);
#ifdef USING_STLSOFT_SIMPLE_STRING
    static void test_assign_4(void);
#endif /* USING_STLSOFT_SIMPLE_STRING */
    static void test_1_25(void);
#ifdef USING_STLSOFT_SIMPLE_STRING
    static void test_equal_1(void);
#endif /* USING_STLSOFT_SIMPLE_STRING */
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

    if (XTESTS_START_RUNNER("test.unit.stlsoft.string.simple_string", verbosity))
    {
#ifdef STLSOFT_USE_XCOVER
        xcover::init();
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_RUN_CASE(test_ctor_default);
        XTESTS_RUN_CASE(test_ctor_repeat);
        XTESTS_RUN_CASE(test_ctor_repeat_2);
        XTESTS_RUN_CASE(test_ctor_repeat_3);
        XTESTS_RUN_CASE(test_ctor_repeat_4);
        XTESTS_RUN_CASE(test_ctor_copy);
        XTESTS_RUN_CASE(test_ctor_range_1);
#ifdef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_ctor_range_2);
#endif /* USING_STLSOFT_SIMPLE_STRING */
        XTESTS_RUN_CASE(test_concatenation_1);
        XTESTS_RUN_CASE(test_concatenation_2);
#ifndef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_concatenation_3);
        XTESTS_RUN_CASE(test_concatenation_4);
        XTESTS_RUN_CASE(test_concatenation_5);
#endif
        XTESTS_RUN_CASE(test_concatenation_6);
        XTESTS_RUN_CASE(test_append_1);
        XTESTS_RUN_CASE(test_append_2);
        XTESTS_RUN_CASE_THAT_THROWS(test_append_3, std::out_of_range);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_resize);
        XTESTS_RUN_CASE(test_reserve);
#ifdef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_clear);
#endif /* USING_STLSOFT_SIMPLE_STRING */
#ifndef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_erase_0_param);
        XTESTS_RUN_CASE(test_erase_1_pos);
        XTESTS_RUN_CASE(test_erase_pos_and_cch);
#endif
        XTESTS_RUN_CASE(test_1_10);
#ifndef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_find_char);
        XTESTS_RUN_CASE(test_find_c_string);
        XTESTS_RUN_CASE(test_find_string);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_rfind_char);
        XTESTS_RUN_CASE(test_rfind_c_string);
        XTESTS_RUN_CASE(test_rfind_string);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_find_first_of_char);
        XTESTS_RUN_CASE(test_find_first_of_c_string);
        XTESTS_RUN_CASE(test_find_first_of_string);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_find_last_of_char);
        XTESTS_RUN_CASE(test_find_last_of_c_string);
        XTESTS_RUN_CASE(test_find_last_of_string);
        XTESTS_RUN_CASE(test_1_19);
        XTESTS_RUN_CASE(test_find_first_not_of_char);
        XTESTS_RUN_CASE(test_find_first_not_of_c_string);
        XTESTS_RUN_CASE(test_find_first_not_of_string);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_find_last_not_of_char);
        XTESTS_RUN_CASE(test_find_last_not_of_c_string);
        XTESTS_RUN_CASE(test_find_last_not_of_string);
#endif
        XTESTS_RUN_CASE(test_1_22);
#ifdef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_push_back);
#endif /* USING_STLSOFT_SIMPLE_STRING */
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_copy);
        XTESTS_RUN_CASE(test_substr);
        XTESTS_RUN_CASE_THAT_THROWS(test_substr_throw, std::out_of_range);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_assign_1);
        XTESTS_RUN_CASE(test_assign_2);
        XTESTS_RUN_CASE(test_assign_3);
#ifdef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_assign_4);
#endif /* USING_STLSOFT_SIMPLE_STRING */
        XTESTS_RUN_CASE(test_1_25);
#ifdef USING_STLSOFT_SIMPLE_STRING
        XTESTS_RUN_CASE(test_equal_1);
#endif /* USING_STLSOFT_SIMPLE_STRING */
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
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft*/simple_string.hpp", NULL);
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
#ifdef USING_STLSOFT_SIMPLE_STRING
    typedef stlsoft::simple_string                          string_t;
    typedef stlsoft::simple_wstring                         wstring_t;
#else /* ? USING_STLSOFT_SIMPLE_STRING */
    typedef std::string                                     string_t;
    typedef std::wstring                                    wstring_t;
#endif /* USING_STLSOFT_SIMPLE_STRING */


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


static void test_ctor_default()
{
    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

#ifdef USING_STLSOFT_SIMPLE_STRING
    {
        string_t    s(static_cast<char const*>(NULL));

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }
#endif /* USING_STLSOFT_SIMPLE_STRING */
}

static void test_ctor_repeat()
{
    string_t    s(0, '~');

    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
}

static void test_ctor_repeat_2()
{
    string_t    s(8, '~');

    XTESTS_TEST_INTEGER_EQUAL(8u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(8u, s.capacity());
#ifdef USING_STLSOFT_SIMPLE_STRING
    XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
    XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

    string_t const& cs = s;

    XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
    XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif // USING_STLSOFT_SIMPLE_STRING
}

static void test_ctor_repeat_3()
{
    string_t    s(9, '~');

    XTESTS_TEST_INTEGER_EQUAL(9u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(9u, s.capacity());
#ifdef USING_STLSOFT_SIMPLE_STRING
    XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
    XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

    string_t const& cs = s;

    XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
    XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif // USING_STLSOFT_SIMPLE_STRING
}

static void test_ctor_repeat_4()
{
    string_t    s(10, '~');

    XTESTS_TEST_INTEGER_EQUAL(10u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
#ifdef USING_STLSOFT_SIMPLE_STRING
    XTESTS_TEST_CHARACTER_EQUAL('~', s.front());
    XTESTS_TEST_CHARACTER_EQUAL('~', s.back());

    string_t const& cs = s;

    XTESTS_TEST_CHARACTER_EQUAL('~', cs.front());
    XTESTS_TEST_CHARACTER_EQUAL('~', cs.back());
#endif // USING_STLSOFT_SIMPLE_STRING
}

static void test_ctor_copy()
{
    {
        string_t    s1;
        string_t    s2(s1);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_t    s1("abc");
        string_t    s2(s1);

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_t    s1("abc");
        string_t    s2(s1, 0u, s1.size());

        XTESTS_TEST_INTEGER_EQUAL(s1.size(), s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }

    {
        string_t    s1("abc");
        string_t    s2(s1, 1u, s1.size() - 1u);

        XTESTS_TEST_INTEGER_EQUAL(2u, s2.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("bc", s2);
    }
}

static void test_ctor_range_1()
{
    static char const alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    string_t        s1(alphabet);
    string_t        s2(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);
    string_t const  s3(s1.begin(), s1.end());
    string_t        s4(s3.begin(), s3.end());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s4);
}

#ifdef USING_STLSOFT_SIMPLE_STRING
static void test_ctor_range_2()
{
    static char const alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    string_t        s1(alphabet);
    string_t        s2(&alphabet[0], &alphabet[0] + STLSOFT_NUM_ELEMENTS(alphabet) -1);
    string_t const  s3(s1.rbegin(), s1.rend());
    string_t        s4(s3.rbegin(), s3.rend());

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s1);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s2);
//  XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(alphabet, s4);
}
#endif /* USING_STLSOFT_SIMPLE_STRING */

static void test_concatenation_1()
{
    string_t    s1("abcdefghijklmnopqrstuvwxyz");
    string_t    s2(s1, 0, 10);
    string_t    s3(s1, 10, 10);
    string_t    s4(s1, 20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_concatenation_2()
{
    string_t    s1("abcdefghijklmnopqrstuvwxyz");
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1.substr(10, 10);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

#ifndef USING_STLSOFT_SIMPLE_STRING
static void test_concatenation_3()
{
    string_t    s1("abcdefghijklmnopqrstuvwxyz");
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1;
                s3.erase(0, 10);
                s3.erase(10);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_concatenation_4()
{
    string_t    s1("abcdefghijklmnopqrstuvwxyz");
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1;
                s3.erase(s3.begin(), s3.begin() + 10);
                s3.erase(s3.begin() + 10, s3.end() - 1);
                s3.erase(s3.end() - 1);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3 + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_concatenation_5()
{
    string_t    s1("abcdefghijklmnopqrstuvwxyz");
    string_t    s2 = s1.substr(0, 10);
    string_t    s3 = s1;
                s3.erase(s3.begin(), s3.begin() + 10);
                s3.erase(s3.begin() + 10, s3.end() - 1);
                s3.erase(s3.end() - 1);
    string_t    s4 = s1.substr(20, 6);
    string_t    s5 = s2 + s3.c_str() + s4;

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}
#endif

static void test_concatenation_6()
{
    string_t    s;

    XTESTS_TEST_BOOLEAN_TRUE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

    s += 'a';

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

    s = s + 'b';

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", s);

    s = 'c' + s;

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("cab", s);

    s = "" + s;

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("cab", s);
}

static void test_append_1(void)
{
    string_t        s1;
    string_t const  s2("abc");

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s1, 0, 0);

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s2, 3u, 0u);

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s2, 0, 3);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

#ifdef USING_STLSOFT_SIMPLE_STRING
    s1.clear();
#else /* ? USING_STLSOFT_SIMPLE_STRING */
    s1.erase(s1.begin(), s1.end());
#endif /* USING_STLSOFT_SIMPLE_STRING */
    s1.append(s2, 2, 3);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("c", s1);

#ifdef USING_STLSOFT_SIMPLE_STRING
    s1.clear();
#else /* ? USING_STLSOFT_SIMPLE_STRING */
    s1.erase(s1.begin(), s1.end());
#endif /* USING_STLSOFT_SIMPLE_STRING */
    s1.append(s2.begin(), s2.end());

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

    std::stringstream   ss("abc");

#ifdef USING_STLSOFT_SIMPLE_STRING
    s1.clear();
    s1.append(std::istream_iterator<char>(ss), std::istream_iterator<char>());

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
#endif /* USING_STLSOFT_SIMPLE_STRING */
}

static void test_append_2(void)
{
    string_t    s1;
    char const  s2[] = "abc";

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s1, 0u, 0);

    XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s1);

    s1.append(s2, 3);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);

    s1.append(s2, 0u);

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
}

static void test_append_3(void)
{
    string_t    s1;

    s1.append(s1, 1u, 0);

    XTESTS_TEST_FAIL("should not get here!");
}

static void test_1_9()
{
}

static void test_swap_1()
{
    {
        string_t    s1;
        string_t    s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        s1.swap(s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_t    s1("abc");
        string_t    s2;

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
        string_t    s1;
        string_t    s2;

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());

        std::swap(s1, s2);

        XTESTS_TEST_BOOLEAN_TRUE(s1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(s2.empty());
    }

    {
        string_t    s1("abc");
        string_t    s2;

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

static void test_resize()
{
    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());

        s.resize(0u);

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());

        s.resize(3u, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~", s);
    }

    {
        string_t    s("abcdef");

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(6u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", s);

        s.resize(3u, '~');

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }
}

static void test_reserve()
{
    {
        string_t    s;

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());

        s.reserve(10u);

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
    }

    {
        string_t    s("abc");

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(10u);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.reserve(1000u);

        XTESTS_TEST_BOOLEAN_FALSE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1000u, s.capacity());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
    }
}

#ifdef USING_STLSOFT_SIMPLE_STRING
static void test_clear()
{
    {
        string_t    s;

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.clear();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}
#endif /* USING_STLSOFT_SIMPLE_STRING */

#ifndef USING_STLSOFT_SIMPLE_STRING
static void test_erase_0_param()
{
    {
        string_t    s;

        s.erase();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.erase();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}

static void test_erase_1_pos()
{
    {
        string_t    s;

        s.erase(size_t(0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.erase(size_t(0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}

static void test_erase_pos_and_cch()
{
    {
        string_t    s;

        s.erase(0u, 10u);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }

    {
        string_t    s("abc");

        s.erase(0u, 10u);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    }
}
#endif

static void test_1_10()
{
}

#ifndef USING_STLSOFT_SIMPLE_STRING
static void test_find_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0'));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find('a'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('A'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find('\0', 1u));
    }
}

static void test_find_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 6u));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 6u));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.find("", 6u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 7u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("", 8u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find("abc"));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find("bcd", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find("bcd", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("bdc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("bdc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("A"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("a", 1u));
    }
}

static void test_find_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find("abc", 4u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find(string_t("bcd"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("bdc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("bdc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find(string_t("a"), 1u));
    }
}

static void test_1_14()
{
}

static void test_rfind_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0'));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 5u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 6u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind('a', 100u));

        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 5u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 6u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind('b', 100u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.rfind('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('A'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind('\0', 1u));
    }
}

static void test_rfind_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("", 0u));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("", 0u));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 7u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 6u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 5u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.rfind(""));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.rfind("", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("", 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.rfind("", 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.rfind("", 5u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.rfind("", 6u));
        XTESTS_TEST_INTEGER_EQUAL(6u, s.rfind("", 7u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("bcd", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 5u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 6u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 7u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind("bcd", 100u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("bdc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("bdc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.rfind("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind("A"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("a", 1u));
    }
}

static void test_rfind_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind("abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 5u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 6u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.rfind("abc", 100u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("bcd"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 20u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.rfind(string_t("bcd"), 100u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("bdc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("bdc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.rfind(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.rfind(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("a")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("a"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.rfind(string_t("a"), 1u));
    }
}

static void test_1_15()
{
}

static void test_find_first_of_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0'));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('A'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of('\0', 1u));
    }
}

static void test_find_first_of_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("abc"));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("abc"));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("defghijklmnopqrstuvwxyz", 4u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_of("abc"));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of("bcd", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of("dcb", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of("bcd", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("BDC", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("aBDC", 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_of("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("A"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of("a", 1u));
    }
}

static void test_find_first_of_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of(string_t("bcd"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_of(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_of(string_t("a"), 1u));
    }
}

static void test_1_18()
{
}

static void test_find_last_of_char()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0'));
    }

    {
        string_t    s("a");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('\0', 1u));
    }

    {
        string_t    s("ab");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('b', 0u));
    }

    {
        string_t    s("abab");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('b', 0u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a', 51u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a', 27u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_of('a', 26u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 25u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 51u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 50u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 28u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_of('b', 27u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 26u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('b', 0u));

        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_of('z', 51u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of('z', 50u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of('z', 26u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of('z', 25u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 24u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 10u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of('z', 0u));
    }
}

static void test_find_last_of_c_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("abc"));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("abc"));
    }

    {
        string_t    s("abc");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc"));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("defghijklmnopqrstuvwxyz", 4u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("abc", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("abc", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("abc", 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("bca", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("bca", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("bca", 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("cab", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("cab", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("cab", 20u));

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("dcb", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("dcb", 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of("dcb", 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb", 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb", 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of("dcb", 20u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("BDC"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("BDC", 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC", 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("aBDC", 20u));

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("AbDC"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("AbDC", 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("AbDC", 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of("AbDC", 20u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a"));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a", 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a", 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of("a", 20u));

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of("z"));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 20u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("z", 24u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of("z", 25u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of("A"));
    }
}

static void test_find_last_of_string()
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("abc"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("bca"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("bca"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("bca"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("cab"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("cab"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("cab"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("dcb"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_of(string_t("dcb"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_of(string_t("dcb"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("BDC"), 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("aBDC"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("AbDC")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("AbDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("AbDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_of(string_t("AbDC"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_of(string_t("a"), 20u));

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 20u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_of(string_t("z"), 25u));

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_of(string_t("A")));
    }
}


static void test_1_19(void)
{
}

static void test_find_first_not_of_char(void)
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a'));
    }

    {
        string_t    s("a");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 2u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 2u));
    }

    {
        string_t    s("ab");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));
    }

    {
        string_t    s("abab");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_first_not_of('a', 51u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_first_not_of('a', 27u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_first_not_of('a', 26u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_first_not_of('a', 25u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_first_not_of('b', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_first_not_of('b', 50u));
        XTESTS_TEST_INTEGER_EQUAL(28u, s.find_first_not_of('b', 28u));
        XTESTS_TEST_INTEGER_EQUAL(28u, s.find_first_not_of('b', 27u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_first_not_of('b', 26u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_first_not_of('b', 10u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('b', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of('z', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_first_not_of('z', 50u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_first_not_of('z', 26u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_first_not_of('z', 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_first_not_of('z', 24u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_first_not_of('z', 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of('z', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of('z', 0u));
    }
}

static void test_find_first_not_of_c_string(void)
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc")));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_first_not_of(("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_first_not_of(("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(("a"), 1u));
    }
}

static void test_find_first_not_of_string(void)
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_first_not_of(string_t("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(string_t("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_first_not_of(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_first_not_of(string_t("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_first_not_of(string_t("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_first_not_of(string_t("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_first_not_of(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_first_not_of(string_t("a"), 1u));
    }
}

static void test_1_21(void)
{
}

static void test_find_last_not_of_char(void)
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a'));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a'));
    }

    {
        string_t    s("a");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 2u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 2u));
    }

    {
        string_t    s("ab");

        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));
    }

    {
        string_t    s("abab");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of('a', 4u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of('a', 3u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 2u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 4u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 3u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('a'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('a', 51u));
        XTESTS_TEST_INTEGER_EQUAL(27u, s.find_last_not_of('a', 27u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of('a', 26u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of('a', 25u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('a', 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of('a', 0u));

        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('b'));
        XTESTS_TEST_INTEGER_EQUAL(51u, s.find_last_not_of('b', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('b', 50u));
        XTESTS_TEST_INTEGER_EQUAL(28u, s.find_last_not_of('b', 28u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_not_of('b', 27u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_not_of('b', 26u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_last_not_of('b', 10u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of('b', 2u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('b', 0u));

        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('z'));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('z', 51u));
        XTESTS_TEST_INTEGER_EQUAL(50u, s.find_last_not_of('z', 50u));
        XTESTS_TEST_INTEGER_EQUAL(26u, s.find_last_not_of('z', 26u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of('z', 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of('z', 24u));
        XTESTS_TEST_INTEGER_EQUAL(10u, s.find_last_not_of('z', 10u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of('z', 1u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of('z', 0u));
    }
}

static void test_find_last_not_of_c_string(void)
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(("abc")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(("z")));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_last_not_of(("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(("a"), 1u));
    }
}

static void test_find_last_not_of_string(void)
{
    {
        string_t    s;

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc")));
    }

    {
        string_t    s("");

        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc")));
    }

    {
        string_t    s("xyz");

        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(string_t("abc")));
    }

    {
        string_t    s("abcabc");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(2u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 5u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 6u));
        XTESTS_TEST_INTEGER_EQUAL(5u, s.find_last_not_of(string_t("defghijklmnopqrstuvwxyz"), 7u));
    }

    {
        string_t    s("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(string_t("abc")));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(~string_t::size_type(0u), s.find_last_not_of(string_t("abc"), 2u));
        XTESTS_TEST_INTEGER_EQUAL(3u, s.find_last_not_of(string_t("abc"), 3u));
        XTESTS_TEST_INTEGER_EQUAL(4u, s.find_last_not_of(string_t("abc"), 4u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("dcb"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("bcd"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(string_t("BDC")));
        XTESTS_TEST_INTEGER_EQUAL(0u, s.find_last_not_of(string_t("BDC"), 0u));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(string_t("aBDC"), 1u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(string_t("z")));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(string_t("z"), 25u));
        XTESTS_TEST_INTEGER_EQUAL(24u, s.find_last_not_of(string_t("z"), 24u));
        XTESTS_TEST_INTEGER_EQUAL(23u, s.find_last_not_of(string_t("z"), 23u));
        XTESTS_TEST_INTEGER_EQUAL(25u, s.find_last_not_of(string_t("A")));
        XTESTS_TEST_INTEGER_EQUAL(1u, s.find_last_not_of(string_t("a"), 1u));
    }
}
#endif


static void test_1_22(void)
{
}

#ifdef USING_STLSOFT_SIMPLE_STRING
static void test_push_back(void)
{
    string_t    s;

    XTESTS_TEST_BOOLEAN_TRUE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

    s.push_back('a');

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(1u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

    s.push_back('b');

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(2u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ab", s);

    s.push_back('c');

    XTESTS_TEST_BOOLEAN_FALSE(s.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
}
#endif /* USING_STLSOFT_SIMPLE_STRING */

static void test_1_23(void)
{
}

static void test_copy(void)
{
    {
        string_t    s;
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        string_t    s("abc");
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 0);

        XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    }

    {
        string_t    s("abc");
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 2);

        XTESTS_TEST_INTEGER_EQUAL(1u, cch);
    }

    {
        string_t    s("abc");
        char        buff[101];
        size_t      cch = s.copy(&buff[0], STLSOFT_NUM_ELEMENTS(buff), 3);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

}

static void test_substr()
{
    string_t const  s1("abcdefghi");
    string_t        s2 = s1.substr(0);
    string_t        s3 = s1.substr(0, s1.size());
    string_t        s4 = s1.substr(0, s1.size() * 2);
    string_t        s5 = s1.substr();

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s3);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s4);
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s5);
}

static void test_substr_throw()
{
    string_t const  s1("abcdefghi");
    string_t        s2 = s1.substr(s1.size() + 1);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_1_24(void)
{
}

static void test_assign_1(void)
{
    {
        string_t    s;

        s.assign("");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s = "";

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s = 'a';

        XTESTS_TEST_INTEGER_EQUAL(1u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("a", s);

        s = string_t();

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign("abc");

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign("abcdefghijklmnopqrstuvwxyz");

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign("");

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }
}

static void test_assign_2(void)
{
    {
        string_t    s;

        s.assign("", 0u);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign("abc", 3);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign("abcdefghijklmnopqrstuvwxyz", 26);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign("abcdefghijklmnopqrstuvwxyz", 3);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign("", 0u);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }
}

static void test_assign_3(void)
{
    string_t const alphabet("abcdefghijklmnopqrstuvwxyz");

    {
        string_t    s;

        s.assign(s, 0, 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

        s.assign(alphabet, 0, 3);

        XTESTS_TEST_INTEGER_EQUAL(3u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

        s.assign(alphabet, 0, 26);

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(alphabet.begin(), alphabet.end());

        XTESTS_TEST_INTEGER_EQUAL(26u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", s);

        s.assign(alphabet, 25, 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);
    }
}

#ifdef USING_STLSOFT_SIMPLE_STRING
static void test_assign_4(void)
{
    std::stringstream   ss("abc");

    string_t    s1 = string_t(std::istream_iterator<char>(ss), std::istream_iterator<char>());

    XTESTS_TEST_BOOLEAN_FALSE(s1.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, s1.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(3u, s1.capacity());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s1);
}
#endif /* USING_STLSOFT_SIMPLE_STRING */

static void test_1_25(void)
{
}

#ifdef USING_STLSOFT_SIMPLE_STRING
static void test_equal_1(void)
{
    string_t    s1("abc");
    string_t    s2("def");
    string_t    s3("abc");
    string_t    s4("def");

    XTESTS_TEST_BOOLEAN_TRUE(s1 == s1);
    XTESTS_TEST_BOOLEAN_FALSE(s1 != s1);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s2);
    XTESTS_TEST_BOOLEAN_FALSE(s1 == s2);
    XTESTS_TEST_BOOLEAN_TRUE(s1 == s3);
    XTESTS_TEST_BOOLEAN_FALSE(s1 != s3);
    XTESTS_TEST_BOOLEAN_TRUE(s1 != s4);
    XTESTS_TEST_BOOLEAN_FALSE(s1 == s4);
}
#endif /* USING_STLSOFT_SIMPLE_STRING */


static void test_compare_1(void)
{
    string_t    s1("abc");
    string_t    s2("def");

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
    string_t    s1("abc");
    string_t    s2("def");

    XTESTS_TEST_INTEGER_LESS(0, s1.compare(s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2.c_str()));
//  XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 4u, s2.c_str()));
    XTESTS_TEST_INTEGER_LESS(0, s1.compare(0u, 3u, s2.c_str(), s2.size()));
}

static void test_compare_3(void)
{
    string_t    s1("def");

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
        string_t    s1("mno");
        string_t    s2("mnopqr");

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
    string_t    s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
    XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
    XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
}

static void test_at_2(void)
{
    string_t const s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s.at(0u));
    XTESTS_TEST_CHARACTER_EQUAL('b', s.at(1u));
    XTESTS_TEST_CHARACTER_EQUAL('c', s.at(2u));
}

static void test_at_3(void)
{
    string_t    s;

    s.at(0u);
}

static void test_at_4(void)
{
    string_t const s("abc");

    s.at(3u);
}


static void test_1_27(void)
{
}

static void test_index_1(void)
{
    string_t    s("abc");

    XTESTS_TEST_CHARACTER_EQUAL('a', s[0u]);
    XTESTS_TEST_CHARACTER_EQUAL('b', s[1u]);
    XTESTS_TEST_CHARACTER_EQUAL('c', s[2u]);
}

static void test_index_2(void)
{
    string_t const s("abc");

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
        string_t    s;

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
        wstring_t   s;

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
    string_t const  s1;
    string_t const  s2("abc");
    string_t const  s3("def");

    {
        std::stringstream   ss;

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
        SimpleStream    ss;

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
    string_t const  s2("abc");
    string_t const  s3("def");

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
    string_t const  s1;
    string_t const  s2("abc");
    string_t const  s3("def");

    {
        std::stringstream ss;

        ss
            << std::setw(4)
            << std::setfill('_')
            << s1
            << std::left
            << s2
            << std::right
            << s3
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("____abc__def", ss.str());
    }
}


static void test_insertion_4(void)
{
    const std::size_t FIELD_WIDTH = 2000;

    string_t const  s1;
    string_t const  s2("abc");
    string_t const  s3("defg");

    std::stringstream   ss;

    ss
        << std::setw(FIELD_WIDTH)
        << std::setfill('_')
        << s1
        << std::left
        << s2
        << std::right
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
            string_t const& s2
        ,   string_t const& s3
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
        string_t    s = stlsoft::string_traits<string_t>::empty_string();

        XTESTS_TEST_BOOLEAN_TRUE(s.empty());
        XTESTS_TEST_INTEGER_EQUAL(0u, s.size());
        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, s.capacity());
        XTESTS_TEST_INTEGER_NOT_EQUAL(0u, s.max_size());
    }

    {
        string_t    s1;
        string_t    s2("abc");
        string_t    s3("def");

        string_t    s4 = stlsoft::string_traits<string_t>::construct(s1, 0u, s1.size());
        string_t    s5 = stlsoft::string_traits<string_t>::construct(s2, 0u, s2.size());
        string_t    s6 = stlsoft::string_traits<string_t>::construct(s3, 0u, s3.size());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s4);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s2, s5);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s3, s6);
    }

    {
        string_t    s1;
        string_t    s2("abc");

        stlsoft::string_traits<string_t>::assign_inplace(s1, s2.begin(), s2.end());

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s1, s2);
    }
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */

