NAME = test.a

SRC = get_case.c printing.a
OBJ = get_case.o printing.o
TEST = printerr_test.c printhex_test.c printstr_test.c printnbr_test.c printchar_test.c printptr_test.c printunsigned_test.c other_test.c 
EXEC = printerr.out printhex.out printchar.out printstr.out printnbr.out printptr.out printunsigned.out other.out

all: $(NAME) $(EXEC)

%.out: %_test.c
	@echo $< $@
	cc $< $(NAME) libftprintf.a -I./../../headers -I./../../libft/headers/ -o $@

$(NAME): $(OBJ)
	make -C ../../ re
	cp -p ../../libftprintf.a ./

%.o: %.c
	cc -c $< -I./../../headers -I./../../libft/headers/ -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean
	make all
	
