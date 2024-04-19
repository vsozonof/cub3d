/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/19 11:26:18 by vsozonof         ###   ########.fr       */
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
	while (x < WINDOW_WIDTH)
	{
		ma->camerax = 2 * x / (double)WINDOW_WIDTH - 1;
		// printf("!!!!!!!!!!!!!!voici x %d\n", x);
		// printf("voici camera %f et maintenant voici ses composante\n %d %d\n", ma->camerax, 2 * x, WINDOW_WIDTH - 1);
		ma->raydirx = ma->dirx + ma->planex * ma->camerax;
		ma->raydiry = ma->diry + ma->planey * ma->camerax;
		// printf("===voici resultat %f\n", ma->diry + ma->planey * ma->camerax);
		// printf("===voici les composante du calcul diry %f, planey %f camerax %f\n", ma->diry, ma->planey, ma->camerax);
		// printf("voici raydiry %f et  raydirx %f\n", ma->raydiry, ma->raydirx);
		ma->mapx = (int)ma->posx;
		ma->mapy = (int)ma->posy;
		ma->deltadistx = fabs(1 / ma->raydirx);
		ma->deltadisty = fabs(1 / ma->raydiry);
		ma->hit = 0;
		// printf("voici deltadisty %f et deltax %f\n", ma->deltadisty, ma->deltadistx);
		if (ma->raydirx < 0)
		{
			ma->stepx = -1;
			ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
			printf("je passe par le 1|||| donc voici mes nombre %f %d %f\n", ma->posx, ma->mapx, ma->deltadistx);
		}
		else
		{
			ma->stepx = 1;
			ma->sidedistx = (ma->mapx + 1.0 - ma->posx) * ma->deltadistx;
			printf("je passe par le 2|||| %f %d %f\n", ma->posx, ma->mapx, ma->deltadistx);
		}
		if (ma->raydiry < 0)
		{
			ma->stepy = -1;
			ma->sidedisty = (ma->posy - ma->mapy) * ma->deltadisty;
			printf("je passe par le 3|||| %f %d %f\n", ma->posy, ma->mapy, ma->deltadisty);
		}
		else
		{
			ma->stepy = 1;
			ma->sidedisty = (ma->mapy + 1.0 - ma->posy) * ma->deltadisty;
			printf("je passe par le 4|||| %f %d %f\n", ma->posy, ma->mapy, ma->deltadisty);
		}
		// printf("voici sidetx %f et sidety %f\n", ma->sidedistx, ma->sidedisty);
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
			// printf("voici sidex %f y %f mapx %d y %d\n", ma->sidedistx, ma->sidedisty, ma->mapx, ma->mapy);
			// if (map->mapx > limite_map || mapy > limit_map) // faire cette condition
			if (ptr->map[ma->mapx][ma->mapy] > 0)
				ma->hit = 1;
		}
		if (ma->side == 0)
		{
			ma->perpwalldist = (ma->sidedistx - ma->deltadistx);
			// printf("voici side = 0 sidesity %f et delta %f\n", ma->sidedistx, ma->deltadistx);
		}
		else
		{
			// printf("==voici side = 1 sidesity %f et delta %f\n", ma->sidedistx, ma->deltadistx);
			ma->perpwalldist = (ma->sidedisty - ma->deltadisty);
			// printf("donc la mon perpwalldist est egal a ca %f pourtant le calcul donne ca %f\n==", ma->perpwalldist, ma->sidedisty - ma->deltadisty);
		}
		ma->line_Height = (int)(WINDOW_HEIGHT / ma->perpwalldist);
		// printf("== perp %f ", ma->perpwalldist);
		// printf("line %d ==\n", ma->line_Height);
		ma->draw_start = -ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		// printf("start = %d - %d\n", ma->draw_start, ma->line_Height);
		if (ma->draw_start < 0) // probleme avec draw_start aussi
			ma->draw_start = 0;
		ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		// printf("draw end %d\n", ma->draw_end);
		// if (ma->draw_end < 0)
			// ma->draw_end *= -1;
		if (ma->draw_end >= WINDOW_HEIGHT || ma->draw_end < 0)
			ma->draw_end = WINDOW_HEIGHT - 1;
		// ma->draw_end /= 2;
		// printf("valeur draw_start %d\n", ma->draw_start);
		// printf("valeur draw_end %d\n", ma->draw_end);
		// usleep(10000);
		j = 0;
		// ma->draw_end = ma->draw_end / 2;
		// ma->draw_start = 150; //CHANGER LES START ET END CAR C'EST PAS BON
		if (j < ptr->ma->draw_start)
		{
			while (j++ < ptr->ma->draw_start)
				render_rect(&ptr->img, (t_rect){x, j, 1, 1, BLUE_PIXEL});
		}
		// printf("je passe le plafond\n");
		if (j < ma->draw_end)
			while (j++ < ma->draw_end)
				img_pix_put(&ptr->img, x, j, RED_PIXEL);
		// printf("je passe le mur\n");
		if (j > ma->draw_end)
			while (j++ < WINDOW_HEIGHT)
				img_pix_put(&ptr->img, x, j, GREEN_PIXEL);
		// printf("je passe le sol\n");
		usleep(5000000);
		x++;
	}
}

