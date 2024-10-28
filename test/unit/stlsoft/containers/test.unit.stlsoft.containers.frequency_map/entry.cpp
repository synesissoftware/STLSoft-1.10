/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.container.frequency_map.cpp
 *
 * Purpose: Unit-tests for `stlsoft::frequency_map`.
 *
 * Created: 12th February 2024
 * Updated: 12th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* ///////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/containers/frequency_map.hpp>

/* ///////////////////////////////////////////////
 * general includes
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
#include <type_traits>
#include <vector> // for `std::begin()`, `std::end()`

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_clear(void);
    static void test_merge(void);
    static void test_op_addassign(void);
    static void test_op_add(void);
    static void test_push(void);
    static void test_swap(void);
    static void test_swap_std(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.container.frequency_map", verbosity))
    {
        XTESTS_RUN_CASE(test_clear);
        XTESTS_RUN_CASE(test_merge);
        XTESTS_RUN_CASE(test_op_addassign);
        XTESTS_RUN_CASE(test_op_add);
        XTESTS_RUN_CASE(test_push);
        XTESTS_RUN_CASE(test_swap);
        XTESTS_RUN_CASE(test_swap_std);

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

    typedef stlsoft::frequency_map<int>                     fm_ordered_int_t;
#if __cplusplus >= 201103L

    typedef stlsoft::frequency_map<
        int
    ,   stlsoft::frequency_map_traits_unordered<int>
    >                                                       fm_unordered_int_t;
#endif /* C++ */


#if __cplusplus >= 201103L

    template <
        typename I
    ,   typename V = typename std::remove_const<typename std::iterator_traits<I>::value_type::first_type>::type
    >
    inline
    std::vector<std::pair<V, std::uint32_t>>
    fmi_to_list(
        I   from
    ,   I   to
    )
    {
        std::vector<std::pair<V, std::uint32_t>> v;

        v.reserve(std::distance(from, to));

        for (I i = from; to != i; ++i)
        {
            v.push_back(*i);
        }

        std::sort(v.begin(), v.end());

        return v;
    }

    template <
        typename T_value
    ,   typename T_traits
    >
    inline
    std::vector<std::pair<T_value, std::uint32_t>>
    fm_to_list(
        stlsoft::frequency_map<T_value, T_traits> const& fm
    )
    {
        std::vector<std::pair<T_value, std::uint32_t>> v;

        v.reserve(fm.size());

        for (typename stlsoft::frequency_map<T_value, T_traits>::const_iterator i = fm.begin(); fm.end() != i; ++i)
        {
            v.push_back(*i);
        }

        std::sort(v.begin(), v.end());

        return v;
    }
#endif /* C++ */



static void test_clear()
{
    {
        fm_ordered_int_t    fm;

        XTESTS_TEST_BOOLEAN_TRUE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[-2]);

        fm.clear();

        XTESTS_TEST_BOOLEAN_TRUE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[-2]);
    }

    {
        fm_ordered_int_t    fm;

        fm.push_n(1, 3);
        fm.push(2);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[-2]);

        fm.clear();

        XTESTS_TEST_BOOLEAN_TRUE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm[-2]);
    }
}

static void test_merge()
{
    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        fm1.merge(fm2);

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());
    }

    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        fm1.push_n(1, 3);
        fm1.push(2);
        fm2.push_n(-2, 7);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);

        fm1.merge(fm2);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(11, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);
    }

#if __cplusplus >= 201103L

    {
        fm_unordered_int_t  fm1;
        fm_unordered_int_t  fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        fm1.merge(fm2);

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());
    }

    {
        fm_unordered_int_t  fm1;
        fm_unordered_int_t  fm2;

        fm1.push_n(1, 3);
        fm1.push(2);
        fm2.push_n(-2, 7);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);

        fm1.merge(fm2);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(11, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);
    }
#endif /* C++ */
}

static void test_op_addassign(void)
{
    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        fm1 += fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());
    }

    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        fm1.push_n(1, 3);
        fm1.push(2);
        fm2.push_n(-2, 7);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);

        fm1 += fm2;

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(11, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(100));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm1[100]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);
    }
}

