/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:32:09 by ihajji            #+#    #+#             */
/*   Updated: 2024/11/09 11:32:09 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	write_num(char *buf, int n)
{
	long	num;
	size_t	i;

	i = 0;
	if (!n)
	{
		buf[i++] = '0';
	}
	if (n < 0)
	{
		num = -(long)n;
	}
	else
		num = (long)n;
	while (num > 0)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	size_t	bytes;

	bytes = write_num(str, n);
	while (bytes--)
	{
		ft_putchar_fd(str[bytes], fd);
	}
}