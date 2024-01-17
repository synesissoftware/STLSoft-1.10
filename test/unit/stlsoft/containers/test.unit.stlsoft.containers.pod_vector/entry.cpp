/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.pod_vector.cpp
 *
 * Purpose: Unit-tests for `stlsoft::pod_vector`.
 *
 * Created: 1st December 2008
 * Updated: 17th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/containers/pod_vector.hpp>
// #include <stlsoft/container/pod_vector.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ header files */
#include <numeric>
#include <string>

/* Standard C header files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_default_ctor(void);
    static void test_1_9(void);
    static void test_1_10(void);
    static void test_copy_ctor(void);
    static void test_copy_assign(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
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

    if(XTESTS_START_RUNNER("test.unit.stlsoft.container.pod_vector", verbosity))
    {
        XTESTS_RUN_CASE(test_default_ctor);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_copy_ctor);
        XTESTS_RUN_CASE(test_copy_assign);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
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

    typedef stlsoft::pod_vector<int>    int_vector_t;

static void test_default_ctor()
{
    int_vector_t        v;
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(cv.begin(), cv.end(), 0));
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_1_9()
{
    int_vector_t        v(10);
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(cv.begin(), cv.end(), 0));
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_1_10()
{
    int_vector_t        v(10, -1);
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(cv.begin(), cv.end(), 0));
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_copy_ctor()
{
    int_vector_t    v1(10, -1);
    int_vector_t    v2(v1);

    XTESTS_TEST_INTEGER_EQUAL(10u, v2.size());
    XTESTS_TEST_BOOLEAN_FALSE(v2.empty());
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v2.begin(), v2.end(), 0));
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v2.size(), v2.capacity());
}

static void test_copy_assign()
{
    int_vector_t    v1(10, -1);
    int_vector_t    v2;

    v2 = v1;

    XTESTS_TEST_INTEGER_EQUAL(10u, v2.size());
    XTESTS_TEST_BOOLEAN_FALSE(v2.empty());
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v2.begin(), v2.end(), 0));
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v2.size(), v2.capacity());
}

static void test_1_14()
{
    const int       ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    int_vector_t    v(ints, ints + STLSOFT_NUM_ELEMENTS(ints));

    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_1_15()
{
    int_vector_t    v(10, -1);

    v.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */

