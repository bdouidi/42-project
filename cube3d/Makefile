# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsy <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:08:38 by dsy               #+#    #+#              #
#    Updated: 2020/06/08 16:26:01 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_utils_pars.c srcs/parsing/ft_pars_info_map.c \
	   srcs/parsing/ft_pars_map.c  srcs/parsing/ft_parsing.c \

LIBFTPATH = project/libft 
LIBOBJ = project/libft/libft.a

libft:
	@echo "compiling libft..."
	cd $(LIBFTPATH) && make

all: libft 
	@echo "compiling cube3D..."
	gcc -Wall -Werror -Wextra $(SRCS) $(LIBOBJ) main.c

clean:
	@cd $(LIBFTPATH) && make clean

fclean: clean
	@cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: libft, all, clean, fclean, re
