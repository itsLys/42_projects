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

void print_arr(const void *arr, size_t size)
{

    const unsigned char *ap;
    ap = (const unsigned char *)arr;
    while (size--)
    {
        printf("%.2x, ", *(ap++));
    }
    printf("\n");
}

void test_mem_cpy(const char *src, size_t size)
{
    char *dst = malloc(size);
    char *dstft = malloc(size);
    memcpy(dstft, dst, size);
    printf("---------------------------\n");
    printf("case number: %zu\n", get_case());
    printf("dst:		");
    print_arr(dst, size);

    printf("ft dst:		");
    print_arr(dstft, size);

    memcpy(dst, src, size);
    ft_memcpy(dstft, src, size);

    printf("src:		");
    print_arr(src, size);

    printf("dst copied:	");
    print_arr(dst, size);

    printf("ftdst copied:	");
    print_arr(dst, size);
    assert(memcmp(dst, dstft, size) == 0);

    printf("\n");
}

void test_mem_cpy_overlap(const char *src, const char *src2, size_t size, int offset)
{
    char *dst = (char *)(src + offset);
    char *dstft = (char *)(src2 + offset);
    ft_memcpy(dstft, dst, size - offset);
    printf("---------------------------\n");
    printf("case number: %zu\n", get_case());
    printf("src:		");
    print_arr(src, size);
    printf("dst:		");
    print_arr(dst, size - offset);

    printf("ft dst:		");
    print_arr(dstft, size - offset);

    memcpy(dst, src, size - offset);
    ft_memcpy(dstft, src, size - offset);

    printf("src:		");
    print_arr(src, size);

    printf("dst copied:	");
    print_arr(dst, size - offset);

    printf("ftdst copied:	");
    print_arr(dst, size - offset);
    assert(memcmp(dst, dstft, size - offset) == 0);

    printf("\n");
}

int main()
{
    const char src[] = {'\x00', '\x41', '\x02', '\x01', '\xf0', '\x71', '\xff', '\x7f', '\x09', '\x1f', '\x0f'};
    const char src2[] = {'\x00', '\x41', '\x02', '\x01', '\xf0', '\x71', '\xff', '\x7f', '\x09', '\x1f', '\x0f'};
    test_mem_cpy(src, 11);
    test_mem_cpy(src, 5);
    test_mem_cpy(src, 1);
    test_mem_cpy(src, 0);
    const char *src0 = malloc(0);
    test_mem_cpy(src0, 11);
    test_mem_cpy(src0, 5);
    test_mem_cpy(src0, 1);
    test_mem_cpy(src0, 0);
    // const char *srcnull = NULL;
    // test_mem_cpy(srcnull, 11);
    // test_mem_cpy(srcnull, 5);
    // test_mem_cpy(srcnull, 1);
    // test_mem_cpy(srcnull, 0);
    // test_same_mem_diff_null();
    test_mem_cpy_overlap(src, src2, 11, 3);
}
