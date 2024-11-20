#include "ft_printf.h"

int print_ptr(unsigned long long addr, t_flags *f)
{
	int count;

	count = 0;
	f->alt_form = 1;
	if (!addr)
	{
		f->precision_flag = 0;
		count += handle_null(f, "(nil)");
	}
	else
	{
			
	}

}

// if zero_flag exist
// 	print 0x, width - 2, and addr
// if !zero_flag 
// 	print width, and addr
// if left adjusted
// 	print addr and width
// if precision exist
// 	print 0x and 0s and addrs precision times
// if ptr == null
// 	print (nil)