static void test_op_add(void)
{
    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        fm_ordered_int_t    fm3 = fm1 + fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm3.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm3.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm3.size());
    }

    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        fm1.push_n(1, 3);
        fm1.push(2);
        fm2.push_n(-2, 7);

        fm_ordered_int_t    fm3 = fm1 + fm2;

        XTESTS_TEST_BOOLEAN_FALSE(fm3.empty());
        XTESTS_TEST_INTEGER_EQUAL(3, fm3.size());
        XTESTS_TEST_INTEGER_EQUAL(11, fm3.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm3.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm3.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm3.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm3.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm3.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm3[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm3[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm3[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm3[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm3[-2]);
    }
}

static void test_push(void)
{
    {
        fm_ordered_int_t        fm;
        fm_ordered_int_t const& fmc = fm;

        XTESTS_TEST_BOOLEAN_TRUE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(105));

        XTESTS_TEST(fm.end() == fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() == fm.find(105));

        XTESTS_TEST(fm.end() == fm.begin());
        XTESTS_TEST(fmc.end() == fmc.begin());

#if __cplusplus >= 201103L

        {
            auto l = fm_to_list(fmc);

            XTESTS_TEST_BOOLEAN_TRUE(l.empty());
        }
#endif /* C++ */

        fm.push(101);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(1, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(1, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(105));

        XTESTS_TEST(fm.end() != fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() == fm.find(105));

        XTESTS_TEST(fm.end() != fm.begin());
        XTESTS_TEST(fmc.end() != fmc.begin());

#if __cplusplus >= 201103L

        {
            auto l = fm_to_list(fmc);

            XTESTS_TEST_INTEGER_EQUAL(1, l.size());

            XTESTS_TEST(std::make_pair(101, 1u) == l[0]);
        }
#endif /* C++ */

        fm.push(105);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(105));

        XTESTS_TEST(fm.end() != fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() != fm.find(105));

        XTESTS_TEST(fm.end() != fm.begin());
        XTESTS_TEST(fmc.end() != fmc.begin());

#if __cplusplus >= 201103L

        {
            auto l = fm_to_list(fmc);

            XTESTS_TEST_INTEGER_EQUAL(2, l.size());

            XTESTS_TEST(std::make_pair(101, 1u) == l[0]);
            XTESTS_TEST(std::make_pair(105, 1u) == l[1]);
        }
#endif /* C++ */

        fm.push(101);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(3, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(2, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(105));

        XTESTS_TEST(fm.end() != fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() != fm.find(105));

        XTESTS_TEST(fm.end() != fm.begin());
        XTESTS_TEST(fmc.end() != fmc.begin());

#if __cplusplus >= 201103L

        {
            auto l = fmi_to_list(fmc.crbegin(), fmc.crend());

            XTESTS_TEST_INTEGER_EQUAL(2, l.size());

            XTESTS_TEST(std::make_pair(101, 2u) == l[0]);
            XTESTS_TEST(std::make_pair(105, 1u) == l[1]);
        }
#endif /* C++ */
    }

#if __cplusplus >= 201103L

    {
        fm_unordered_int_t          fm;
        fm_unordered_int_t const&   fmc = fm;

        XTESTS_TEST_BOOLEAN_TRUE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(105));

        XTESTS_TEST(fm.end() == fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() == fm.find(105));

        XTESTS_TEST(fm.end() == fm.begin());
        XTESTS_TEST(fmc.end() == fmc.begin());

        {
            auto l = fm_to_list(fmc);

            XTESTS_TEST_BOOLEAN_TRUE(l.empty());
        }

        fm.push(101);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(1, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(1, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(105));

        XTESTS_TEST(fm.end() != fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() == fm.find(105));

        XTESTS_TEST(fm.end() != fm.begin());
        XTESTS_TEST(fmc.end() != fmc.begin());

        {
            auto l = fm_to_list(fmc);

            XTESTS_TEST_INTEGER_EQUAL(1, l.size());

            XTESTS_TEST(std::make_pair(101, 1u) == l[0]);
        }

        fm.push(105);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(105));

        XTESTS_TEST(fm.end() != fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() != fm.find(105));

        XTESTS_TEST(fm.end() != fm.begin());
        XTESTS_TEST(fmc.end() != fmc.begin());

        {
            auto l = fm_to_list(fmc);

            XTESTS_TEST_INTEGER_EQUAL(2, l.size());

            XTESTS_TEST(std::make_pair(101, 1u) == l[0]);
            XTESTS_TEST(std::make_pair(105, 1u) == l[1]);
        }

        fm.push(101);

        XTESTS_TEST_BOOLEAN_FALSE(fm.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm.size());
        XTESTS_TEST_INTEGER_EQUAL(3, fm.total());

        XTESTS_TEST_INTEGER_EQUAL(2, fm.count(101));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(102));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(103));
        XTESTS_TEST_INTEGER_EQUAL(0, fm.count(104));
        XTESTS_TEST_INTEGER_EQUAL(1, fm.count(105));

        XTESTS_TEST(fm.end() != fm.find(101));
        XTESTS_TEST(fm.end() == fm.find(102));
        XTESTS_TEST(fm.end() == fm.find(103));
        XTESTS_TEST(fm.end() == fm.find(104));
        XTESTS_TEST(fm.end() != fm.find(105));

        XTESTS_TEST(fm.end() != fm.begin());
        XTESTS_TEST(fmc.end() != fmc.begin());

        {
            auto l = fmi_to_list(fmc.cbegin(), fmc.cend());

            XTESTS_TEST_INTEGER_EQUAL(2, l.size());

            XTESTS_TEST(std::make_pair(101, 2u) == l[0]);
            XTESTS_TEST(std::make_pair(105, 1u) == l[1]);
        }
    }

