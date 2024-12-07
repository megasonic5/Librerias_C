#ifndef _ASSERT_H
#define _ASSERT_H 1

#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
# define assert(expression) ((void)0)
#else
# define assert(expression) \
    ((expression) ? (void)0 : __assert_fail (#expression, __FILE__, __LINE__, __ASSERT_FUNCTION))
#endif

void __assert_fail (const char *assertion, const char *file, unsigned int line, const char *function) __attribute__((noreturn));

#endif /* _ASSERT_H */