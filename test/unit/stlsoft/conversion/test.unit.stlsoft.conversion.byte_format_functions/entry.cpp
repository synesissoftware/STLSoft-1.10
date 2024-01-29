/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.convertion.byte_format_functions.cpp
 *
 * Purpose: Unit-tests for `stlsoft::basic_simple_string`.
 *
 * Created: 12th September 2019
 * Updated: 29th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * feature control
 */

// #define STLSOFT_DEBUG
// #define STLSOFT_CONVERSION_BYTE_FORMAT_FUNCTIONS_USE_SPRINTF


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/conversion/byte_format_functions.hpp>


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

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_format_bytes_1_byte_1_grouping(void);
    static void test_format_bytes_1_byte_2_grouping(void);
    static void test_format_bytes_1_byte_4_grouping(void);
    static void test_format_bytes_1_byte_8_grouping(void);
    static void test_format_bytes_1_byte_16_grouping(void);

    static void test_format_bytes_5_byte_1_grouping(void);
    static void test_format_bytes_5_byte_2_grouping(void);
    static void test_format_bytes_5_byte_4_grouping(void);
    static void test_format_bytes_5_byte_8_grouping(void);
    static void test_format_bytes_5_byte_16_grouping(void);

    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);
    static void test_1_30(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.convertion.byte_format_functions", verbosity))
    {
#ifdef STLSOFT_USE_XCOVER
        xcover::init();
#endif /* STLSOFT_USE_XCOVER */

        XTESTS_RUN_CASE(test_format_bytes_1_byte_1_grouping);
        XTESTS_RUN_CASE(test_format_bytes_1_byte_2_grouping);
        XTESTS_RUN_CASE(test_format_bytes_1_byte_4_grouping);
        XTESTS_RUN_CASE(test_format_bytes_1_byte_8_grouping);
        XTESTS_RUN_CASE(test_format_bytes_1_byte_16_grouping);

        XTESTS_RUN_CASE(test_format_bytes_5_byte_1_grouping);
        XTESTS_RUN_CASE(test_format_bytes_5_byte_2_grouping);
        XTESTS_RUN_CASE(test_format_bytes_5_byte_4_grouping);
        XTESTS_RUN_CASE(test_format_bytes_5_byte_8_grouping);
        XTESTS_RUN_CASE(test_format_bytes_5_byte_16_grouping);

        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_1_30);

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

static void test_format_bytes_1_byte_1_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   1
                                            ,   "#"
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("01", sz, n);
}

static void test_format_bytes_1_byte_2_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   2
                                            ,   "#"
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("0001", sz, n);
}

static void test_format_bytes_1_byte_4_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   4
                                            ,   "#"
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("00000001", sz, n);
}

static void test_format_bytes_1_byte_8_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   8
                                            ,   "#"
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("0000000000000001", sz, n);
}

static void test_format_bytes_1_byte_16_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   16
                                            ,   "#"
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("00000000000000000000000000000001", sz, n);
}


static void test_format_bytes_5_byte_1_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01, 0x02, 0x03, 0x04, 0x05 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   1
                                            ,   " "
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("01 02 03 04 05", sz, n);
}

static void test_format_bytes_5_byte_2_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01, 0x02, 0x03, 0x04, 0x05 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   2
                                            ,   " "
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("0201 0403 0005", sz, n);
}

static void test_format_bytes_5_byte_4_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01, 0x02, 0x03, 0x04, 0x05 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   4
                                            ,   " "
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("04030201 00000005", sz, n);
}

static void test_format_bytes_5_byte_8_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01, 0x02, 0x03, 0x04, 0x05 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   8
                                            ,   " "
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("0000000504030201", sz, n);
}

static void test_format_bytes_5_byte_16_grouping()
{
    char                    sz[1001];
    stlsoft::byte_t const   bytes[] =   { 0x01, 0x02, 0x03, 0x04, 0x05 };
    std::size_t const       n       =   stlsoft::format_bytes(
                                                &bytes[0], sizeof(bytes)
                                            ,   &sz[0], STLSOFT_NUM_ELEMENTS(sz)
                                            ,   16
                                            ,   " "
                                            );

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N("00000000000000000000000504030201", sz, n);
}


static void test_1_21()
{
}

static void test_1_22(void)
{
}

static void test_1_23(void)
{
}

static void test_1_24(void)
{
}

static void test_1_25(void)
{
}

static void test_1_26(void)
{
}

static void test_1_27(void)
{
}

static void test_1_28(void)
{
}

static void test_1_29(void)
{
}

static void test_1_30(void)
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */

