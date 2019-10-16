# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 14:44:04 by idouidi           #+#    #+#              #
#    Updated: 2019/10/16 18:50:32 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_strlen.c \
		ft_strdup.c ft_memset.c ft_bzero.c \
		ft_strchr.c\
		ft_memchr.c ft_memmove.c ft_memccpy.c \
		ft_memcpy.c  ft_strrchr.c ft_strnstr.c \
		ft_strncmp.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_strlcpy.c ft_strmapi.c ft_memcmp.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_putendl_fd.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

INC =  -I includes

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SRC) $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all
