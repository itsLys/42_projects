#include "get_next_line.h"
#include <stdio.h>

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

// char *extract_line(char *last)
// {
// 	char *line;
//
// 	while (*last != '\n')
// 		last++;
// 	line = ft_strjoin(line, ++last);
//
// 	return line;
// }

char	*get_next_line(int fd)
{
	static char	*last;
	char		*line;

	if (last)
	{
		while (*last && *last != '\n')
			last++;
		if (*last == NL)
			last++;
	}
	printf("addr->>	%p\n", last);
	printf("str->>	%s\n", last);
	return(read_line(fd, &last));
}
// before reading a line, check the last read buffer if it has lines that should be returned
