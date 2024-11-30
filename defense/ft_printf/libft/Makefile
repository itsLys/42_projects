SRC 		= ft_atoi.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strlen.c ft_putchar_fd.c
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
	@echo "$(GREEN)$(BOLD)Libft.a done!$(RESET)"

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
