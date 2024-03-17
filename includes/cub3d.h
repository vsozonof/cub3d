/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:11:41 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/17 16:28:47 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define CHECK_N_ARG	"Checking argument number"
# define CHECK_F_NAME	"Checking file name"
# define OPEN_FILE		"Opening file"
# define READ_MAP		"Reading map file"

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


#endif