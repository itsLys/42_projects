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

void *clean_up(void *buff)
{
	free(buff);
	return (NULL);
}

char	*read_buffer(int fd, char **last)
{
	ssize_t bytes;
	char	*line;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (clean_up(*last));
	line = "";
	if (*last)
		line = *last;
	while (!ft_strchr(buff, NL))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			return (clean_up(buff));
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
			return (clean_up(buff));
	}
	free(*last);
	*last = buff;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
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
