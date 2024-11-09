#include "libft.h"
#include "test.h"
#include <stdio.h>
#include <string.h>
// The memchr() function scans the initial n bytes of the memory area
// pointed to by s for the first instance of c.  Both c
// and the bytes of the memory area pointed to by s are interpreted as unsigned char.

// to the matching byte or NULL if the character does not  occur  in
// the given memory area.
// void	*ft_memchr(const void *s, int c, size_t n)
//

void test_memchr()
{
	size_t i = 0;
	void *ft_p;
	void *p;
	unsigned char buff[13] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60',
							  '\x70', '\x80', '\x90', '\xa0', '\xb0', '\xc0'};
	unsigned char find[7] = {'\x00', '\x01', '\xf0', '\x30', '\x7f', '\x1f', '\xa0'};
	while (i < 7)
	{
		printf("---------------------------\n");
		printf("case:		%zu\n", get_case());
		printf("Buffer:		");
		print_bytes(buff, 11);
		printf("To find:	%.2x\n", find[i]);
		printf("memchr:		%p\n", p = memchr(buff, find[i], 11));
		printf("ft_memchr:	%p\n", ft_p = ft_memchr(buff, find[i], 11));
		assert(p == ft_p && "Adresses are not equal");
		i++;
	}
}

int main()
{
	test_memchr();
	void *p = memchr(NULL, 3, 0);
	void *ftp = ft_memchr(NULL, 3, 0);
	// p = memchr(NULL, 3, 1);
	// ftp = ft_memchr(NULL, 3, 1);
}
