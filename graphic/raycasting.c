/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/11 11:58:44 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_info *ptr)
{
	int		x;
	t_math	*ma;
	(void)ptr;

	x = 0;
	ma = ptr->ma;
	while (x < WINDOW_WIDTH)
	{
		// calculate ray position and direction
		ma->camerax = 2 * x / WINDOW_WIDTH -1; // x coordinate in camera space
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
		ma->deltadistx = sqrt(1 + (ma->raydiry * ma->raydiry) / (ma->raydirx * ma->raydirx));
      	ma->deltadisty = sqrt(1 + (ma->raydirx * ma->raydirx) / (ma->raydiry * ma->raydiry));
		// printf("ma->raudirx %f\n", ma->raydirx);
		// printf("ma->raudiry %f\n", ma->raydiry);
		// printf("deltadisty %f\n", ma->deltadisty);
		ma->hit = 0;
		if (ma->raydirx < 0)
		{
			// printf("si raydirx < 0\n");
			ma->stepx = -1;
			ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
			// printf("posx %f mapx %d deltadistx %f\n", ma->posx, ma->mapx, ma->deltadistx);
			// printf("voici le resultat %f\n", (ma->posx - ma->mapx) * ma->deltadistx);
		}
		else
		{
			// printf("si raydirx le reste\n");
			ma->stepx = 1;
			ma->sidedistx = (ma->mapx + 1.0 - ma->posx) * ma->deltadistx;
			// printf("posx %f mapx %d deltadistx %f\n", ma->posx, ma->mapx, ma->deltadistx);
			// printf("voici le resultat %f\n", (ma->posx - ma->mapx) * ma->deltadistx);
		}
		if (ma->raydiry < 0)
		{
			// printf("si raydiry < 0\n");
			ma->stepy = -1;
			ma->sidedisty = (ma->posy - ma->mapy) * ma->deltadisty;
			// printf("posy %f mapy %d deltadisty %f\n", ma->posy, ma->mapy, ma->deltadisty);
			// printf("voici le resultat %f\n", (ma->posy - ma->mapy) * ma->deltadisty);
		}
		else
		{
			// printf("si raydiry le reste\n");
			ma->stepy = 1;
			ma->sidedisty = (ma->mapy + 1.0 - ma->posy) * ma->deltadisty;
			// printf("posy %f mapy %d deltadisty %f\n", ma->posy, ma->mapy, ma->deltadisty);
			// printf("voici le resultat %f\n", (ma->posy - ma->mapy) * ma->deltadisty);
		}
		// printf("deltadisty %f\n MAINTENANT ", ma->deltadisty);
		// printf("mapy %d posy %f\n", ma->mapy, ma->posy);
		// printf("AVANT L'APPEL PRINTF\n");
		// printf("voici sidex %f et sidey %f\n", ma->sidedistx, ma->sidedisty);
		digital_differential_analyser(ma, ptr);
		if (ma->side == 0)
		{
			printf("side = 0\n");
			printf("======\nvoici side %f\n", ma->sidedistx);
			printf("voici delta %f\n", ma->deltadistx);
			ma->perpwalldist = (ma->sidedistx - ma->deltadistx);
		}
		else
		{
			printf("side = ou plus\n");
			printf("======\nvoici side %f\n", ma->sidedisty);
			printf("voici delta %f\n", ma->deltadisty);
			ma->perpwalldist = (ma->sidedisty - ma->deltadisty);
		}
		ma->line_Height = (WINDOW_HEIGHT / ma->perpwalldist); // le probleme viens du fait que ma division est fausse
		// printf("voici perpwalldist %f\n", ma->perpwalldist); //c ar perpwalldist est de 0 et c'est lui qui divise
		// printf("voici map_height %d\n", ma->map_height);
		// printf("essaie line Height / 2 %d\n", ma->line_Height / 2);
		// printf("essaie line Height tout court %d\n", ma->line_Height);
		// printf("!!voici le resultat de l'equation entre perpwalldist et map height %d\n", ma->line_Height / 2 + ma->map_height / 2);
		ma->draw_start = -ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		// printf("line height / 2 = %d\n", ma->line_Height / 2);
		// printf("map_height = %d\n", 2 + ma->map_height / 2);
		if (ma->draw_start < 0)
			ma->draw_start = 0;
		ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		if (ma->draw_end >= WINDOW_HEIGHT)
			ma->draw_end = WINDOW_HEIGHT - 1;
		printf("voici mon draw_start %d\n", ma->draw_start);
		// wall_creation_minimap(ptr); // je me sers pas des draw start/end car pas
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
			ma->sidedisty += ma->deltadisty;
			ma->mapy += ma->stepy;
			ma->side = 1;
		}
		// printf("voici mes co x %f et y %f\n", ma->mapx, ma->mapy);
		// if (ma->mapx < 0 || ma->mapy < 0)
		// {
		// 	ma->out = 1;
		// 	return ;
		// }
		// if (ma->mapx > ma->map_width || ma->mapy > ma->map_height)
		// {
		// 	ma->hit = 1;
		// }
		// printf("may %d side %f\n", ma->mapy, ma->sidedisty);
		if (ptr->map[ma->mapx][ma->mapy] > 0)
			ma->hit = 1;
	}
}
