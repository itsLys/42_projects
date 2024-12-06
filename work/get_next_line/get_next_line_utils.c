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

char	*ft_strdup(const char *s)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (!s)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	substr[0] = '\0';
	line_append(substr, s + start);
	return (substr);
}
