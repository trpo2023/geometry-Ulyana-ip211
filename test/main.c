#define CTEST_MAIN
#define CTEST_SEGFAULT

#include "../thirdparty/ctest.h"
#include <stdio.h>

int main(int argc, const char* argv[])
{
    int result = ctest_main(argc, argv);
    return result;
}