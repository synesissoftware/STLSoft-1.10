/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.unixstl.filesystem.path.cpp
 *
 * Purpose: Unit-tests for `unixstl::basic_path`.
 *
 * Created: 16th February 2024
 * Updated: 16th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <unixstl/filesystem/path.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/conversion/sas_to_string.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
// #include <numeric>
// #include <vector>
#include <iomanip>
#include <sstream>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_construct_default(void);
    static void test_construct_filename(void);
    static void test_construct_relative_directory_and_file(void);


} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.unixstl.filesystem.path", verbosity))
    {
        XTESTS_RUN_CASE(test_construct_default);
        XTESTS_RUN_CASE(test_construct_filename);
        XTESTS_RUN_CASE(test_construct_relative_directory_and_file);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * names
 */

namespace {

    // using xtests::cpp::util::temp_directory;

    typedef unixstl::path_a                                 path_a_t;
    typedef unixstl::path_a                                 path_t;

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{

static void test_construct_default()
{
    char    buffer[1001];

    path_a_t p1;

    XTESTS_TEST_BOOLEAN_TRUE(p1.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, p1.size());
    XTESTS_TEST_INTEGER_EQUAL(0, p1.length());
#if 0

    XTESTS_TEST(p1.end() == p1.begin());
    XTESTS_TEST(p1.rend() == p1.rbegin());
#endif
    XTESTS_REQUIRE(XTESTS_TEST(nullptr != p1.c_str()));
    XTESTS_TEST('\0' == *p1.c_str());
    XTESTS_TEST_INTEGER_EQUAL(0, ::strcmp("", p1.c_str()));
    XTESTS_REQUIRE(XTESTS_TEST(nullptr != p1.data()));
    XTESTS_TEST('\0' == *p1.data());

    buffer[0] = '~';
    XTESTS_TEST_INTEGER_EQUAL(0, p1.copy(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer)));
    XTESTS_TEST('\0' == buffer[0]);
    XTESTS_TEST_INTEGER_EQUAL(0, ::strcmp("", buffer));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::sas_to_string(p1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", stlsoft::sas_to_string_m(p1));
    XTESTS_TEST_POINTER_EQUAL(nullptr, stlsoft::c_str_ptr_null(buffer));
    XTESTS_TEST_POINTER_EQUAL(nullptr, stlsoft::c_str_ptr_null_a(buffer));

    XTESTS_TEST_INTEGER_EQUAL(0, p1.get_location().len);
    XTESTS_TEST_INTEGER_EQUAL(0, p1.get_file().len);
    XTESTS_TEST_INTEGER_EQUAL(0, p1.get_ext().len);

    {
        std::stringstream stm;

        stm
            << "["
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10)
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[**********]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10) << std::left
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[**********]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10) << std::right
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[**********]", stm.str());
    }



    path_a_t p2;

    XTESTS_TEST_BOOLEAN_TRUE(p1.equal(""));
    XTESTS_TEST("" == p1);
    XTESTS_TEST(p1 == "");

    XTESTS_TEST_BOOLEAN_TRUE(p1.equal(p2));
    XTESTS_TEST(p1 == p2);
    XTESTS_TEST_BOOLEAN_FALSE(p1 != p2);

    path_a_t p3(p1);

    XTESTS_TEST_BOOLEAN_TRUE(p3.empty());
    XTESTS_TEST_INTEGER_EQUAL(0, p3.size());
    XTESTS_TEST_INTEGER_EQUAL(0, p3.length());
}

static void test_construct_filename()
{
    char    buffer[1001];

    path_a_t p1("file.ext");

    XTESTS_TEST_BOOLEAN_FALSE(p1.empty());
    XTESTS_TEST(8 == p1.size());
    XTESTS_TEST(8 == p1.length());
#if 0

    XTESTS_TEST(p1.end() == p1.begin());
    XTESTS_TEST(p1.rend() == p1.rbegin());
#endif
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, p1.c_str());
    XTESTS_TEST('\0' != *p1.c_str());
    XTESTS_TEST(0 == ::strcmp("file.ext", p1.c_str()));
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, p1.data());
    XTESTS_TEST('\0' != *p1.data());

    buffer[0] = '~';
    XTESTS_TEST(8 == p1.copy(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer)));
    XTESTS_TEST('\0' != buffer[0]);
    XTESTS_TEST(0 == ::strcmp("file.ext", buffer));

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file.ext", stlsoft::sas_to_string(p1));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file.ext", stlsoft::sas_to_string_m(p1));
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, stlsoft::c_str_ptr_null(buffer));
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, stlsoft::c_str_ptr_null_a(buffer));

    XTESTS_TEST(0 == p1.get_location().len);
    XTESTS_TEST("file.ext" == p1.get_file());
    XTESTS_TEST(".ext" == p1.get_ext());

    {
        std::stringstream stm;

        stm
            << "["
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[file.ext]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10) << std::left
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[file.ext**]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10) << std::right
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[**file.ext]", stm.str());
    }


    XTESTS_TEST(p1.equal(p1));
    XTESTS_TEST(p1 == p1);
    XTESTS_TEST(p1.equivalent(p1));


    path_a_t p2;

    XTESTS_TEST(p1.equal("file.ext"));
    XTESTS_TEST("file.ext" == p1);
    XTESTS_TEST(p1 == "file.ext");

