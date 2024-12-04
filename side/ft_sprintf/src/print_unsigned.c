#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#define BASE 10

int print_unsigned_digits(unsigned num, t_flags *f, int len)
{
	char *buff;
	int count;
	int i;

	count = 0;
	i = 0;
	if (!num && f->precision_flag && !f->precision_value)
		return (0);
	buff = malloc(len);
	while (len--)
	{
		buff[i++] = "0123456789"[num % BASE];
		num /= BASE;
	}
	while (i-- > 0)
		count += ft_putchar_fd(buff[i], 1);
	free(buff);
	return (count);
}

int print_unsigned(unsigned num, t_flags *f, int len)
{
	int	count;

	count = 0;
	if (f->precision_value > len)
		len = f->precision_value;
	if (!f->left_adjusted)
		count = print_width(f, len);
	count += print_unsigned_digits(num, f, len);
	if (f->left_adjusted)
		count += print_width(f, len);
	return (count);
}

int handle_unsigned(unsigned int u, t_flags *f)
{
	int count;
	int numlen;
	numlen = get_num_len(u, 10);
	count = print_unsigned(u, f, numlen);
	return (count);
}
