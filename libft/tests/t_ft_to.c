#include "../libft.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_case()
{
    static size_t i = 0;
    return (i++);
}

void test_toup(char c)
{
    int tou = toupper(c);
    int ft_tou = ft_toupper(c);

    printf("---------------------------\n");
    printf("char:		'%c'\n", c);
    printf("value:		%d\n", c);
    printf("\n");
    printf("toupper:	'%c'\n", tou);
    printf("value:		%d\n", tou);
    printf("\n");
    printf("ft_toupper:	'%c'\n", ft_tou);
    printf("value:		%d\n", ft_tou);
    printf("\n");
    assert(tou == ft_tou);
}

void test_tolow(char c)
{
    int tolow = tolower(c);
    int ft_tolow = ft_tolower(c);

    printf("---------------------------\n");
    printf("char:		'%c'\n", c);
    printf("value:		%d\n", c);
    printf("\n");
    printf("tolower:	'%c'\n", tolow);
    printf("value:		%d\n", tolow);
    printf("\n");
    printf("ft_tolower:	'%c'\n", ft_tolow);
    printf("value:		%d\n", ft_tolow);
    printf("\n");
    assert(tolow == ft_tolow);
}

void test(char *str)
{
    while (*str)
    {
        test_toup(*str);
        test_tolow(*(str++));
    }
}

int main()
{

    char upper_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char ascii[255];
    int i = 0;
    while (i < 254)
    {
        ascii[i] = i + 1;
        i++;
    }
    ascii[i] = '\0';
    i = 0;
    test(upper_alpha);
    test(lower_alpha);
    test(digits);
    // test(ascii);
    test_tolow('\0');
    test_tolow(0);
    test_toup('\0');
    test_toup(0);
}
