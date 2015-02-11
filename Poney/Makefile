# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 17:58:37 by scoudert          #+#    #+#              #
#    Updated: 2015/02/11 18:52:01 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ponyr_kaileurdelarmord

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGSD = $(CFLAGS) -g

SDL = -I ./SDL/ -L SDL

#`sdl-config --cflags --libs`

SDL_F = SDL_image

SRC = main.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
#	$(CC) $(CFLAGS) -c $(SRC) $(SDL) -l$(SDL_F)
	$(CC) $(CFLAGS) $(SRC) $(SDL) -l$(SDL_F) libft/libft.a
	make -C libft/ clean

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

debug:
	@make -C libft/
	@$(CC) $(CFLAGSD) -c $(SRC) $(SDL) -l$(SDL_F) libft/libft.a
	@$(CC) $(OBJ) -o $(NAME)
	@make -C libft/ clean
