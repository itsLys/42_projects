/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:45:10 by ihajji            #+#    #+#             */
/*   Updated: 2024/12/03 12:19:00 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // !BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>
# define MAX_READ 0x7ffff000
# define MAX_FD 1024

ssize_t	ft_strchr(const char *str, int c);

#endif // !GET_NEXT_LINE_H
