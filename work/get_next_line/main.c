#include "get_next_line.h"

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	// printf("str->	%s", get_next_line(fd));
	// printf("str->	%s", get_next_line(fd));
	// printf("str->	%s", get_next_line(fd));
	// printf("str->	%s", get_next_line(fd));
	// printf("str->	%s", get_next_line(fd));
	// printf("str->	%s", get_next_line(fd));
}
