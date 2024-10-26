#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned char table[255];
	int	i;
	i = 0;
	while (i < 255)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
			table[i] = 1;
		else
			table[i] = 0;
		i++;
	}
	return (table[(unsigned char)c]);
}
