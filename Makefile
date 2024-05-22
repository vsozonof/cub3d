# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/05/22 14:46:12 by tpotilli         ###   ########.fr        #
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
	   parsing/memory_handler.c \
	   parsing/memory_handler_extra.c \
	   parsing/argument_checker.c \
	   parsing/params_checker-1.c \
	   parsing/params_checker-2.c \
	   parsing/texture_utils-1.c \
	   parsing/map_checker.c \
	   parsing/wall_checker.c \
	   parsing/wall_checker-utils.c \
	   parsing/printers/print-tools-1.c \
	   graphic/players_utils.c \
	   graphic/map.c \
	   graphic/utils_function.c \
	   graphic/map_helper.c \
	   graphic/mlx_utils.c \
	   graphic/raycasting.c \
	   graphic/keys_hook.c \
	   graphic/init_struct.c\
	   graphic/img_creation.c \
	   graphic/free_function.c \
	   graphic/init_image.c \


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