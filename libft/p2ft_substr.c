#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *substr;
    size_t i;

    i = 0;
    substr = ft_calloc(len + 1, 1);
    if (substr == NULL)
        return (NULL);
    while (s[start] && start < len)
    {
        substr[i++] = s[start++];
    }
    substr[i] = '\0';
    // size, len???

    return (substr);
}
// Allocates (with malloc(3))
// and returns a substring from the string ’s’.
// The substring begins at index ’start’
// and is of maximum size ’len’.
