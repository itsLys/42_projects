#include "ft_printf.h"

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
