# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/21 11:49:49 by nado-nas          #+#    #+#              #
#    Updated: 2025/10/23 18:15:55 by nado-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = srcs/my_main.c srcs/utils.c srcs/error.c #srcs/pipex.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes -Ilibft
LIBFT_PATH = libft
MAKE_LIBFT = make -C $(LIBFT_PATH)
LIBFT = -L $(LIBFT_PATH) -lft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE_LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE_LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE_LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re