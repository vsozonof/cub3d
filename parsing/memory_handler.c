/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:09:25 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/20 12:20:11 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	memory_handler(t_data *data, t_utils *utils)
{
	free_memory_data(data);
	free_memory_utils(utils);
}

void	free_memory_utils(t_utils *utils)
{
	if (utils->mlx)
	{
		mlx_destroy_display(utils->mlx);
		free(utils->mlx);
	}
	if (utils->north)
		free(utils->north);
	if (utils->south)
		free(utils->south);
	if (utils->west)
		free(utils->west);
	if (utils->east)
		free(utils->east);
	if (utils->floor_color)
	{	
		if (utils->floor_color[0])
			free(utils->floor_color[0]);
		if (utils->floor_color[1])
			free(utils->floor_color[1]);
		if (utils->floor_color[2])
			free(utils->floor_color[2]);
		free(utils->floor_color);
	}
	ft_split_free(utils->map);
	free_memory_utils_2(utils);
}

void	free_memory_utils_2(t_utils *utils)
{
	if (utils->ceiling_color)
	{
		if (utils->ceiling_color[0])
			free(utils->ceiling_color[0]);
		if (utils->ceiling_color[1])
			free(utils->ceiling_color[1]);
		if (utils->ceiling_color[2])
			free(utils->ceiling_color[2]);
		free(utils->ceiling_color);
	}
}

void	free_memory_data(t_data *data)
{
	if (data->map)
		free(data->map);
	if (data->north_texture)
		free(data->north_texture);
	if (data->south_texture)
		free(data->south_texture);
	if (data->east_texture)
		free(data->east_texture);
	if (data->west_texture)
		free(data->west_texture);
	if (data->floor_color)
		free(data->floor_color);
	if (data->ceiling_color)
		free(data->ceiling_color);
}
