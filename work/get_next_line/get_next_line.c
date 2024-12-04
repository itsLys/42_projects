#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

char	*read_line(int fd, char *last)
{
	char	*line;
	size_t	buff_size;
	ssize_t	bytes_read;

	line = NULL;
	buff_size = BUFFER_SIZE;
	if (buff_size > MAX_READ)
		buff_size = MAX_READ;
	last = malloc(buff_size + 1);
	while (find_char(last, '\n'))
	{
		bytes_read = read(fd, line, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(last);
			return NULL;
		}
		last[bytes_read] = '\0';
		line = ft_strjoin(line, last);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*line;


	if (fd < 0 || fd > MAX_FD|| BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, last);
	return (line);
}
/////////////////////////////

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	printf("str->	%s\n", get_next_line(fd));
	printf("str->	%s\n", get_next_line(fd));
	printf("str->	%s\n", get_next_line(fd));
}
