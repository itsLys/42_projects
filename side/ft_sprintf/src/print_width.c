#include "ft_printf.h"
#include <stdio.h>

// n number of the characters that are already printed or to be printed;
int print_width(t_flags *f, int n)
{
	int count = 0;
	while (f->width - n > 0)
	{
		if (f->zero_padded)
			*(f->str++) = '0';
		else
			*(f->str++) = ' ';
		f->width--;
		count++;
	}
	return count;
}
