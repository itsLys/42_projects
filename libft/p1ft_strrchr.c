#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t i;
	c = (char)c;

	i = ft_strlen(s);
	while (i > 0 && *(s + i) != c)
		i--;
	if (*(s + i) == c)
		return (char *)(s + i);
	return (NULL);
}
