/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:56:01 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/02 10:52:36 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	are_walls_placed_correctly(t_data *data)
{
	char	*tmp;

	tmp = ft_strtrim(data->map, "\n");
	free(data->map);
	data->map = tmp;
	replace_wspace_by_walls(data->map);
	if (check_first_line(data->map))
		return (1);
	else if (check_last_line(data->map, get_n_lines(data->map)))
		return (1);
	return (0);
}

void	replace_wspace_by_walls(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == ' ' || map[i] == '\t')
			map[i] = '1';
		i++;
	}
}

// int	check_core_lines(char *map)
// {
	// 
// }

int	check_first_line(char *map)
{
	int	i;

	i = 0;
	while (map[i] && (map[i] == ' ' || map[i] == '\t'))
		i++;
	while (map[i] && map[i] != '\n')
	{
		if (map[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_last_line(char *map, int n_lines)
{
	int	i;

	i = 0;
	while (map[i] && n_lines > 0)
	{
		if (map[i] == '\n')
			n_lines--;
		i++;
	}
	while (map[i])
	{
		if (map[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}