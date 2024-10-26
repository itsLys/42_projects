#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void valid_isalnum_test(char *str)
{
	static unsigned is_case = 0;
	int i = 0;
	int c;
	while (i < strlen(str))
	{
		c = str[i];
		printf("---------------------------\n");
		printf("isalnum case:	%d\n", is_case++);
		printf("character:		\'%c\'\n", c);
		printf("value:			\'%d\'\n", c);
		printf("isalnum:		%s\n", isalnum(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", isalnum(c));
		printf("ft_isalnum:		%s\n", ft_isalnum(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_isalnum(c));
		assert(isalnum(c) == ft_isalnum(c));
		printf("\n");
		i++;
	}
}

void invalid_isalnum_test(int c)
{
	static unsigned is_case = 0;
	int i = 0;
	printf("---------------------------\n");
	printf("invalid isalnum case:	%d\n", is_case++);
	printf("c value:		\'%x\'\n", c);
	printf("isalnum:		%s\n", isalnum(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", isalnum(c));
	printf("ft_isalnum:		%s\n", ft_isalnum(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", ft_isalnum(c));
	assert(isalnum(c) == ft_isalnum(c));
	printf("\n");
	i++;
}

void valid_isalpha_test(char *str)
{
	static unsigned is_case = 0;
	int i = 0;
	int c;
	while (str[i])
	{
		c = str[i];
		printf("---------------------------\n");
		printf("isalpha case:		%d\n", is_case++);
		printf("character:		\'%c\'\n", c);
		printf("isalpha:		%s\n", isalpha(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", isalpha(c));
		printf("ft_isalpha:		%s\n", ft_isalpha(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_isalpha(c));
		assert(isalpha(c) == ft_isalpha(c));
		printf("\n");
		i++;
	}
}

void invalid_isalpha_test(int c)
{
	static unsigned is_case = 0;
	int i = 0;
	printf("---------------------------\n");
	printf("invalid isalpha case:	%d\n", is_case++);
	printf("c value:		\'%x\'\n", c);
	printf("isalpha:		%s\n", isalpha(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", isalpha(c));
	printf("ft_isalpha:		%s\n", ft_isalpha(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", ft_isalpha(c));
	assert(isalpha(c) == ft_isalpha(c));
	printf("\n");
	i++;
}

void valid_isdigit_test(char *str)
{
	static unsigned is_case = 0;
	int i = 0;
	int c;
	while (str[i])
	{
		c = str[i];
		printf("---------------------------\n");
		printf("isdigit case:		%d\n", is_case++);
		printf("character:		\'%c\'\n", c);
		printf("isdigit:		%s\n", isdigit(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", isdigit(c));
		printf("ft_isdigit:		%s\n", ft_isdigit(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_isdigit(c));
		assert(isdigit(c) == ft_isdigit(c));
		printf("\n");
		i++;
	}
}

void invalid_isdigit_test(int c)
{
	static unsigned is_case = 0;
	int i = 0;
	printf("---------------------------\n");
	printf("invalid isdigit case:	%d\n", is_case++);
	printf("c value:		\'%x\'\n", c);
	printf("isdigit:		%s\n", isdigit(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", isdigit(c));
	printf("ft_isdigit:		%s\n", ft_isdigit(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", ft_isdigit(c));
	assert(isdigit(c) == ft_isdigit(c));
	printf("\n");
	i++;
}

void valid_isascii_test(char *str)
{
	static unsigned is_case = 0;
	int i = 0;
	int c;
	while (str[i])
	{
		c = str[i];
		printf("---------------------------\n");
		printf("isascii case:		%d\n", is_case++);
		printf("character:		\'%c\'\n", c);
		printf("isascii:		%s\n", isascii(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", isascii(c));
		printf("ft_isascii:		%s\n", ft_isascii(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_isascii(c));
		assert(isascii(c) == ft_isascii(c));
		printf("\n");
		i++;
	}
}

void invalid_isascii_test(int c)
{
	static unsigned is_case = 0;
	int i = 0;
	printf("---------------------------\n");
	printf("invalid isascii case:	%d\n", is_case++);
	printf("c value:		\'%x\'\n", c);
	printf("isascii:		%s\n", isascii(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", isascii(c));
	printf("ft_isascii:		%s\n", ft_isascii(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", ft_isascii(c));
	assert(isascii(c) == ft_isascii(c));
	printf("\n");
	i++;
}

void valid_isprint_test(char *str)
{
	static unsigned is_case = 0;
	int i = 0;
	int c;
	while (str[i])
	{
		c = str[i];
		printf("---------------------------\n");
		printf("isprint case:		%d\n", is_case++);
		printf("character:		\'%c\'\n", c);
		printf("isprint:		%s\n", isprint(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", isprint(c));
		printf("ft_isprint:		%s\n", ft_isprint(c) == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_isprint(c));
		assert(isprint(c) == ft_isprint(c));
		printf("\n");
		i++;
	}
}

void invalid_isprint_test(int c)
{
	static unsigned is_case = 0;
	int i = 0;
	printf("---------------------------\n");
	printf("invalid isprint case:	%d\n", is_case++);
	printf("c value:		\'%x\'\n", c);
	printf("isprint:		%s\n", isprint(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", isprint(c));
	printf("ft_isprint:		%s\n", ft_isprint(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", ft_isprint(c));
	assert(isprint(c) == ft_isprint(c));
	printf("\n");
	i++;
}

int main()
{
	char upper_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lower_alpha[] = "abcdefghijklmnopqrstuvwxyz";
	char digits[] = "0123456789";
	char ascii[256];
	int i = 0;
	while (i < 255)
	{
		ascii[i] = i;
		i++;
	}
	ascii[i] = '\0';
	valid_isalnum_test(upper_alpha);
	valid_isalnum_test(lower_alpha);
	valid_isalnum_test(digits);
	valid_isalnum_test(ascii);

	invalid_isalnum_test(0);
	invalid_isalnum_test(-1);

	valid_isalpha_test(upper_alpha);
	valid_isalpha_test(lower_alpha);
	valid_isalpha_test(digits);
	valid_isalpha_test(ascii);

	invalid_isalpha_test(0);
	invalid_isalpha_test(-1);

	valid_isdigit_test(upper_alpha);
	valid_isdigit_test(lower_alpha);
	valid_isdigit_test(digits);
	valid_isdigit_test(ascii);

	invalid_isdigit_test(0);
	invalid_isdigit_test(-1);

	valid_isascii_test(upper_alpha);
	valid_isascii_test(lower_alpha);
	valid_isascii_test(digits);
	valid_isascii_test(ascii);

	invalid_isascii_test(0);
	invalid_isascii_test(-1);

	valid_isprint_test(upper_alpha);
	valid_isprint_test(lower_alpha);
	valid_isprint_test(digits);
	valid_isprint_test(ascii);

	invalid_isprint_test(0);
	invalid_isprint_test(-1);
}
// TODO:
//
