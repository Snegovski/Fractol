# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 14:17:42 by ral-bakr          #+#    #+#              #
#    Updated: 2024/05/20 15:40:37 by ral-bakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -Ofast -fsanitize=address
RM		=	rm	-rf

SRCS 	=	fractol.c events.c mandelbrot.c julia.c atof.c

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re
