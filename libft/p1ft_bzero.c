#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *sp;

	sp = (unsigned char *)s;
	while (n--)
		*(sp++) = '\0';
}
