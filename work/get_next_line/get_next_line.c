#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *extract_line(char **last)
{
	char *tmp;

	tmp = dup_until(find_chr(*last, NL) + 1, 0);
	free(*last);
	*last = tmp;
	if (find_chr(tmp, NL))
		return (dup_until(*last, NL));
	return (NULL);
	
}

char	*read_buffer(int fd, char **last)
{
	ssize_t bytes;
	char	*line;
	char	*buffer;
	
	buffer = malloc(BUFFER_SIZE + 1);
	line = *last;
	if (!buffer)
		return (NULL);
	while (!find_chr(buffer, NL))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(*last);
			return (NULL);
		}
		buffer[bytes] = 0;
		line = join_reads(line, buffer);
		if (!line)
		{
			free(buffer);
			free(*last);
			return (NULL);
		}
		if (bytes == 0)
			break;
	}
	*last = buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char *line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	if (find_chr(last, NL))
		line = extract_line(&last);
	if (line)
		return (line);
	line = read_buffer(fd, &last);
	return(line);
}

//	declare static var
//	check if it contains a newline
//	if it does
//		change it to point to past the newline
//		give it to the reading function so that it can read new
//	   read and append it to the prev
