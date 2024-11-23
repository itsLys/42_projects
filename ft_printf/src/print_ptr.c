#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#define BASE 16

int print_addr_digits(unsigned long long addr, t_flags *f, int n)
{
	char *buff;
	char *hexdigits;
	int count;
	int i;

	count = 0;
	i = 0;
	hexdigits = "0123456789abcdef"; // used it 1 time, remove
	if (f->precision_value > n)
		n = f->precision_value;
	buff = malloc(n);
	while (n--)
	{
		buff[i] = hexdigits[addr % BASE];
		i++;
		addr /= BASE;
	}
	buff[i++] = 'x';
	buff[i++] = '0';
	while (i-- > 0)
		count += ft_putchar_fd(buff[i], 1);
	free(buff);
	return (count);
}

int print_addr(unsigned long long addr, t_flags *f, int n)
{
	int count;

	count = 0;
	if (f->precision_value > n)
		n = f->precision_value;
	if (!f->left_adjusted)
		count += print_width(f, n + 2);
	count += print_addr_digits(addr, f, n);
	if (f->left_adjusted)
		count += print_width(f, n + 2);
	return (count);
}

int handle_null_ptr(t_flags *f)
{
	int count;
	int nil_len;
	char *str;

	count = 0;
	str = "(nil)";
	nil_len = ft_strlen(str);
	if (!f->left_adjusted)
		count += print_width(f, nil_len);
	ft_putstr_fd(str, 1);
	count += nil_len;
	if (f->left_adjusted)
		count += print_width(f, nil_len);
	return count;
}

int handle_ptr(unsigned long long addr, t_flags *f)
{
	int count;
	int numlen;

	numlen = get_num_len(addr, 16);
	if (!addr)
		count = handle_null_ptr(f);
	else
		count = print_addr(addr, f, numlen);
	return (count);
}

// TODO: Only printing is remaining, keep going
