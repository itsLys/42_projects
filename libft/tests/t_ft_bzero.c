#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void print_buff(void *buff_orig, void *buff_ft, size_t size)
{
	int i = 0;
	printf("buff original:\t");
	while (i < size)
		printf("%x, ", ((unsigned char *)buff_orig)[i++]);
	printf("\n");

	i = 0;
	printf("buff ft:\t");
	while (i < size)
		printf("%x, ", ((unsigned char *)buff_ft)[i++]);
	printf("\n");
}

void test_bzero(size_t size, size_t n)
{
	static int case_n = 0;
	unsigned char *buff_orig = (unsigned char *)malloc(size);
	unsigned char *buff_ft = (unsigned char *)malloc(size);
	size_t i = 0;
	printf("-------------------\n");
	printf("------ test case: %d ------\n", case_n++);
	printf("Buffers initialized:\n");
	memset(buff_orig, 0xff, size);
	memcpy(buff_ft, buff_orig, size);
	print_buff(buff_orig, buff_ft, size);
	printf("\n");
	printf("Bzero applied:\n");
	bzero(buff_orig, n);
	ft_bzero(buff_ft, n);
	print_buff(buff_orig, buff_ft, size);
	assert(memcmp(buff_orig, buff_ft, size) == 0);
	free(buff_orig);
	free(buff_ft);
}

int main()
{
	// BZERO
	test_bzero(10, 2);
	test_bzero(10, 10);
	test_bzero(2, 10);
	test_bzero(0, 10);
	test_bzero(10, 0);
	test_bzero(0, 0);
}
