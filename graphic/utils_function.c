/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:11:39 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/07 11:14:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_map(char **map, t_info *ptr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	len++;
	ptr->utils->map = malloc(sizeof(char *) * (len + 1));
	while (map[i])
	{
		j = 0;
		ptr->utils->map[i] = malloc(sizeof(char) * (len + 1));
		while (map[i][j])
		{
			ptr->utils->map[i][j] = map[i][j];
			j++;
		}
		ptr->utils->map[i][j] = '\0';
		i++;
	}
	ptr->utils->map[i] = NULL;
}

int	len_db_tab(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map[i])
		i++;
	i--;
	return (i);
}

int	len_map(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	setup_color_ceiling_floor(t_info *ptr)
{
	ptr->crgb = ft_atoi(ptr->utils->ceiling_color[0]) * 65536
		+ ft_atoi(ptr->utils->ceiling_color[1]) * 256
		+ ft_atoi(ptr->utils->ceiling_color[2]);
	ptr->frgb = ft_atoi(ptr->utils->floor_color[0]) * 65536
		+ ft_atoi(ptr->utils->floor_color[1]) * 256
		+ ft_atoi(ptr->utils->floor_color[2]);
	return (0);
}
