NAME		= ft_printf.a
LIBFT		= libft/libft.a
LIBFTDIR	= libft/
CC 			= cc -c -Wall -Wextra -Werror
AR			= ar rcs
INCLUDES	= -I./headers -I./libft/headers

SRC			= ft_printf.c
SRCDIR		= src
OBJDIR		= obj
OBJ 		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

GREEN  		= \033[0;32m
YELLOW 		= \033[0;33m
BLUE   		= \033[0;34m
MAGENTA		= \033[0;35m
BOLD   		= \033[1m
RESET  		= \033[0m
RM			= rm -rf


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(GREEN)ft_printf done!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(CYAN)Compiling $(notdir $<)...$(RESET)"
	@$(CC) $< $(INCLUDES) -o $@
	@echo "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(RESET)"
	@$(AR) $(NAME) $@

$(LIBFT):
	@echo "$(CYAN)Compiling $(notdir $<)...$(RESET)"
	@make -C $(LIBFT_DIR) all
	@echo "$(CYAN)Copying $(notdir $<)to $(NAME)...$(RESET)"
	@cp $(LIBFT) $(NAME)
	@echo "$(GREEN)Copying done!$(RESET)"
	@echo "$(RED)Cleaning $(LIBFTDIR)...$(RESET)"
	@make -C $(LIBFT_DIR) fclean

clean :
	@echo "$(RED)Cleaning $(OBJDIR)...$(RESET)"
	@${RM} $(OBJDIR)

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@${RM} $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, build
