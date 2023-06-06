NAME = so_long
OBJECTS = $(shell find ./ -name "*.o")
A = $(shell find ./ -name "*.a")
CC = gcc

FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -g
CFILES = $(shell find . -name "*.c")

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

all :
	@make -C ./libft
	@make -C ./ft_printf
	@make -C ./minilibx
	$(CC) ./src/*.c ./libft/libft.a ./ft_printf/libftprintf.a $(FLAGS) -o so_long
	
clean:
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(OBJECTS)
	@rm -f $(A)
	@rm -f $(R)Removed [$(NAME)]$(X)

re: fclean all

norm:
	@echo $(Y)[--NORMINETTE CLEAN--]$(G)
	norminette $(shell find ./src/ -name "*.c")

.PHONY: all clean fclean re
