#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void print_arr(void *arr, size_t size)
{

	unsigned char *ap;
	ap = (unsigned char *) arr;
	while (size--)
	{
		printf("%x, ", *(ap++));
	}
}

void test_same_mem_same_size()
{
	char buff1[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	char buff2[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	void *porig;
	void *pft;
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("array 1: ");
	print_arr(buff1, 11);
	printf("array 1: ");
	print_arr(buff2, 11);
	printf("\n");
	printf("byte to find %xu\n", find[j]);
	porig = memchr(buff, find[j], 11);
	pft = ft_memchr(buff, find[j], 11);
	printf("pointer orig: %p\n", porig);
	printf("pointer ft: %p\n", pft);
	assert(porig == pft);
	printf("\n");
	j++;
}
