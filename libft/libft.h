// can contain macros and typedefs if needed

#include <stdlib.h>
typedef enum e_bool {
	FALSE, TRUE
} t_bool ;
// size_t	ft_strlen(const char *s);
// void 	*ft_memset(void *s, int c, size_t n);
// char	*ft_strcpy(char *dst, const char *src);
// void	ft_memdel(void **ap);
// char	*ft_strncpy(char *dst, const char *src, size_t dsize);
// int		ft_isspace(int c);
// int		ft_isdigit(int c);
// int		ft_isupper(int c);
// int		ft_islower(int c);
// int		ft_isalpha(int c);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n) ;
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void 	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
size_t	t_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_tolower(int c);
int		ft_toupper(int c);