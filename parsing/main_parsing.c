/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:54:57 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/20 11:41:46 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_map_to_double_char(t_data *data, t_utils *utils)
{
	utils->map = ft_split(data->map, '\n');
}

int	parsing_manage(t_data *data, int argc, char **argv, t_utils *utils)
{
	pr_parsing_start();
	if (is_there_enough_args(argc))
		return (1);
	data->map_name = argv[1];
	if (argument_checker(data))
		return (memory_handler(data, utils), 1);
	if (map_file_parser(data))
		return (memory_handler(data, utils), 1);
	if (are_params_valid(data, utils))
		return (memory_handler(data, utils), 1);
	put_map_to_double_char(data, utils);
	if (is_map_valid(data, utils))
		return (memory_handler(data, utils), 1);
	free(data->map);
	return (0);
}
