#include "libft.h"
#include "test.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_strdup(const char *str)
{
	char *sdup = strdup(str);
	char *ft_sdup = ft_strdup(str);
	printf("---------------------------\n");
	printf("case number: 	%zu\n", get_case());
	printf("\n");
	printf("str:		\"%s\"\n", str);
	printf("addr		\"%p\"\n", str);
	printf("\n");
	printf("strdup:		\"%s\"\n", sdup);
	printf("addr		\"%p\"\n", sdup);
	printf("\n");
	printf("ft strdup:	\"%s\"\n", ft_sdup);
	printf("addr		\"%p\"\n", ft_sdup);
	assert(memcmp(sdup, ft_sdup, strlen(str) + 1) == 0);
	free(sdup);
	free(ft_sdup);
}

int main()
{

	test_strdup("Hello");
	test_strdup("h");
	test_strdup("");
	test_strdup("Hello, How are you");
	// char *sdup = strdup(NULL);
	// char *ftsdup = strdup(NULL);
}
