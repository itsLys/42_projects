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

void test_strncmp(const char *s1, const char *s2, size_t n)
{

    int sncmp = strncmp(s1, s2, n);
    int ft_sncmp = ft_strncmp(s1, s2, n);
    printf("---------------------------\n");
    printf("case number: %zu\n", get_case());
    printf("\n");
    printf("str1:		\"%s\"\n", s1);
    printf("str2:		\"%s\"\n", s2);
    printf("n:		\"%zu\"\n", n);
    printf("\n");
    printf("strncmp:	\"%d\"\n", sncmp);
    printf("ft_strncmp:	\"%d\"\n", ft_sncmp);
    printf("\n");
    assert((sncmp > 0 && ft_sncmp > 0) || (sncmp < 0 && ft_sncmp < 0) || (sncmp == 0 && ft_sncmp == 0));
}

int main()
{
    test_strncmp("Hello", "Hello", 5);
    test_strncmp("H", "H", 1);
    test_strncmp("", "", 0);

    test_strncmp("Hello, World", "Hello, Universe", 5);
    test_strncmp("HAHA", "HEHE", 1);
    test_strncmp("Bro", "Son", 0);

    test_strncmp("Hello", "Heslo", 5);
    test_strncmp("H", "2", 1);
}
