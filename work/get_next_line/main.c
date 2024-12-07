#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	printf("BUFFER_SIZE->		%d\n", BUFFER_SIZE);
	printf("sizeof BUFFER_SIZE->	%lu\n", sizeof(BUFFER_SIZE));

	int fd = open("file2.txt", O_RDWR);
	write(fd, "Sorem ipsum dolor sit amet, consectetur adipiscing elit.\nSed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\nThis is the last line without a newline", strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nSed do eiusmod tempor incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\nDuis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.\nExcepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\nThis is the last line without a newline"));
	lseek(fd, 0, SEEK_SET);
	char *line;
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	printf("str->	%s", (line = get_next_line(fd)) != NULL ? line : "(null)\n");
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
}
