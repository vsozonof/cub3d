/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checker-2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:09:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/23 11:52:21 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx_ptr(t_utils *utils)
{
	pr_msg(INIT_MLX, 0);
	utils->mlx = mlx_init();
	if (!(utils->mlx))
	{
		pr_msg(INIT_MLX, 1);
		return (pr_error("Failed to load the MiniLibX"));
	}
	pr_msg(INIT_MLX, 2);
	return (0);
}

int	are_textures_valid(t_data *data, t_utils *utils)
{
	int	img_width;
	int	img_height;

	pr_msg(CHECK_TEXTUR, 0);
	img_width = 64;
	img_height = 64;
	utils->north = mlx_xpm_file_to_image(utils->mlx, data->north_texture,
			&img_width, &img_height);
	utils->south = mlx_xpm_file_to_image(utils->mlx, data->south_texture,
			&img_width, &img_height);
	utils->east = mlx_xpm_file_to_image(utils->mlx, data->east_texture,
			&img_width, &img_height);
	utils->west = mlx_xpm_file_to_image(utils->mlx, data->west_texture,
			&img_width, &img_height);
	if (!utils->north || !utils->south || !utils->east || !utils->west)
	{
		pr_msg(CHECK_TEXTUR, 1);
		return (pr_error("A texture is invalid"));
	}
	pr_msg(CHECK_TEXTUR, 2);
	return (0);
}

int	are_colors_valid(t_data *data, t_utils *utils)
{
	int	i;

	((i = 0));
	utils->floor_color = ft_split(data->floor_color, ',');
	utils->ceiling_color = ft_split(data->ceiling_color, ',');
	while (utils->floor_color[i] && utils->ceiling_color[i])
	{
		if (ft_is_str_digit(utils->floor_color[i])
			&& ft_is_str_digit(utils->ceiling_color[i]))
			return (1);
		if (ft_atoi(utils->floor_color[i]) < 0
			|| ft_atoi(utils->floor_color[i]) > 255)
			return (1);
		if (ft_atoi(utils->ceiling_color[i]) < 0
			|| ft_atoi(utils->ceiling_color[i]) > 255)
			return (1);
		i++;
	}
	if (i != 3)
		return (1);
	free_and_set_to_null_1(data);
	return (0);
}

int	are_params_valid(t_data *data, t_utils *utils)
{
	if (init_mlx_ptr(utils))
		return (1);
	if (are_textures_valid(data, utils))
		return (1);
	pr_msg(CHECK_COLORS, 0);
	if (are_colors_valid(data, utils))
	{
		pr_msg(CHECK_COLORS, 1);
		return (pr_error("Invalid color code"));
	}
	pr_msg(CHECK_COLORS, 2);
	return (0);
}
