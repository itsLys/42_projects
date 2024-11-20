#include "ft_printf.h"

int put_ptr(unsigned long long addr, t_flags *f, char *s)
{
	int count;
	int numlen;

	count = 0;
	numlen = get_num_len(addr, 16);
	if (f->precision_value < numlen)
		f->precision_value = numlen;
	if (f->zero_padded)
	{
		ft_putstr_fd(s, 1);
		count += 2;
	}
	if (!f->left_adjusted)
		print_width(f, f->precision_value + f->force_sign + 2);
	if (!f->zero_padded)
	{
		ft_putstr_fd(s, 1);
		count+= 2;
	}
	count += print_precision(f, numlen);
}

int handle_ptr(unsigned long long addr, t_flags *f)
{
	int count;

	count = 0;
	f->alt_form = 1;
	if (!addr)
	{
		f->precision_flag = 0;
		count += handle_null(f, "(nil)");
	}
	if (f->space_flag && !f->force_sign)
	{
		count += ft_putchar_fd(' ', 1);
		f->width--;
	}
	if (f->force_sign)
		count += put_ptr(addr, f, "+0x");
	else 
		count += put_ptr(addr, f, "0x");
	return count;
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

