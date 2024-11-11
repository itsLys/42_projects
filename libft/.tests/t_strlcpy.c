#include "libft.h"
#include "test.h"
#include <assert.h>
#include <bsd/string.h>
#include <limits.h>
#include <stdio.h>

void test_strlcpy(const char *str, size_t size)
{
	char buf[20] = "Hello";
	char ftbuf[20] = "Hello";
	size_t strlcpyr = strlcpy(buf, str, size);
	size_t ftstrlcpyr = ft_strlcpy(ftbuf, str, size);

	printf("---------------------------\n");
	printf("case number: 	%zu\n", get_case());
	printf("\n");
	printf("src:		\"%s\"\n", str);
	printf("\n");
	printf("strlcpy:	\"%s\"\n", buf);
	printf("value:		%zu\n", strlcpyr);
	printf("\n");
	printf("ft_strlcpy:	\"%s\"\n", ftbuf);
	printf("value:		%zu\n", ftstrlcpyr);
	assert(memcmp(buf, ftbuf, size) == 0);
	assert(strlcpyr == ftstrlcpyr);
}

int main()
{
	char src[20] = "BRO:";
	char dest[20] = "Hello";
	test_strlcpy(" World", 20);
	test_strlcpy(" WWWWWWWWWorld", 14);
	test_strlcpy(" World", 2);
	test_strlcpy(" W", 1);
	test_strlcpy("", 0);
	size_t slcpy = strlcat(NULL, src, 0);
	size_t ftslcpy = ft_strlcat(NULL, src, 0);
	// slcpy = strlcat(NULL, src, 1);
	// ftslcpy = ft_strlcat(NULL, src, 1);
	// slcpy = strlcat(dest, NULL, 0);
	// ftslcpy = ft_strlcat(dest, NULL, 0);
	// slcpy = strlcat(NULL, NULL, 0);
	// ftslcpy = ft_strlcat(NULL, NULL, 0);
}
