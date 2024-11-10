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

void test_strchr(const char *str, int c)
{
	char *sch = strchr(str, c);
	char *ft_sch = ft_strchr(str, c);
	printf("---------------------------\n");
	printf("case number: 	%zu\n", get_case());
	printf("byte:		\"%.2x\"\n", c);
	printf("value:		\"%.2d\"\n", c);
	printf("\n");
	printf("str:		\"%s\"\n", str);
	printf("addr		\"%p\"\n", str);
	printf("\n");
	printf("strchr:		\"%s\"\n", sch);
	printf("addr		\"%p\"\n", sch);
	printf("\n");
	printf("ft strchr:	\"%s\"\n", ft_sch);
	printf("addr		\"%p\"\n", ft_sch);
	assert(sch == ft_sch);
}

int main()
{
	// test existing char
	test_strchr("Hello", 'H');
	test_strchr("Hello", 'o');
	test_strchr("Hello", 0);
	test_strchr("Hello", '\0');

	// test non exis
	test_strchr("Hello", 'a');
	test_strchr("Hello", 'h');
	test_strchr("Hello", 1);

	// edge
	test_strchr("Hello", 1000);
	test_strchr("Hello", INT_MAX);
	test_strchr("Hello", INT_MIN);
	test_strchr("Hello", 1000);
	test_strchr("Hello", -1);
	test_strchr("Hello", -50);
	test_strchr("Hello", INT_MIN);
	test_strchr("Hello", 0x7f000048);
	test_strchr("Hello", 0x7f000065);
	test_strchr("Hello", 0x7fff006c);
	test_strchr("Hello", 0x7fffaa6f);
	test_strchr("Hello", 0x7fffaa00);
	test_strchr("Hello", 0xff000048);
	test_strchr("Hello", 0xff000065);
	test_strchr("Hello", 0xffff006c);
	test_strchr("Hello", 0xffffaa6f);
	test_strchr("Hello", 0xffffaa00);
	test_strchr("Hello", 0xffffaa00);
	test_strchr("Hello", -0x7f000048);
	test_strchr("Hello", -0x7f000065);
	test_strchr("Hello", -0x7fff006c);
	test_strchr("Hello", -0x7fffaa6f);
	test_strchr("Hello", -0x7fffaa00);
	test_strchr("Hello", -0xff000048);
	test_strchr("Hello", -0xff000065);
	test_strchr("Hello", -0xffff006c);
	test_strchr("Hello", -0xffffaa6f);
	test_strchr("Hello", -0xffffaa00);
	test_strchr("Hello", -0xffffaa00);
	test_strchr("Hello", 0x7f0048);
	test_strchr("Hello", 0x7f0065);
	test_strchr("Hello", 0x7f006c);
	test_strchr("Hello", 0x7faa6f);
	test_strchr("Hello", 0x7faa00);
	test_strchr("Hello", 0xff0048);
	test_strchr("Hello", 0xff0065);
	test_strchr("Hello", 0xff006c);
	test_strchr("Hello", 0xffaa6f);
	test_strchr("Hello", 0xffaa00);
	test_strchr("Hello", 0xffaa00);
	test_strchr("Hello", 0x7f48);
	test_strchr("Hello", 0x7f65);
	test_strchr("Hello", 0x7f6c);
	test_strchr("Hello", 0x7f6f);
	test_strchr("Hello", 0x7f00);
	test_strchr("Hello", 0xff48);
	test_strchr("Hello", 0xff65);
	test_strchr("Hello", 0xff6c);
	test_strchr("Hello", 0xff6f);
	test_strchr("Hello", 0xff00);
	test_strchr("Hello", 0xff00);
	test_strchr("", 0xff00);
	test_strchr("", 0xffaa);
	// test_strchr("", int c)
	// TODO:
	// 	type casting knowledge gap,,
	// 	sign preservation when casting
	// 	stack vs heap in depth
	//
	// 	aa bb cc FF
	//
}
