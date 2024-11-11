#include "libft.h"
#include "test.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_strmapi(const char *s, char (*f)(unsigned int, char), const char *exp)
{
	char *str = ft_strmapi(s, f);
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("source:			\"%s\"\n", s);
	printf("expected:		\"%s\"\n", exp);
	printf("ft strmapi:		\"%s\"\n", str);
	printf("\n");
	if (s && f)
		assert(strcmp(str, exp) == 0);
	free(str);
}
char vowel_toupper(unsigned int i, char c)
{
	return (strchr("aeiou", c)) ? toupper(c) : c;
}

int main()
{
	test_strmapi("abcdefg", vowel_toupper, "AbcdEfg");
	test_strmapi("aeiou", vowel_toupper, "AEIOU");
	test_strmapi("bcdf", vowel_toupper, "bcdf");
	test_strmapi("$%#", vowel_toupper, "$%#");
	test_strmapi("$%#", NULL, NULL);
	test_strmapi("Hello World", NULL, NULL);
	test_strmapi(NULL, vowel_toupper, NULL);
	test_strmapi(NULL, NULL, NULL);
}
