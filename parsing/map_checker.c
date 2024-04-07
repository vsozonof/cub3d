/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:01:07 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/07 10:25:29 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_n_lines(char *map)
{
	int	len;
	int	lines;
	int	i;

	lines = 0;
	len = 0;
	i = 0;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
		{
			if (lines == 0)
				len++;
			i++;
		}
		lines++;
		if (map[i] == '\n')
			i++;
	}
	return (lines);
}

int	is_map_valid(t_data *data)
{
	pr_msg("Checking the map\n", 0); // j'ai mis un \n a ton print
	if (are_walls_placed_correctly(data))
		return (pr_error("The walls are placed incorrectly."));
	return (0);
}
