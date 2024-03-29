# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 14:09:59 by vsozonof          #+#    #+#              #
#    Updated: 2024/03/29 14:42:26 by tpotilli         ###   ########.fr        #
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
	   parsing/params_checker.c \
	   parsing/texture_utils-1.c \
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
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) -lreadline $(SRCS_LIB)
	@echo "                                   \r\c"

%.o: %.c
	@echo "$(RD)🧊 CUB3D -\t$(WH)$(BL)Compiling $(OR)($<)$(WH)\c\r"
	@$(CC) $(CFLAGS) -Imlx_linux -c -o $@ $< $(INCLUDES)
	@echo "                                   \r\c"

init:
	make all -C ./libft

clean:
		make clean -C ./libft
		@$(RM) $(OBJS)
		@echo "$(RD)🧊 CUB3D -\t$(WH)$(GR)All .o files were deleted !$(WH)"

fclean: 
		make fclean -C ./libft
		@$(RM) $(NAME) $(OBJS)
		@echo "$(RD)🧊 CUB3D -\t$(WH)$(GR)All .o files and binaries were deleted !$(WH)"

re: fclean all

.PHONY: all clean fclean re init