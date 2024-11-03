#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void test_substr(const char *s, unsigned int i, size_t len, const char *exp)
{
	char *str = ft_substr(s, i, len);
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("source:			%s\n", s);
	printf("index:			%u\n", i);
	printf("lenght:			%zu\n", len);
	printf("expected:		\"%s\"\n", exp);
	printf("ft_substr:		\"%s\"\n", str);
	printf("\n");
	assert(strcmp(str, exp) == 0);
	free(str);
}

int main()
{
	test_substr("Hello World", 0, 5, "Hello");
	test_substr("Hello World", 0, 0, "");
	test_substr("Hello World", 5, 0, "");
	test_substr("Hello World", 1, 1, "e");
	test_substr("Hello World", 1, 10, "ello World");
	test_substr("Hello World", 1, 100, "ello World");
	test_substr("Hello World", 1, 9, "ello Worl");
	test_substr("Hello World", 6, 5, "World");
	test_substr("OpenAI GPT", 0, 4, "Open");
	test_substr("OpenAI GPT", 5, 3, "I G");
	test_substr("Hello", 0, 5, "Hello");
	test_substr("Hello", 0, 10, "Hello");
	test_substr("Hello", 5, 5, "");
	test_substr("Hello", 10, 5, "");
	test_substr("", 0, 5, "");
	test_substr("abcdefg", 2, 0, "");
	test_substr("abcdefg", -1, 3, "");
	test_substr("abcdefg", 2, 10, "cdefg");
	test_substr("abcdefg", 3, 2, "de");
	test_substr("   Hello   ", 0, 3, "   ");
	test_substr("   Hello   ", 3, 5, "Hello");
	test_substr("   Hello   ", 8, 3, "   ");
	test_substr("!@#$%^&*()", 0, 5, "!@#$%");
	test_substr("!@#$%^&*()", 3, 4, "$%^&");
	char long_string[1001];
	memset(long_string, 'x', 1000);
	long_string[1000] = '\0'; // Null-terminate
	test_substr(long_string, 0, 1000, long_string);
	test_substr("Hello World", 6, 10, "World");
	test_substr("Hello", 1, 1, "e");
	test_substr("Hello", 4, 1, "o");
	test_substr(NULL, 4, 1, "");

	return 0;
}
