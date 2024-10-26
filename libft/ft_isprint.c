#include "libft.h"

int	ft_isprint(int c)
{
	unsigned short table[255];
	unsigned char x = c;
	int i;
	i = 0;
	while (i < 255)
	{
		if (i >= ' ' && i <= 127)
			table[i] = 16384;
		else
			table[i] = 0;
		i++;
	}
	return (table[x]);
}
