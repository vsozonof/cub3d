/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 09:28:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/27 14:29:42 by tpotilli         ###   ########.fr       */
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
		// printf("voici x %d\n", x);
		delta_distance_calculation(ma, x);
		ray_calculation(ma);
		digital_differential_analyser(ma, ptr);
		j = 0;
		finish_calcul_and_print(ptr, ma, x, j);
		// printf("voici ma boucle %d\n", x);
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
	// printf("voici le calcul 2 * %d / %d\n", x, WINDOW_WIDTH - 1);
	// printf("voici camerax %f\n", ma->camerax);
	// printf("voici mon raydirx %f et mon raydiry %f\n", ma->raydirx, ma->raydiry);
	// printf("voici raydirx %f\n", ma->raydirx);
	// printf("voici les composante de raydirx %f %f %f\n", ma->dirx, ma->planex, ma->camerax);
	ma->mapx = (int)ma->posx;
	ma->mapy = (int)ma->posy;
	if (ma->raydirx == 0)
		ma->deltadistx = 2;
	else
		ma->deltadistx = fabs(1 / ma->raydirx);
	if (ma->raydiry == 0)
		ma->deltadisty = 2;
	else
		ma->deltadisty = fabs(1 / ma->raydiry);
	// printf("voici deltax %f et voici deltay %f\n", ma->deltadistx, ma->deltadisty);
	ma->hit = 0;
}

void	ray_calculation(t_math *ma)
{
	if (ma->raydirx < 0)
	{
		ma->stepx = -1;
		ma->sidedistx = (ma->posx - ma->mapx) * ma->deltadistx;
		// printf("je passe par le 1|||| donc voici mes nombre %f %d %f\n", ma->posx, ma->mapx, ma->deltadistx);
	}
	else
	{
		ma->stepx = 1;
		ma->sidedistx = (ma->mapx + 1.0 - ma->posx) * ma->deltadistx;
		// printf("je passe par le 2|||| %f %d %f\n", ma->posx, ma->mapx, ma->deltadistx);
	}
	if (ma->raydiry < 0)
	{
		ma->stepy = -1;
		ma->sidedisty = (ma->posy - ma->mapy) * ma->deltadisty;
		// printf("je passe par le 3|||| %f %d %f\n", ma->posy, ma->mapy, ma->deltadisty);
	}
	else
	{
		ma->stepy = 1;
		ma->sidedisty = (ma->mapy + 1.0 - ma->posy) * ma->deltadisty;
		// printf("je passe par le 4|||| %f %d %f\n", ma->posy, ma->mapy, ma->deltadisty);
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
	// printf("voici mon perp %f voici mon line height %d\n", ma->perpwalldist, ma->line_Height);
	ma->draw_start = -ma->line_Height / 2 + WINDOW_HEIGHT / 2;
	if (ma->draw_start < 0)
		ma->draw_start = 0;
	ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
	if (ma->draw_end >= WINDOW_HEIGHT || ma->draw_end < 0)
		ma->draw_end = WINDOW_HEIGHT - 1;
	// printf("voici draw_start %d et end %d\n", ma->draw_start, ma->draw_end);
	if (x > 960)
	{
		// usleep(500000);
		// return ;
	}
	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, BLUE_PIXEL});
	if (j < ma->draw_end)
		while (j++ < ma->draw_end)
			img_pix_put(&ptr->img, x, j, RED_PIXEL);
	if (j > ma->draw_end)
		while (j++ < WINDOW_HEIGHT)
			img_pix_put(&ptr->img, x, j, GREEN_PIXEL);
}

/*
ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
	if (ma->draw_end >= WINDOW_HEIGHT || ma->draw_end < 0)
		ma->draw_end = WINDOW_HEIGHT - 1;
	if (j < ptr->ma->draw_start)
	{
		while (j++ < ptr->ma->draw_start)
		{
			// printf("1 j %d\n", j);
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, BLUE_PIXEL});
		}
	}
	if (j < ma->draw_end)
		while (j++ < ma->draw_end)
		{
			// printf("2 j %d\n", j);
			img_pix_put(&ptr->img, x, j, RED_PIXEL);
		}
	if (j > ma->draw_end)
		while (j++ < WINDOW_HEIGHT)
		{
			// printf("3 j %d\n", j);
			img_pix_put(&ptr->img, x, j, GREEN_PIXEL);
		}
*/

/*
void	finish_calcul_and_print(t_info *ptr, t_math *ma, int x, int j)
{
	ma->draw_end = ma->line_Height / 2 + WINDOW_HEIGHT / 2;
	if (ma->draw_end >= WINDOW_HEIGHT || ma->draw_end < 0)
		ma->draw_end = WINDOW_HEIGHT - 1;
	if (j < ptr->ma->draw_start)
	{
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, BLUE_PIXEL});
	}
	if (j < ma->draw_end)
		while (j++ < ma->draw_end)
			img_pix_put(&ptr->img, x, j, RED_PIXEL);
	if (j > ma->draw_end)
		while (j++ < WINDOW_HEIGHT)
			img_pix_put(&ptr->img, x, j, GREEN_PIXEL);
}
*/

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
			if (ptr->utils->map[ma->mapx][ma->mapy] > 0)
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