#include "../libft.h"
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void valid_is_test(char *str, size_t size)
{
	static unsigned is_case = 0;
	int i = 0;
	int c;
	int is_aln_c, is_alp_c, is_dig_c, is_asc_c, is_prnt_c;
	int ft_is_aln_c, ft_is_alp_c, ft_is_dig_c, ft_is_asc_c, ft_is_prnt_c;
	while (i < size)
	{
		c = str[i];
		is_aln_c = isalnum(c);
		is_alp_c = isalpha(c);
		is_dig_c = isdigit(c);
		is_asc_c = isascii(c);
		is_prnt_c = isprint(c);

		ft_is_aln_c = ft_isalnum(c);
		ft_is_alp_c = ft_isalpha(c);
		ft_is_dig_c = ft_isdigit(c);
		ft_is_asc_c = ft_isascii(c);
		ft_is_prnt_c = ft_isprint(c);

		printf("---------------------------\n");
		printf("case:	%zu\n", get_case());
		printf("character:		\'%c\'\n", c);
		printf("value:			%d\n", c);

		printf("\n");
		printf("isalnum:		%s\n", is_aln_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", is_aln_c);
		printf("ft_isalnum:		%s\n", ft_is_aln_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_is_aln_c);
		assert((!is_aln_c && !ft_is_aln_c) || (is_aln_c && ft_is_aln_c));
		printf("\n");

		printf("isalpha:		%s\n", is_alp_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", is_alp_c);
		printf("ft_isalpha:		%s\n", ft_is_aln_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_is_aln_c);
		assert((!is_alp_c && !ft_is_alp_c) || (is_alp_c && ft_is_alp_c));
		printf("\n");

		printf("isdigit:		%s\n", is_dig_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", is_dig_c);
		printf("ft_isdigit:		%s\n", ft_is_dig_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_is_dig_c);
		assert((!is_dig_c && !ft_is_dig_c) || (is_dig_c && ft_is_dig_c));
		printf("\n");

		printf("isascii:		%s\n", is_asc_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", is_asc_c);
		printf("ft_isascii:		%s\n", ft_is_asc_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_is_asc_c);
		assert((!is_asc_c && !ft_is_asc_c) || (is_asc_c && ft_is_asc_c));
		printf("\n");

		printf("isprint:		%s\n", is_prnt_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", is_prnt_c);
		printf("ft_isprint:		%s\n", ft_is_prnt_c == 0 ? "FALSE" : "TRUE");
		printf("return value:	%d\n", ft_is_prnt_c);
		assert((!is_prnt_c && !ft_is_prnt_c) || (is_prnt_c && ft_is_prnt_c));
		printf("\n");
		i++;
	}
}

int main()
{
	char upper_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char lower_alpha[] = "abcdefghijklmnopqrstuvwxyz";
	char digits[] = "0123456789";
	char ascii[255];
	int i = 0;
	while (i < 255)
	{
		ascii[i] = i;
		i++;
	}
	valid_is_test(upper_alpha, strlen(upper_alpha));
	valid_is_test(lower_alpha, strlen(lower_alpha));
	valid_is_test(digits, strlen(digits));
	valid_is_test(ascii, 255);
}
// TODO:
