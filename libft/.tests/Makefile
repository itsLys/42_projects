# TODO: 
# 	must contain at least the rules
# 		$(NAME), all, clean, fclean, re
# 	must cOmpile with the flags
# 		-Wall, -Wextra, -Werror
NAME = libft.a
SRC_TEST = print_bytes.c get_case.c \
				t_atoi.c \
				t_bzero.c \
				t_fd.c \
				t_is.c \
				t_itoa.c \
				t_lst.c \
				t_memchr.c \
				t_memcmp.c \
				t_memcpy.c \
				t_memmove.c \
				t_memset.c \
				t_split.c \
				t_strchr.c \
				t_strdup.c \
				t_striteri.c \
				t_strjoin.c \
				t_strlcat.c \
				t_strlcpy.c \
				t_strlen.c \
				t_strmapi.c \
				t_strncmp.c \
				t_strnstr.c \
				t_strrchr.c \
				t_strtrim.c \
				t_substr.c \
				t_to.c 

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
