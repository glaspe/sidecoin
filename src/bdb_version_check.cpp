#include <cstdio>
#include <assert.h>
#include <db_cxx.h>

// Make sure we've actually got Berkeley DB 4.8 installed
int main()
{
    printf("Berkeley DB version: %d.%d\n", DB_VERSION_MAJOR, DB_VERSION_MINOR);
    assert(DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR == 8);
    return 0;
}
