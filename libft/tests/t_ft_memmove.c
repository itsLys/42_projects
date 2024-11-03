#include "../libft.h"
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

void test_mem_move(const char *src, size_t size)
{
	char *dst = malloc(size);
	char *dstft = malloc(size);
	memmove(dstft, dst, size);
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("dst:		");
	print_arr(dst, size);

	printf("ft dst:		");
	print_arr(dstft, size);

	memmove(dst, src, size);
	ft_memmove(dstft, src, size);

	printf("src:		");
	print_arr(src, size);

	printf("dst moved:	");
	print_arr(dst, size);

	printf("ftdst moved:	");
	print_arr(dst, size);
	assert(memcmp(dst, dstft, size) == 0);

	printf("\n");
}

void test_mem_move_overlap(const char *src, const char *src2, size_t size, int offset)
{
	char *dst = (char *)(src + offset);
	char *dstft = (char *)(src2 + offset);
	memmove(dstft, dst, size - offset);
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("src:		");
	print_arr(src, size);
	printf("dst:		");
	print_arr(dst, size - offset);
	printf("\n");

	printf("src2:		");
	print_arr(src2, size);
	printf("ft dst:		");
	print_arr(dstft, size - offset);
	printf("\n");

	memmove(dst, src, size - offset);
	ft_memmove(dstft, src2, size - offset);

	printf("src:		");
	print_arr(src, size);
	printf("dst moveed:	");
	print_arr(dst, size - offset);
	printf("\n");

	printf("src2:		");
	print_arr(src2, size);
	printf("ftdst moveed:	");
	print_arr(dstft, size - offset);
	assert(memcmp(dst, dstft, size - offset) == 0);

	printf("\n");
}

int main()
{
	char src[] = {'\x00', '\x41', '\x02', '\x01', '\xf0', '\x71', '\xff', '\x7f', '\x09', '\x1f', '\x0f'};
	char src2[] = {'\x00', '\x41', '\x02', '\x01', '\xf0', '\x71', '\xff', '\x7f', '\x09', '\x1f', '\x0f'};
	test_mem_move(src, 11);
	test_mem_move(src, 5);
	test_mem_move(src, 1);
	test_mem_move(src, 0);
	const char *src0 = malloc(0);
	test_mem_move(src0, 11);
	test_mem_move(src0, 5);
	test_mem_move(src0, 1);
	test_mem_move(src0, 0);
	// const char *srcnull = NULL;
	// test_mem_move(srcnull, 11);
	// test_mem_move(srcnull, 5);
	// test_mem_move(srcnull, 1);
	// test_mem_move(srcnull, 0);
	// test_same_mem_diff_null();
	test_mem_move_overlap(src, src2, 11, 3);
}
