# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkok <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 12:19:29 by mkok              #+#    #+#              #
#    Updated: 2017/03/22 12:42:35 by mkok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAG = -g

LIBMLX =  -L mlx/ -lmlx -lm -framework OpenGL -framework AppKit

# gcc main.c -L. -lmlx -L libft/ -lft -framework OpenGL -framework AppKit
#
SRC =   ./src/main.c			\
		./src/read_all.c		\
		./src/to_int_map.c		\
		./src/to_c_list.c		\
		./src/draw.c			\
		./src/translate_z.c		\
		./src/validate.c		\
		./src/htoi.c			\
		./src/init_g_prop.c		\
		./src/init_c.c			\
		./src/print_c_list.c

OBJ = $(SRC:.c=.o)

LIBFT = -L libft/ -lft -I libft/

.PHONY:clean re all fclean

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAG) -o $(NAME) $(SRC) $(LIBFT) $(LIBMLX)
	@echo "\033[33;32m$(NAME) is ready :)"

%.o:%.c
	@$(CC) $(FLAG) -o $@ -c $< -I libft/ -I.

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "\x1b[36mclean ok"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\x1b[36mfclean ok"

re: fclean all
