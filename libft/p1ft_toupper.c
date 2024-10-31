#include "libft.h"

int ft_toupper(int c)
{
    return (c - ('a' - 'A') * (c >= 'a' && c <= 'z'));
}
