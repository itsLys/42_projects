NAME		= libftprintf.a 
LIBFT		= libft/libft.a
LIBFTDIR	= libft/
CC 			= cc -c -Wall -Wextra -Werror
AR			= ar rcs
INCLUDES	= -I./headers -I./libft/headers

SRC			= ft_printf.c print_char.c print_hex.c print_nbr.c print_ptr.c print_str.c print_unsigned.c print_width.c utils.c
OBJDIR		= obj
SRCDIR		= src
OBJ 		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

GREEN  		= \033[0;32m
YELLOW 		= \033[0;33m
BLUE   		= \033[0;34m
MAGENTA		= \033[0;35m
BOLD   		= \033[1m
RESET  		= \033[0m
RM			= rm -rf


all: $(NAME)
	cp -p $(NAME) tests/unit_tests/$(NAME)
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
	@make -C $(LIBFTDIR) all
	@echo "$(CYAN)Copying $(notdir $<)to $(NAME)...$(RESET)"
	@cp $(LIBFT) $(NAME)  
	@echo "$(GREEN)Copying done!$(RESET)"

clean :
	@echo "$(RED)Cleaning $(OBJDIR)...$(RESET)"
	@${RM} $(OBJDIR) # {}??

fclean : clean
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@${RM} $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, build
