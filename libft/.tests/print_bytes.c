#include "libft.h"
#include "test.h"
void print_bytes(const void *buff, size_t size)
{

	const unsigned char *ap;
	ap = (const unsigned char *)buff;
	printf("[");
	while (size--)
	{
		printf("%.2x", *(ap++));
		if (size)
			printf(", ");
	}
	printf("]\n");
}
