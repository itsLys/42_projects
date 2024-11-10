#include "libft.h"
#include "test.h"

void test_memset(unsigned char *src, size_t size, int byte)
{
	unsigned char *dst = malloc(size);
	unsigned char *dstft = malloc(size);
	memcpy(dst, src, size);
	memcpy(dstft, src, size);
	printf("---------------------------\n");
	printf("case number: %zu\n", get_case());
	printf("dst:		");
	print_bytes(dst, size);

	printf("ft dst:		");
	print_bytes(dstft, size);

	memset(dst, byte, size);
	ft_memset(dstft, byte, size);

	printf("src:		");
	print_bytes(src, size);

	printf("dst setd:	");
	print_bytes(dst, size);

	printf("ftdst setd:	");
	print_bytes(dstft, size);
	assert(memcmp(dst, dstft, size) == 0);

	printf("\n");
	free(dst);
	free(dstft);
}

int main()
{

	unsigned char buff[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							  '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	char byte = 0xaf;
	test_memset(buff, 11, byte);
	test_memset(buff, 5, byte);
	test_memset(buff, 1, byte);
	test_memset(buff, 0, byte);
	void *p = memset(NULL, byte, 0);
	printf("memset:		size == 0\n\t\tdest == NULL:\t%p\n", p);
	// p = memset(NULL, byte, 4);
	// printf("memset:		size == 0\n\t\tdest == NULL:\t%p\n", p);
	void *ftp = ft_memset(NULL, byte, 0);
	printf("ft_memset:	size == 0\n\t\tdest == NULL:\t%p\n", p);
	// p = memset(NULL, byte, 4);
	// printf("memset:		size == 0\n\t\tdest == NULL:\t%p\n", p);
}
