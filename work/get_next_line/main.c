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

void t(int fd)
{
	printf("----------------------------------------\n");
	print_gnl(get_next_line(fd));
}

int main(void)
{
	printf("BUFFER_SIZE->		%lx\n", (long unsigned) BUFFER_SIZE);
	printf("sizeof BUFFER_SIZE->	%lu\n", sizeof(BUFFER_SIZE));

	int fd0 = open("f00.txt", O_RDONLY);
	int fd1 = open("f01.txt", O_RDONLY);
	int fd2 = open("f02.txt", O_RDONLY);
	int fd3 = open("trweqrq.txt", O_RDONLY);
	int fd4 = open("trweqrq.txt", O_RDONLY);
	int fd5 = open("trweqrq.txt", O_RDONLY);
	int fd6 = open("trweqrq.txt", O_RDONLY);
	t(fd0);
	t(fd2);
	t(fd1);
	t(fd0);
	t(fd0);
	t(fd4);
	t(fd4);
	t(fd5);
	t(fd6);
	t(fd6);
	t(fd4);
	t(fd5);
	t(fd1);
	t(fd2);
	t(fd3);
	t(fd4);
	t(fd2);
	t(fd1);
	t(fd5);
	t(fd6);
	t(fd1);
	t(fd1);
	t(fd3);
	t(fd1);
}
