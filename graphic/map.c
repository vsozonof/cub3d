/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:18 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/22 15:51:40 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	window_creation(t_utils *utils, t_data *data)
{
	t_info	ptr;
	t_math	ma;
	int		i;

	i = 0;
	ptr.data = data;
	ptr.utils = utils;
	if (init_struct(&ptr, utils, &ma) == 1)
		exit (1);
	initialize_tex(&ptr);
	while (i < 4)
	{
		if (ptr.tex[i].w != 64 || ptr.tex[i].h != 64)
			free_all_img(&ptr);
		i++;
	}
	ptr.img.addr = mlx_get_data_addr(ptr.img.mlx_img, &ptr.img.bpp,
			&ptr.img.line_len, &ptr.img.endian);
	if (!ptr.img.addr)
		free_all_img(&ptr);
	printf("coucouc\n");
	mlx_loop_hook(ptr.mlx, &render, &ptr);
	mlx_hook(ptr.win, 17, 0, mouse_hook, &ptr);
	mlx_key_hook(ptr.win, get_key_hook, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}

void	print_img_simulation(t_info *ptr, int x, int j, t_math *ma)
{
	int		w;

	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, ptr->crgb});
	if (j < ma->draw_end)
	{
		w = 0;
		if (ptr->ma->side == 0 && ptr->ma->raydirx < 0)
			w = 3;
		if (ptr->ma->side == 0 && ptr->ma->raydirx >= 0)
			w = 1;
		if (ptr->ma->side == 1 && ptr->ma->raydiry >= 0)
			w = 2;
		j = verify_texture(ptr, w, j, x);
	}
	while (j++ < WINDOW_HEIGHT)
		img_pix_put(&ptr->img, x, j, ptr->frgb);
}

static	int	ft_texx(t_info *ptr, int texx, int texn)
{
	if (ptr->ma->side == 0 && ptr->ma->raydirx < 0)
		texx = ptr->tex[texn].w - texx - 1;
	if (ptr->ma->side == 0 && ptr->ma->raydirx >= 0)
		texx = texx - ptr->tex[texn].w - 1;
	if (ptr->ma->side == 1 && ptr->ma->raydiry >= 0)
		texx = ptr->tex[texn].w - texx - 1;
	return (texx);
}

int	verify_texture(t_info *ptr, int texn, int y, int x)
{
	int			texx;
	int			texy;
	double		step;

	if (ptr->ma->side == 0)
		ptr->ma->wlx = ptr->ma->posy + ptr->ma->perpwalldist * ptr->ma->raydiry;
	else
		ptr->ma->wlx = ptr->ma->posx + ptr->ma->perpwalldist * ptr->ma->raydirx;
	ptr->ma->wlx -= floor((ptr->ma->wlx));
	step = 1.0 * ptr->tex[texn].h / ptr->ma->line_height;
	texx = (int)(ptr->ma->wlx * (double)ptr->tex[texn].w);
	texx = ft_texx(ptr, texx, texn);
	ptr->ma->texpos = \
	(ptr->ma->draw_start - WINDOW_HEIGHT / 2 + ptr->ma->line_height / 2) * step;
	while (y <= ptr->ma->draw_end)
	{
		texy = (int)ptr->ma->texpos & (ptr->tex[texn].h - 1);
		ptr->ma->texpos += step;
		if (y < (WINDOW_HEIGHT - 1) && x < (WINDOW_WIDTH - 1))
			img_pix_put(&ptr->img, x, y,
				ptr->tex[texn].addr[texy * ptr->tex[texn].line_len / 4 + texx]);
		y++;
	}
	return (y);
}
