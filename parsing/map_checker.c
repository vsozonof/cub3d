/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:01:07 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/10 14:42:36 by vsozonof         ###   ########.fr       */
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

int	is_in_charset(char c, char cc)
{
	static int	flag;

	if (c == '1' || c == '0' || c == ' ')
		return (1);
	else if ((c == 'W' || c == 'N' || c == 'S' || c == 'E') && !flag)
	{
		flag = 1;
		return (1);
	}
	else if (c == '\n' && cc != '\n')
		return (1);
	else
		return (0);
}

int	charset_checker(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!is_in_charset(map[i], map[i + 1]))
			return (1);
		else
			i++;
	}
	return (0);
}

int	is_there_a_player(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (map[i] == 'N' || map[i] == 'S' || map[i] == 'W' || map[i] == 'E')
			return (1);
	return (0);
}

int	is_map_valid(t_data *data, t_utils *utils)
{
	pr_msg("Checking the map", 0);
	if (charset_checker(data->map))
	{
		pr_msg("Checking the map", 1);
		return (pr_error("Invalid character detected inside the map."));
	}
	if (!is_there_a_player(data->map))
	{
		pr_msg("Checking the map", 1);
		return (pr_error("No players detected."));
	}
	if (are_walls_placed_correctly(utils))
	{
		pr_msg("Checking the map", 1);
		return (pr_error("The walls are placed incorrectly."));
	}
	pr_msg("Checking the map", 2);
	return (0);
}
