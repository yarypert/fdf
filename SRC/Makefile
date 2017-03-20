NAME = FdF

COMPIL = -L/home/sholyu/Bureau/42/05-FdF/minilibx -lm -lmlx -lXext -lX11

COMPILM = gcc -lmlx -framework OpenGL -framework AppKit

SRCS = draw_image.c get_coord.c main.c parse.c read.c hook.c menu.c

OBJ = draw_image.o get_coord.o main.o parse.o read.o hook.o menu.o

INCLUDES = -I ./

LIB = Libft/libft.a

FLAGS = -Wall -Werror -Wextra

$(NAME) :
	@echo "\033[33;33m===FDF : Compilation for Mac...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

all: $(NAME)

%.o: %.c
	gcc -c $<

linux:
	@echo "\033[33;33m===FDF : Compilation for Linux...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@gcc $(OBJ) $(COMPIL) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

mac:
	@echo "\033[33;33m===FDF : Compilation for Mac...\033[0m"
	@make -C Libft
	@gcc $(FLAGS) -c $(SRCS) $(INCLUDES)
	@$(COMPILM) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)
	@mkdir -p TMP
	@mv $(OBJ) TMP

clean:
	@make clean -C Libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C Libft
	@rm -rf TMP
	@rm -rf $(NAME)

re: fclean all

remac: fclean mac

relinux: fclean linux

.SUFFIXES:

.PHONY: all clean fclean re
