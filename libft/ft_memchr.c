#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *sp;
	

	sp = (const char *) s;
	while(n--)
	{
		if (*sp == (char) c)
			return ((void *) sp);
		sp++;
	}
	return (NULL);
}
