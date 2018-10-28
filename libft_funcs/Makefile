# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/10/17 00:49:11 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft18.a

BLIBFT = libft_funcs/

SRC = ft_strstr.c \
	  ft_joinstr.c \
	  ft_atoi.c \
	  ft_strcat.c \
	  b_printf.c \
	  bprintf_parser.c \
	  findarg.c \
	  ft_putstr.c \
	  ft_newstr.c \
	  ft_itoa.c \
	  ft_isdigit.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlen.c \
	  ft_strncpy.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memdel.c

HEADER = includes

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJECTS)
		@gcc -Wall -Wextra -Werror -c $(SRC) -I.
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)
		@echo "your lib is ready"

debug:
		#gcc -Wall -Wextra -Werror -g -o test $(SRC) -I.

clean:
		@rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME)

re: fclean all
