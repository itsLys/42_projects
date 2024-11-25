#include "ft_printf.h"
#include <stdio.h>

int handle_char(t_flags *f, int c)
{
	int count;

	count = 0;
	if (!f->left_adjusted)
		count += print_width(f, 1);
	*(f->str++) = c;
	count++;
	if (f->left_adjusted)
		count += print_width(f, 1);
	return count;
}

// char accepts only width and left alignment coupled with width
// |B|
// |         B|
// |B         |
