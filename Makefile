# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 14:57:47 by igaliuk           #+#    #+#              #
#    Updated: 2018/01/23 12:37:52 by igaliuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
NAME3 = randomizer

CC = gcc

FLAG = -Wall -Wextra -Werror

VPATH = sources

INC = ./headers

SRC = ft_checksort.c \
	ft_checkflags.c \
	ft_error.c \
	ft_lsts.c \
	ft_readstacka.c \
	ft_swaps.c \
	ft_usa.c \
	ft_zero.c
SRC1 = push_swap.c \
	ft_badsort.c \
	ft_sorta.c \
	ft_sortalast.c \
	ft_sortb.c \
	ft_sortblast.c \
	ft_stepa.c \
	ft_stepb.c \
	ft_reca.c \
	ft_recb.c \
	ft_tofin.c \
	ft_updatesort.c 
SRC2 = checker.c \
	ft_flags.c \
	ft_operations.c \
	get_next_line.c
SRC3 = randomizer.c

OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

all: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1) $(OBJ)
	@echo "       Compiling push_swap....\n"
	make -C sources/libft
	@$(CC) $(FLAG) sources/libft/libft.a -o $@ $^
	@ranlib sources/libft/libft.a

$(NAME2): $(OBJ2) $(OBJ)
	@echo "       Compiling checker....\n"
	@$(CC) $(FLAG) sources/libft/libft.a -o $@ $^

$(NAME3): $(OBJ3) 
	@echo "       Compiling randomizer....\n"
	@$(CC) $(FLAG) -o $@ $^

%.o: %.c
	@$(CC) $(FLAG) -I$(INC) -c -o $@ $<

clean:
	@echo "\n       Deleting objects....\n"
	@rm -f $(OBJ) $(OBJ1) $(OBJ2) $(OBJ3)
	make clean -C sources/libft

fclean: clean
	@echo "       Deleting objects and binary file....\n"
	@rm -f $(NAME1) $(NAME2) $(NAME3)
	make fclean -C sources/libft

re: fclean all
