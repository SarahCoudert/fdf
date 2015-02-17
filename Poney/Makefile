# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 17:58:37 by scoudert          #+#    #+#              #
#    Updated: 2015/02/17 15:22:38 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = ponyr_kaileurdelarmord

#CC = gcc

#CFLAGS = -Wall -Wextra -Werror

#CFLAGSD = $(CFLAGS) -g

#SDL =$(shell `sdl-config --libs --cflags`)

#SDL_F = SDL_image

#SRC = main.c \
	  event.c \

#OBJ = $(SRC:.c=.o)

#all: $(NAME)

#$(NAME): $(SRC)
#	make -C libft/
#	$(CC) $(CFLAGS) -c $(SRC) $(SDL) -l$(SDL_F)
#	$(CC) $(CFLAGS) $(SRC) $(SDL) -l$(SDL_F) libft/libft.a
#	make -C libft/ clean

#clean:
#	rm -f $(OBJ)

#fclean: clean
#	rm $(NAME)

#re: fclean all

#debug:
#	@make -C libft/
#	@$(CC) $(CFLAGSD) -c $(SRC) $(SDL) -l$(SDL_F) libft/libft.a
#	@$(CC) $(OBJ) -o $(NAME)
#	@make -C libft/ clean

all : 
	$(shell gcc -Wall -Werror -Wextra /SRC/main.c /SRC/event.c `sdl-config --cflags --libs` -lSDL -lSDL_image -lSDL_mixer /SRC/INCLUDES/libft/libft.a)
