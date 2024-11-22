#include "ft_printf.h"
#include <stdio.h>
#define BASE 16

int print_addr_digits(unsigned long long addr, t_flags *f, int n)
{
	char str[16];
	char *hexdigits;
	int count;
	int i;

	count = 0;
	i = 0;
	hexdigits = "0123456789abcdef";
	if (f->precision_value > n)
		n = f->precision_value;
	while (n--)
	{
		// printf("\nprecision value:	%d\n", f->precision_value);
		// printf("\nn:			%d\n", n);
		str[i] = hexdigits[addr % BASE];
		i++;
		addr /= BASE;
	}
	str[i++] = 'x';
	str[i++] = '0';
	while (i-- > 0)
		count += ft_putchar_fd(str[i], 1);
	return (count);
}

int print_addr(unsigned long long addr, t_flags *f, int n)
{
	int count;

	count = 0;
	if (f->precision_value > n)
		n = f->precision_value;
	if (!f->left_adjusted)
		count += print_width(f, n + 2);
	count += print_addr_digits(addr, f, n);
	if (f->left_adjusted)
		count += print_width(f, n + 2);
	return (count);
}

int handle_ptr(unsigned long long addr, t_flags *f)
{
	int count;
	int numlen;

	numlen = get_num_len(addr, 16);
	if (!addr)
		count = handle_null(f, "(nil)");
	else
		count = print_addr(addr, f, numlen);
	return (count);
}

// |0x55f447d8d004|
// | 0x55f447d8d004|
// |(nil)|
// |(nil)|
// |                         (nil)|
// |      0x55f447d8d004|
// |0x55f447d8d004      |
// |     +0x55f447d8d004|
// |0x00000055f447d8d004|
// |+0x0000055f447d8d004|
// |+0x0000000055f447d8d004|
// |        0x0000000055f447d8d004|
// |                 +0x0000000055f447d8d004|
// if zero_flag exist
// 	print 0x, width - 2, and addr
// if !zero_flag 
// 	print width, and addr
// if left adjusted
// 	print addr and width
// if precision exist
// 	print 0x and 0s and addrs precision times
// if force sign
// 	prefix '+'
// if space 
// 	prefix ' '
// if ptr == null
// 	print (nil)

// TODO: Only printing is remaining, keep going
