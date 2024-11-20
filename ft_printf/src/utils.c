#include "ft_printf.h"

int get_num_len(unsigned long long n, int base)
{
	int len;

	len = 1;
	while (len > base - 1)
	{
		len /= base;
		len++;
	}
	return len;
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
