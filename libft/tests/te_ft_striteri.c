#include "libft.h"
#include "test.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void test_striteri(const char *s, void (*f)(unsigned int, char *), const char *exp)
{
	char *str;
	if (s)
	{
		str = malloc(strlen(s));
		strcpy(str, s);
	}
	else
		str = NULL;

	ft_striteri(str, f);
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("source:			\"%s\"\n", s);
	printf("expected:		\"%s\"\n", exp);
	printf("ft striteri:		\"%s\"\n", str);
	printf("\n");
	if (s)
		assert(strcmp(str, exp) == 0);
}
void vowel_toupper(unsigned int i, char *c)
{
	if (strchr("aeiou", *c))
		*c = toupper(*c);
}

int main()
{
	test_striteri("Hello World", vowel_toupper, "HEllO WOrld");
	test_striteri("abcdefg", vowel_toupper, "AbcdEfg");
	test_striteri("aeiou", vowel_toupper, "AEIOU");
	test_striteri("bcdf", vowel_toupper, "bcdf");
	test_striteri("$%#", vowel_toupper, "$%#");
	test_striteri(NULL, vowel_toupper, NULL);
}
