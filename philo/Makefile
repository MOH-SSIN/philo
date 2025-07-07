# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 15:25:30 by mez-zahi          #+#    #+#              #
#    Updated: 2025/07/07 18:11:29 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf


# les dossiers
SRC = src
INCLUDE = include
UTILS = utils
PARSIN = parsin


SRCS = main.c \
		${SRC}/ft_parsing_1.c \
		${SRC}/prepare_simulation.c \
		${UTILS}/ft_atoi.c \
		${UTILS}/ft_putstr_fd.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGE) $(OBJS) -o $(NAME) 

%.o : %.c include/philo.h
	$(CC) $(CFLAGE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all