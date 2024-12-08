#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

void	print_gnl(char *line)
{
	char *str;

	if (!line)
		str = "(NULL)\n";
	else
		str = line;
	printf("line->		%s", str);
	free(line);
}

void t(void)
{
	printf("----------------------------------------\n");
	int fd = open("f14.txt", O_RDONLY);
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
	print_gnl(get_next_line(fd));
}

int main(void)
{
	printf("BUFFER_SIZE->		%lx\n", (long unsigned) BUFFER_SIZE);
	printf("sizeof BUFFER_SIZE->	%lu\n", sizeof(BUFFER_SIZE));

	t();
}
