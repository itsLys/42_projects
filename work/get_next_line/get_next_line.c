#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char	*read_line(int fd, char *last)
{
	char *buffer = malloc(BUFFER_SIZE);

	ssize_t bytes = read(fd, last, BUFFER_SIZE);

}

char	*get_next_line(int fd)
{
	static char	*last;
	read_line(fd, last);
	printf("last->	|%s|\n", last);
}
// before reading a line, check the last read buffer if it has lines that should be returned
