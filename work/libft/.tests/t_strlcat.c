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
	size_t strlcatr = strlcat(buf, str, size);
	size_t ftstrlcatr = ft_strlcat(ftbuf, str, size);

	printf("---------------------------\n");
	printf("case number: 	%zu\n", get_case());
	printf("\n");
	printf("src:		\"%s\"\n", str);
	printf("\n");
	printf("strlcat:	\"%s\"\n", buf);
	printf("value:		%zu\n", strlcatr);
	printf("\n");
	printf("ft_strlcat:	\"%s\"\n", ftbuf);
	printf("value:		%zu\n", ftstrlcatr);
	assert(memcmp(buf, ftbuf, size) == 0);
	assert(strlcatr == ftstrlcatr);
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
	size_t slcat = strlcat(NULL, src, 0);
	size_t ftslcat = ft_strlcat(NULL, src, 0);
	// slcat = strlcat(NULL, src, 1);
	// ftslcat = ft_strlcat(NULL, src, 1);
	// slcat = strlcat(dest, NULL, 0);
	// ftslcat = ft_strlcat(dest, NULL, 0);
	// slcat = strlcat(NULL, NULL, 0);
	// ftslcat = ft_strlcat(NULL, NULL, 0);
}
// buffer[20];