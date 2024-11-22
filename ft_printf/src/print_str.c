#include "ft_printf.h"

int putnstr(t_flags *f, char *str, int n)
{
	int count;
	int chars;

	count = 0;
	chars = n;
	if (!f->left_adjusted)
		count += print_width(f, chars);
	while (*str && n--)
		count += ft_putchar_fd(*(str++), 1);
	if (f->left_adjusted)
		count += print_width(f, chars);
	return count;
}

int handle_precision(t_flags *f, char *str)
{
	int count;
	int slen;

	count = 0;
	slen = ft_strlen(str);
	if (!f->precision_flag || f->precision_value > slen)
		f->precision_value = slen;
	count += putnstr(f, str, f->precision_value);
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
	if (f->precision_flag && f->precision_value >= 0 && f->precision_value < (int) slen)
		count += print_width(f, 0);
	else
		count += handle_precision(f, str);
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
		count += handle_precision(f, str);
	return count;
}
// calculate how many charachters are yu printing in total: field width
// calculate how many charachters from th string are you printing: precision
// determine if it is left or right adjusted: `-`
//

// if precision exists and < strlen("(null)")
// 	print_nothing;
//
//
