#include "../libft.h"
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
    printf("case number: %zu\n", get_case());
    printf("str:		\"%s\"\n", str);
    printf("strchr:		\"%s\"\n", sch);
	printf("addr		\"%p\"", sch);
	printf("\n");
    printf("ft strchr:	\"%s\"\n", ft_sch);
	printf("addr		\"%p\"\n", ft_sch);
    assert(sch == ft_sch);
}

int main()
{
    // test existing char
    test_strchr("Hello", 'h');
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
	// TODO:
	// 	type casting knowledge gap,, 
	// 	sign preservation when casting
	// 	
	// 	aa bb cc FF
	//
}
