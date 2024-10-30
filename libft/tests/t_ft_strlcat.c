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

void test_strlcat_enough_size(const char *str)
{
	char dst_str[] = "Hello, ";
	size_t dst_size = strlen(str) + strlen(dst_str) + 1;
	
	char *slcat_dst = malloc(dst_size);
	strcpy(slcat_dst, dst_str);
	size_t slcat_value = strlcat(slcat_dst, str, dst_size);

	char *ft_slcat_dst = malloc(strlen(dst_str) + 1);
	strcpy(ft_slcat_dst, dst_str);
	size_t ft_slcat_value = ft_strlcat(ft_slcat_dst, str, dst_size);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcat:	\"%s\"\n", slcat_dst);
    printf("value:		\"%zu\"\n", slcat_value);
    printf("addr		\"%p\"\n", slcat_dst);
    printf("\n");
    printf("ft_strlcat:	\"%s\"\n", ft_slcat_dst);
    printf("value:		\"%zu\"\n", ft_slcat_value);
    printf("addr		\"%p\"\n", ft_slcat_dst);
    assert(memcmp(slcat_dst, ft_slcat_dst, dst_size) == 0);
	assert(slcat_value == ft_slcat_value);
}

void test_strlcat_not_enough_size(const char *str)
{
	char dst_str[] = "Hello, ";
	size_t dst_size = strlen(str) - 3 + strlen(dst_str) + 1;
	
	char *slcat_dst = malloc(dst_size);
	strcpy(slcat_dst, dst_str);
	size_t slcat_value = strlcat(slcat_dst, str, dst_size);

	char *ft_slcat_dst = malloc(strlen(dst_str) + 1);
	strcpy(ft_slcat_dst, dst_str);
	size_t ft_slcat_value = ft_strlcat(ft_slcat_dst, str, dst_size);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcat:	\"%s\"\n", slcat_dst);
    printf("value:		\"%zu\"\n", slcat_value);
    printf("addr		\"%p\"\n", slcat_dst);
    printf("\n");
    printf("ft_strlcat:	\"%s\"\n", ft_slcat_dst);
    printf("value:		\"%zu\"\n", ft_slcat_value);
    printf("addr		\"%p\"\n", ft_slcat_dst);
    assert(memcmp(slcat_dst, ft_slcat_dst, dst_size) == 0);
	assert(slcat_value == ft_slcat_value);
}

void test_strlcat_size0(const char *str)
{
	char dst_str[] = "Hello, ";
	size_t dst_size = strlen(str) - 3 + strlen(dst_str) + 1;
	
	char *slcat_dst = malloc(dst_size);
	strcpy(slcat_dst, dst_str);
	size_t slcat_value = strlcat(slcat_dst, str, 0);

	char *ft_slcat_dst = malloc(strlen(dst_str) + 1);
	strcpy(ft_slcat_dst, dst_str);
	size_t ft_slcat_value = ft_strlcat(ft_slcat_dst, str, 0);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcat:	\"%s\"\n", slcat_dst);
    printf("value:		\"%zu\"\n", slcat_value);
    printf("addr		\"%p\"\n", slcat_dst);
    printf("\n");
    printf("ft_strlcat:	\"%s\"\n", ft_slcat_dst);
    printf("value:		\"%zu\"\n", ft_slcat_value);
    printf("addr		\"%p\"\n", ft_slcat_dst);
    assert(memcmp(slcat_dst, ft_slcat_dst, dst_size) == 0);
	assert(slcat_value == ft_slcat_value);
}

void test_strlcat_srcempty(const char *str)
{
	char dst_str[] = "";
	size_t dst_size = strlen(dst_str) + 1;
	
	char *slcat_dst = malloc(dst_size);
	strcpy(slcat_dst, dst_str);
	size_t slcat_value = strlcat(slcat_dst, str, 0);

	char *ft_slcat_dst = malloc(strlen(dst_str) + 1);
	strcpy(ft_slcat_dst, dst_str);
	size_t ft_slcat_value = ft_strlcat(ft_slcat_dst, str, 0);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcat:	\"%s\"\n", slcat_dst);
    printf("value:		\"%zu\"\n", slcat_value);
    printf("addr		\"%p\"\n", slcat_dst);
    printf("\n");
    printf("ft_strlcat:	\"%s\"\n", ft_slcat_dst);
    printf("value:		\"%zu\"\n", ft_slcat_value);
    printf("addr		\"%p\"\n", ft_slcat_dst);
    assert(memcmp(slcat_dst, ft_slcat_dst, dst_size) == 0);
	assert(slcat_value == ft_slcat_value);
}

int main()
{
	test_strlcat_enough_size("World");
	test_strlcat_enough_size("WWWWWWWWWorld");
	test_strlcat_enough_size("W");
	test_strlcat_enough_size("");

	test_strlcat_not_enough_size("World");
	test_strlcat_not_enough_size("WWWWWWWWWorld");
	test_strlcat_not_enough_size("W");
	test_strlcat_not_enough_size("");

	test_strlcat_size0("World");
	test_strlcat_size0("WWWWWWWWWorld");
	test_strlcat_size0("W");
	test_strlcat_size0("");

	test_strlcat_srcempty("World");
	test_strlcat_srcempty("WWWWWWWWWorld");
	test_strlcat_srcempty("W");
	test_strlcat_srcempty("");

}
