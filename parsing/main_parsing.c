/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:54:57 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/02 10:50:18 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_map_in_double_char_theo_suce_moi_stp(t_data *data, t_utils *utils)
{
	utils->map = ft_split(data->map, '\n');
}

int	parsing_manager(t_data *data, int argc, char **argv, t_utils *utils)
{
	pr_parsing_start();
	if (is_there_enough_args(argc))
		return (1);
	data->map_name = argv[1];
	if (argument_checker(data))
		return (1);
	if (map_file_parser(data))
		return (1);
	if (are_params_valid(data, utils))
		return (1);
	if (is_map_valid(data))
		return (1);
	put_map_in_double_char_theo_suce_moi_stp(data, utils);
	int i = 0;
	while (utils->map[i])
	{
		printf("-> %s\n", utils->map[i]);
		i++;
	}
	return (0);
}
