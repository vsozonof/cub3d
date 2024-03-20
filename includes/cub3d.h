/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:41 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/20 14:08:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define CHECK_N_ARG	"Checking argument number"
# define CHECK_F_NAME	"Checking file name"
# define OPEN_FILE		"Opening file"
# define READ_MAP		"Reading map file"
# define GET_PARAMS		"Gathering parameters"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300
#define MLX_ERROR 1
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	char	*map_name;
	char	*map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceiling_color;
	int		fd;
}	t_data;

// typedef struct s_game
// {
// 	int		x;
// 	int		y;
// 	int		nb_item;
// 	int		nb_exit;
// 	int		nb_player;
// 	int		p_x;
// 	int		p_y;
// 	int		exit_x;
// 	int		exit_y;
// 	int		exit;
// 	int		p_mov;
// 	int		mov;
// 	void	*mlx;
// 	void	*win;
// 	char	**map;
// 	char	*img_0;
// 	char	*img_1;
// 	char	*img_2;
// 	char	*img_3;
// 	char	*img_4;
// 	char	*img_5;
// }		t_game;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct t_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		cur_img;
}	t_game;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

int		main(int argc, char **argv);
void	initialize_struct(t_data *data);

int		parsing_manager(t_data *data, int argc, char **argv);
int		is_there_enough_args(int n);
int		argument_checker(t_data *data);
int		read_map(t_data *data);
int		open_map(char *map_name);
int		is_valid_name(char *map_name);

int		map_file_parser(t_data *data);

int		texture_path_getter(t_data *data, int i);
int		color_code_getter(t_data *data, int i);
int		double_checker_1(char *str, int *i, int mode, t_data *data);
int		double_checker_2(char *str, int *i, int mode, t_data *data);
char	*extract_path(char *str, int *i);

// ! Printing
void	pr_parsing_start(void);
void	pr_msg(char *msg, int mode);
void	pr_error_spe(char *msg, int *i);

//graphic
void		img_pix_put(t_img *img, int x, int y, int color);
int			render_rect(t_img *img, t_rect rect);
void		render_background(t_img *img, int color);
int			handle_keypress(int keysym, t_data *data);
int			render(t_data *data);
int			exec_ta_vue(void);



#endif