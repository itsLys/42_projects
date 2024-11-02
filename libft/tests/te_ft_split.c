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

void print_list(char **list)
{
	printf("[");
	while (*list)
	{
		printf("\"%s\"", *(list++));
		if (*list)
			printf(", ");
	}
	printf("]\n");
}

static const char *skip_delim(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return s;
}

static const char *skip_word(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return s;
}

static size_t count_words(const char *s, char c)
{
	size_t count;

	count = 0;
	while (*s)
	{
		s = skip_delim(s, c);
		if (*s)
			count++;
		s = skip_word(s, c);
	}
	return (count);
}

// int print_err(char **s, char **x, size_t i)
// {
//     printf("assertion failed\n");
//     printf("s: %s\n", *s);
//     printf("x: %s\n", *s);
//     printf("i: %zu\n", i);
//     return 1;
// }

void test_split(const char *s, char c, char **exp)
{
	char **str = ft_split(s, c);
	size_t wc = count_words(s, c);
	size_t i = 0;
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("source:			\"%s\"\n", s);
	printf("delimeter:		'%c'\n", c);
	printf("expected:		");
	// printf("%s:::::::::\n", *(exp + 2));
	print_list(exp);
	printf("ft_split:		");
	print_list(str);
	printf("\n");
	while (str[i])
	{
		assert(strcmp(str[i], exp[i]) == 0);
		i++;
	}
	free(str);
}

int main()
{

	test_split("Hello World", '\0', (char *[]){"Hello World", NULL});
	test_split(" ", ' ', (char *[]){"", NULL});
	test_split("             d           ", ' ', (char *[]){"d", NULL});
	test_split("", ' ', (char *[]){"", NULL});
	test_split("d", 'd', (char *[]){"", NULL});
	test_split("dddddddd", 'd', (char *[]){"", NULL});
	test_split("dddsssdddsssdddsddd", 's', (char *[]){"ddd", "ddd", "ddd", "ddd", NULL});
	test_split("Hello World", ' ', (char *[]){"Hello", "World", NULL});
	test_split("Hello World", ' ', (char *[]){"Hello", "World", NULL});
	test_split("This is a test", ' ', (char *[]){"This", "is", "a", "test", NULL});
	test_split("One,Two,Three", ',', (char *[]){"One", "Two", "Three", NULL});
	test_split("C;C++;C#", ';', (char *[]){"C", "C++", "C#", NULL});
	test_split("apple;banana;cherry", ';', (char *[]){"apple", "banana", "cherry", NULL});
	test_split("2021-12-31", '-', (char *[]){"2021", "12", "31", NULL});
	test_split("split|this|string", '|', (char *[]){"split", "this", "string", NULL});
	test_split("  leading and trailing  ", ' ', (char *[]){"leading", "and", "trailing", NULL});
	test_split("singleword", ' ', (char *[]){"singleword", NULL});
	test_split("abc,,,def", ',', (char *[]){"abc", "def", NULL});
}
