# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 17:58:37 by scoudert          #+#    #+#              #
#    Updated: 2015/03/03 17:28:19 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PoneyJump

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_D = $(CFLAGS) -g

SDL_F = SDL_image

SRC = main.c \
	  event.c \
	  menu.c \
	  obstacles.c \
	  pause.c

OBJ = $(SRC:.c=.o)

INC = includes

LIBFT = ./libft/

SDL_DIR = SDL

S_D = -D_GNU_SOURCE=1 -D_THREAD_SAFE

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -I $(SDL_DIR)/include/SDL $(S_D) -L$(SDL_DIR)/lib \
		-lSDL -lSDLmain -Wl,-framework,Cocoa -lSDL -lSDL_image -lSDL_mixer \
		-lSDL_ttf libft/libft.a -o $(NAME)
	make -C $(LIBFT) clean

debug: $(SRC)
	make -C $(LIBFT) debug
	$(CC) $(CFLAGS_D) $(SRC) -I $(SDL_DIR)/include/SDL $(S_D) \
		-L$(SDL_DIR)/lib -lSDL -lSDLmain -Wl,-framework,Cocoa\
		-lSDL -lSDL_image -lSDL_mixer -lSDL_ttf libft/libft.a \
		-o $(NAME)

linux: $(SRC)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -I $(SDL_DIR)/include/SDL $(S_D) \
		-L$(SDL_DIR)/lib -lSDL -lSDLmain -lSDL -lSDL_image -lSDL_mixer \
		-lSDL_ttf libft/libft.a \
		-o $(NAME)
	make -C $(LIBFT) clean

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY : fclean re all linux debug
