/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:41 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/02 10:53:09 by vsozonof         ###   ########.fr       */
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

# include "../libft/includes/libft.h"
# include "mlx.h"

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


#endif