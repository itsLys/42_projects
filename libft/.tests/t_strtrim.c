#include "libft.h"
#include "test.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

void test_strtrim(const char *s, const char *set, const char *exp)
{
	char *str = ft_strtrim(s, set);
	printf("---------------------------\n");
	printf("case number:		%zu\n", get_case());
	printf("source:			\"%s\"\n", s);
	printf("charset:		\"%s\"\n", set);
	printf("expected:		\"%s\"\n", exp);
	printf("ft_strtrim:		\"%s\"\n", str);
	printf("\n");
	if (s && set)
		assert(strcmp(str, exp) == 0);
	free(str);
}

int main()
{
	test_strtrim(" Hello World ", " ", "Hello World");
	test_strtrim("xyzHello Worldzxy", "yzx", "Hello World");
	test_strtrim("Hello World", "yzx", "Hello World");
	test_strtrim("Hello World", "", "Hello World");
	test_strtrim("Hello World", "Hello World", "");
	test_strtrim(" Hello World ", " ", "Hello World");
	test_strtrim("!!Hello World!!", "!", "Hello World");
	test_strtrim("*Hello*", "*", "Hello");
	test_strtrim("#Test#", "#", "Test");
	test_strtrim("###Hello###", "#", "Hello");

	// Multiple character charset
	test_strtrim("  !!Hello World!!  ", " !", "Hello World");
	test_strtrim("**Hello World**", "* ", "Hello World");
	test_strtrim("??Hello World??", "? ", "Hello World");
	test_strtrim("%%Hello World%%", "% ", "Hello World");
	test_strtrim("~~Hello~~", "~", "Hello");

	// Mixed cases
	test_strtrim("  !!**Hello World**!!  ", " !*", "Hello World");
	test_strtrim("##Hello World##", "# ", "Hello World");
	test_strtrim("$$$Hello$$$", "$", "Hello");
	test_strtrim("~~~Hello~~~", "~", "Hello");

	// Edge cases
	test_strtrim("", " ", "");
	test_strtrim("", "", "");
	test_strtrim(" ", " ", "");
	test_strtrim("     ", " ", "");
	test_strtrim("!!", "!", "");
	test_strtrim(NULL, "!", "");
	test_strtrim("dsa", NULL, "");
	test_strtrim(NULL, NULL, "");

	// Special characters and unicode
	test_strtrim("\tHello World\t", "\t", "Hello World");
	test_strtrim("🌍🌍Hello World🌍🌍", "🌍", "Hello World");
	test_strtrim("😊Hello😊", "😊", "Hello");
	test_strtrim("  @#%Hello$%^  ", " @#$%^", "Hello");
}
