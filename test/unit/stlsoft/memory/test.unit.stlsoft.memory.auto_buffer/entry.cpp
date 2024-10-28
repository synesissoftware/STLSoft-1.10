/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.stlsoft.memory.auto_buffer.cpp
 *
 * Purpose: Unit-tests for `stlsoft::auto_buffer`.
 *
 * Created: 25th February 2009
 * Updated: 18th January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <stlsoft/memory/auto_buffer.hpp>

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
#include <numeric>
#include <vector>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_construct_1(void);
    static void test_construct_2(void);
    static void test_construct_3(void);

    static void test_resize(void);
    static void test_allocator(void);
    static void test_copy_from(void);
    static void test_swap_1(void);
    static void test_swap_2(void);
    static void test_swap_3(void);
    static void test_1_10(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.stlsoft.memory.auto_buffer", verbosity))
    {
        XTESTS_RUN_CASE(test_construct_1);
        XTESTS_RUN_CASE(test_construct_2);
        XTESTS_RUN_CASE(test_construct_3);

        XTESTS_RUN_CASE(test_resize);
        XTESTS_RUN_CASE(test_allocator);
        XTESTS_RUN_CASE(test_copy_from);
        XTESTS_RUN_CASE(test_swap_1);
        XTESTS_RUN_CASE(test_swap_2);
        XTESTS_RUN_CASE(test_swap_3);
        XTESTS_RUN_CASE(test_1_10);

#ifdef STLSOFT_USE_XCOVER
        XCOVER_REPORT_FILE_COVERAGE("*stlsoft/*/auto_buffer.hpp", NULL);
#endif /* STLSOFT_USE_XCOVER */

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

static void test_construct_1()
{
    stlsoft::auto_buffer<char> buff(0);

    XTESTS_TEST_INTEGER_EQUAL(0u, buff.size());
    XTESTS_TEST_INTEGER_NOT_EQUAL(0u, buff.internal_size());
}

static void test_construct_2()
{
    stlsoft::auto_buffer<char, 10> buff(0);

    XTESTS_TEST_INTEGER_EQUAL(0u, buff.size());
    XTESTS_TEST_INTEGER_EQUAL(10u, buff.internal_size());
}

static void test_construct_3()
{
    stlsoft::auto_buffer<char, 10> buff(10);

    XTESTS_TEST_INTEGER_EQUAL(10u, buff.size());
    XTESTS_TEST_INTEGER_EQUAL(10u, buff.internal_size());
}

static void test_resize()
{
    stlsoft::auto_buffer<char, 10>      buff(1u);

    char* const first = buff.data();

    { for (size_t i = 0; i != buff.internal_size(); ++i)
    {
        buff.resize(i);

        XTESTS_TEST_INTEGER_EQUAL(i, buff.size());
        XTESTS_TEST_POINTER_EQUAL(first, buff.data());
    }}

    { for (size_t i = 1u + buff.internal_size(); i != 10000; ++i)
    {
        buff.resize(i);

        XTESTS_TEST_INTEGER_EQUAL(i, buff.size());
        XTESTS_TEST_POINTER_NOT_EQUAL(first, buff.data());
    }}
}

static void test_allocator()
{
    stlsoft::auto_buffer<char, 10>::allocator_type  ator;
    stlsoft::auto_buffer<char, 10>                  buff(0);

    std::vector<char*>  buffers;

    size_t  size = 1;

    { for (size_t i = 0; i != 32; ++i, size <<= 1)
    {
        try
        {
#ifdef STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT
            char* p = ator.allocate(size, NULL);
#else /* ? STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */
            char* p = ator.allocate(size);
#endif /* STLSOFT_LF_ALLOCATOR_ALLOCATE_HAS_HINT */

            if (NULL != p)
            {
                buffers.push_back(p);
            }
        }
        catch(std::bad_alloc&)
        {}
    }}

    // Now we're close to exhaustion
    size = 1;

    { for (size_t i = 0; i != 32; ++i, size <<= 1)
    {
#ifdef STLSOFT_CF_THROW_BAD_ALLOC
        try
        {
            XTESTS_TEST_BOOLEAN_TRUE(buff.resize(size));
        }
        catch(std::bad_alloc&)
        {}
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    }}

    { for (std::vector<char*>::iterator b = buffers.begin(); b != buffers.end(); ++b)
    {
        ator.deallocate(*b, 0u);
    }}
}

static void test_copy_from()
{
    typedef stlsoft::auto_buffer<int, 8> ab_int_8_t;

    int const ints[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4 };

    ab_int_8_t          buff(STLSOFT_NUM_ELEMENTS(ints));
    ab_int_8_t const&   cbuff = buff;

    assert(buff.size() >= STLSOFT_NUM_ELEMENTS(ints));
    std::copy(
        std::begin(ints), std::end(ints)
    ,   buff.begin()
    );

    XTESTS_TEST_BOOLEAN_FALSE(buff.empty());
    XTESTS_TEST_INTEGER_EQUAL(10, buff.size());
    XTESTS_TEST_INTEGER_EQUAL(-5, std::accumulate(cbuff.begin(), cbuff.end(), 0));


    ab_int_8_t  buff2(0);

    XTESTS_TEST_BOOLEAN_TRUE(buff2.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, buff2.size());
    XTESTS_TEST_INTEGER_EQUAL(0, std::accumulate(buff2.rbegin(), buff2.rend(), 0));

    buff2.copy_from(cbuff);

    XTESTS_TEST_BOOLEAN_FALSE(buff2.empty());
    XTESTS_TEST_INTEGER_EQUAL(10, buff2.size());
    XTESTS_TEST_INTEGER_EQUAL(-5, std::accumulate(buff2.rbegin(), buff2.rend(), 0));
}

static void test_swap_1()
{
    // ab1.swap(ab2)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab1.swap(ab2);

        XTESTS_TEST_INTEGER_EQUAL(8u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }

    // ab2.swap(ab1)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab2.swap(ab1);

        XTESTS_TEST_INTEGER_EQUAL(8u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }
}

static void test_swap_2()
{
    // ab1.swap(ab2)
    {
        stlsoft::auto_buffer<int, 10>   ab1(50);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(50u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab1.swap(ab2);

        XTESTS_TEST_INTEGER_EQUAL(8u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(50u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }

    // ab2.swap(ab1)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab2.swap(ab1);

        XTESTS_TEST_INTEGER_EQUAL(8u,  ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u, ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }
}

static void test_swap_3()
{
    // ab1.swap(ab2)
    {
        stlsoft::auto_buffer<int, 10>   ab1(50);
        stlsoft::auto_buffer<int, 10>   ab2(8);

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(50u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(8u,  ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab1.swap(ab2);

        XTESTS_TEST_INTEGER_EQUAL(8u,  ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(50u, ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }

    // ab2.swap(ab1)
    {
        stlsoft::auto_buffer<int, 10>   ab1(10);
        stlsoft::auto_buffer<int, 10>   ab2(18);

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            ab1[i] = int(i);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            ab2[i] = -int(i);
        }}

        XTESTS_TEST_INTEGER_EQUAL(10u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(18u, ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab2[i]);
        }}


        ab2.swap(ab1);

        XTESTS_TEST_INTEGER_EQUAL(18u, ab1.size());
        XTESTS_TEST_INTEGER_EQUAL(10u, ab2.size());

        { for (size_t i = 0; i != ab1.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(-int(i), ab1[i]);
        }}

        { for (size_t i = 0; i != ab2.size(); ++i)
        {
            XTESTS_TEST_INTEGER_EQUAL(int(i), ab2[i]);
        }}
    }
}

static void test_1_10()
{

}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

