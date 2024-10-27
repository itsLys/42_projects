
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
//
//
//

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

void print_arr(char *arr, size_t size)
{
	while (size--)
	{
		printf("%x, ", *(arr++));
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

int main()
{
	test_memchr_find_existing();
}
