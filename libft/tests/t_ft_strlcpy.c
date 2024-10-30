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

void test_strlcpy_enough_size(const char *str)
{
    char dst_str[] = "Hello, ";
    size_t dst_size = strlen(str) + 1;

    char *slcpy_dst = malloc(dst_size);
    strcpy(slcpy_dst, dst_str);
    size_t slcpy_value = strlcpy(slcpy_dst, str, dst_size);

    char *ft_slcpy_dst = malloc(strlen(dst_str) + 1);
    strcpy(ft_slcpy_dst, dst_str);
    size_t ft_slcpy_value = ft_strlcpy(ft_slcpy_dst, str, dst_size);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcpy:	\"%s\"\n", slcpy_dst);
    printf("value:		\"%zu\"\n", slcpy_value);
    printf("addr		\"%p\"\n", slcpy_dst);
    printf("\n");
    printf("ft_strlcpy:	\"%s\"\n", ft_slcpy_dst);
    printf("value:		\"%zu\"\n", ft_slcpy_value);
    printf("addr		\"%p\"\n", ft_slcpy_dst);
    assert(memcmp(slcpy_dst, ft_slcpy_dst, dst_size) == 0);
    assert(slcpy_value == ft_slcpy_value);
}

void test_strlcpy_notenough_size(const char *str)
{
    char dst_str[] = "Hello, ";
    size_t dst_size = 3;

    char *slcpy_dst = malloc(dst_size);
    strcpy(slcpy_dst, dst_str);
    size_t slcpy_value = strlcpy(slcpy_dst, str, dst_size);

    char *ft_slcpy_dst = malloc(strlen(dst_str) + 1);
    strcpy(ft_slcpy_dst, dst_str);
    size_t ft_slcpy_value = ft_strlcpy(ft_slcpy_dst, str, dst_size);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcpy:	\"%s\"\n", slcpy_dst);
    printf("value:		\"%zu\"\n", slcpy_value);
    printf("addr		\"%p\"\n", slcpy_dst);
    printf("\n");
    printf("ft_strlcpy:	\"%s\"\n", ft_slcpy_dst);
    printf("value:		\"%zu\"\n", ft_slcpy_value);
    printf("addr		\"%p\"\n", ft_slcpy_dst);
    assert(memcmp(slcpy_dst, ft_slcpy_dst, dst_size) == 0);
    assert(slcpy_value == ft_slcpy_value);
}

void test_strlcpy_size0(const char *str)
{
    char dst_str[] = "Hello, ";
    size_t dst_size = 0;

    char *slcpy_dst = malloc(dst_size);
    strcpy(slcpy_dst, dst_str);
    size_t slcpy_value = strlcpy(slcpy_dst, str, dst_size);

    char *ft_slcpy_dst = malloc(strlen(dst_str) + 1);
    strcpy(ft_slcpy_dst, dst_str);
    size_t ft_slcpy_value = ft_strlcpy(ft_slcpy_dst, str, dst_size);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcpy:	\"%s\"\n", slcpy_dst);
    printf("value:		\"%zu\"\n", slcpy_value);
    printf("addr		\"%p\"\n", slcpy_dst);
    printf("\n");
    printf("ft_strlcpy:	\"%s\"\n", ft_slcpy_dst);
    printf("value:		\"%zu\"\n", ft_slcpy_value);
    printf("addr		\"%p\"\n", ft_slcpy_dst);
    assert(memcmp(slcpy_dst, ft_slcpy_dst, dst_size) == 0);
    assert(slcpy_value == ft_slcpy_value);
}

void test_strlcpy_size1(const char *str)
{
    char dst_str[] = "Hello, ";
    size_t dst_size = 1;

    char *slcpy_dst = malloc(dst_size);
    strcpy(slcpy_dst, dst_str);
    size_t slcpy_value = strlcpy(slcpy_dst, str, dst_size);

    char *ft_slcpy_dst = malloc(strlen(dst_str) + 1);
    strcpy(ft_slcpy_dst, dst_str);
    size_t ft_slcpy_value = ft_strlcpy(ft_slcpy_dst, str, dst_size);

    printf("---------------------------\n");
    printf("case number: 	%zu\n", get_case());
    printf("\n");
    printf("str:		\"%s\"\n", str);
    printf("addr		\"%p\"\n", str);
    printf("\n");
    printf("strlcpy:	\"%s\"\n", slcpy_dst);
    printf("value:		\"%zu\"\n", slcpy_value);
    printf("addr		\"%p\"\n", slcpy_dst);
    printf("\n");
    printf("ft_strlcpy:	\"%s\"\n", ft_slcpy_dst);
    printf("value:		\"%zu\"\n", ft_slcpy_value);
    printf("addr		\"%p\"\n", ft_slcpy_dst);
    assert(memcmp(slcpy_dst, ft_slcpy_dst, dst_size) == 0);
    assert(slcpy_value == ft_slcpy_value);
}

int main()
{
    test_strlcpy_enough_size("World");
    test_strlcpy_enough_size("Hello  World!");
    test_strlcpy_enough_size("Hel,,,,,,lo  twqeWorld!");
    test_strlcpy_enough_size("c");
    test_strlcpy_enough_size("");

    test_strlcpy_notenough_size("World");
    test_strlcpy_notenough_size("Hello  World!");
    test_strlcpy_notenough_size("Hel,,,,,,lo  twqeWorld!");
    test_strlcpy_notenough_size("c");
    test_strlcpy_notenough_size("");

    test_strlcpy_size0("World");
    test_strlcpy_size0("Hello  World!");
    test_strlcpy_size0("Hel,,,,,,lo  twqeWorld!");
    test_strlcpy_size0("c");
    test_strlcpy_size0("");

    test_strlcpy_size1("World");
    test_strlcpy_size1("Hello  World!");
    test_strlcpy_size1("Hel,,,,,,lo  twqeWorld!");
    test_strlcpy_size1("c");
    test_strlcpy_size1("");
}
