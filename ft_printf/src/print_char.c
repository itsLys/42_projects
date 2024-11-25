#include "ft_printf.h"

int handle_char(t_flags *f, int c)
{
	int count;

	count = 0;
	if (!f->left_adjusted)
		count += print_width(f, 1);
	count += ft_putchar_fd(c, 1); // the charachter c will be counted in the printwidth functuion
	if (f->left_adjusted)
		count += print_width(f, 1);
	return count;
}
