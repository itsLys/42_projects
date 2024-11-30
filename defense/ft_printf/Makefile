NAME		= libftprintf.a 
LIBFT		= libft/libft.a
LIBFTDIR	= libft/
CC 			= cc -c -Wall -Wextra -Werror
AR			= ar rcs
INCLUDES	= -I./headers -I./libft/headers

SRC			= ft_printf_bonus.c print_char.c print_hex.c print_nbr.c print_ptr.c print_str.c print_unsigned.c utils.c parsing.c
OBJDIR		= obj
SRCDIR		= src
OBJ 		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

GREEN  		= \033[0;32m
YELLOW 		= \033[0;33m
MAGENTA		= \033[0;35m
RESET  		= \033[0m
RM			= rm -rf


all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(GREEN)$(BOLD)$(NAME) done!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(MAGENTA)Compiling $(notdir $<)...$(RESET)"
	@$(CC) $< $(INCLUDES) -o $@
	@echo "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(RESET)"
	@$(AR) $(NAME) $@

$(LIBFT):
	@echo "$(MAGENTA)Compiling $(notdir $<)...$(RESET)"
	@make -C $(LIBFTDIR) all
	@echo "$(MAGENTA)Copying $(notdir $<)to $(NAME)...$(RESET)"
	@cp $(LIBFT) $(NAME)  
	@echo "$(GREEN)$(BOLD)Copying done!$(RESET)"

clean :
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)Cleaning $(OBJDIR)...$(RESET)"
	@$(RM) $(OBJDIR)

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
