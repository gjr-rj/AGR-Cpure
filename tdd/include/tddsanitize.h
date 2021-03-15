#ifndef _TDDSANITIZE_H
#define _TDDSANITIZE_H

#ifdef _RUN_SMOKE
#ifdef _RUN_SANITIZE
void run_tddsanitize(void);
#else
#define run_tddsanitize()
#endif

#endif /* #ifdef _RUN_SMOKE */

#endif /* #ifndef _TDDSANITIZE_H */