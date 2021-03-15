#include "sanitize.h"
#include "utils.h"
#include "tdd.h"

int
main(int argc, char *argv[])
{
#ifdef _RUN_SMOKE
    run_tdd();
#else

#endif

    LOG_SANITIZE();

    return 0;
}
