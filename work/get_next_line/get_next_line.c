#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char	*read_line(int fd, char **last)
{
	char *buffer;
	ssize_t bytes;
	char	*line;

	line = NULL;
	buffer = malloc(BUFFER_SIZE);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	while (ft_strchr(buffer, NL) == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
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
	char *line;

	if (ft_strchr(last, '\n'))
	{

	}
	line = read_line(fd, &last);
	printf("last start ->> %s <<- last end|\n", last);
	return();
}
// before reading a line, check the last read buffer if it has lines that should be returned
