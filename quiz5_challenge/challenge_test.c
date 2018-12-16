#include <stdio.h>
#include <stdlib.h>
#include "challenge.h"

#define assert(EXPRESSION) ((EXPRESSION) ? _assert_pass(#EXPRESSION, __FILE__, __LINE__) : \
                                           _assert_fail(#EXPRESSION, __FILE__, __LINE__))

void _assert_fail(const char *expression, const char *file, int line)
{
    fprintf(stderr, "Assertion '%s' failed, file '%s' line '%d'.\n", expression, file, line);
}

void _assert_pass(const char *expression, const char *file, int line)
{
    fprintf(stdout, "Assertion '%s' passed, file '%s' line '%d'.\n", expression, file, line);
}

int main(void)
{
	assert(evaluate("1+2*5")==11);
	assert(evaluate("1-2*5")==-9);
	assert(evaluate("0-9")==-9);
}
