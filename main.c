#include "sanitize.h"

int
main(int argc, char *argv[])
{
    int *i = (int *)COMMON_MALLOC(sizeof(i));
    char *c = (char *)COMMON_MALLOC(255);

#ifdef _SMOKE

#else

#endif

    COMMON_FREE(i);
    COMMON_FREE(c);

    LOG_SANITIZE();

    return 0;
}
