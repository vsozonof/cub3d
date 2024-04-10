/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:56:01 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/10 14:48:44 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	are_walls_placed_correctly(t_utils *utils)
{
	replace_wspace_by_walls(utils->map);
	if (check_map(utils->map, double_tab_len(utils->map)))
		return (1);
	return (0);
}

int	check_map_utils(char **map, int l_len, int x, int y)
{
	if (l_len > (int)ft_strlen(map[y]))
	{
		if (map[y][ft_strlen(map[y]) - 1] != '1')
			return (pr_error("uwu"));
		else
		{
			x = ft_strlen(map[y]);
			while (map[y - 1][x])
			{
				if (map[y - 1][x] != '1')
					return (pr_error("gowowowo"));
				x++;
			}
		}
	}
	else if (l_len < (int)ft_strlen(map[y]))
	{
		while (map[y][l_len])
		{
			if (map[y][l_len] != '1')
				return (pr_error("guwuwuwuwu"));
			l_len++;
		}
	}
	return (0);
}

int	check_map(char **map, int len)
{
	int	y;
	int	x;
	int	l_len;

	l_len = ((x = 0));
	if (check_first_line(map[0], &l_len))
		return (1);
	y = 1;
	while (y < len)
	{
		if (map[y][0] != '1')
			return (1);
		if (l_len == (int)ft_strlen(map[y]) && map[y][l_len - 1] != '1')
			return (1);
		else if (check_map_utils(map, l_len, x, y))
			return (1);
		l_len = ft_strlen(map[y]);
		y++;
	}
	if (check_last_line(map[y - 1]))
		return (1);
	return (0);
}

int	check_last_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != '1')
			return (1);
	return (0);
}

int	check_first_line(char *f_line, int *len)
{
	while (f_line[*len])
	{
		if (f_line[*len] != '1')
			return (1);
		*len += 1;
	}
	return (0);
}
