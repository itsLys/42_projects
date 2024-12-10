#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

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
	int fd = open("f6.txt", O_RDONLY);

	t(fd);
	t(fd);
	t(fd);
	t(fd);


}
