/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:01:16 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/20 11:30:27 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_struct(t_data *data, t_utils *utils)
{
	data->map_name = NULL;
	data->map = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->ceiling_color = NULL;
	data->floor_color = NULL;
	utils->map = NULL;
	utils->north = NULL;
	utils->south = NULL;
	utils->west = NULL;
	utils->east = NULL;
	utils->floor_color = NULL;
	utils->ceiling_color = NULL;
	utils->mlx = NULL;
}
