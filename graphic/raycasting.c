/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/11 14:58:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_info *ptr)
{
	int		x;
	t_math	*ma;
	
	x = 0;
	ma = ptr->ma;
	while (x < WINDOW_WIDTH)
	{
		ma->camerax = 2 * x / WINDOW_WIDTH - 1; // peut etre devoir mettre le double
		ma->raydirx = ma->dirx + ma->planex * ma->camerax;
		ma->raydiry = ma->diry + ma->planey * ma->camerax;
		ma->deltadistx = fabs(1 / ma->raydirx);
		ma->deltadisty = fabs(1 / ma->raydiry);
		ma->mapx = ma->posx;
		ma->mapy = ma->posy;
		if (ma->raydirx == 0)
			ma->deltadistx = 1e30;
		else
			ma->deltadistx = fabs(1 / ma->raydirx);
		if (ma->raydiry == 0)
			ma->deltadisty = 1e30;
		else
			ma->deltadisty = fabs(1 / ma->raydiry);

		ma->hit = 0;
		if (ma->raydirx < 0)
		{
			ma->stepx = -1;
			ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
		}
		else
		{
			ma->stepx = -1;
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
		while (ma->hit == 0)
		{
			if (ma->sidedistx < ma->sidedisty)
			{
				ma->sidedistx += ma->deltadistx;
				ma->mapx += ma->stepx;
				ma->side = 0;
			}
			else
			{
				ma->sidedisty += ma->deltadisty;
				ma->mapy += ma->stepy;
				ma->side = 1;
			}
			if (ptr->map[ma->mapx][ma->mapy] > 0)
				ma->hit = 1;
		}
		if (ma->side == 0)
			ma->perpwalldist = (ma->sidedistx - ma->deltadistx);
		else
			ma->perpwalldist = (ma->sidedisty - ma->deltadisty);
		x++;
	}

}
