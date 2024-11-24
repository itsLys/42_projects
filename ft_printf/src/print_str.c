#include "ft_printf.h"
#include <stdio.h>

int printnstr(t_flags *f, char *str, int len)
{
	int count;
	int n;

	count = 0;
	n = len;
	if (!f->left_adjusted)
		count += print_width(f, len);
	while (n-- && *str)
		count += ft_putchar_fd(*(str++), 1);
	if (f->left_adjusted)
		count += print_width(f, len);
	return count;
}

int handle_str_precision(t_flags *f, char *str)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(str);
	if (f->precision_flag && f->precision_value < len)
		len = f->precision_value;
	count += printnstr(f, str, len);
	return count;
}

int	handle_null_str(t_flags *f)
{
	int count;
	char *str;
	int slen;

	count = 0;
	str = "(null)";
	slen = ft_strlen(str);
	if (f->precision_flag && f->precision_value >= 0 && f->precision_value < slen)
		count += print_width(f, 0);
	else
		count += handle_str_precision(f, str);
	return count;
}

int handle_str(char *str, t_flags *f)
{
	int count;
	// int slen;

	count = 0;
	if (!str)
		count += handle_null_str(f);
	else
		count += handle_str_precision(f, str);
	return count;
}
