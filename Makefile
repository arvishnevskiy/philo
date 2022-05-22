# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kelisabe <kelisabe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 14:21:41 by kelisabe          #+#    #+#              #
#    Updated: 2022/05/22 16:30:57 by kelisabe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = first_utils.c time_utils.c philo.c data_pars.c phils_init.c philo_launch.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER = philo.h

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra -std=c99

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
