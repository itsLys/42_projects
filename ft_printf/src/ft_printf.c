#include <cctype>
#include <stdarg.h>
#include <stdatomic.h>
#include <stdio.h>
#include "ft_printf.h"

void parse_flags(const char *fmt, t_flags *f)
{
	if (*fmt == '#')
		f->alt_form = 1;
	else if (*fmt == '0')
	{
		if (!f->left_adjusted)
			f->zero_padded = 1;
	}
	else if (*fmt == '-')
	{
		f->left_adjusted = 1;
		f->zero_padded = 0;
	}
	else if (*fmt == ' ')
		f->space_flag = 1;
	else if (*fmt == '+')
	{
		f->space_flag = 0;
		f->force_sign = 1;
	}
}

int parse_integer(const char *fmt, int *n)
{
	int count = 0;

	*n = ft_atoi(fmt);
	while (*fmt && ft_isdigit(*fmt))
	{
		count++;
		fmt++;
	}
	return count;
}

int print_conversion(char c, va_list args, t_flags *f)
{
	int count = 0;

	if (c == 'c')
		count += print_char(va_arg(args, int), f);
	else if (c == 's')
		count += print_str(va_arg(args, char *), f);
	else if (c == 'p')
		count += print_ptr(va_arg(args, unsigned long long), f);
	else if (c == 'd' || c == 'i')
		count += print_nbr(va_arg(args, int), f);
	else if (c == 'u')
	{
		f->force_sign = 0;
		count += print_nbr(va_arg(args, char *), f);
	}
	else if (c == 'x' || c == 'X')
		count += print_hex(va_arg(args, unsigned int), f, c);
	else if (c == '%')
		count += ft_putchar_fd('%', 1);
	return (count);
}


int parse_fmt(const char *fmt, va_list args, t_flags *f)
{
	int count;

	count = 0;
	while (*fmt && ft_strchr(FLAGS, *fmt))
		parse_flags(fmt++, f);
	if (*fmt && ft_isdigit(*fmt))
		fmt += parse_integer(fmt, &(f->width));
	if (*fmt && *fmt == '.')
	{
		fmt++;
		fmt += parse_integer(fmt, &(f->precision));
	}
	f->coversion = *(fmt++);
	count += print_conversion(*fmt, args, f);
	return count;
}

int	ft_printf(const char *fmt, va_list args) //change to elipsis later
{
	int count = 0;
	t_flags f;

	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		else
		{
			fmt++;
			if (check_valid(fmt))
			{
				ft_memset(&f, 0, sizeof(f));
				count += parse_fmt(fmt, args, &f);
			}
			else
				break;
		}
		fmt++;
	}
	va_end(args);
	return count;
}
// TODO: Unit tests
