#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *str;
	size_t i;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
// NOTE:
//	pointers to functions
