# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi <javi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:06:26 by javi              #+#    #+#              #
#    Updated: 2023/09/29 12:39:26 by javi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher

SRC =	./src/philosopher.c		\
		./src/utils.c			\
		./src/parser.c			\
		./src/utils_time.c		\
		./src/routines.c		\
		#./src/ft_check.c		\

OBJT = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re