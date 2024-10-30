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

void test_strnstr(const char *h, const char *n, size_t len)
{

    char *snstr = strnstr(h, n, len);
    char *ft_snstr = ft_strnstr(h, n, len);
    printf("---------------------------\n");
    printf("case number: %zu\n", get_case());
    printf("\n");
    printf("haystack:	\"%s\"\n", h);
    printf("needle:		\"%s\"\n", n);
    printf("len:		\"%zu\"\n", len);
    printf("\n");
    printf("strnstr:	\"%s\"\n", snstr);
    printf("addr:		\"%p\"\n", snstr);
    printf("\n");
    printf("ft_strnstr:	\"%s\"\n", ft_snstr);
    printf("addr:		\"%p\"\n", ft_snstr);
    printf("\n");
    assert(ft_snstr == snstr);
}

int main()
{
    test_strnstr("Hello, World", "Hello", 5);
    test_strnstr("Hello", "Hello", 5);
    test_strnstr("Hello", "Hell0", 5);
    test_strnstr("Hello", "1ello", 5);
    test_strnstr("Hello", "Henlo", 5);
    test_strnstr("World, Hello", "Hello", 100);
    test_strnstr("World, Hello World", "Hello", 100);
    test_strnstr("World,HelloWorld", "Hello", 100);
    test_strnstr("World,He.lloWorld", "Hello", 100);
    test_strnstr("				World, Hello			", "Hello", 100);
    test_strnstr("World, Hello", "Hello ", 100);
    test_strnstr("World, Hello	", "Hello ", 100);
    test_strnstr("Hello, World", "Hello", 4);
    test_strnstr("Hello", "e", 2);
    test_strnstr("Hello", "e", 1);
    test_strnstr("Hello", "o", 100);
    test_strnstr("Hello", "H", 100);
    test_strnstr("Hello", "H", 0);
    test_strnstr("", "", 100);
}
