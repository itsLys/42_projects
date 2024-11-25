#include "ft_printf.h"
#include <assert.h>
#include <stdio.h>

int get_num_len(unsigned long long n, unsigned base)
{
	int len;

	len = 1;
	while (n > base - 1)
	{
		n /= base;
		len++;
	}
	return len;
}

int check_valid(const char *fmt)
{
	while (*fmt && ft_strchr(FLAGS, *fmt)) // the check of null byte is probabely a red herring
		fmt++;
	while (*fmt && ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '.')
		fmt++;
	while (*fmt && ft_isdigit(*fmt))
		fmt++;
	if (*fmt && ft_strchr(CONVERSIONS, *fmt))
		return 1;
	return 0;
}

