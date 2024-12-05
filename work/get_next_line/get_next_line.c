#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	read_next(char **last)
{
	char *tmp;

	tmp = ft_strdup(ft_strchr(*last, NL) + 1);
	free(*last);
	*last = tmp;
}

char	*read_buffer(int fd, char **last)
{
	ssize_t bytes;
	char	*line;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (*last)
		line = ft_strdup(*last);
	else
		line = ft_strdup("");
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
	free(*last);
	*last = buffer;
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*last;

	if (ft_strchr(last, NL))
		read_next(&last);
	return(read_buffer(fd, &last));
}

//	declare static var
//	check if it contains a newline
//	if it does
//		change it to point to past the newline
//		give it to the reading function so that it can read new
//	   read and append it to the prev
