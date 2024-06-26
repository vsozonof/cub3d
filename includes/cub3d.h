/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:00:23 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/27 09:38:58 by tpotilli         ###   ########.fr       */
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
# define CHECK_COLORS	"Checking color codes"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
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
# include <math.h>

// ! ****************************************************
// ? 			Structure Declaration
// ! ****************************************************

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
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_math
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	posx;
	double	posy;
	double	dirx;
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
	double	texpos;
	double	wlx;
	int		fov;
	int		out;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		line_height;
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

typedef struct s_texture
{
	char	*texture;
	void	*img;
	int		*addr;
	void	*save;
	int		endian;
	int		line_len;
	int		bpp;
	int		w;
	int		h;
}	t_text;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_math	*ma;
	t_line	*line;
	t_utils	*utils;
	t_data	*data;
	t_text	tex[4];
	int		cur_img;
	int		p_mov;
	double	pa;
	int		w_size;
	int		fov;
	int		frgb;
	int		crgb;
	int		maps;
	int		x_map_max;
	int		y_map_max;
	int		token;
}	t_info;

// ! ****************************************************
// ? 			MAIN && INITIALIZATION
// ! ****************************************************

int			main(int argc, char **argv);
void		initialize_struct(t_data *data, t_utils *utils);

// ! ****************************************************
// ? 			BASIC PARSING
// ! ****************************************************

int			parsing_manage(t_data *data, int argc, char **argv, t_utils *utils);
int			is_there_enough_args(int n);
int			argument_checker(t_data *data);
int			read_map(t_data *data);
int			open_map(char *map_name);
int			is_valid_name(char *map_name);

// ! ****************************************************
// ? 			MAP FILE PARSING
// ! ****************************************************

int			map_file_parser(t_data *data);
int			texture_path_getter(t_data *data, int i);
int			color_code_getter(t_data *data, int i);
int			double_checker_1(char *str, int *i, int mode, t_data *data);
int			double_checker_2(char *str, int *i, int mode, t_data *data);
char		*extract_path(char *str, int *i);
int			are_params_valid(t_data *data, t_utils *utils);

// ! ****************************************************
// ? 			GAME MAP PARSING
// ! ****************************************************

int			is_map_valid(t_data *data, t_utils *utils);
int			check_map(char **map, int len);

// ! ****************************************************
// ? 			CHECKING WALLS VALIDITY
// ! ****************************************************

int			are_walls_placed_correctly(t_utils *utils);
int			check_first_line(char *f_line, int *len);
int			check_last_line(char *line);
void		replace_wspace_by_walls(char **map);

// ! ****************************************************
// ? 			PARSING UTILS
// ! ****************************************************

int			get_n_lines(char *map);
int			double_tab_len(char **p);
void		pr_parsing_start(void);
void		pr_msg(char *msg, int mode);
void		pr_error_spe(char *msg, int *i);

// ! ****************************************************
// ? 			Graphics Handler
// ! ****************************************************

int			render(t_info *info);
int			mouse_hook(t_info *ptr);
int			get_key_hook(int keycode, t_info *ptr);
void		close_windows_esc(t_info *ptr);
int			found_player_type(t_utils *utils);
int			found_player_pos_x(char **argv);
int			found_player_pos_y(char **argv);
void		struct_map(char **map, t_info *ptr);
void		img_pix_put(t_img *img, int x, int y, int color);
void		render_background(t_img *img, int color);
int			render_rect(t_img *img, t_rect rect);
int			handle_keypress(int keysym, t_info *ptr);
int			window_creation(t_utils *utils, t_data *data);
int			get_key_hook(int keycode, t_info *ptr);
int			try_moove(t_info *ptr);
int			init_struct(t_info *ptr, t_utils *util, t_math *ma);
void		found_pos_player_minimap(t_info *ptr);
int			check_keycode(int keycode);
void		player_pov_rotation(t_math *ma, int input);
void		make_ray(t_info *ptr, int fi_x, int fi_y);
void		raycasting(t_info *ptr);
void		digital_dif_analyser(t_math *ma, t_info *ptr);
void		player_movement_map(t_math *ma, int input, t_info *ptr);
void		delta_distance_calculation(t_math *ma, int x);
void		ray_calculation(t_math *ma);
void		finish_calcul_and_print(t_info *ptr, t_math *ma, int x, int j);
void		setup_cardinal_point(t_math *ma, t_info *ptr);
int			player_tag(t_info *ptr);
int			len_map(char *str);
void		player_movement_front(double x, double y, t_info *ptr, t_math *ma);
void		player_movement_side(double x, double y, t_info *ptr, t_math *ma);
int			len_db_tab(char **map);
int			setup_color_ceiling_floor(t_info *ptr);
void		print_img_simulation(t_info *ptr, int x, int j, t_math *ma);
int			verify_texture(t_info *ptr, int texn, int y, int x);
t_math		*ma_init(t_math *ma, t_info *ptr);
void		initialize_tex(t_info *ptr);
void		free_db_tab(char **map);
void		setup_cardinal_helper(t_math *ma, t_info *ptr);
void		free_all_img(t_info *ptr);
void		free_parsing_fonction(t_info *ptr);
void		check_xpm(t_info *ptr);
void		initialize_addr(t_info *ptr);
void		free_all_bef(t_info *ptr);

// ! ****************************************************
// ? 			Program Memory Handler
// ! ****************************************************

void		memory_handler(t_data *data, t_utils *utils);
void		free_memory_data(t_data *data);
void		free_memory_utils(t_utils *utils);
void		free_memory_utils_2(t_utils *utils);
void		free_and_set_to_null_1(t_data *data);
void		free_and_set_to_null_2(t_data *data);

#endif