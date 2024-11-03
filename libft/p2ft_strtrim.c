#include "libft.h"

// TODO:
//	diff between char const *, const char *
static int issep(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return 1;
		set++;
	}
	return (0);
}

static size_t get_end(char const *s1, char const *set)
{
	size_t i;

	i = ft_strlen(s1);
	while (i-- > 0)
	{
		if (!issep(s1[i], set))
			return (i);
	}
	return (i);
}

static size_t get_start(char const *s1, char const *set)
{
	size_t i;

	i = 0;
	while (s1[i] && issep(s1[i], set))
		i++;
	return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *str;
	size_t s;
	size_t e;

	if (!s1)
		return (NULL);

	s = get_start(s1, set);
	e = get_end(s1, set);
	str = ft_substr(s1, s, e - s + 1);
	if (!str)
		return (NULL);
	return (str);
}
//  Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.
//
// R: The trimmed string.
// NULL if the allocation fails.
