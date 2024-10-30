#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t slen;
	size_t dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	int i = 0;

	if (dsize <= dlen)
		return (slen + dsize);
	while (src[i] && dlen + i < dsize - 1)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}
// TODO: 
// 	return value of strlcat meaning and usage
