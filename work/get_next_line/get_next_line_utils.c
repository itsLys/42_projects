#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

size_t	count_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	total_size = count_len(s1) + count_len(s2) + 1;
	str = malloc(total_size);
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	str_append(s1, str);
	str_append(s2, str);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	slen;
	int		i;

	slen = count_len(s);
	dup = malloc(slen + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (*s && slen--)
		dup[i++] = *(s++);
	return (dup);
}

void	str_append(const char *src, char *dst)
{
	while (*dst)
		dst++;
	while (*src && *src != '\n')
		*(dst++) = *(src++);
	if (*src)
		*(dst++) = '\n';
	*dst = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (char)c;
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)(s));
	return (NULL);
}
