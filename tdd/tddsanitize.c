#include "tddsanitize.h"

#if defined(_RUN_SMOKE) && defined(_RUN_SANITIZE)

#include "sanitize.h"
#include "utils.h"
#include "assert.h"
#include "string.h"

void
run_tddsanitize(void)
{
    char funcName[STZ_MAX_SIZE_NAME_FUNC];
    char *c;
    int *i;
    float *f;
    char *s;
    long *l;

    assert(0 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert('\0' == funcName[0]);
    assert(0 == getSanitizeLastLine());
    assert(0 == getSanitizeLastAddr());
    assert(0 == getSanitizeLastSize());

    c = (char *)COMMON_MALLOC(sizeof(char));
    assert(1 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(27 == getSanitizeLastLine());
    assert((unsigned long)c == getSanitizeLastAddr());
    assert(sizeof(char) == getSanitizeLastSize());

    i = (int *)COMMON_MALLOC(sizeof(int));
    assert(2 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(35 == getSanitizeLastLine());
    assert((unsigned long)i == getSanitizeLastAddr());
    assert(sizeof(int) == getSanitizeLastSize());

    f = (float *)COMMON_MALLOC(sizeof(float));
    assert(3 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(43 == getSanitizeLastLine());
    assert((unsigned long)f == getSanitizeLastAddr());
    assert(sizeof(float) == getSanitizeLastSize());

    s = (char *)COMMON_MALLOC(sizeof(char) * STZ_MAX_SIZE_NAME_FUNC);
    assert(4 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(51 == getSanitizeLastLine());
    assert((unsigned long)s == getSanitizeLastAddr());
    assert(sizeof(char) * STZ_MAX_SIZE_NAME_FUNC == getSanitizeLastSize());

    l = (long *)COMMON_MALLOC(sizeof(long));
    assert(5 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(59 == getSanitizeLastLine());
    assert((unsigned long)l == getSanitizeLastAddr());
    assert(sizeof(long) == getSanitizeLastSize());

    COMMON_FREE(c);
    assert(4 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(59 == getSanitizeLastLine());
    assert((unsigned long)l == getSanitizeLastAddr());
    assert(sizeof(long) == getSanitizeLastSize());

    COMMON_FREE(l);
    assert(3 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(51 == getSanitizeLastLine());
    assert((unsigned long)s == getSanitizeLastAddr());
    assert(sizeof(char) * STZ_MAX_SIZE_NAME_FUNC == getSanitizeLastSize());

    COMMON_FREE(f);
    assert(2 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(51 == getSanitizeLastLine());
    assert((unsigned long)s == getSanitizeLastAddr());
    assert(sizeof(char) * STZ_MAX_SIZE_NAME_FUNC == getSanitizeLastSize());

    COMMON_FREE(i);
    assert(1 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert(0 == strcmp("run_tddsanitize", funcName));
    assert(51 == getSanitizeLastLine());
    assert((unsigned long)s == getSanitizeLastAddr());
    assert(sizeof(char) * STZ_MAX_SIZE_NAME_FUNC == getSanitizeLastSize());

    COMMON_FREE(s);
    assert(0 == getSanitizeAmountAllocated());
    getSanitizeLastFuncName(funcName);
    assert('\0' == funcName[0]);
    assert(0 == getSanitizeLastLine());
    assert((unsigned long)c == getSanitizeLastAddr());
    assert(sizeof(char) == getSanitizeLastSize());
}

#endif /* #if definde(_RUN_SMOKE) && defined (_RUNSANITIZE) */
