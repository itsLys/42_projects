/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:26:40 by ihajji            #+#    #+#             */
/*   Updated: 2024/12/07 14:48:17 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **last)
{
	char	*tmp;

	tmp = dup_until(find_chr(*last, NL) + 1, 0);
	if (!tmp)
		return (NULL);
	free(*last);
	*last = tmp;
	if (find_chr(tmp, NL))
		return (dup_until(*last, NL));
	return (NULL);
}

static void	*clean_up(void **p)
{
	free(*p);
	*p = NULL;
	return (NULL);
}

static char	*read_buffer(int fd, char **last)
{
	ssize_t	bytes;
	char	*line;
	char	*buffer;

	line = *last;
	buffer = malloc((unsigned int)BUFFER_SIZE + 1);
	if (!buffer)
		return (clean_up((void **)last));
	while (!find_chr(buffer, NL))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (clean_up((void **)&buffer), clean_up((void **)last));
		buffer[bytes] = 0;
		line = join_reads(line, buffer);
		if (!line)
			return (clean_up((void **)&buffer), clean_up((void **)last));
		if (bytes == 0)
			break ;
	}
	free(*last);
	*last = buffer;
	if (!line[0])
		return (clean_up((void **)last), clean_up((void **)&line));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	line = NULL;
	if (find_chr(last, NL))
		line = extract_line(&last);
	if (line)
		return (line);
	line = read_buffer(fd, &last);
	return (line);
}