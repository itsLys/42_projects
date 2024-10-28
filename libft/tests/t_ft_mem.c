#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE1 10
#define SIZE2 100
#define SIZE3 1
#define SIZE4 2
#define SIZE5 0

// The memchr() function scans the initial n bytes of the memory area
// pointed to by s for the first instance of c.  Both c
// and the bytes of the memory area pointed to by s are interpreted as unsigned char.

// to the matching byte or NULL if the character does not  occur  in
// the given memory area.
// void	*ft_memchr(const void *s, int c, size_t n)
//
// TODO:
// 	search the whole array for an existing byte
// 		in the first, in the middle, in the end
// 	search the whole array for a on-existing byte
// 	search a part of the array for an existing byte in that part
// 	search a part of the array for an existing byte after that part
// 	search a part of the array for an non-existing byte
//	search an array with n = 0
//	search an array with size = 0 and n > 0
//	search an array with n = 0 and size = 0

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void print_arr(void *arr, size_t size)
{

	unsigned char *ap;
	ap = (unsigned char *) arr;
	while (size--)
	{
		printf("%x, ", *(ap++));
	}
}

void test_memchr_find_existing()
{
	char buff[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	char find[] = {'\x00', '\x01', '\xf0', '\xff', '\x7f', '\x1f', '\x0f'};
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 11)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 11);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 11);
			pft = ft_memchr(buff, find[j], 11);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_find_existing_uc()
{
	unsigned char buff[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	unsigned char find[] = {'\x00', '\x01', '\xf0', '\xff', '\x7f', '\x1f', '\x0f'};
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 11)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 11);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 11);
			pft = ft_memchr(buff, find[j], 11);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_find_existing_int()
{
	unsigned char buff[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	unsigned char find[] = {'\x00', '\x01', '\xf0', '\xff', '\x7f', '\x1f', '\x0f'};
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 11)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 11);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 11 * 4);
			pft = ft_memchr(buff, find[j], 11 * 4);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_find_existing_uint()
{
	unsigned char buff[] = {'\x00', '\x41','\x02','\x01', '\xf0', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	unsigned char find[] = {'\x00', '\x01', '\xf0', '\xff', '\x7f', '\x1f', '\x0f'};
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 11)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 11);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 11 * 4);
			pft = ft_memchr(buff, find[j], 11 * 4);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_find_nonexisting()
{
	char buff[] = {'\x00', '\x41','\xf2','\xf3', '\xf0', '\x71','\xff', '\x7f', '\x09','\x9f', '\xaf'};
	char find[] = {'\x01', '\x02', '\x30', '\x6f', '\x1f', '\x6f', '\x0f'};
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 11)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 11);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 11);
			pft = ft_memchr(buff, find[j], 11);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_find_part()
{
	char buff[] = {'\x00', '\x41','\x02','\x01', '\xff', '\x71','\xff', '\x7f', '\x09','\x1f', '\x0f'};
	char find[] = {'\x00', '\x01', '\xf0', '\xff', '\x7f', '\x1f', '\x0f'};
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 5)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 5);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 5);
			pft = ft_memchr(buff, find[j], 5);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_s0n0()
{
	char buff[0];
	char find[0];
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 5)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 0);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 0);
			pft = ft_memchr(buff, find[j], 0);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_s0()
{
	char buff[0];
	char find[0];
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 5)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 0);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 5);
			pft = ft_memchr(buff, find[j], 5);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

void test_memchr_s0()
{
	char buff[0];
	char find[0];
	size_t i = 0;
	size_t j = 0;
	void *porig;
	void *pft;
	while (i < 5)
	{
		while (j < 7)
		{
			printf("---------------------------\n");
			printf("case number: %zu\n", get_case());
			printf("array: ");
			print_arr(buff, 0);
			printf("\n");
			printf("byte to find %xu\n", find[j]);
			porig = memchr(buff, find[j], 5);
			pft = ft_memchr(buff, find[j], 5);
			printf("pointer orig: %p\n", porig);
			printf("pointer ft: %p\n", pft);
			assert(porig == pft);
			printf("\n");
			j++;
		}
		i++;
	}
}

int main()
{
	test_memchr_find_existing();
	test_memchr_find_existing_uc();
	test_memchr_find_existing_uint();
	test_memchr_find_nonexisting();
	test_memchr_find_part();
	test_memchr_s0n0();
}
