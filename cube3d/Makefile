# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/06/29 22:34:51 by othabchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/parsing/ft_utils_pars.c srcs/parsing/ft_pars_info_map.c \
	   srcs/parsing/ft_pars_map.c  srcs/parsing/ft_parsing.c \
	   srcs/parsing/ft_adjust_map.c srcs/display/ft_cub3d.c \
	   srcs/display/ft_set_info_map.c srcs/display/trgb.c \
	   srcs/display/ft_display.c srcs/display/ft_raycasting.c \
	   srcs/display/ft_utils_display.c \
	   srcs/display/ft_utils_display2.c \

LIBFTPATH	= project/libft 
LIBOBJ		= project/libft/libft.a
MLXPATH		= mlx/
@OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
MLXFLAGS	= -L$(MLXPATH) -lmlx -framework OpenGL -framework AppKit
NAME		= cub3D

all: $(NAME)

$(NAME): $(@OBJS)
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFTPATH)
	@echo "Done."
	@echo "Compiling cub3D..."
	@gcc ${CFLAGS} -o ${NAME} ${@OBJS} main.c $(LIBOBJ) $(MLXFLAGS)
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
