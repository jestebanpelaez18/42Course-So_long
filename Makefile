# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 16:34:21 by jpelaez-          #+#    #+#              #
#    Updated: 2023/04/04 15:41:30 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long 

SRC = main.c init_map.c utils.c error.c\

OBJECT = $(SRC:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/get_next_line.c
GNL_UTILS = $(GNL_DIR)/get_next_line_utils.c

# MINLBX_DIR = ./minilibx
# MINLBX = $(MINLBX_DIR)/libmlx.a

HEADER = so_long.h
LIBFT_HEADER = ./libft/libft.h

FLAGS = -Wall -Wextra -Werror 
IFLAGS = -I $(HEADER) 

# LIBX = -Lmlx -lmlx -framework OpenGL -framework AppKit
CC = CC 

all: $(NAME) 

$(NAME):  $(OBJECT) 
		make -C $(LIBFT_DIR)
		$(CC) $(FLAGS) $(IFLAGS) $(OBJECT) $(GNL) $(GNL_UTILS) $(LIBFT) -o $(NAME) 

	
clean:
	make -C $(LIBFT_DIR) fclean
	rm -f $(OBJECT) 

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean