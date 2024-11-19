#include "ft_printf.h"

int print_char(int c, t_flags *f)
{
	int count;

	count = 0;
	if (f->left_adjusted)
	{
		ft_putchar_fd(c, 1);
		count += print_width(f, 1);
	}
}
