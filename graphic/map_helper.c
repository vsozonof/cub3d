/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:05:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/17 10:42:23 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pov_rotation(t_math *ma, int input)
{
	double	olddirx;
	double	oldplanex;

	olddirx = ma->dirx;
	if (input == 5)
	{
		ma->dirx = ma->dirx * cos(-0.2) - ma->diry * sin(-0.2);
		ma->diry = olddirx * sin(-0.2) + ma->diry * cos(-0.2);
		oldplanex = ma->planex;
		ma->planex = ma->planex * cos(-0.2) - ma->planey * sin(-0.2);
		ma->planey = oldplanex * sin(-0.2) + ma->planey * cos(-0.2);
	}
	else if (input == 7)
	{
		ma->dirx = ma->dirx * cos(0.2) - ma->diry * sin(0.2);
		ma->diry = olddirx * sin(0.2) + ma->diry * cos(0.2);
		oldplanex = ma->planex;
		ma->planex = ma->planex * cos(0.2) - ma->planey * sin(0.2);
		ma->planey = oldplanex * sin(0.2) + ma->planey * cos(0.2);
	}
}

void	player_movement_map(t_math *ma, int input, t_info *ptr)
{
	double	x;
	double	y;

	y = ma->posy;
	x = ma->posx;
	if (input == 1 || input == 3)
		player_movement_front(x, y, ptr, ma);
	else
		player_movement_side(x, y, ptr, ma);
}

void	player_movement_front(double x, double y, t_info *ptr, t_math *ma)
{
	int		vertical_len;
	int		horizontal_len;

	if (ptr->p_mov == 1)
	{
		if (x + 0.2 < 0)
			return ;
		x += ma->dirx * 0.2;
		y += ma->diry * 0.2;
	}
	else if (ptr->p_mov == 3)
	{
		if (x - 0.2 < 0)
			return ;
		x -= ma->dirx * 0.2;
		y -= ma->diry * 0.2;
	}
	vertical_len = len_db_tab(ptr->utils->map);
	horizontal_len = ft_strlen(ptr->utils->map[(int)y]) - 1;
	if (y < 1 || x < 1 || vertical_len <= (int)y || horizontal_len <= (int)x)
		return ;
	if (ptr->utils->map[(int)y][(int)x] == '1')
		return ;
	ma->posy = y;
	ma->posx = x;
}

void	player_movement_side(double x, double y, t_info *ptr, t_math *ma)
{
	int		vertical_len;
	int		horizontal_len;

	if (ptr->p_mov == 2)
	{
		if (y - 0.2 < 0)
			return ;
		x -= ma->planex * 0.2;
		y -= ma->planey * 0.2;
	}
	else if (ptr->p_mov == 4)
	{
		if (y + 0.2 < 0)
			return ;
		x += ma->planex * 0.2;
		y += ma->planey * 0.2;
	}
	vertical_len = len_db_tab(ptr->utils->map);
	horizontal_len = ft_strlen(ptr->utils->map[(int)y]) - 1;
	if (y < 1 || x < 1 || vertical_len <= (int)y || horizontal_len <= (int)x)
		return ;
	if (ptr->utils->map[(int)y][(int)x] == '1')
		return ;
	ma->posy = y;
	ma->posx = x;
}

void	found_pos_player_minimap(t_info *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr->utils->map[i])
	{
		j = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == 'N' || ptr->utils->map[i][j] == 'S'
				|| ptr->utils->map[i][j] == 'W' || ptr->utils->map[i][j] == 'E')
			{
				ptr->ma->posx = WINDOW_WIDTH - 50;
				ptr->ma->posy = 50;
			}
			j++;
		}
		i++;
	}
}
