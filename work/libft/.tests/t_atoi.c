#include "libft.h"
#include "test.h"
#include <assert.h>
#include <stdio.h>

void test_ft_atoi(const char *str)
{
	int atoi_int = atoi(str);
	int ft_atoi_int = ft_atoi(str);
	printf("-------------------\n");
	printf("test case:	%zu\n", get_case());
	printf("str:		\"%s\"\n", str);
	printf("atoi:		%d\n", atoi_int);
	printf("ft_atoi:	%d\n", ft_atoi_int);
	assert(atoi_int == ft_atoi_int);
	printf("\n");
}

int main()
{
	test_ft_atoi("123");
	test_ft_atoi(" -456");
	test_ft_atoi("789 ");
	test_ft_atoi("		11f1");
	test_ft_atoi("-222	   ");
	test_ft_atoi("     2147483647");
	test_ft_atoi("     -2147483648	");
	test_ft_atoi("0");
	test_ft_atoi("00000");
	test_ft_atoi("-00000");
	test_ft_atoi("	 00000");
	test_ft_atoi("	 0gf0000  ");
	test_ft_atoi(" \t-456");
	test_ft_atoi("789 ");
	test_ft_atoi("		\n111");
	test_ft_atoi("-222	   ");
	test_ft_atoi("  \v -333	   ");
	test_ft_atoi("		\f\v+444f	");
	test_ft_atoi("     \r2147483647");
	test_ft_atoi("     \r214s7483647dsa");
	test_ft_atoi("     \r\f\v-2147483648	");
	test_ft_atoi("	 \f\r00000");
	test_ft_atoi("	 \t00000  ");

	// invalid input
	test_ft_atoi("     \r\f\v-d214	");
	test_ft_atoi("     \r\f\v-0000214 dsaewq	");
	test_ft_atoi("     \r\f\v-002s00214 dsaewq	");
	test_ft_atoi("    --+333	   ");
	test_ft_atoi("		---444f	");
	test_ft_atoi(" ---+--+1234ab567");
	test_ft_atoi(" \a123");
	test_ft_atoi("f123");
	test_ft_atoi(" - 123");
	test_ft_atoi("s- 123");

	test_ft_atoi("     9223372036854775807");
	test_ft_atoi("     -9223372036854775808");
	test_ft_atoi("     9223372036854775806");
	test_ft_atoi("     -9223372036854775807");
	test_ft_atoi("     -9223372036854775806");
	test_ft_atoi("     9223372036854775808");
	test_ft_atoi("     -9223372036854775809");
	test_ft_atoi("     9999999999999999999");
	test_ft_atoi("     -9999999999999999999");
	test_ft_atoi("     99999999999999999999");
	test_ft_atoi("     -99999999999999999999");
	test_ft_atoi("     999999999999999999999999");
	test_ft_atoi("     -9999999999999999999999999");
	test_ft_atoi("     18446744073709551615");
	test_ft_atoi("     184467440737095516151");
	test_ft_atoi("     -18446744073709551615");
	test_ft_atoi("     19223372036854775807");
	test_ft_atoi("     -19223372036854775808");
}
