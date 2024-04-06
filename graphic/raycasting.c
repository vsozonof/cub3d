/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/06 15:03:07 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_info *ptr)
{
	int		x;
	double	w;
	t_math	*ma;
	(void)ptr;

	x = 0;
	w = 1;
	ma = ptr->ma;
	while (x < w)
	{
		// calculate ray position and direction
		ma->camerax = 2 * x / w -1; // x coordinate in camera space
		ma->raydirx = ma->dirx + ma->planex * ma->camerax;
		ma->raydiry = ma->diry + ma->planey * ma->camerax;
		printf("voici dirx %f et diry %f\n", ma->dirx, ma->diry);
		printf("voici planex %f et planey %f\n", ma->planex, ma->planey);
		printf("voici camerax %f\n", ma->camerax);
	
		ma->mapx = (int)ma->posx; // dans quel case nous somme
		ma->mapy = (int)ma->posy;

		//longueur du rayon depuis notre position
		if (ma->raydirx == 0)
		{
			ma->deltadistx = 1e30;
			ma->deltadistx = abs(1 / (int)ma->raydirx);
		}
		if (ma->raydiry == 0)
		{
			ma->deltadisty = 1e30;
			ma->deltadisty = abs(1 / (int)ma->raydiry);
		}
		ma->hit = 0;
		
		if (ma->raydirx < 0)
		{
			ma->stepx = -1;
			ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
		}
		else
		{
			ma->stepx = 1;
			ma->sidedistx = (ma->mapx + 1 - ma->posx) * ma->deltadistx;
		}
		if (ma->raydiry < 0)
		{
			ma->stepy = -1;
			ma->sidedisty = (ma->posy - ma->mapy) * ma->deltadisty;
		}
		else
		{
			ma->stepy = 1;
			ma->sidedisty = (ma->mapy + 1 - ma->posy) * ma->deltadisty;
		}
		// digital differenctial analyser
		digital_differential_analyser(ma, ptr);
		if (ma->side == 0)
			ma->perpwalldist = (ma->sidedistx - ma->deltadistx);
		else
			ma->perpwalldist = (ma->sidedisty - ma->deltadisty);
		ma->line_Height = (int)(WINDOW_HEIGHT / ma->perpwalldist);
		
		ma->draw_start = -ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		if (ma->draw_start < 0)
			ma->draw_end = 0;
		ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		if (ma->draw_end >= WINDOW_HEIGHT)
			ma->draw_end = WINDOW_HEIGHT - 1;
		x++;
	}
}

void	digital_differential_analyser(t_math *ma, t_info *ptr)
{
	while (ma->hit == 0)
	{
		//jump to the next map square, either in x -direction or y
		if (ma->sidedistx < ma->sidedisty)
		{
			ma->sidedistx += ma->deltadistx;
			ma->mapx += ma->stepx;
			ma->side = 0;
		}
		else
		{
			ma->sidedisty += ma->deltadistx;
			ma->mapy += ma->stepy;
			ma->side = 1;
		}
		if (ptr->map[ma->mapx][ma->mapy] > 0)
			ma->hit = 1;
	}
}
