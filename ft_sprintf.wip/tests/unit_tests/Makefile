NAME = test.a

SRC = get_case.c printing.a
OBJ = get_case.o printing.o
TEST = printhex_test.c printstr_test.c printnbr_test.c printchar_test.c printptr_test.c 
EXEC = printhex.out printchar.out printstr.out printnbr.out printptr.out

all: $(NAME) $(EXEC)

%.out: %_test.c
	@echo $< $@
	cc $< $(NAME) libftprintf.a -I./../../headers -I./../../libft/headers/ -o $@

$(NAME): $(OBJ)
	make -C ../../ re

%.o: %.c
	cc -c $< -I./../../headers -I./../../libft/headers/ -o $@
	ar rcs $(NAME) $@

clean:
	rm $(OBJ)

fclean: clean
	rm $(EXEC)

re: fclean
	make all
	
