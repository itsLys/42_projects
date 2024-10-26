#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c >= '\t' && c <= '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long n;
	long prev;
	int sign;


	n = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr && (*nptr == '-' || *nptr == '+'))
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		prev = n;
		n = (*(nptr++) - '0') + n * 10;
		if (n < prev)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
	}
	return (n * sign);
}
