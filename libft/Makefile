# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idouidi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 14:44:04 by idouidi           #+#    #+#              #
#    Updated: 2019/10/28 16:42:21 by idouidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_atoi.c ft_strlen.c \
		ft_strdup.c ft_memset.c ft_bzero.c \
		ft_strchr.c ft_strlcat.c \
		ft_memchr.c ft_memmove.c ft_memccpy.c \
		ft_memcpy.c  ft_strrchr.c ft_strnstr.c \
		ft_strncmp.c ft_isalpha.c  ft_calloc.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_tolower.c ft_toupper.c \
		ft_strlcpy.c ft_strmapi.c ft_memcmp.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_putendl_fd.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c  ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c  ft_lstiter_bonus.c  ft_lstmap_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

INC =  libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) ${INC}
	ar rc $(NAME) $(OBJ) ${INC}
	ranlib $(NAME)

bonus: $(BONUS_OBJ) $(OBJ) ${INC}
ifeq ("$(shell ls -R | grep bonus.o)","")
	ar rcs $(NAME) $< $(BONUS_OBJ) $(OBJ) ${INC}
endif 

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ $(INCS)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
