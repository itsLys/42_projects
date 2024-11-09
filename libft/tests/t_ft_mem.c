#include "libft.h"
#include "test.h"
#include <stdio.h>
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
	unsigned char buff[11] = {'\x00', '\x10', '\x20', '\x30', '\x40', '\x50', '\x60', '\x70', '\x80', '\x90', '\xa0'};
	unsigned char find[7] = {'\x00', '\x01', '\xf0', '\x30', '\x7f', '\x1f', '\xa0'};
	printf("---------------------------\n");
	printf("case:	%zu\n", get_case());
	while ()
}

int main()
{
}
