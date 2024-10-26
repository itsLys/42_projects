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
	printf("c value:		\'%d\'\n", c);
	printf("isalnum:		%s\n", isalnum(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", isalnum(c));
	printf("ft_isalnum:		%s\n", ft_isalnum(c) == 0 ? "FALSE" : "TRUE");
	printf("return value:		%d\n", ft_isalnum(c));
	assert(isalnum(c) == ft_isalnum(c));
	printf("\n");
	i++;
}

void isalpha_test(char *str)
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
	// i = ft_isalnum(INT_MAX - 1);
	invalid_isalnum_test(32767);
	// invalid_isalnum_test(INT_MAX); // UB: seg fault
	//	invalid_isalnum_test(INT_MIN); UB: seg fault
}
// TODO:
//
