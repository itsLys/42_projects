#include "test.h"
#include <stdio.h>

void test_printf(const char  *fmt, ...)
{
    int pf, ftpf;
    va_list args;
    va_list ftargs;

    va_start(args, fmt);
    va_start(ftargs, fmt);
    printf("\n");
    printf("-----------\n");
    printf("case:    	%d\n", get_case());
    printf("printf:		");
	pf = vprintf(fmt, args);
    printf("\n");
	fflush(stdout);
	printf("ft_printf:	");
	fflush(stdout);
    ftpf = ft_printf(fmt, ftargs);
	printf("\n");
    // printf("pf:			%d\n", pf);
    // printf("ftpf:		%d\n", ftpf);

    assert(pf == ftpf);
    va_end(args);
    va_end(ftargs);
}
