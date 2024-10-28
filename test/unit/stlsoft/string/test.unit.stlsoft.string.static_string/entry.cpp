/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.string.static_string.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_static_string`.
 *
 * Created: 4th November 2008
 * Updated: 17th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/string/static_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
    static void test_1_5(void);
    static void test_1_6(void);
    static void test_1_7(void);
    static void test_1_8(void);
    static void test_1_9(void);
    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_12(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_copy(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.string.static_string", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_copy);
        XTESTS_RUN_CASE(test_1_19);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void test_1_0()
{
    typedef stlsoft::basic_static_string<char, 10>  string_t;

    string_t    s;

    XTESTS_TEST_PASSED();
}

static void test_1_1()
{
    typedef stlsoft::basic_static_string<char, 10>  string_t;

    string_t    s(0, '~');

    XTESTS_TEST_PASSED();
}

static void test_1_2()
{
    typedef stlsoft::basic_static_string<char, 10>  string_t;

    string_t    s(8, '~');

    XTESTS_TEST_PASSED();
}

static void test_1_3()
{
    typedef stlsoft::basic_static_string<char, 10>  string_t;

    string_t    s(9, '~');

    XTESTS_TEST_PASSED();
}

static void test_1_4()
{
    typedef stlsoft::basic_static_string<char, 10>  string_t;

    string_t    s(10, '~');

    XTESTS_TEST_PASSED();
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_copy()
{
    typedef stlsoft::basic_static_string<char, 26> string_t;

    string_t const alphabet("abcdefghijklmnopqrstuvwxyz");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", alphabet);

    {
        char dest[26 + 1] = { 0 };

        size_t n = alphabet.copy(&dest[0], 26);
        dest[26] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(26, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", dest);
    }

    {
        char dest[20 + 1] = { 0 };

        size_t n = alphabet.copy(&dest[0], 20);
        dest[20] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(20, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdefghijklmnopqrst", dest);
    }

    {
        char dest[20 + 1] = { 0 };

        size_t n = alphabet.copy(&dest[0], 20, 6);
        dest[20] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(20, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghijklmnopqrstuvwxyz", dest);
    }

    {
        char dest[10 + 1] = { 0 };

        size_t n = alphabet.copy(&dest[0], 20, 16);
        dest[10] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(10, n);
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("qrstuvwxyz", dest);
    }
}

static void test_1_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */

