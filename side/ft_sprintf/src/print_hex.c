#include "ft_printf.h"
#include <stdio.h>
#define BASE 16
#include <stdlib.h>

int print_hex_digits(unsigned int x, t_flags *f, int len, char* hexdigits)
{
	char *buff;
	int count;
	int i;

	count = 0;
	i = 0;
	if (!x && f->precision_flag && !f->precision_value)
		return (0);
	if (!x)
		return ft_putchar_fd('0', 1);
	buff = malloc(len);
	while (len--)
	{
		buff[i++] = hexdigits[x % BASE];
		x /= BASE;
	}
	if (f->alt_form)
	{
		buff[i-2] = hexdigits[BASE];
		buff[i-1] = '0';
	}
	while (i-- > 0)
		count += ft_putchar_fd(buff[i], 1);
	free(buff);
	return count;
}

int print_hexadecimal(unsigned int x, t_flags *f, int len, char c)
{
	int count;
	char *hexdigits;

	count = 0;
	if (c == 'x')
		hexdigits = "0123456789abcdefx";
	else
		hexdigits = "0123456789ABCDEFX";
	if (f->precision_value > len)
		len = f->precision_value;
	if (f->alt_form)
		len += 2;
	if (f->zero_padded && f->width > len)
		len = f->width;
	else
		if (!f->left_adjusted)
		count = print_width(f, len);
	count += print_hex_digits(x, f, len, hexdigits);
	if (f->left_adjusted)
		count += print_width(f, len);
	return count;
}

int	handle_hex(unsigned int x, t_flags *f, char c)
{
	int count;
	int numlen;
	numlen = get_num_len(x, 16);
	count = print_hexadecimal(x, f, numlen, c);
	return (count);
}
