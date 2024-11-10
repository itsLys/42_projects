#include "libft.h"
#include "test.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_strlen(const char *str)
{

	size_t slen = strlen(str);
	size_t ft_slen = ft_strlen(str);
	printf("---------------------------\n");
	printf("case number: 	%zu\n", get_case());
	printf("\n");
	printf("str:		\"%s\"\n", str);
	printf("addr		\"%p\"\n", str);
	printf("\n");
	printf("strlen:		\"%zu\"\n", slen);
	printf("\n");
	printf("ft_strlen:	\"%zu\"\n", slen);
	printf("\n");
	assert(slen == ft_slen);
}

int main()
{
	test_strlen("World");
	test_strlen("Hello  World!");
	test_strlen("Hel,,,,,,lo  twqeWorld!");
	test_strlen("c");
	test_strlen("");
	// size_t slen = strlen(NULL);
	// size_t ftslen = ft_strlen(NULL);
}
