/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_checker-2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:09:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/06 07:08:29 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx_ptr(t_utils *utils)
{
	pr_msg(INIT_MLX, 0);
	utils->mlx = mlx_init();
	// if (!(utils->mlx))
	// {
	// 	pr_msg(INIT_MLX, 1);
	// 	return (pr_error("Failed to load the MiniLibX"));
	// }
	pr_msg(INIT_MLX, 2);
	return (0);
}

int	are_textures_valid(t_data *data, t_utils *utils)
{
	int	img_width;
	int	img_height;

	pr_msg(CHECK_TEXTUR, 0);
	utils->north = mlx_xpm_file_to_image(utils->mlx, data->north_texture,
			&img_width, &img_height);
	utils->south = mlx_xpm_file_to_image(utils->mlx, data->south_texture,
			&img_width, &img_height);
	utils->east = mlx_xpm_file_to_image(utils->mlx, data->east_texture,
			&img_width, &img_height);
	utils->west = mlx_xpm_file_to_image(utils->mlx, data->west_texture,
			&img_width, &img_height);
	// if (!utils->north || !utils->south || !utils->east || !utils->west)
	// {
	// 	pr_msg(CHECK_TEXTUR, 1);
	// 	return (pr_error("A texture is invalid"));
	// }
	pr_msg(CHECK_TEXTUR, 2);
	return (0);
}

int	are_colors_valid(t_data *data, t_utils *utils)
{
	(void)data;
	(void)utils;
	return (0);
}

int	are_params_valid(t_data *data, t_utils *utils)
{
	(void)data;
	if (init_mlx_ptr(utils))
		return (1);
	if (are_textures_valid(data, utils))
		return (1);
	
	return (0);
}
