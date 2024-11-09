#include "libft.h"
#include "test.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_same_mem_same_size(void *buff1, void *buff2)
{
	int cmp;
	int ft_cmp;
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("buffer1:	");
	print_bytes(buff1, 10);
	printf("buffer2:	");
	print_bytes(buff2, 10);
	cmp = memcmp(buff1, buff2, 10);
	ft_cmp = ft_memcmp(buff1, buff2, 10);
	printf("memcmp value: %d\n", cmp);
	printf("ft_memcmp value: %d\n", ft_cmp);
	assert((cmp > 0 && ft_cmp > 0) || (cmp < 0 && ft_cmp < 0) || (!cmp && !ft_cmp));
	printf("\n");
}

int main()
{
	unsigned char buff1[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							   '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	unsigned char buff2[10] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60', '\x70', '\x80', '\x90'};

	unsigned char buff3[13] = {'\x10', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							   '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	unsigned char buff4[10] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60', '\x70', '\x80', '\x90'};

	unsigned char buff5[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							   '\x70', '\x80', '\x91', '\xa0', '\xb0', '\xc0'};
	unsigned char buff6[10] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60', '\x70', '\x80', '\x90'};
	test_same_mem_same_size(buff1, buff2);
	test_same_mem_same_size(buff3, buff4);
	test_same_mem_same_size(buff5, buff6);
	memcmp(NULL, NULL, 0);
}
