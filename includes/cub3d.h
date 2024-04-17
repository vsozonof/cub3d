/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:00:23 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/17 10:56:49 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define CHECK_N_ARG	"Checking argument number"
# define CHECK_F_NAME	"Checking file name"
# define OPEN_FILE		"Opening file"
# define READ_MAP		"Reading map file"
# define GET_PARAMS		"Gathering parameters"
# define CHECK_PARAMS	"Checking parameters"
# define INIT_MLX		"Initializing MiniLibX"
# define CHECK_TEXTUR	"Checking wall textures"

# define WINDOW_WIDTH 2560 //longueur
# define WINDOW_HEIGHT 1440 //largueur
# define MLX_ERROR 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF
# define YELLOW_PIXEL 0xFFFF00
# define BLACK_PIXEL 0x000000
# define BLUE_PIXEL 0x0000FF
# define PI 3.14159265359

# include "../libft/includes/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <math.h>

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

typedef struct s_utils
{
	void	*mlx;
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	**floor_color;
	char	**ceiling_color;
}	t_utils;

// typedef struct s_game
// {
// 	int		x;
// 	int		y;
// 	int		nb_exit;
// 	int		nb_player;
// 	int		px;
// 	int		py;
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
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_math
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	posx; // position player
	double	posy;
	double	dirx; // where the player look
	double	diry;
	double	planex;
	double	planey;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	old_dirx;
	double	old_diry;
	double	old_planex;
	double	wall_x;
	int		fov;
	int		out;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_Height;
	int		draw_start;
	int		draw_end;
}	t_math;

typedef struct s_line
{
	int		x;
	int		y;
	int		yb;
	int		yf;
	int		tex_x;
	int		tex_y;
}	t_line;

typedef struct s_info
{
    void	*mlx;
	void	*win;
	t_img	img;
	t_math	*ma;
	t_line	*line;
	int		cur_img;
	int		p_mov;
	double	pa; // player angle
	int		w_size;
	int		fov;
	char	**map;
	char	*frgb;
	char	*crgb;
	int		mapS;
	int		x_map_max;
	int		y_map_max;
}	t_info;

int		main(int argc, char **argv);
void	initialize_struct(t_data *data, t_utils *utils);

// Basic parsing

int		parsing_manager(t_data *data, int argc, char **argv, t_utils *utils);
int		is_there_enough_args(int n);
int		argument_checker(t_data *data);
int		read_map(t_data *data);
int		open_map(char *map_name);
int		is_valid_name(char *map_name);

// File parsing

int		map_file_parser(t_data *data);
int		texture_path_getter(t_data *data, int i);
int		color_code_getter(t_data *data, int i);
int		double_checker_1(char *str, int *i, int mode, t_data *data);
int		double_checker_2(char *str, int *i, int mode, t_data *data);
char	*extract_path(char *str, int *i);
int		are_params_valid(t_data *data, t_utils *utils);

// Map parsing

int		is_map_valid(t_data *data);
int		get_n_lines(char *map);

// WALL CHECKING
int		are_walls_placed_correctly(t_data *data);
int		check_first_line(char *map);
int		check_last_line(char *map, int n_lines);
void	replace_wspace_by_walls(char *map);

// ! Printing
void	pr_parsing_start(void);
void	pr_msg(char *msg, int mode);
void	pr_error_spe(char *msg, int *i);

//graphic

int			render(t_info *info);
int			exec_manager(int argc, char **argv, t_data *data, t_utils *utils);
int			exec_tmp(void);
int			window_create(t_data *data, t_utils *utils);
void		game_start(t_info *ptr);
int			mouse_hook(t_info *ptr);
int			get_key_hook(int keycode, t_info *ptr);
void		close_windows_esc(t_info *ptr);
int			essaie(t_data *data, t_info *ptr, t_utils *utils);

// graphic utils
int			found_player_type(t_utils *utils);
int			found_player_pos(char **argv);
int			refresh_player_pos(char **argv, t_info *ptr);
int			found_player_pos_x(char **argv);
int			found_player_pos_y(char **argv);
void		initialize_game(t_info *ptr);
void		struct_map(char **map, t_info *ptr);

//mini_map
int			minimap_manager(t_info *ptr);
int			draw_player_minimap(t_info *ptr);
int			draw_wall_minimap(t_info *ptr);
void		img_pix_put(t_img *img, int x, int y, int color);
void		render_background(t_img *img, int color);
int			render_rect(t_img *img, t_rect rect);
int			handle_keypress(int keysym, t_info *ptr);
int			window_creation(t_data *data, t_utils *utils);
int			make_minimap(t_info *ptr);
void		player_movement(t_math *ma, int input, t_info *ptr);
int			get_key_hook(int keycode, t_info *ptr);
int			try_moove(t_info *ptr);
int			init_struct(t_info *ptr, t_utils *util, t_math *ma);
void		wall_creation_minimap(t_info *ptr);
void		show_db_tab(char **map);
void		found_pos_player_minimap(t_info *ptr);
int			check_keycode(int keycode);
void		player_pov_rotation(t_math *ma, int input);
void		player_creation_minimap(t_info *ptr);
void		make_ray(t_info *ptr, int fi_x, int fi_y);
void		found_case_ray(int bgx, int bgy, int fix, int fiy);
void		raycasting(t_info *ptr);
int			make_map(t_info *ptr, int i);
void		digital_differential_analyser(t_math *ma, t_info *ptr);
t_math		*ma_init(t_math *ma);
void		player_movement_minimap(t_math *ma, int input, t_info *ptr);
void		wall_creation_map(t_info *ptr, int i);
void		make_cf(t_info *ptr);


#endif