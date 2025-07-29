# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: elenpere <elenpere@student.42.fr>          #+#    #+#             #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-01-15 11:46:28 by elenpere          #+#    #+#             #
#   Updated: 2025-01-15 11:46:28 by elenpere         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTFT_DIR = ./printf
PRINTFT = $(PRINTFT_DIR)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = algorithm_chunk.c algorithm_small.c op_push.c op_reverse_rotate.c \
	op_rotate.c op_stack.c op_swap.c push_swap.c utils_general.c \
	utils_index.c utils_lists.c utils_num_validation.c utils_split.c utils_parsing.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(PRINTFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTFT):
	make -C $(PRINTFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTFT) -o $(NAME)

clean: 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re