#include "libft.h"

char *ft_strdup(const char *s)
{
	char *dup;
	size_t ssize;

	ssize = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * ssize);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, ssize);
	return (dup);
}
