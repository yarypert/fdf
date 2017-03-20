# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/06 00:55:05 by yarypert          #+#    #+#              #
#    Updated: 2017/03/11 00:56:55 by yarypert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./

FLAG = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_factorial.c ft_find_next_prime.c ft_is_prime.c\
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c\
	  ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_lstadd.c ft_lstdel.c\
	  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c\
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_pgcd.c ft_power.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c\
	  ft_putstr.c ft_putstr_fd.c ft_sqrt.c ft_str_is_alpha.c\
	  ft_str_is_lowercase.c ft_str_is_numeric.c ft_str_is_printable.c\
	  ft_str_is_uppercase.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c\
	  ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c\
	  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strlowcase.c\
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c\
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_strupcase.c\
	  ft_tolower.c ft_toupper.c ft_void.c get_next_line.c ft_abs.c\

OBJ = ${SRC:c=o}

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) -I$(HEADER) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mkdir tmp
	@mv $(OBJ) tmp

.PHONY: clean
clean :
	@rm -Rf tmp
	@echo "\033[38;5;40m[✓] \033[38;5;15m Removed object files"

fclean: clean
	@rm -Rf $(NAME)
	@echo "\033[38;5;40m[✓] \033[38;5;15m Removed executable" $(NAME)

re : fclean all