/*
void	raycasting(t_info *ptr)
{
	int		x;
	t_math	*ma;

	x = 0;
	ma = ptr->ma;
	while (x < WINDOW_WIDTH)
	{
		ma->camerax = 2 * x / WINDOW_WIDTH - 1;
		ma->raydirx = ma->dirx + ma->planex * ma->camerax;
		ma->raydiry = ma->diry + ma->planey * ma->camerax;
		ma->deltadistx = fabs(1 / ma->raydirx);
		ma->deltadisty = fabs(1 / ma->raydiry);
		ma->mapx = (int)ma->posx;
		ma->mapy = (int)ma->posy;
		if (ma->raydirx == 0)
			ma->deltadistx = 1e30;
		else
			ma->deltadistx = fabs(1 / ma->raydirx);
		if (ma->raydiry == 0)
			ma->deltadisty = 1e30;
		else
			ma->deltadisty = fabs(1 / ma->raydiry);

		ma->hit = 0;
		printf("================\n");
		if (ma->raydirx < 0)
		{
			ma->stepx = -1;
			ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
			printf("je suis dans le premier if\n");
		}
		else
		{
			ma->stepx = -1;
			ma->sidedistx = (ma->mapx + 1.0 - ma->posx) * ma->deltadistx;
			printf("je suis dans le second if\n");
		}
		if (ma->raydiry < 0)
		{
			ma->stepy = -1;
			ma->sidedisty = (ma->posy - ma->mapy) * ma->deltadisty;
			printf("je suis dans le troisieme if\n");
		}
		else
		{
			ma->stepy = 1;
			ma->sidedisty = (ma->mapy + 1.0 - ma->posy) * ma->deltadisty;
			printf("je suis dans le dernier if\n");
		}
		printf("voici la formule %f\n", (ma->posx - ma->mapx) * ma->deltadistx);
		printf("voici delta %f\n", ma->deltadistx);
		printf("voici le premier side %f\n", ma->sidedistx);
		while (ma->hit == 0)
		{
			if (ma->sidedistx < ma->sidedisty)
			{
				printf("sidex est plus petit que y\n");
				printf("side %f delta %f\n", ma->sidedistx, ma->deltadistx);
				ma->sidedistx += ma->deltadistx;
				ma->mapx += ma->stepx;
				ma->side = 0;
			}
			else
			{
				printf("Y est plus petit que x\n");
				ma->sidedisty += ma->deltadisty;
				ma->mapy += ma->stepy;
				ma->side = 1;
			}
			if (ptr->map[ma->mapx][ma->mapy] > 0)
				ma->hit = 1;
		}
		printf("voici le second side %f\n", ma->sidedistx);
		if (ma->side == 0)
			ma->perpwalldist = (ma->sidedistx - ma->deltadistx);
		else
			ma->perpwalldist = (ma->sidedisty - ma->deltadisty);
		ma->line_Height = (WINDOW_HEIGHT / ma->perpwalldist);
		printf("donc voici line_height %f %d\n", ma->perpwalldist, WINDOW_HEIGHT);
		ma->draw_start = -ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		if (ma->draw_start < 0)
			ma->draw_start = 0;
		ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
		printf("voici draw_end %d, %d\n", ma->line_Height, 2 + WINDOW_HEIGHT / 2);
		// printf("valeur draw_end %d\n", ma->draw_end);
		// printf("WIND_HEIGHT %d\n", WINDOW_HEIGHT);
		// if (ma->draw_end < 0)
			// ma->draw_end *= -1;
		if (ma->draw_end >= WINDOW_HEIGHT)
			ma->draw_end = WINDOW_HEIGHT - 1;
		x++;
		printf("voici draw_start %d end %d\n", ma->draw_start, ma->draw_end);
		printf("voici x %d\n", x);
	}
}
*/