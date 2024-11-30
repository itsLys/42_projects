SRC 		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			  ft_itoa.c ft_atoi.c ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c  \
			  ft_memcpy.c ft_memmove.c ft_memset.c \
			  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
			  ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c  \
			  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c  \
			  ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
			  ft_tolower.c ft_toupper.c
SRC_BONUS 	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
			  ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
			  ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
			  ft_lstsize_bonus.c
INCLUDES	= -I./headers
OBJDIR		= obj
SRCDIR		= src
NAME		= libft.a
CC 			= cc -c -Wall -Wextra -Werror
AR			= ar rcs
OBJ 		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))     
OBJ_BONUS	= $(addprefix $(OBJDIR)/, $(SRC_BONUS:.c=.o))

GREEN  		= \033[0;32m
YELLOW 		= \033[0;33m
BLUE   		= \033[0;34m
MAGENTA		= \033[0;35m
BOLD   		= \033[1m
RESET  		= \033[0m
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Libft.a done!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(notdir $<)...$(RESET)"
	@$(CC) $< $(INCLUDES) -o $@
	@echo "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(RESET)"
	@$(AR) $(NAME) $@

bonus: $(OBJ) $(OBJ_BONUS)
	@echo "$(GREEN)Libft.a (bonus) done!$(RESET)"

clean :
	@echo "$(RED)Cleaning $(OBJDIR)...$(RESET)"
	@${RM} $(OBJDIR)

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@${RM} $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, build
