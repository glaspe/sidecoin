#include <cstdio>
#include "src/db4.8/build_unix/db_cxx.h"

#ifndef DB_VERSION_STRING
#define DB_VERSION_STRING "BDB version not found"
#endif

int main()
{
    printf("%s\n", DB_VERSION_STRING);
    printf("%d.%d\n", DB_VERSION_MAJOR, DB_VERSION_MINOR);
    return 0;
}
