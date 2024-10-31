#include "libft.h"

int ft_tolower(int c)
{
    return (c + ('a' - 'A') * (c >= 'A' && c <= 'Z'));
}
