#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *mem;
	size_t total;

	total = nmemb * size;
	if (!size || !nmemb || total / nmemb != size)
		return (NULL);
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, total);
	return (mem);
}
