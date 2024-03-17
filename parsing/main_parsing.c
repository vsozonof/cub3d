/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:54:57 by vsozonof          #+#    #+#             */
/*   Updated: 2024/03/17 16:29:22 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parsing_manager(t_data *data, int argc, char **argv)
{
	pr_parsing_start();
	if (is_there_enough_args(argc))
		return (1);
	data->map_name = argv[1];
	if (argument_checker(data))
		return (1);
	if (map_file_parser(data))
		return (1);
	printf("NO = %s - SO = %s - EA = %s - WE = %s - F = %s - C = %s\n", data->north_texture, data->south_texture, data->east_texture, data->west_texture, data->floor_color, data->ceiling_color);
	return (0);
}
