#include "libft.h"
#include "test.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void print_arr(const void *arr, size_t size)
{

	const unsigned char *ap;
	ap = (const unsigned char *)arr;
	while (size--)
	{
		printf("%.2x, ", *(ap++));
	}
	printf("\n");
}

void test_mem_set(char *src, size_t size, int byte)
{
	char *dst = malloc(size);
	char *dstft = malloc(size);
	memcpy(dst, src, size);
	memcpy(dstft, src, size);
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("dst:		");
	print_arr(dst, size);

	printf("ft dst:		");
	print_arr(dstft, size);

	memset(dst, byte, size);
	ft_memset(dstft, byte, size);

	printf("src:		");
	print_arr(src, size);

	printf("dst setd:	");
	print_arr(dst, size);

	printf("ftdst setd:	");
	print_arr(dstft, size);
	assert(memcmp(dst, dstft, size) == 0);

	printf("\n");
	free(dst);
	free(dstft);
}

int main()
{
	char src[] = {'\x00', '\x41', '\x02', '\x01', '\xf0', '\x71', '\xff', '\x7f', '\x09', '\x1f', '\x0f'};
	char byte = 0xaf;
	test_mem_set(src, 11, byte);
	test_mem_set(src, 5, byte);
	test_mem_set(src, 1, byte);
	test_mem_set(src, 0, byte);
	char *src0 = malloc(0);
	test_mem_set(src0, 11, byte);
	test_mem_set(src0, 5, byte);
	test_mem_set(src0, 1, byte);
	test_mem_set(src0, 0, byte);
	// char *srcnull = NULL;
	// test_mem_set(srcnull, 11, byte);
	// test_mem_set(srcnull, 5);
	// test_mem_set(srcnull, 1);
	// test_mem_set(srcnull, 0);
	// test_same_mem_diff_null();
}
