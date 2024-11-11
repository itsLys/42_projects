#include "libft.h"
#include "test.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void print_list(char **list)
{
	printf("[");
	if (!list)
		printf("(null)");
	else
		while (*list)
		{
			printf("\"%s\"", *(list++));
			if (*list)
				printf(", ");
		}
	printf("]\n");
}

void test_split(const char *s, char c, char **exp)
{
	char **str = ft_split(s, c);
	size_t i = 0;
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("source:			\"%s\"\n", s);
	printf("delimeter:		'%c'\n", c);
	printf("expected:		");
	print_list(exp);
	printf("ft_split:		");
	print_list(str);
	printf("\n");
	if (exp)
	{
		while (str[i])
		{
			assert(strcmp(str[i], exp[i]) == 0);
			i++;
		}
	}
	// free(str);
}

// void print_bytes(const void *p, size_t n)
// {
// 	char *sp = (char *)p;
// 	while (n--)
// 	{
// 		printf("%p\n", sp);
// 		printf("%d\n", *(sp++));
// 	}
// }
int main()
{
	test_split("Hello World", '\0', (char *[]){"Hello World", NULL});
	test_split("          ", ' ', (char *[]){"", NULL});
	test_split("Hello World", 0, (char *[]){"Hello World", NULL});
	test_split(NULL, '\0', NULL);
	test_split(NULL, 'd', NULL);
	test_split(" ", ' ', (char *[]){"", NULL});
	test_split("             d           ", ' ', (char *[]){"d", NULL});
	test_split("", ' ', (char *[]){"", NULL});
	test_split("d", 'd', (char *[]){"", NULL});
	test_split("dddddddd", 'd', (char *[]){"", NULL});
	test_split("ddddsssdddsssdddsddd", 's', (char *[]){"dddd", "ddd", "ddd", "ddd", NULL});
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
	// ft_split((int *)0x9000999999, 0);
}
