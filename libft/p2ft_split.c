#include "libft.h"
#include <stdio.h>
#include <unistd.h>

static const char *skip_delim(const char *s, char c)
{
	while (*s == c)
		s++;
	return s;
}

static const char *skip_word(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	return s;
}

static size_t count_words(const char *s, char c)
{
	size_t count;

	count = 0;
	write(1, "Hello\n", 6);
	while (*s)
	{
		s = skip_delim(s, c);
		if (*s)
			count++;
		s = skip_word(s, c);
	}
	if (count == 0)
		return 1;
	return (count);
}

static size_t get_word_len(const char *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return len;
}

static char **free_mem(char **list, size_t i)
{
	while (i-- > 0)
		free(list[i]);
	free(list);
	return (NULL);
}

char **ft_split(char const *s, char c)
{
	// printf("Hello");
	size_t list_size;
	char **list;
	char *word;
	size_t i;

	if (s == NULL)
		return (NULL);
	i = 0;
	list_size = count_words(s, c) + 1;
	list = ft_calloc(list_size, sizeof(char *));
	if (!list)
		return (NULL);
	list[--list_size] = NULL;
	while (i < list_size)
	{
		s = skip_delim(s, c);
		word = ft_substr(s, 0, get_word_len(s, c));
		if (!word)
			return (free_mem(list, i));
		list[i++] = word;
		s = skip_word(s, c);
	}
	return (list);
}
// TODO:
//	allocate a char ** of the words
//
// NOTE:
//	what is const char * vs const char
//
//	"ddddddddddddddd"
//	""
//	'd'
