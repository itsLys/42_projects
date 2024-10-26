#include "libft.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_ft_atoi(const char *str)
{
	static int atoi_case = 0;
	int atoi_int = atoi(str);
	int ft_atoi_int = ft_atoi(str);
	printf("-------------------\n");
	printf("test case:	%d\n", atoi_case++);
	printf("str:		\"%s\"\n", str);
	printf("atoi:		%d\n", atoi_int);
	printf("ft_atoi:	%d\n", ft_atoi_int);
	assert(atoi_int == ft_atoi_int);
	printf("\n");
}

void test_ft_bzero_uc(size_t alloc, size_t del)
{
	static int bzero_case = 0;
	unsigned char *buff_orig = (unsigned char *) malloc(alloc);
	unsigned char *buff_ft = (unsigned char *) malloc(alloc);
	size_t i = 0;
	memset(buff_orig, 5, alloc);
	memset(buff_ft, 5, alloc);
	printf("-------------------\n");
	printf("test case:	%d\n", bzero_case++);

	printf("buff orig: \n");
	while (i < alloc)
		printf("%d, ", buff_orig[i++]);
	printf("\n");

	i = 0;
	printf("buff ft: \n");
	while (i < alloc)
		printf("%d, ", buff_ft[i++]);
	printf("\n");

	bzero(buff_orig, del);
	ft_bzero(buff_ft, del);

	i = 0;
	printf("bzero buff orig: \n");
	while (i < alloc)
		printf("%d, ", buff_orig[i++]);
	printf("\n");

	i = 0;
	printf("ft bzero buff ft: \n");
	while (i < alloc)
		printf("%d, ", buff_ft[i++]);
	printf("\n");
	assert(memcmp(buff_orig, buff_ft, alloc) == 0);

	free(buff_orig);
	free(buff_ft);
}


void test_ft_bzero_ui(size_t alloc, size_t del)
{
	static int bzero_case = 0;
	unsigned int *buff_orig = (unsigned int *) malloc(alloc * sizeof(int));
	unsigned int *buff_ft = (unsigned int *) malloc(alloc * sizeof(int));
	size_t i = 0;
	memset(buff_orig, 5, alloc * sizeof(int));
	memset(buff_ft, 5, alloc * sizeof(int));
	printf("-------------------\n");
	printf("test case:	%d\n", bzero_case++);

	printf("buff orig: \n");
	while (i < alloc)
		printf("%d, ", buff_orig[i++]);
	printf("\n");

	i = 0;
	printf("buff ft: \n");
	while (i < alloc)
		printf("%d, ", buff_ft[i++]);
	printf("\n");

	bzero(buff_orig, del);
	ft_bzero(buff_ft, del);

	i = 0;
	printf("bzero buff orig: \n");
	while (i < alloc)
		printf("%d, ", buff_orig[i++]);
	printf("\n");

	i = 0;
	printf("ft bzero buff ft: \n");
	while (i < alloc)
		printf("%d, ", buff_ft[i++]);
	printf("\n");
	assert(memcmp(buff_orig, buff_ft, alloc) == 0);

	free(buff_orig);
	free(buff_ft);
}

void test_ft_calloc(size_t nmemb)
{
	static int calloc_case = 0;
	unsigned char *buff_orig = (unsigned char *) calloc(nmemb, 1);
	unsigned char *buff_ft = (unsigned char *) ft_calloc(nmemb, 1);
	size_t i = 0;
	printf("-------------------\n");
	printf("test case:	%d\n", calloc_case++);

	printf("buff orig: \n");
	while (i < nmemb)
		printf("%d, ", buff_orig[i++]);
	printf("\n");

	i = 0;
	printf("buff ft: \n");
	while (i < nmemb)
		printf("%d, ", buff_ft[i++]);
	printf("\n");
	assert(memcmp(buff_orig, buff_ft, nmemb) == 0);

	free(buff_orig);
	free(buff_ft);
}

int main()
{
	// ATOI
	test_ft_atoi("123");
	test_ft_atoi(" -456");
	test_ft_atoi("789 ");
	test_ft_atoi("		111");
	test_ft_atoi("-222	   ");
	test_ft_atoi("    --+333	   ");
	test_ft_atoi("		---444f	");
	test_ft_atoi("     2147483647");
	test_ft_atoi("     -2147483648	");
	test_ft_atoi(" ---+--+1234ab567");
	test_ft_atoi("0");
	test_ft_atoi("00000");
	test_ft_atoi("-00000");
	test_ft_atoi("	 00000");
	test_ft_atoi("	 00000  ");
	test_ft_atoi(" \t-456");
	test_ft_atoi("789 ");
	test_ft_atoi("		\n111");
	test_ft_atoi("-222	   ");
	test_ft_atoi("  \v --+333	   ");
	test_ft_atoi("		\f\v---444f	");
	test_ft_atoi("     \r2147483647");
	test_ft_atoi("     \r\f\v-2147483648	");
	test_ft_atoi(" ---+--+1234ab567");
	test_ft_atoi("0");
	test_ft_atoi("00000");
	test_ft_atoi("-00000");
	test_ft_atoi("	 00000");
	test_ft_atoi("	 00000  ");

	// invalid input
	test_ft_atoi("f123");
	test_ft_atoi(" - 123");
	test_ft_atoi("s- 123");

	// BZERO
	test_ft_bzero_uc(4, 4);
	test_ft_bzero_uc(4, 2);
	test_ft_bzero_uc(2, 4);
	test_ft_bzero_uc(0, 4);
	test_ft_bzero_uc(4, 0);
	test_ft_bzero_uc(0, 0);


	test_ft_bzero_ui(4, 4);
	test_ft_bzero_ui(4, 2);
	test_ft_bzero_ui(2, 4);
	test_ft_bzero_ui(0, 4);
	test_ft_bzero_ui(4, 0);
	test_ft_bzero_ui(0, 0);


	test_ft_calloc(3);
	test_ft_calloc(4);
	test_ft_calloc(1);
	test_ft_calloc(0);
	// test_ft_calloc(-1);
}
