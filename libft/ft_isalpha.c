#include "libft.h"

int	ft_isalpha(int c)
{
	unsigned short table[255];
	size_t i;

	i = 0;
	while (i < 255)
	{
		if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
			table[i] = 1024;
		else
			table[i] = 0;
		i++;
	}
	return (table[c]);
}