#endif /* C++ */
}

static void test_swap()
{
    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        fm1.swap(fm2);

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        fm2.swap(fm1);

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());
    }

    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        fm1.push_n(1, 3);
        fm1.push(2);
        fm2.push_n(-2, 7);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);

        fm1.swap(fm2);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(2, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(3, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.count(2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm2[2]);

        fm2.swap(fm1);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);
    }
}

static void test_swap_std()
{
    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        std::swap(fm1, fm2);

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());

        std::swap(fm2, fm1);

        XTESTS_TEST_BOOLEAN_TRUE(fm1.empty());
        XTESTS_TEST_BOOLEAN_TRUE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.total());
    }

    {
        fm_ordered_int_t    fm1;
        fm_ordered_int_t    fm2;

        fm1.push_n(1, 3);
        fm1.push(2);
        fm2.push_n(-2, 7);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);

        std::swap(fm1, fm2);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(2, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(7, fm1.count(-2));
        XTESTS_TEST_INTEGER_EQUAL(3, fm2.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.count(2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm1[-2]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm2[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm2[2]);

        std::swap(fm2, fm1);

        XTESTS_TEST_BOOLEAN_FALSE(fm1.empty());
        XTESTS_TEST_BOOLEAN_FALSE(fm2.empty());
        XTESTS_TEST_INTEGER_EQUAL(2, fm1.size());
        XTESTS_TEST_INTEGER_EQUAL(4, fm1.total());
        XTESTS_TEST_INTEGER_EQUAL(1, fm2.size());
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.total());

        XTESTS_TEST_INTEGER_EQUAL(0, fm1.count(0));
        XTESTS_TEST_INTEGER_EQUAL(0, fm2.count(100));
        XTESTS_TEST_INTEGER_EQUAL(3, fm1.count(1));
        XTESTS_TEST_INTEGER_EQUAL(1, fm1.count(2));
        XTESTS_TEST_INTEGER_EQUAL(7, fm2.count(-2));

        XTESTS_TEST_INTEGER_EQUAL(0, fm1[0]);
        XTESTS_TEST_INTEGER_EQUAL(0, fm2[100]);
        XTESTS_TEST_INTEGER_EQUAL(3, fm1[1]);
        XTESTS_TEST_INTEGER_EQUAL(1, fm1[2]);
        XTESTS_TEST_INTEGER_EQUAL(7, fm2[-2]);
    }
}


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

