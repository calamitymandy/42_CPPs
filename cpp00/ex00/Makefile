# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amdemuyn <amdemuyn@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 14:13:44 by amdemuyn          #+#    #+#              #
#    Updated: 2024/08/17 14:25:36 by amdemuyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
REMOVE = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
		$(REMOVE) $(OBJS)

fclean: clean
				$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re

