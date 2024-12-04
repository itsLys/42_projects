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

# define MAX_READ 0x7ffff000
# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif // !BUFFER_SIZE

# if BUFFER_SIZE > MAX_READ
#  undef BUFFER_SIZE
#  define BUFFER_SIZE MAX_READ
# endif

# include <stdlib.h>
# include <unistd.h>

ssize_t	find_char(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	str_append(const char *src, char *dst);

#endif // !GET_NEXT_LINE_H
