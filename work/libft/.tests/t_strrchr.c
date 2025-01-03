#include "libft.h"
#include "test.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_strrchr(const char *str, int c)
{
	char *sch = strrchr(str, c);
	char *ft_sch = ft_strrchr(str, c);
	printf("---------------------------\n");
	printf("case number: 	%zu\n", get_case());
	printf("byte:		\'%c\'\n", c);
	printf("value:		\"%.2x\"\n", c);
	printf("\n");
	printf("str:		\"%s\"\n", str);
	printf("addr		\"%p\"\n", str);
	printf("\n");
	printf("strrchr:	\"%s\"\n", sch);
	printf("addr		\"%p\"\n", sch);
	printf("\n");
	printf("ft strrchr:	\"%s\"\n", ft_sch);
	printf("addr		\"%p\"\n", ft_sch);
	assert(sch == ft_sch);
}

int main()
{
	// test existing char
	test_strrchr("Hello", 'H');
	test_strrchr("Hello", 'o');
	test_strrchr("Hello", 0);
	test_strrchr("Hello", '\0');

	// test non exis
	test_strrchr("Hello", 'a');
	test_strrchr("Hello", 'h');
	test_strrchr("Hello", 1);

	// edge
	test_strrchr("Hello", 1000);
	test_strrchr("Hello", INT_MAX);
	test_strrchr("Hello", INT_MIN);
	test_strrchr("Hello", 1000);
	test_strrchr("Hello", -1);
	test_strrchr("Hello", -50);
	test_strrchr("Hello", INT_MIN);
	test_strrchr("Hello", 0x7f000048);
	test_strrchr("Hello", 0x7f000065);
	test_strrchr("Hello", 0x7fff006c);
	test_strrchr("Hello", 0x7fffaa6f);
	test_strrchr("Hello", 0x7fffaa00);
	test_strrchr("Hello", 0xff000048);
	test_strrchr("Hello", 0xff000065);
	test_strrchr("Hello", 0xffff006c);
	test_strrchr("Hello", 0xffffaa6f);
	test_strrchr("Hello", 0xffffaa00);
	test_strrchr("Hello", 0xffffaa00);
	test_strrchr("Hello", -0x7f000048);
	test_strrchr("Hello", -0x7f000065);
	test_strrchr("Hello", -0x7fff006c);
	test_strrchr("Hello", -0x7fffaa6f);
	test_strrchr("Hello", -0x7fffaa00);
	test_strrchr("Hello", -0xff000048);
	test_strrchr("Hello", -0xff000065);
	test_strrchr("Hello", -0xffff006c);
	test_strrchr("Hello", -0xffffaa6f);
	test_strrchr("Hello", -0xffffaa00);
	test_strrchr("Hello", -0xffffaa00);
	test_strrchr("Hello", 0x7f0048);
	test_strrchr("Hello", 0x7f0065);
	test_strrchr("Hello", 0x7f006c);
	test_strrchr("Hello", 0x7faa6f);
	test_strrchr("Hello", 0x7faa00);
	test_strrchr("Hello", 0xff0048);
	test_strrchr("Hello", 0xff0065);
	test_strrchr("Hello", 0xff006c);
	test_strrchr("Hello", 0xffaa6f);
	test_strrchr("Hello", 0xffaa00);
	test_strrchr("Hello", 0xffaa00);
	test_strrchr("Hello", 0x7f48);
	test_strrchr("Hello", 0x7f65);
	test_strrchr("Hello", 0x7f6c);
	test_strrchr("Hello", 0x7f6f);
	test_strrchr("Hello", 0x7f00);
	test_strrchr("Hello", 0xff48);
	test_strrchr("Hello", 0xff65);
	test_strrchr("Hello", 0xff6c);
	test_strrchr("Hello", 0xff6f);
	test_strrchr("Hello", 0xff00);
	test_strrchr("Hello", 0xff00);
	test_strrchr("", 0xff00);
	// char *sch = strrchr(NULL, 0);
	// char *ftsch = ft_strrchr(NULL, 0);
}
