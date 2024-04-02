# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/04/02 10:55:56 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -I/usr/include -Imlx_linux -g3
INCLUDES = -I/usr/include -Imlx

BL=\033[1;34m
GR=\033[1;32m
OR=\033[1;33m
RD=\033[1;31m
WH=\033[0m

SRCS_LIB = libft/libft.a \

SRCS = main.c \
	   parsing/main_parsing.c \
	   parsing/init_struct.c \
	   parsing/argument_checker.c \
	   parsing/params_checker-1.c \
	   parsing/params_checker-2.c \
	   parsing/texture_utils-1.c \
	   parsing/map_checker.c \
	   parsing/wall_checker.c \
	   parsing/printers/print-tools-1.c \
	   graphic/graphic1.c \
	   graphic/exemple_graphic.c \
	   graphic/window_create.c \
	   graphic/players_utils.c \


OBJS = $(SRCS:.c=.o)

RM = rm -f
MLX_DIR = ./mlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz

all: init $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(RD)🧊 CUB3D -\t$(WH)$(BL)Linking $(OR)($<)$(WH)\r"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(SRCS_LIB) $(MLX_FLAGS)
	@echo "                                   \r\c"

%.o: %.c
	@echo "$(RD)🧊 CUB3D -\t$(WH)$(BL)Compiling $(OR)($<)$(WH)\c\r"
	@$(CC) $(CFLAGS) -Imlx_linux -c -o $@ $< $(INCLUDES)
	@echo "                                   \r\c"

init:
	make all -C ./libft
	make all -C ./mlx

clean:
		make clean -C ./libft
		make clean -C ./mlx
		@$(RM) $(OBJS)
		@echo "$(RD)🧊 CUB3D -\t$(WH)$(GR)All .o files were deleted !$(WH)"

fclean: 
		make fclean -C ./libft
		make clean	-C ./mlx
		@$(RM) $(NAME) $(OBJS)
		@echo "$(RD)🧊 CUB3D -\t$(WH)$(GR)All .o files and binaries were deleted !$(WH)"

re: fclean all

.PHONY: all clean fclean re init