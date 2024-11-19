#include "ft_printf.h"

int putnstr(char *str, int n)
{
	int count = 0;
	while (*str && n--)
		count += ft_putchar_fd(*(str++), 1);
	return count;
}

int print_str(char *str, t_flags *f)
{
	int count = 0;
	size_t strlen = ft_strlen(str);

	if (f->precision_flag)
	{
		count += print_width(f, f->precision_value);
		count += putnstr(str, f->precision_value);
	}
	else
	{
		count += print_width(f, strlen);
		count += putnstr(str, strlen);
	}
	return count;
}
