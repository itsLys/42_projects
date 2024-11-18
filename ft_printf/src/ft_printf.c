#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int parse_flags()// populate struct
int parse_fmt(const char *fmt, va_list args, t_flags *f)
{
	int count;

	count = 0;
	while (*fmt && ft_strchr(FLAGS, *fmt))
	{
		parse_flags(fmt, arg, f);
	}
}

int	ft_printf(const char *fmt, va_list args) //change to elipsis later
{
	int count = 0;
	t_flags f;

	ft_memset(&f, 0, sizeof(f));
	while (*fmt)
	{
		if (*fmt != '%')
		{
			printf("%c", *fmt); // putchar_fd
			count++;
		}
		else
		{
			fmt++;
			count += parse_fmt(fmt, args, &f);
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
