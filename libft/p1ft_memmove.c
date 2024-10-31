#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char *dp;
    const char *sp;

    if (dest == src || n == 0)
        return (dest);
    dp = (char *)dest;
    sp = (const char *)src;
    if (dp > sp)
    {
        while (n--)
            dp[n] = sp[n];
    }
    else
    {
        ft_memcpy(dp, sp, n);
    }
    return (dest);
}
