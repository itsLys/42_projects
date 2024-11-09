#include "libft.h"
#include "test.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void test_itoa(int c, char *exp)
{

	char *str = ft_itoa(c);
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("number:			%d\n", c);
	printf("expected:		\"%s\"\n", exp);
	printf("itoa:			\"%s\"\n", str);
	printf("\n");
	assert(strcmp(str, exp) == 0);
	free(str);
}

int main()
{
	test_itoa(0, "0");
	test_itoa(1, "1");
	test_itoa(-1, "-1");
	test_itoa(42, "42");
	test_itoa(-42, "-42");
	test_itoa(1337, "1337");
	test_itoa(-1337, "-1337");
	test_itoa(12345, "12345");
	test_itoa(-67890, "-67890");
	test_itoa(INT_MAX, "2147483647");
	test_itoa(0x7fffffff, "2147483647");
	test_itoa(INT_MIN, "-2147483648");
	test_itoa(0x80000000, "-2147483648");
	test_itoa(9999, "9999");
	test_itoa(-9999, "-9999");
}
