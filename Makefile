# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jguleski <jguleski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 16:52:43 by jguleski          #+#    #+#              #
#    Updated: 2018/10/28 17:41:15 by jguleski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf
LIBFT = libft_funcs
FLAGS = -Wall -Wextra -Werror

MLX = minilibx_macos -lmlx
FRAME = -framework  OpenGL -framework AppKit
LIB = $(LIBFT)/libft18.a

SRC = fdfactions.c \
	  rotate.c \
	  color.c \
	  fdfimage.c \
	  drawmap.c \
	  ft_split.c \
	  fdfparse.c \
	  actionhandler.c \
	  crta.c \
	  main.c \
	  getlinija.c \
	  util.c

INCLUDES = -Iincludes -I$(LIBFT)
# OBJECTS = $(SRC:%.c=%.o)

all: $(LIB) $(SRC)
	 gcc $(FLAGS) $(INCLUDES) $(SRC) -L $(MLX) $(LIB) $(FRAME) -o $(NAME)

%.o: %.c
		@gcc -Wall -Wextra -Werror -c -I$(BLIBFT) $< -o $@

# $(NAME): $(OBJECTS) 
# 		@ar rc $(NAME) $(OBJECTS) 
# 		@ranlib $(NAME)
# 		@echo "your lib is ready"
# 		@#gcc -Wall -Wextra -Werror -o test $(SRC) -I.

$(LIB):
		@make -C $(LIBFT)

debug:
		gcc $(FLAGS) -g $(INCLUDES) $(SRC) -L $(MLX) $(LIB) $(FRAME) -o a.out

clean:
		make -C $(LIBFT) clean

fclean:	clean
		rm -f $(NAME)
		@make -C $(LIBFT) fclean

re: fclean all
