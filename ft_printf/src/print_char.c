#include "ft_printf.h"

int print_char(int c, t_flags *f)
{
	int count;

	count = 0;
	if (f->left_adjusted)
		count += print_width(f);
}
