# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skholodn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:19:35 by skholodn          #+#    #+#              #
#    Updated: 2017/11/21 16:26:44 by skholodn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

GL = -lm -lmlx -framework OpenGL -framework AppKit

INCLUDES = visual.h

SRCS =  main.c \
		../gnl/get_next_line.c \
		../arr_free.c \
		funct_1.c \
		funct_2.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) $(GL) $(OBJ) -o $(NAME) ../libft/libft.a

%.o: %.c $(INCLUDES) 
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all