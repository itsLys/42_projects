#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sp;

	sp = (unsigned char *) s;
	while(--n)
	{
		if (*(sp++) == c)
			return ((void *) sp);
	}
	return (NULL);
}
