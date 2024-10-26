#include "libft.h"

int	ft_isdigit(int c)
{
	unsigned short table[255];
	unsigned char x = c;
	int i;
	i = 0;
	while (i < 255)
	{
		if (i >= '0' && i <= '9')
			table[i] = 2048;
		else
			table[i] = 0;
		i++;
	}
	return (table[x]);
}
