# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skholodn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:14:27 by skholodn          #+#    #+#              #
#    Updated: 2017/11/21 16:14:30 by skholodn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = skholodn.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

GL = -lm -lmlx -framework OpenGL -framework AppKit

INCLUDES = fdf.h

SRCS =      main.c \
			gnl/get_next_line.c \
			arr_free.c \
			parse_name.c \
			parse_token.c \
			fill_map.c

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(GL) $(OBJ) -o $(NAME) $(LIBFT) $(PRINTF)
	$(VISUAL)

%.o: %.c $(INCLUDES) 
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES)

$(LIBFT):
	make -C ./libft/

$(PRINTF):
	make -C ./ft_printf/

$(VISUAL):
	make -C ./visual/

clean:
	rm -f $(OBJ)
	make clean -C libft/
	make clean -C ft_printf/
	make clean -C visual/

fclean: clean
	rm -f $(NAME)