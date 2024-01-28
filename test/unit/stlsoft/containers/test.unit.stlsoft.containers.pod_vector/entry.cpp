/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.pod_vector.cpp
 *
 * Purpose: Unit-tests for `stlsoft::pod_vector`.
 *
 * Created: 1st December 2008
 * Updated: 28th January 2024
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
#include <stdexcept>
#include <string>
#include <vector> // for `std::begin()`, `std::end()`

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_default_ctor(void);
    static void test_ctor_size(void);
    static void test_ctor_size_and_value(void);
    static void test_ctor_begin_end(void);
    static void test_copy_ctor(void);
    static void test_copy_assign(void);

    static void test_assign(void);
    static void test_at_1(void);
    static void test_at_2(void);
    static void test_clear(void);
    static void test_erase(void);
    static void test_front_and_back(void);
    static void test_insert(void);
    static void test_pop_back(void);
    static void test_push_back(void);
    static void test_reserve(void);
    static void test_resize(void);
    static void test_subscript_operator(void);
    static void test_swap(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.container.pod_vector", verbosity))
    {
        XTESTS_RUN_CASE(test_default_ctor);
        XTESTS_RUN_CASE(test_ctor_size);
        XTESTS_RUN_CASE(test_ctor_size_and_value);
        XTESTS_RUN_CASE(test_ctor_begin_end);
        XTESTS_RUN_CASE(test_copy_ctor);
        XTESTS_RUN_CASE(test_copy_assign);

        XTESTS_RUN_CASE(test_assign);
        XTESTS_RUN_CASE(test_at_1);
        XTESTS_RUN_CASE_THAT_THROWS(test_at_2, std::out_of_range);
        XTESTS_RUN_CASE(test_clear);
        XTESTS_RUN_CASE(test_erase);
        XTESTS_RUN_CASE(test_front_and_back);
        XTESTS_RUN_CASE(test_insert);
        XTESTS_RUN_CASE(test_pop_back);
        XTESTS_RUN_CASE(test_push_back);
        XTESTS_RUN_CASE(test_reserve);
        XTESTS_RUN_CASE(test_resize);
        XTESTS_RUN_CASE(test_subscript_operator);
        XTESTS_RUN_CASE(test_swap);

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
#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.rbegin(), v.rend(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(cv.rbegin(), cv.rend(), 0));
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_ctor_size()
{
    int_vector_t        v(10);
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(cv.begin(), cv.end(), 0));
#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.rbegin(), v.rend(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(cv.rbegin(), cv.rend(), 0));
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_ctor_size_and_value()
{
    int_vector_t        v(10, -1);
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(cv.begin(), cv.end(), 0));
#ifdef STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v.rbegin(), v.rend(), 0));
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(cv.rbegin(), cv.rend(), 0));
#endif /* STLSOFT_LF_BIDIRECTIONAL_ITERATOR_SUPPORT */
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_ctor_begin_end()
{
    int const           ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    int_vector_t const  v(ints, ints + STLSOFT_NUM_ELEMENTS(ints));

    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
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

static void test_assign()
{
    int const ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };

    int_vector_t v;

    v.assign(0, -1);

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));

    v.assign(7, -1);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(7u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(-7, std::accumulate(v.begin(), v.end(), 0));

    v.assign(std::begin(ints), std::end(ints));

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(5, std::accumulate(v.begin(), v.end(), 0));
}

static void test_at_1()
{
    int const           ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    int_vector_t        v(ints, ints + STLSOFT_NUM_ELEMENTS(ints));
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());

    XTESTS_TEST_INTEGER_EQUAL(-4, v.at(0));
    XTESTS_TEST_INTEGER_EQUAL(-2, v.at(2));
    XTESTS_TEST_INTEGER_EQUAL( 0, v.at(4));
    XTESTS_TEST_INTEGER_EQUAL(+2, v.at(6));
    XTESTS_TEST_INTEGER_EQUAL(+4, v.at(8));

    XTESTS_TEST_INTEGER_EQUAL(-4, cv.at(0));
    XTESTS_TEST_INTEGER_EQUAL(-2, cv.at(2));
    XTESTS_TEST_INTEGER_EQUAL( 0, cv.at(4));
    XTESTS_TEST_INTEGER_EQUAL(+2, cv.at(6));
    XTESTS_TEST_INTEGER_EQUAL(+4, cv.at(8));
}

