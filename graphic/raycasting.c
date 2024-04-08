/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/08 09:22:26 by tpotilli         ###   ########.fr       */
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
		// printf("voici raydirx %f et raydiry %f\n", ma->raydirx, ma->raydiry);
		// printf("voici planex %f et planey %f\n", ma->planex, ma->planey);
		// printf("planey %f et camerax %f\n", ma->planey, ma->camerax);
		// printf("voici camerax %f\n", ma->camerax);
		// printf("raydir %f\n", ma->raydiry);
		ma->mapx = (int)ma->posx; // dans quel case nous somme
		ma->mapy = (int)ma->posy;
		//longueur du rayon depuis notre position
		if (ma->raydirx == 0)
			ma->deltadistx = 1e30;
		else
			ma->deltadistx = fabs(1 / ma->raydirx);
		if (ma->raydiry == 0)
			ma->deltadisty = 1e30;
		else
			ma->deltadisty = fabs(1 / ma->raydiry);
		// printf("deltadisty %f\n", ma->deltadisty);
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
		// printf("deltadisty %f\n MAINTENANT ", ma->deltadisty);
		// printf("mapy %d posy %f\n", ma->mapy, ma->posy);
		// printf("AVANT L'APPEL PRINTF\n");
		// printf("voici sidex %f et sidey %f\n", ma->sidedistx, ma->sidedisty);
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
		wall_creation_minimap(ptr); // je me sers pas des draw start/end car pas
		x++;// encore a l'etape des murs
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
		// printf("may %d side %f\n", ma->mapy, ma->sidedisty);
		printf("voici mes co x %d et y %d\n", ma->mapx, ma->mapy);
		if (ptr->map[ma->mapx][ma->mapy] > 0)
			ma->hit = 1;
	}
}
