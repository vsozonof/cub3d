/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:40:16 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/02 12:13:26 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// x gauche a droite
// y haut en bas

int	found_player_pos_x(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'N' || argv[i][j] == 'S'
				|| argv[i][j] == 'W' || argv[i][j] == 'E')
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	found_player_pos_y(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'N' || argv[i][j] == 'S'
				|| argv[i][j] == 'W' || argv[i][j] == 'E')
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	found_player_type(t_utils *utils)
{
	int i;
	int	j;

	i = 0;
	while (utils->map[i])
	{
		j = 0;
		while (utils->map[i][j])
		{
			if (utils->map[i][j] == 'N')
				return (1);
			else if (utils->map[i][j] == 'S')
				return (2);
			else if (utils->map[i][j] == 'E')
				return (3);
			else if (utils->map[i][j] == 'W')
				return (4);
			j++;
		}
		i++;
	}
	return (0);
}
