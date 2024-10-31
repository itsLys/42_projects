#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    c = (char) c;
    while (*s && *s != c)
        s++;
    if (*s == c)
        return (char *)(s);
    return (NULL);
}
