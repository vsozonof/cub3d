/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:05:40 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/20 13:07:08 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_set_to_null_1(t_data *data)
{
	if (data->floor_color)
	{
		free(data->floor_color);
		data->floor_color = NULL;
	}
	if (data->ceiling_color)
	{
		free(data->ceiling_color);
		data->ceiling_color = NULL;
	}
	free_and_set_to_null_2(data);
}

void	free_and_set_to_null_2(t_data *data)
{
	if (data->north_texture)
	{
		free(data->north_texture);
		data->north_texture = NULL;
	}
	if (data->east_texture)
	{
		free(data->east_texture);
		data->east_texture = NULL;
	}
	if (data->west_texture)
	{
		free(data->west_texture);
		data->west_texture = NULL;
	}
	if (data->south_texture)
	{
		free(data->south_texture);
		data->south_texture = NULL;
	}
}