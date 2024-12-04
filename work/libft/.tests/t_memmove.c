#include "libft.h"
#include "test.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_mem_move(unsigned char *src1, int offset, size_t size)
{
	unsigned char *s = malloc(size);
	unsigned char *fts = malloc(size);
	unsigned char *dst;
	unsigned char *ftdst;
	memcpy(s, src1, size);
	memcpy(fts, src1, size);
	dst = s + offset;
	ftdst = fts + offset;
	printf("---------------------------\n");
	printf("case number:	%zu\n", get_case());
	printf("size:		%zu\n", size);
	printf("s1:		");
	print_bytes(s, size);
	printf("s2:		");
	print_bytes(fts, size);
	printf("dst:		");
	print_bytes(dst, size);
	printf("ftdst:		");
	print_bytes(ftdst, size);

	memmove(dst, s, size);
	ft_memmove(ftdst, fts, size);

	printf("MOVED\n");
	printf("dst:		");
	print_bytes(dst, size);
	printf("ftdst:		");
	print_bytes(ftdst, size);
	assert(memcmp(dst, ftdst, size) == 0);

	// free(dst);
	// free(ftdst);
	printf("\n");
	// free(s + offset);
	// free(fts + offset);
}

int main()
{

	unsigned char buff[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							  '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};

	// unsigned char buff2[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
	// 						   '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	test_mem_move(buff, 3, 10);
	test_mem_move(buff, 0, 13);
	test_mem_move(buff, -3, 15);
	test_mem_move(buff, 8, 7);
	test_mem_move(buff, 1, 2);
	test_mem_move(buff, 0, 1);
	test_mem_move(buff, 9, 0);

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
