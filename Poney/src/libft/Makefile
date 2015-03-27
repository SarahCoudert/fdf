# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoudert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/13 16:10:00 by scoudert          #+#    #+#              #
#    Updated: 2015/03/26 18:34:36 by scoudert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

DEBUG = $(CFLAGS) -g

CFLAGS=-Wall -Wextra -Werror

SRC= del.c ft_lstdel.c ft_putchar.c ft_putnbr_fd.c ft_tabnew.c tab_merge_sort.c\
ft_lstadd.c ft_lstdelone.c ft_putchar_fd.c ft_putn.c get_next_line.c \
ft_lstaddend.c ft_lstiter.c ft_putendl.c ft_putstr.c ft_lstcountbytes.c \
ft_lstmap.c ft_putendl_fd.c ft_putstr_fd.c ft_itoa.c\
ft_lstcountelements.c ft_lstnew.c ft_putnbr.c ft_swap.c

OBJ=$(SRC:.c=.o)

RM=rm -f

H_PATH= ../includes/

.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@echo "\033[32mCompile all \".c\"\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) -I $(H_PATH)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)

clean:
	@echo "\033[31mDelete all \".o\" in libft\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[31mDelete libft.a\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(H_PATH)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[36mCreate libft.a \033[0m"
	@ranlib $(NAME)
