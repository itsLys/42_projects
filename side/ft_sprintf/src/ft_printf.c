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

int parse_integer(const char *fmt, int *n, t_flags *f)
{
	int count = 0;

	*n = ft_atoi(fmt);
	while (*fmt && ft_isdigit(*fmt))
	{
		count++;
		fmt++;
		f->total++;
	}
	return count;
}

void print_conversion(char c, va_list args, t_flags *f)
{
	if (c == 'c')
	{
		f->zero_padded = 0;
		f->printed += handle_char(f, va_arg(args, int));
	}
	else if (c == 's')
	{
		f->zero_padded = 0;
		f->printed += handle_str(va_arg(args, char *), f);
	}
	else if (c == 'p')
		f->printed += handle_ptr(va_arg(args, unsigned long long), f);
	else if (c == 'd' || c == 'i')
		f->printed += handle_nbr(va_arg(args, int), f);
	else if (c == 'u')
		f->printed += handle_unsigned(va_arg(args, unsigned int), f);
	else if (c == 'x' || c == 'X')
		f->printed += handle_hex(va_arg(args, unsigned int), f, c);
	else if (c == '%')
		f->printed += ft_putchar_fd('%', 1);
	else
		return;
}

void parse_fmt(const char *fmt, va_list args, t_flags *f)
{
	while (*fmt && ft_strchr(FLAGS, *fmt))
	{
		parse_flags(fmt++, f);
		f->total++;
	}
	if (ft_isdigit(*fmt))
		fmt += parse_integer(fmt, &(f->width), f);
	if (*fmt == '.')
	{
		fmt++;
		f->total++;
		f->precision_flag = 1;
		fmt += parse_integer(fmt, &(f->precision_value), f);
	}
	f->coversion = *fmt;
	f->total++;
	print_conversion(*fmt, args, f);
}

int	ft_sprintf(const char *fmt, va_list args, char *str) //change to elipsis later
{
	int count;
	t_flags f;

	count = 0;
	while (*fmt)
	{
		ft_memset(&f, 0, sizeof(f));
		f.str = str;
		if (*fmt != '%')
		{
			*(f.str++) = *(fmt++);
			count++;
		}
		else
		{
			if (check_valid(++fmt))
			{
				parse_fmt(fmt, args, &f);
				fmt += f.total;
				f.str += f.printed;
				count += f.printed;
			}
			else
			{
				*(f.str) = '%';
				count++;
			}
		}
	}
	va_end(args);
	return count;
}
// TODO: Unit tests
// handle error from write,
// handle \0 after a %
