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

void test_substr(const char *s, unsigned int i, size_t len, const char *exp)
{
    char *str = ft_substr(s, i, len);
    printf("---------------------------\n");
    printf("case number:		%zu\n", get_case());
    printf("source:			%s\n", s);
    printf("index:			%u\n", i);
    printf("lenght:			%zu\n", len);
    printf("expected:		\"%s\"\n", exp);
    printf("ft_substr:		\"%s\"\n", str);
    printf("\n");
    assert(strcmp(str, exp) == 0);
}

int main()
{
    test_substr("Hello World", 0, 5, "Hello");
    test_substr("Hello World", 6, 5, "World");
}
