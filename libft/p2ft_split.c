#include "libft.h"

static const char *skip_delim(const char *s, char c)
{
    while (*s && *s == c)
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
    while (*s)
    {
        s = skip_delim(s, c);
        if (*s)
            count++;
        s = skip_word(s, c);
    }
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

char **ft_split(char const *s, char c)
{
    size_t word_count;
    char **list;
    size_t i;

    word_count = count_words(s, c);
    list = ft_calloc(word_count + 1, sizeof(char *));
    if (!list)
        return (NULL);
    list[--word_count] = NULL;
    while (word_count)
    {
        s = skip_delim(s, c);
        list[word_count] = ft_substr(s, 0, get_word_len(s, c));
        s = skip_word(s, c);
    }
    return (list);
}
// TODO:
//	allocate a char ** of the words
//
// NOTE:
//	what is const char * vs const char
