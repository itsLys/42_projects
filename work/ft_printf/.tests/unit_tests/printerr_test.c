#include "test.h"

void test_err(const char  *fmt, ...)
{
    int ftpf;
    va_list ftargs;

    va_start(ftargs, fmt);
    printf("\n");
    printf("-----------\n");
    printf("case:    	%d\n", get_case());
	printf("ft_printf:	");
	fflush(stdout);
    ftpf = ft_printf(fmt, ftargs);
	printf("\n");
    printf("ftpf:		%d\n", ftpf);

    assert(ftpf == -1);
    va_end(ftargs);
}
int main()
{
	test_err("|%x|\n", 0xaabbccdd);             
	test_err("|%X|\n", 0xaabbccdd);             
	test_err("|%d|\n", 0xaabbccdd);             
	test_err("|%i|\n", 0xaabbccdd);             
	test_err("|%s|\n", "Hello World!");             
	test_err("|%c|\n", 0xaabbccdd);             
	test_err("|%p|\n", 0xaabbccdd);             
	test_err("|%%|\n", 0xaabbccdd);             
}
