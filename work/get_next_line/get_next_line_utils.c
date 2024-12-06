#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// implement dup until
char	*strdup_until(const char *s)
{
	char	*dup;
	int		i;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (*s)
		dup[i++] = *(s++);
	dup[i] = '\0';
	return (dup);
}

void	line_append(const char *src, char *dst)
{
	while (*dst)
		dst++;
	if (src)
	{
		while (*src && *src != '\n')
			*(dst++) = *(src++);
		if (*src)
			*(dst++) = '\n';
		*dst = '\0';
	}
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		c = (char)c;
		while (*s && *s != c)
			s++;
		if (*s == c)
			return ((char *)(s));
	}
	return (NULL);
}

