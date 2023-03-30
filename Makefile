# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 16:34:21 by jpelaez-          #+#    #+#              #
#    Updated: 2023/03/30 14:52:49 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

SRC =

OBJECT = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINLBX_DIR = ./minilibx
MINLBX = $(MINLBX_DIR)/libmlx.a

HEADER = so_long.h
LIBFT_HEADER = ./libft/libft.h

FLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(HEADER) 

LIBX = -Lmlx -lmlx -framework OpenGL -framework AppKit
CC = CC

all: $(NAME) 

$(NAME):  $(OBJECT) 
		make -C $(LIBFT_DIR)
		make -C $(MINLBX_DIR)
		$(CC) $(FLAGS) $(IFLAGS) $(LIBX) $(OBJECT) $(LIBFT) $(MINLBX) -o $(NAME) 
	
clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(MINLBX_DIR) fclean
	rm -f $(OBJECT) 

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean