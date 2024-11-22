NAME = test.a

SRC = get_case.c printing.a
OBJ = get_case.o printing.o

all: $(NAME)
	make -C ../../ re
	cc printptr_test.c $(NAME) libftprintf.a -I./../../headers -I./../../libft/headers/

$(NAME): $(OBJ)

%.o: %.c
	cc -c $< -I./../../headers -I./../../libft/headers/ -o $@
	ar rcs $(NAME) $@

clean: 
	rm $(OBJ)
	
