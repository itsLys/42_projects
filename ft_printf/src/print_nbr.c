#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

char *handle_nbr_flags(t_flags *f, long num, int len, int sign)
{
	char *str;
	int total;
	int i;

	if (f->precision_flag && !f->precision_value)
		return (ft_strdup(""));
	total = len + (sign < 0) + ((sign > 0) * (f->space_flag || f->force_sign));
	i = 0;
	if (f->precision_value >= total)
		total = f->precision_value + (sign < 0);
	str = ft_calloc((total + 1), 1);
	while (total--)
	{
		str[i++] = "0123456789"[num % 10]; // BASE VAR
		num /= 10;
	}
	if (sign < 0)
		str[--i] = '-';
	else if (f->force_sign && sign > 0)
		str[--i] = '+';
	else if (f->space_flag && sign > 0)
		str[--i] = ' ';
	str[++i] = '\0';
	return str;
}

int print_nbr(long num, t_flags *f, int len, int sign)
{
	int count;
	int total;
	char *str;
	int i;

	str = handle_nbr_flags(f, num, len, sign);
	total = ft_strlen(str);
	count = 0;
	i = total;
	if (!f->left_adjusted)
		count = print_width(f, total);
	while (i-- > 0)
		count += ft_putchar_fd(str[i], 1);
	if (f->left_adjusted)
		count += print_width(f, total);
	free(str);
	return count;
}

int	handle_nbr(int n, t_flags *f)
{
	int count;
	int numlen;
	long num;
	int sign;

	sign = 1;
	num = n;
	if (n < 0)
	{
		num = -num;
		sign = -sign;
	}
	numlen = get_num_len(num, 10);
	count = print_nbr(num, f, numlen, sign);
	return (count);
}
