#include "sanitize.h"
#include "utils.h"
#include "tdd.h"

int
main(int argc, char *argv[])
{
    char *c = (char *) COMMON_MALLOC (10);
    UNUSED_PARAMETER(c);
#ifdef _RUN_SMOKE
    run_tdd();
#else

#endif

    LOG_SANITIZE();

    return COMMON_AMOUNT();
}
