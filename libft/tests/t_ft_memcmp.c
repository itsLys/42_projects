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

void print_arr(const void *arr, size_t size)
{

	const unsigned char *ap;
	ap = (const unsigned char *) arr;
	while (size--)
	{
		printf("%.2x, ", *(ap++));
	}
}

void test_same_mem_same_size()
{
	const char buff1[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	const char buff2[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	int cmp;
	int ft_cmp;
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("array 1: ");
	print_arr(buff1, 11);
	printf("array 2: ");
	print_arr(buff2, 11);
	printf("\n");
	cmp = memcmp(buff1, buff2, 11);
	ft_cmp = ft_memcmp(buff1, buff2, 11);
	printf("memcmp value: %d\n", cmp);
	printf("memcmp interpertation: %d\n", cmp);
	if (cmp > 0)
		printf("buff1 > buff2\n");
	else if (cmp < 0)
		printf("buff1 < buff2\n");
	else if (cmp == 0)
		printf("buff1 = equal buff2\n");
	printf("ft_memcmp value: %d\n", cmp);
	printf("memft_cmp interpertation: %d\n", ft_cmp);
	if (ft_cmp > 0)
		printf("buff1 > buff2\n");
	else if (ft_cmp < 0)
		printf("buff1 < buff2\n");
	else if (ft_cmp == 0)
		printf("buff1 = equal buff2\n");
	assert((cmp > 0 && ft_cmp > 0) || (cmp < 0 && ft_cmp < 0) || (!cmp && !ft_cmp));
	printf("\n");
}

int main()
{
	test_same_mem_same_size();
}

