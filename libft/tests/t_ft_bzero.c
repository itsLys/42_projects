#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "../libft.h"

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

void test_memory_initialized(size_t size, size_t n)
{
	static int case_n = 0;
	unsigned char *buff_orig = (unsigned char *) malloc(size);
	unsigned char *buff_ft = (unsigned char *) malloc(size);
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

void test_memory_set_to_zero(size_t size, size_t n)
{
	static int case_n = 0;
	unsigned char *buff_orig = (unsigned char *) malloc(size);
	unsigned char *buff_ft = (unsigned char *) malloc(size);
	size_t i = 0;
	printf("-------------------\n");
	printf("------ test case: %d ------\n", case_n++);
	printf("Buffers initialized:\n");
	memset(buff_orig, 0, size);
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

void test_nullp(size_t n)
{
	unsigned char *buff;
	buff = NULL;
	// ft_bzero(buff, n); // seg fault
	// bzero(buff, n);
}

void test_sizemax(void)
{
	unsigned char *buff;
	buff = malloc(SIZE_MAX / 1000000000000000);
	// ft_bzero(buff, SIZE_MAX); // seg fault
	// bzero(buff, SIZE_MAX); // seg fault
	free(buff);
}

int main()
{
	// BZERO
	test_memory_initialized(10, 2);
	test_memory_initialized(10, 10);
	test_memory_initialized(2, 10);
	test_memory_initialized(0, 10);
	test_memory_initialized(10, 0);
	test_memory_initialized(0, 0);
	test_memory_initialized(10, SIZE_MAX);

	test_memory_set_to_zero(10, 2);
	test_memory_set_to_zero(10, 10);
	test_memory_set_to_zero(2, 10);
	test_memory_set_to_zero(0, 10);
	test_memory_set_to_zero(10, 0);
	test_memory_set_to_zero(0, 0);

	test_nullp(1);
}
// TODO:	[x] NULL Pointer as input
// 			[x] Zero length
// 			[x] Delete 0 bytes
// 			Memory overlap
// 			MAX_SIZE
// 			[x] Memory already zeroed
// 			Non contiguous memory block through pointer arithmetic
// 
