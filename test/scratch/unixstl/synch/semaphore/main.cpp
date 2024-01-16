
// #define UNIXSTL_USE_SEMAPHORE_APPLE_DISPATCH
// #define UNIXSTL_USE_SEMAPHORE_POSIX

#include <unixstl/synch/semaphore.hpp>

#include <platformstl/filesystem/path_functions.h>

#include <thread>

#include <stdio.h>


int main(int /* argc */, char* argv[])
{
    char const* const   program_name = platformstl::get_executable_name_from_path(argv[0]).ptr;

    try
    {
        unixstl::semaphore  sem(2);

        if (!sem.try_lock())
        {
            throw std::runtime_error("unexpected failure to lock 1st time");
        }

        if (!sem.try_lock())
        {
            throw std::runtime_error("unexpected failure to lock 2nd time");
        }

        sem.unlock();

        if (!sem.try_lock())
        {
            throw std::runtime_error("unexpected failure to lock 3rd time (with only 1 held currently)");
        }

        if (sem.try_lock())
        {
            throw std::runtime_error("unexpected success to lock 4th time");
        }

        sem.unlock();

        if (!sem.try_lock())
        {
            throw std::runtime_error("unexpected failure to lock 5th time (with only 1 held currently)");
        }

        return 0;
    }
    catch (std::bad_alloc&)
    {
        fprintf(
            stderr
        ,   "%s: out of memory\n"
        ,   program_name
        );
    }
    catch (std::exception& x)
    {
        fprintf(
            stderr
        ,   "%s: exception: %s\n"
        ,   program_name
        ,   x.what()
        );
    }

    return EXIT_FAILURE;
}
