#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    //  TODO: What is size_t?
    size_t i;
    size_t j;
    size_t hlen;
    size_t nlen;

    hlen = ft_strlen(haystack);
    nlen = ft_strlen(needle);
    if (hlen < nlen || len < nlen)
        return NULL;

    i = 0;
    if (needle[0])
    {
        while (haystack[i] && i < len)
        {
            if (haystack[i] == needle[0])
            {
                j = 0;
                while (i + j < len && needle[j] && needle[j] == haystack[i + j])
                    j++;
                if (needle[j] == '\0')
                    return (char *)(haystack + i);
            }
            i++;
        }
        return (NULL);
    }
    return (char *)(haystack);
}
