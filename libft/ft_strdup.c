#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;

	dup = malloc (sizeof(char) * (ft_strlen(s) + 1));
	return (ft_strcpy(dup, s));
}
