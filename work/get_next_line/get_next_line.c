#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char	*read_next(char **last)
{
	char *tmp;

	tmp = ft_strdup(ft_strchr(*last, NL) + 1);
	printf("\n::::deref *last	|%s|::::\n", ft_strchr(*last, NL));
	free(*last);
	*last = tmp;
	return (ft_strjoin("", *last));
}

char	*read_buffer(int fd, char **last)
{
	char 	*buffer;
	ssize_t bytes;
	char	*line;

	line = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(buffer, NL) == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	*last = buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last;
	if (ft_strchr(last, NL))
		return(read_next(&last));
	return(read_buffer(fd, &last));
}
