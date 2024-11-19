#include <stdarg.h>
#include <stdatomic.h>
#include <stdio.h>
#include "ft_printf.h"

int parse_flags(const char *fmt, va_list args, t_flags *f)
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
	else
	f->


}

int parse_width(const char *fmt, va_list args, t_flags *f)
{

}

int parse_conversions(const char *fmt, va_list args, t_flags *f)
{

}

int parse_precision(const char *fmt, va_list args, t_flags *f)
{

}

int check_valid(const char *fmt)
{
	int  valid = 0;
	while (*fmt && ft_strchr(FLAGS, *fmt)) // the check of null byte is probabely a red herring
		fmt++;
	while (*fmt && ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '.')
		fmt++;
	while (*fmt && ft_isdigit(*fmt))
		fmt++;
	if (ft_strchr(CONVERSIONS, *fmt))
		return 1;
	return 0;
}

int parse_fmt(const char *fmt, va_list args, t_flags *f)
{
	int count;

	count = 0;
	while (*fmt && ft_strchr(FLAGS, *fmt))
		fmt += parse_flags(fmt, args, f);
	if (*fmt && ft_isdigit(*fmt))
		fmt += parse_width(fmt, args, f);
	if (*fmt && *fmt == '.')
		fmt += parse_precision(fmt, args, f);
	if (*fmt && ft_strchr(CONVERSIONS, *fmt))
		fmt += parse_conversions(fmt, args, f);
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
// if (*format == 'd')
// 	count += printf("%d", va_arg(args, int));
// else if (*format == 'c')
// 	count += printf("%c", va_arg(args, int));
// else if (*format == 's')
// 	count += printf("%s", va_arg(args, char *));
// else if (*format == '%')
// 	count += printf("%c", va_arg(args, int));
// else if (*format == 'p')
// 	count += printf("%p", va_arg(args, unsigned char *));
// else
// {
// 	printf("%c", '%');
// 	printf("%c", *format);
// 	count += 2;
// }
