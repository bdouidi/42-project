# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/02/28 19:04:03 by othabchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OBJS = srcs/*\

SRCS = srcs/parser/*.c \
	   srcs/mlx_functions/*.c \
	   srcs/utils/*.c \
	   srcs/raycasting/raycasting_utils.c \
#	   srcs/raycasting/raycasting.c \

LIBFTPATH = includes/libft 
LIBOBJ = includes/libft/libft.a

libft:
	@echo "compiling..."
	cd $(LIBFTPATH) && make

all: libft
	gcc -Wall -Werror -Wextra $(SRCS) main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit $(LIBOBJ) -o Cub3D

clean:
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: libft, all, clean, fclean, re
