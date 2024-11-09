#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t slen;

	if (!s)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	// if (len > slen)
	// 	return (ft_strdup(s + start));
	// 	TODO:
	//	fix unwanted memory allocation
	substr = ft_calloc(len + 1, 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
// strlen 	== 10;
// len 		== 100;
// index 	== 6
//
//
//
//
// Allocates (with malloc(3))
// and returns a substring from the string ’s’.
// The substring begins at index ’start’
// and is of maximum size ’len’.
