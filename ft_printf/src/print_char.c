#include "ft_printf.h"

int print_char(int c, t_flags *f)
{
	int count;

	count = 0;
	if (!f->left_adjusted)
		count += print_width(f, 1);
	ft_putchar_fd(c, 1); // the charachter c will be counted in the printwidth functuion
	if (f->left_adjusted)
		count += print_width(f, 1);
	return count;
}
