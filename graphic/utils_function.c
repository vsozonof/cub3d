/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:11:39 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/27 10:59:31 by tpotilli         ###   ########.fr       */
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

void	show_db_tab(char **map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("la map\n");
	if (!map)
		return ;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return ;
}

int		len_map(char *str) // strlen pour la map car les mur peuvent etre multiple
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			return (i);
		i++;
	}
	return (i);
}
