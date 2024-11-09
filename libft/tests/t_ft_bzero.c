#include "libft.h"
#include "test.h"

void test_bzero(size_t size, size_t n)
{
	unsigned char *buff = (unsigned char *)malloc(size);
	unsigned char *buff_ft = (unsigned char *)malloc(size);
	size_t i = 0;
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("size:		%zu\n", size);
	printf("n:		%zu\n", n);
	printf("Initializing buffers:\n");
	memset(buff, 0xff, size);
	memset(buff_ft, 0xff, size);

	printf("buff original:\t");
	print_bytes(buff, size);
	printf("buff ft:\t");
	print_bytes(buff_ft, size);

	printf("Bzero applied:\n");
	bzero(buff, n);
	ft_bzero(buff_ft, n);

	printf("buff original:\t");
	print_bytes(buff, size);
	printf("buff ft:\t");
	print_bytes(buff_ft, size);

	assert(memcmp(buff, buff_ft, size) == 0);
	free(buff);
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
	ft_bzero(NULL, 0);
	bzero(NULL, 0);
}
