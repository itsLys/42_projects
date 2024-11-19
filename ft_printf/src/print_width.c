#include "ft_printf.h"

// n number of the characters that are already printed or to be printed;
int print_width(int n, t_flags *f)
{
	int count = 0;
	while (f->width - n > 0)
	{
		if (f->zero_padded)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		f->width--;
		count++;
	}
	return count;
}
