#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

size_t	count_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*str;

	total_size = count_len(s1) + count_len(s2);
	str = malloc(total_size + 1);
	if (!str)
		return (NULL);
	// TODO: check after malloc returns NULL weather the last is freeed or not
	str[0] = '\0';
	line_append(s1, str);
	line_append(s2, str);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	;
	dup = malloc(count_len(s) + 1);
	if (dup == NULL)
		return (NULL);
	// TODO: check and free after
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
