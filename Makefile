# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javi <javi@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 17:06:26 by javi              #+#    #+#              #
#    Updated: 2023/10/03 18:31:21 by javi             ###   ########.fr        #
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
		./src/thread.c				\

OBJT = $(SRC:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread

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