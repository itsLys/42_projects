# TODO: 
# 	must contain at least the rules
# 		$(NAME), all, clean, fclean, re
# 	must cOmpile with the flags
# 		-Wall, -Wextra, -Werror
NAME = libft.a
SRC_TEST = print_bytes.c get_case.c \
tef_ft_lst.c      te_ft_strjoin.c  t_ft_bzero.c   t_ft_memmove.c  t_ft_strlcpy.c  t_ft_to.c \
te_ft_fd.c        te_ft_strmapi.c  t_ft_is.c      t_ft_memset.c   t_ft_strlen.c \
te_ft_itoa.c      te_ft_strtrim.c  t_ft_memchr.c  t_ft_strchr.c   t_ft_strncmp.c \
te_ft_split.c     te_ft_substr.c   t_ft_memcmp.c  t_ft_strdup.c   t_ft_strnstr.c \
te_ft_striteri.c  t_ft_atoi.c      t_ft_memcpy.c  t_ft_strlcat.c  t_ft_strrchr.c 
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)
AROPTS = rcs	

all:
	cc t_ft_memcmp.c   -L. -lft print_bytes.c get_case.c -o test_memcmp

$(NAME): $(OBJ)
	ar $(AROPTS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	ar $(AROPTS) $(NAME) $(OBJ) $(OBJ_BONUS)

test: $(OBJ) $(OBJ_BONUS) $(OBG_TEST)
	ar $(AROPTS) $(NAME) $(OBJ) $(OBJ_BONUS) $(OBG_TEST)

clean:
	rm -f $(OBJ) $(OBJ_BONUS) $(OBG_TEST)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
