#include "../libft.h"
#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

size_t get_case()
{
	static size_t i = 0;
	return (i++);
}

int main()
{
	ssize_t fd = open("txt.txt", O_RDWR);
	if (fd == -1)
		exit(EXIT_FAILURE);
	ft_putchar_fd('c', fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Hello", fd);
	ft_putendl_fd("World!", fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(1, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-1, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(321, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-654, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(100000, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);
}
