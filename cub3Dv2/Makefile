# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/10/14 06:53:23 by othabchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/parsing/ft_utils_pars.c srcs/parsing/ft_pars_info_map.c \
	   srcs/parsing/ft_pars_map.c  srcs/parsing/ft_parsing.c \
	   srcs/parsing/ft_adjust_map.c srcs/parsing/ft_set_info_map.c \
	   srcs/display/cub3d.c srcs/display/trgb.c \
	   srcs/display/display.c srcs/display/raycasting.c \
	   srcs/display/utils_display.c srcs/display/dda.c \
	   srcs/display/bitmap.c srcs/display/utils_display2.c \

LIBFTPATH	= project/libft 
LIBOBJ		= project/libft/libft.a
MLXOBJ		= mlx_linux/libmlx.a
MLXPATH		= mlx_linux/
@OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address  -march=native -flto 
MLXFLAGS	= -L$(MLXPATH) -lm -lXext -lX11 
NAME		= cub3D

all: $(NAME)

$(NAME): $(@OBJS)
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "Done."
	@echo "Compiling cub3D..."
	@gcc ${CFLAGS} -o ${NAME} ${@OBJS} main.c $(LIBOBJ) $(MLXOBJ) $(MLXFLAGS)
	@echo "Done."

clean:
	rm -rf $(@OBJS)
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@rm -f $(NAME)
	cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: libft, all, clean, fclean, re
.SILENT:
