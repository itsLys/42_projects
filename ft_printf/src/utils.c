/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:21:09 by ihajji            #+#    #+#             */
/*   Updated: 2024/11/25 14:21:09 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width(t_flags *f, int n)
{
	int	count;

	count = 0;
	while (f->width - n > 0)
	{
		if (f->zero_padded)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		f->width--;
		count++;
	}
	return (count);
}

int	get_num_len(unsigned long long n, unsigned int base)
{
	int	len;

	len = 1;
	while (n > base - 1)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	check_valid(const char *fmt)
{
	while (*fmt && ft_strchr(FLAGS, *fmt))
		fmt++;
	while (ft_isdigit(*fmt))
		fmt++;
	if (*fmt == '.')
		fmt++;
	while (ft_isdigit(*fmt))
		fmt++;
	if (ft_strchr(CONVERSIONS, *fmt))
		return (1);
	return (0);
}
