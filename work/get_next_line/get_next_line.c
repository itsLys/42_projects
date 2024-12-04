#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char	*read_line(int fd, char *last)
{
	char	*line;
	ssize_t	bytes_read;

	last = malloc(BUFFER_SIZE + 1);
	if (!last)
		return NULL;
	while (ft_strchr(last, NL) == NULL)
	{
		bytes_read = read(fd, last, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(last);
			return NULL;
		}
		printf("last:::::	%s\n", last);
		last[bytes_read] = '\0';
		line = ft_strjoin(line, last);
	}
	return line;
}

char	*get_next_line(int fd)
{
	static char	*last;
	char *line;
	printf("LAST:::::%s\n", last);

	if (fd < 0 || fd > MAX_FD|| BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, last);
	return (line);
}
// before reading a line, check the last read buffer if it has lines that should be returned