static void test_at_2()
{
    int const           ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    int_vector_t const  v(ints, ints + STLSOFT_NUM_ELEMENTS(ints));

    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());

    v.at(9);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_clear()
{
    int_vector_t v(10, -1);

    v.clear();

    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(v.size(), v.capacity());
}

static void test_erase()
{
    int const ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };


    // { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 }

    int_vector_t v(std::begin(ints), std::end(ints));

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(5, std::accumulate(v.begin(), v.end(), 0));


    // { -4, -3, -2, -1, 0, 1, 2, 3, 5 }

    v.erase(v.begin() + 8);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(+1, std::accumulate(v.begin(), v.end(), 0));


    // { -4, 0, 1, 2, 3, 5 }

    v.erase(v.begin() + 1, v.begin() + 4);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(6u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(+7, std::accumulate(v.begin(), v.end(), 0));


    // { -4, 0, 1, 2, 3, 5 }

    v.erase(v.end(), v.end());

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(6u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(+7, std::accumulate(v.begin(), v.end(), 0));


    // { -4, 0, 1, 2, 3 }

    v.erase(v.begin() + 5, v.end());

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(5u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(+2, std::accumulate(v.begin(), v.end(), 0));


    // { 1, 2, 3 }

    v.erase(v.begin(), v.begin() + 2);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(3u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(+6, std::accumulate(v.begin(), v.end(), 0));


    // { }

    v.erase(v.begin(), v.end());

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
}

static void test_front_and_back()
{
    int const           ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    int_vector_t        v(ints, ints + STLSOFT_NUM_ELEMENTS(ints));
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());

    XTESTS_TEST_INTEGER_EQUAL(-4, v.front());
    XTESTS_TEST_INTEGER_EQUAL(+4, v.back());

    XTESTS_TEST_INTEGER_EQUAL(-4, cv.front());
    XTESTS_TEST_INTEGER_EQUAL(+4, cv.back());
}

static void test_insert()
{
    int const ints_neg8_to_neg5[] = { -8, -7, -6, -5 };
    int const ints_neg3_to_neg1[] = { -3, -2, -1 };


    // { }

    int_vector_t    v;

    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));


    // { 1 }

    v.insert(v.end(), 1);

    XTESTS_TEST_INTEGER_EQUAL(1u, v.size());
    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(1, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(1, v[0]);


    // { 1, 2 }

    v.insert(v.end(), 2);

    XTESTS_TEST_INTEGER_EQUAL(2u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(3, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(1, v[0]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[1]);


    // { 0, 1, 2 }

    v.insert(v.begin(), 0);

    XTESTS_TEST_INTEGER_EQUAL(3u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(3, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, v[0]);
    XTESTS_TEST_INTEGER_EQUAL(1, v[1]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[2]);


    // { -8, -7, -6, -5, 0, 1, 2 }

    v.insert(v.begin(), std::begin(ints_neg8_to_neg5), std::end(ints_neg8_to_neg5));

    XTESTS_TEST_INTEGER_EQUAL(7u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(-23, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, v[4]);
    XTESTS_TEST_INTEGER_EQUAL(1, v[5]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[6]);


    // { -8, -7, -6, -5, -4, 0, 1, 2 }

    v.insert(v.begin() + 4, -4);

    XTESTS_TEST_INTEGER_EQUAL(8u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(-27, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, v[5]);
    XTESTS_TEST_INTEGER_EQUAL(1, v[6]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[7]);


    // { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2 }

    v.insert(v.begin() + 5, std::begin(ints_neg3_to_neg1), std::end(ints_neg3_to_neg1));

    XTESTS_TEST_INTEGER_EQUAL(11u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(-33, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, v[8]);
    XTESTS_TEST_INTEGER_EQUAL(1, v[9]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[10]);


    // { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 4 }

    v.insert(v.begin() + 11, 1, 4);

    XTESTS_TEST_INTEGER_EQUAL(12u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(-29, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, v[8]);
    XTESTS_TEST_INTEGER_EQUAL(1, v[9]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[10]);


    // { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 3, 3, 4 }

    v.insert(v.begin() + 11, 4, 3);

    XTESTS_TEST_INTEGER_EQUAL(16u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(-17, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(0, v[8]);
    XTESTS_TEST_INTEGER_EQUAL(1, v[9]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[10]);
    XTESTS_TEST_INTEGER_EQUAL(3, v[11]);
    XTESTS_TEST_INTEGER_EQUAL(3, v[12]);
    XTESTS_TEST_INTEGER_EQUAL(3, v[13]);
    XTESTS_TEST_INTEGER_EQUAL(3, v[14]);
    XTESTS_TEST_INTEGER_EQUAL(4, v[15]);
}

static void test_pop_back()
{
    int_vector_t v(10, 1);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(10, std::accumulate(v.begin(), v.end(), 0));

    v.pop_back();

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(9, std::accumulate(v.begin(), v.end(), 0));

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(1, std::accumulate(v.begin(), v.end(), 0));

    v.pop_back();

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));
}

static void test_push_back()
{
    int_vector_t v;

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));

    v.push_back(1);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(1u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(1, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(1, v[0]);

    v.push_back(2);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(2u, v.size());
    XTESTS_TEST_INTEGER_EQUAL(3, std::accumulate(v.begin(), v.end(), 0));
    XTESTS_TEST_INTEGER_EQUAL(1, v[0]);
    XTESTS_TEST_INTEGER_EQUAL(2, v[1]);
}

static void test_reserve()
{
    int_vector_t v;

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, v.capacity());
    XTESTS_TEST_INTEGER_LESS_OR_EQUAL(1024u, v.capacity());

    v.reserve(250);

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(250u, v.capacity());
}

static void test_resize()
{
    int_vector_t v;

    XTESTS_TEST_BOOLEAN_TRUE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(0u, v.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(0u, v.capacity());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));

    v.resize(10);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(10u, v.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(10u, v.capacity());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v.begin(), v.end(), 0));

    v.resize(12, 2);

    XTESTS_TEST_BOOLEAN_FALSE(v.empty());
    XTESTS_TEST_INTEGER_EQUAL(12u, v.size());
    XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(12u, v.capacity());
    XTESTS_TEST_INTEGER_EQUAL(4, std::accumulate(v.begin(), v.end(), 0));
}

static void test_subscript_operator()
{
    int const           ints[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
    int_vector_t        v(ints, ints + STLSOFT_NUM_ELEMENTS(ints));
    int_vector_t const& cv = v;

    XTESTS_TEST_INTEGER_EQUAL(9u, v.size());

    XTESTS_TEST_INTEGER_EQUAL(-4, v[0]);
    XTESTS_TEST_INTEGER_EQUAL(-2, v[2]);
    XTESTS_TEST_INTEGER_EQUAL( 0, v[4]);
    XTESTS_TEST_INTEGER_EQUAL(+2, v[6]);
    XTESTS_TEST_INTEGER_EQUAL(+4, v[8]);

    XTESTS_TEST_INTEGER_EQUAL(-4, cv[0]);
    XTESTS_TEST_INTEGER_EQUAL(-2, cv[2]);
    XTESTS_TEST_INTEGER_EQUAL( 0, cv[4]);
    XTESTS_TEST_INTEGER_EQUAL(+2, cv[6]);
    XTESTS_TEST_INTEGER_EQUAL(+4, cv[8]);
}

static void test_swap()
{
    int_vector_t    v1(10, -1);
    int_vector_t    v2;

    v1.swap(v2);

    XTESTS_TEST_INTEGER_EQUAL(0u, v1.size());
    XTESTS_TEST_BOOLEAN_TRUE(v1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(v1.begin(), v1.end(), 0));

    XTESTS_TEST_INTEGER_EQUAL(10u, v2.size());
    XTESTS_TEST_BOOLEAN_FALSE(v2.empty());
    XTESTS_TEST_INTEGER_EQUAL(-10, std::accumulate(v2.begin(), v2.end(), 0));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

