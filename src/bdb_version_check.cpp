#include <cstdio>
#include "bdb/build_unix/db_cxx.h"

int main()
{
    printf("Berkeley DB version: %d.%d\n", DB_VERSION_MAJOR, DB_VERSION_MINOR);
    return 0;
}
