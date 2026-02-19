# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ziwang <ziwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 20:26:33 by ziwang            #+#    #+#              #
#    Updated: 2026/02/09 17:11:39 by ziwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = $(addprefix srcs/, ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c) main.c
OBJ := $(SRC:%.c=%.o)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I$(INC_DIR)
ARNAME = ar rcs $(NAME)
INC_DIR = includes
RM = rm -f
all: $(NAME)
$(NAME): $(OBJ)
	$(ARNAME) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