#ifdef _WIN32

    XTESTS_TEST(      p1.equivalent("FILE.EXT"));
#else

    XTESTS_TEST_BOOLEAN_FALSE(p1.equivalent("FILE.EXT"));
#endif
    XTESTS_TEST_BOOLEAN_FALSE(p1.equivalent("life.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(p1.equal(p2));
    XTESTS_TEST_BOOLEAN_FALSE(p1 == p2);
    XTESTS_TEST(p1 != p2);

    path_a_t p3(p1);

    XTESTS_TEST_BOOLEAN_FALSE(p3.empty());
    XTESTS_TEST(8 == p3.size());
    XTESTS_TEST(8 == p3.length());

    XTESTS_TEST(p1.equal(p3));
    XTESTS_TEST(p3 == p1);
    XTESTS_TEST(p1 == p3);

    XTESTS_TEST(p1.equivalent(p3));
    XTESTS_TEST(p3.equivalent(p1));
}

static void test_construct_relative_directory_and_file()
{
    char    buffer[1001];

    path_a_t p1("dir-1/file.ext");

    XTESTS_TEST_BOOLEAN_FALSE(p1.empty());
    XTESTS_TEST(14 == p1.size());
    XTESTS_TEST(14 == p1.length());
#if 0

    XTESTS_TEST(p1.end() == p1.begin());
    XTESTS_TEST(p1.rend() == p1.rbegin());
#endif
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, p1.c_str());
    XTESTS_TEST('\0' != *p1.c_str());
    XTESTS_TEST(0 == ::strcmp("dir-1/file.ext", p1.c_str()));
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, p1.data());
    XTESTS_TEST('\0' != *p1.data());

    buffer[0] = '~';
    XTESTS_TEST(14 == p1.copy(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer)));
    XTESTS_TEST('\0' != buffer[0]);
    XTESTS_TEST(0 == ::strcmp("dir-1/file.ext", buffer));

    XTESTS_TEST(14 == stlsoft::c_str_len(p1));
    XTESTS_TEST(14 == stlsoft::c_str_len_a(p1));
    XTESTS_TEST(0 == ::strcmp("dir-1/file.ext", stlsoft::c_str_ptr(buffer)));
    XTESTS_TEST(0 == ::strcmp("dir-1/file.ext", stlsoft::c_str_ptr_a(buffer)));
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, stlsoft::c_str_ptr_null(buffer));
    XTESTS_TEST_POINTER_NOT_EQUAL(nullptr, stlsoft::c_str_ptr_null_a(buffer));

    XTESTS_TEST("dir-1/" == p1.get_location());
    XTESTS_TEST("file.ext" == p1.get_file());
    XTESTS_TEST(".ext" == p1.get_ext());

    {
        std::stringstream stm;

        stm
            << "["
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[dir-1/file.ext]",  stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10)
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[dir-1/file.ext]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10) << std::left
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[dir-1/file.ext]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(10) << std::right
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[dir-1/file.ext]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(20)
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[dir-1/file.ext******]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(20) << std::left
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[dir-1/file.ext******]", stm.str());
    }

    {
        std::stringstream stm;

        stm
            << "["
            << std::setfill('*')
            << std::setw(20) << std::right
            << p1
            << "]"
            ;

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("[******dir-1/file.ext]", stm.str());
    }


    XTESTS_TEST(p1.equal(p1));
    XTESTS_TEST(p1 == p1);
    XTESTS_TEST(p1.equivalent(p1));


    path_a_t p2;

    XTESTS_TEST(p1.equal("dir-1/file.ext"));
    XTESTS_TEST("dir-1/file.ext" == p1);
    XTESTS_TEST(p1 == "dir-1/file.ext");

#ifdef _WIN32

    XTESTS_TEST(      p1.equivalent("dir-1/FILE.EXT"));
#else

    XTESTS_TEST_BOOLEAN_FALSE(p1.equivalent("dir-1/FILE.EXT"));
#endif
    XTESTS_TEST_BOOLEAN_FALSE(p1.equivalent("dir-1/life.ext"));

    XTESTS_TEST_BOOLEAN_FALSE(p1.equal(p2));
    XTESTS_TEST_BOOLEAN_FALSE(p1 == p2);
    XTESTS_TEST(p1 != p2);

    path_a_t p3(p1);

    XTESTS_TEST_BOOLEAN_FALSE(p3.empty());
    XTESTS_TEST(14 == p3.size());
    XTESTS_TEST(14 == p3.length());

    XTESTS_TEST(p1.equal(p3));
    XTESTS_TEST(p3 == p1);
    XTESTS_TEST(p1 == p3);

    XTESTS_TEST(p1.equivalent(p3));
    XTESTS_TEST(p3.equivalent(p1));
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

