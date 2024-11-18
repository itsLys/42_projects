int	printf_prototype(const char *format, va_list args)
{
	// va_list args;
	//
	// va_start(args, format);
	int count = 0;
	while (*format)
	{
		if (*format != '%')
		{
			printf("%c", *format);
			count++;
		}
		else
		{
			format++;
			if (*format == 'd')
				count += printf("%d", va_arg(args, int));
			else if (*format == 'c')
				count += printf("%c", va_arg(args, int));
			else if (*format == 's')
				count += printf("%s", va_arg(args, char *));
			else if (*format == '%')
				count += printf("%c", va_arg(args, int));
			else if (*format == 'p')
				count += printf("%p", va_arg(args, unsigned char *));
			else
			{
				printf("%c", '%');
				printf("%c", *format);
				count += 2;
			}
		}
		format++;
	}
	va_end(args);
	return count;
}
