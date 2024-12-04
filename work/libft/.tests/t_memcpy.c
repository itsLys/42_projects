#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <string.h>

void test_mem_cpy(const unsigned char *src, size_t size)
{
	unsigned char buff[7] = {'\x00', '\x01', '\xf0', '\x30', '\x7f', '\x1f', '\xa0'};
	unsigned char *dst = malloc(size);
	unsigned char *ftdst = malloc(size);
	memcpy(dst, buff, size);
	memcpy(ftdst, buff, size);
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());

	printf("size:		%zu\n", size);
	printf("src:		");
	print_bytes(src, 7);
	printf("dst:		");
	print_bytes(dst, size);
	printf("ft dst:		");
	print_bytes(ftdst, size);

	memcpy(dst, src, size);
	ft_memcpy(ftdst, src, size);

	printf("dst copied:	");
	print_bytes(dst, size);
	printf("ftdst copied:	");
	print_bytes(dst, size);
	assert(memcmp(dst, ftdst, size) == 0);

	free(dst);
	free(ftdst);
	printf("\n");
}

int main()
{

	unsigned char buff[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							  '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	test_mem_cpy(buff, 10);
	test_mem_cpy(buff, 13);
	test_mem_cpy(buff, 15);
	test_mem_cpy(buff, 7);
	test_mem_cpy(buff, 2);
	test_mem_cpy(buff, 1);
	test_mem_cpy(buff, 0);

	void *p = memcpy(NULL, NULL, 0);
	printf("memcpy:		size == 0\n\t\tdest == src == NULL:\t%p\n", p);
	p = memcpy(NULL, NULL, 4);
	printf("memcpy:		size == 4\n\t\tdest == src == NULL:\t%p\n", p);
	p = memcpy(NULL, buff, 0);
	printf("memcpy:		size == 0\n\t\tdest == NULL:\t\t%p\n", p);
	p = memcpy(buff, NULL, 0);
	printf("memcpy:		size == 0\n\t\tsrc == NULL:\t\t%p\n", p);
	// p = memcpy(NULL, buff, 4);
	// printf("memcpy:		size == 4\n\t\tdest == NULL: %p\n", p);
	// p = memcpy(buff, NULL, 4);
	// printf("memcpy:		size == 4\n\t\tsrc == NULL: %p\n", p);

	void *ftp = ft_memcpy(NULL, NULL, 0);
	printf("ft_memcpy:		size == 0\n\t\tdest == src == NULL:\t%p\n", p);
	ftp = ft_memcpy(NULL, NULL, 4);
	printf("ft_memcpy:		size == 4\n\t\tdest == src == NULL:\t%p\n", p);
	ftp = ft_memcpy(NULL, buff, 0);
	printf("ft_memcpy:		size == 0\n\t\tdest == NULL:\t\t%p\n", p);
	ftp = ft_memcpy(buff, NULL, 0);
	printf("ft_memcpy:		size == 0\n\t\tsrc == NULL:\t\t%p\n", p);
	// ftp = ft_memcpy(NULL, buff, 4);
	// printf("ft_memcpy:		size == 4\n\t\tdest == NULL: %p\n", p);
	// ftp = ft_memcpy(buff, NULL, 4);
	// printf("ft_memcpy:		size == 4\n\t\tsrc == NULL: %p\n", p);
}
