#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *dup;

    dup = (unsigned char *)s;
    while (n--)
        *dup++ = (unsigned char)c;
    return (s);
}
