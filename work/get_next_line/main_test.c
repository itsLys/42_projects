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

	int fd0 = open("f0.txt", O_RDONLY);
	int fd1 = open("f1.txt", O_RDONLY);
	int fd2 = open("f2.txt", O_RDONLY);
	int fd3 = open("f3.txt", O_RDONLY);
	int fd4 = open("f4.txt", O_RDONLY);
	int fd5 = open("f5.txt", O_RDONLY);
	int fd_non = open("ewq", O_RDONLY);

	{
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0);
		t(fd0); // threshold
		t(fd0);
		t(fd0);

	}

	{
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1);
		t(fd1); // threshold
		t(fd1);
		t(fd1);
	}

	{
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2);
		t(fd2); // threshold
		t(fd2);
		t(fd2);
	}

	{
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3);
		t(fd3); // threshold
		t(fd3);
		t(fd3);
	}

	{
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4);
		t(fd4); // threshold
		t(fd4);
		t(fd4);
	}

	{
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5);
		t(fd5); // threshold
		t(fd5);
		t(fd5);
	}

	printf("\n");
	printf("fd0:	%d\t", fd0);
	printf("fd1:	%d\t", fd1);
	printf("fd2:	%d\t", fd2);
	printf("fd3:	%d\t", fd3);
	printf("fd4:	%d\t", fd4);
	printf("fd5:	%d\t", fd5);
	printf("fd_non:	%d\t", fd_non);
}
