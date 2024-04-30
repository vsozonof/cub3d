/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/30 16:00:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_info *ptr)
{
	int		x;
	int		j;
	t_math	*ma;

	x = 0;
	ma = ptr->ma;
	setup_color_ceiling_floor(ptr);
	while (x < WINDOW_WIDTH)
	{
		delta_distance_calculation(ma, x);
		ray_calculation(ma);
		digital_differential_analyser(ma, ptr);
		j = 0;
		finish_calcul_and_print(ptr, ma, x, j);
		x++;
	}
}

void	delta_distance_calculation(t_math *ma, int x)
{
	ma->camerax = 2 * x / (double)WINDOW_WIDTH - 1;
	if (ma->camerax == 0)
		ma->camerax = 0.001042;
	ma->raydirx = ma->dirx + ma->planex * ma->camerax;
	ma->raydiry = ma->diry + ma->planey * ma->camerax;
	ma->mapx = (int)ma->posx;
	ma->mapy = (int)ma->posy;
	if (ma->raydirx == 0)
		ma->deltadistx = 1;
	else
		ma->deltadistx = fabs(1 / ma->raydirx);
	if (ma->raydiry == 0)
		ma->deltadisty = 1;
	else
		ma->deltadisty = fabs(1 / ma->raydiry);
	ma->hit = 0;
}

void	ray_calculation(t_math *ma)
{
	if (ma->raydirx < 0)
	{
		ma->stepx = -1;
		ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
	}
	else
	{
		ma->stepx = 1;
		ma->sidedistx = (ma->mapx + 1.0 - ma->posx) * ma->deltadistx;
	}
	if (ma->raydiry < 0)
	{
		ma->stepy = -1;
		ma->sidedisty = (ma->posy - ma->mapy) * ma->deltadisty;
	}
	else
	{
		ma->stepy = 1;
		ma->sidedisty = (ma->mapy + 1.0 - ma->posy) * ma->deltadisty;
	}
}

void	digital_differential_analyser(t_math *ma, t_info *ptr)
{
	int 	i;
	int 	j;

	while (ma->hit == 0)
	{
		i = 0;
		j = 0;
		if (ma->sidedistx < ma->sidedisty)
		{
			ma->sidedistx += ma->deltadistx;
			i = len_map(ptr->utils->map[ma->mapy]);
			ma->mapx += ma->stepx;
			ma->side = 0;
		}
		else
		{
			ma->sidedisty += ma->deltadisty;
			i = len_map(ptr->utils->map[ma->mapy]);
			ma->mapy += ma->stepy;
			ma->side = 1;
		}
		if (ma->mapx < 0 || ma->mapy < 0)
		{
			ma->hit = 1;
			break ;
		}
		if (ptr->utils->map[ma->mapy][ma->mapx] == '1')
			ma->hit = 1;
	}
}

void	finish_calcul_and_print(t_info *ptr, t_math *ma, int x, int j)
{
	if (ma->side == 0)
			ma->perpwalldist = (ma->sidedistx - ma->deltadistx);
	else
		ma->perpwalldist = (ma->sidedisty - ma->deltadisty);
	ma->line_Height = (int)(WINDOW_HEIGHT / ma->perpwalldist);
	ma->draw_start = -ma->line_Height / 2 + WINDOW_HEIGHT / 2;
	if (ma->draw_start < 0)
		ma->draw_start = 0;
	ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
	if (ma->draw_end >= WINDOW_HEIGHT || ma->draw_end < 0)
		ma->draw_end = WINDOW_HEIGHT - 1;
	print_img_simulation(ptr, x, j, ma);
}
