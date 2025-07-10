# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 15:25:30 by mez-zahi          #+#    #+#              #
#    Updated: 2025/07/10 17:57:02 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# ======= DOSSIERS =======
SRC = src
INCLUDE = include
UTILS = utils
PARSIN = parsin

# ======= FICHIERS SOURCES =======
SRCS = main.c \
       $(SRC)/ft_parsing_1.c \
       $(SRC)/prepare_simulation.c \
       $(SRC)/lancer_simulation.c \
       $(SRC)/routine.c \
       $(SRC)/ft_free.c \
       $(UTILS)/ft_atoi.c \
       $(UTILS)/ft_putstr_fd.c \
       $(UTILS)/utlis_1.c

OBJS = $(SRCS:.c=.o)

# ======= REGLES =======
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDE)/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all