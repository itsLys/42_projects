#include "libft.h"
#include "test.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_mem_move(unsigned char *src1, unsigned char *src2, int offset, size_t size)
{
	unsigned char *dst = src1 + offset;
	unsigned char *ftdst = src2 + offset;
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());

	printf("size:		%zu\n", size);
	printf("src1:		");
	print_bytes(src1, size);
	printf("src2:		");
	print_bytes(src2, size);
	printf("dst:		");
	print_bytes(dst, size);
	printf("ft dst:		");
	print_bytes(ftdst, size);

	memmove(dst, src1, size);
	ft_memmove(ftdst, src2, size);

	printf("dst moved:	");
	print_bytes(dst, size);
	printf("ftdst moved:	");
	print_bytes(ftdst, size);
	assert(memcmp(dst, ftdst, size) == 0);

	// free(dst);
	// free(ftdst);
	printf("\n");
}

int main()
{

	unsigned char buff[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							  '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};

	unsigned char buff2[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							   '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	test_mem_move(buff, buff2, 3, 10);
	test_mem_move(buff, buff2, 0, 13);
	test_mem_move(buff, buff2, -3, 15);
	test_mem_move(buff, buff2, 7, 7);
	test_mem_move(buff, buff2, 1, 2);
	test_mem_move(buff, buff2, 0, 1);
	test_mem_move(buff, buff2, 9, 0);

	void *p = memmove(NULL, NULL, 0);
	printf("memmove:		size == 0\n\t\tdest == src == NULL:\t%p\n", p);
	p = memmove(NULL, NULL, 4);
	printf("memmove:		size == 4\n\t\tdest == src == NULL:\t%p\n", p);
	p = memmove(NULL, buff, 0);
	printf("memmove:		size == 0\n\t\tdest == NULL:\t\t%p\n", p);
	p = memmove(buff, NULL, 0);
	printf("memmove:		size == 0\n\t\tsrc == NULL:\t\t%p\n", p);
	// p = memmove(NULL, buff, 4);
	// printf("memmove:		size == 4\n\t\tdest == NULL: %p\n", p);
	// p = memmove(buff, NULL, 4);
	// printf("memmove:		size == 4\n\t\tsrc == NULL: %p\n", p);

	void *ftp = ft_memmove(NULL, NULL, 0);
	printf("ft_memmove:		size == 0\n\t\tdest == src == NULL:\t%p\n", p);
	ftp = ft_memmove(NULL, NULL, 4);
	printf("ft_memmove:		size == 4\n\t\tdest == src == NULL:\t%p\n", p);
	ftp = ft_memmove(NULL, buff, 0);
	printf("ft_memmove:		size == 0\n\t\tdest == NULL:\t\t%p\n", p);
	ftp = ft_memmove(buff, NULL, 0);
	printf("ft_memmove:		size == 0\n\t\tsrc == NULL:\t\t%p\n", p);
	// ftp = ft_memmove(NULL, buff, 4);
	// printf("ft_memmove:		size == 4\n\t\tdest == NULL: %p\n", p);
	// ftp = ft_memmove(buff, NULL, 4);
	// printf("ft_memmove:		size == 4\n\t\tsrc == NULL: %p\n", p);
}
