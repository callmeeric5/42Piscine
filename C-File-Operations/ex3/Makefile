# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 11:41:15 by ziwang            #+#    #+#              #
#    Updated: 2026/02/14 11:46:35 by ziwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_hexdump
SRC = main.c ft_hexdump.c utilis.c
OBJ := $(SRC:%.c=%.o)
HEADER = ft_hexdump.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
