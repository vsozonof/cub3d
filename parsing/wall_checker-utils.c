/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker-utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:46:39 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/10 14:46:59 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	double_tab_len(char **p)
{
	int	i;

	i = 0;
	if (!p)
		return (-1);
	while (p[i])
		i++;
	return (i);
}

void	replace_wspace_by_walls(char **map)
{
	int	i;
	int	j;

	i = ((j = 0));
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == ' ' || map[i][j] == '\t')
				map[i][j] = '1';
			j++;
		}
		i++;
		j = 0;
	}
}
