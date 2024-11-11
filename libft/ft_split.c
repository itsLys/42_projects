/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:32:09 by ihajji            #+#    #+#             */
/*   Updated: 2024/11/09 11:32:09 by ihajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	if (count == 0)
		return (1);
	return (count);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char	**free_mem(char **list, size_t i)
{
	while (i-- > 0)
		free(list[i]);
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**list;
	char	*word;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = count_words(s, c);
	list = ft_calloc(word_count + 1, sizeof(char *));
	if (!list)
		return (NULL);
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word = ft_substr(s, 0, get_word_len(s, c));
		if (!word)
			return (free_mem(list, i));
		list[i++] = word;
		while (*s && *s != c)
			s++;
	}
	return (list);
}

// NOTE:
//	what is const char * vs const char
