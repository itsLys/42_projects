#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void *clean_up(void *buff)
{
	free(buff);
	return (NULL);
}

char	*read_buffer(int fd, char **last)
{
	ssize_t bytes;
	char	*line;
	char	*buffer;
}

char	*join_reads(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*line;

	total_size = count_len(s1) + count_len(s2);
	line = malloc(total_size + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line_append(s1, line);
	line_append(s2, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	if (ft_strchr(last, NL))
	{
		shift_left(&last);
	}
	return(read_buffer(fd, &last));
}

//	declare static var
//	check if it contains a newline
//	if it does
//		change it to point to past the newline
//		give it to the reading function so that it can read new
//	   read and append it to the prev
