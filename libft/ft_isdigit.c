#include "libft.h"

int	ft_isdigit(int c)
{
	unsigned char table[255];
	int i;
	i = 0;
	while (i < 255)
	{
		if (i >= '0' && i <= '9')
			table[i] = 1;
		else
			table[i] = 0;
		i++;
	}
	return (table[(unsigned char) c]);
}
