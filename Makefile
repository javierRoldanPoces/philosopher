# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javier <javier@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:06:26 by javi              #+#    #+#              #
#    Updated: 2023/10/02 21:20:27 by javier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	./src/philosopher.c			\
		./src/utils.c				\
		./src/parser.c				\
		./src/utils_time.c			\
		./src/routines.c			\
		./src/actions.c				\
		./src/ft_check.c			\
		./src/philosopher_exit.c 	\

OBJT = $(SRC:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

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