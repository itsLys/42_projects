#include "test.h"

void test_printf(const char  *fmt, ...)
{
    int pf, ftpf;
    va_list args;
    va_list ftargs;

    va_start(args, fmt);
    va_start(ftargs, fmt);
    printf("-----------\n");
    printf("case:    %d\n", get_case());
    printf("printf:\n");
	printf("ft_printf:\n");
    pf = vprintf(fmt, args);
    ftpf = ft_printf(fmt, ftargs);
    printf("pf:	%d\n", pf);
    printf("ftpf:	%d\n", ftpf);

    assert(pf == ftpf);
    va_end(args);
    va_end(ftargs);
}
