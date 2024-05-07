/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:11:39 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/07 09:18:05 by tpotilli         ###   ########.fr       */
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

int		len_map(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	setup_color_ceiling_floor(t_info *ptr)
{
	ptr->crgb =  ft_atoi(ptr->utils->ceiling_color[0]) * 65536 + ft_atoi(ptr->utils->ceiling_color[1]) * 256 + ft_atoi(ptr->utils->ceiling_color[2]);
	ptr->frgb = ft_atoi(ptr->utils->floor_color[0]) * 65536 + ft_atoi(ptr->utils->floor_color[1]) * 256 + ft_atoi(ptr->utils->floor_color[2]);
	return (0);
}

int	init_wall(t_info *ptr, int i)
{
	t_text	tex;

	tex.addr = (int *)mlx_get_data_addr(ptr->utils->north, &tex.bpp,
			&tex.line_len, &tex.endian);
	ptr->tex[i] = tex;
	// printf("%d %d\n", tex.h, tex.w);
	// if (tex.h != 64 || tex.w != 64)
		// return (-1);
	// 	&ptr->tex[0].line_len, &ptr->tex[0].endian);
	// ptr->tex.img = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex.addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex.bpp,
		// &ptr->tex.line_len, &ptr->tex.endian);
	// tex[0].img = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[0].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[0].bpp,
	// 	&ptr->tex[0].line_len, &ptr->tex[0].endian);
	// if (!ptr->tex[0].img)
	// 	return (-1);
	// ptr->tex[1].img = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[1].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[1].bpp,
	// 	&ptr->tex[1].line_len, &ptr->tex[1].endian);
	// if (!ptr->tex[1].img)
	// 	return (-1);
	// ptr->tex[2].img = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[2].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[2].bpp,
	// 	&ptr->tex[2].line_len, &ptr->tex[2].endian);
	// if (!ptr->tex[2].img)
	// 	return (-1);
	// ptr->tex[3].img = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[3].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[3].bpp,
	// 	&ptr->tex[3].line_len, &ptr->tex[3].endian);
	// if (!ptr->tex[3].img)
	// 	return (-1);
	return (0);
}
