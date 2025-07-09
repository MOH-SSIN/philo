# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 15:25:30 by mez-zahi          #+#    #+#              #
#    Updated: 2025/07/09 20:40:34 by mez-zahi         ###   ########.fr        #
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
		${SRC}/lancer_simulation_1.c \
		${SRC}/routine.c \
		${SRC}/ft_free.c  \
		${UTILS}/ft_atoi.c \
		${UTILS}/ft_putstr_fd.c \
		${UTILS}/utlis_1.c \
		
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