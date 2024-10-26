#include "libft.h"

int	ft_isascii(int c)
{
	unsigned char table[255];
	unsigned char x = c;
	int	i;
	i = 0;
	while (i < 255)
	{
		if (i >= 0 && i <= 127)
			table[i] = 1;
		else
			table[i] = 0;
		i++;
	}
	return (table[x]);
}
