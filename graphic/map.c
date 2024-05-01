/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:18 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/01 14:52:07 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_map(t_info *ptr, int i)//les position du joueur doit deprendre de sa pos de depart
{
	(void)i;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
	return (0);
}

int	window_creation(t_data *data, t_utils *utils)
{
	t_info	ptr;
	t_math	ma;
	(void)data;

	ptr.utils = utils;
	if (init_struct(&ptr, utils, &ma) == 1)
		return (1);
	ptr.img.mlx_img = mlx_new_image(ptr.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ptr.img.addr = mlx_get_data_addr(ptr.img.mlx_img, &ptr.img.bpp,
			&ptr.img.line_len, &ptr.img.endian);
	mlx_loop_hook(ptr.mlx, &render, &ptr);
	mlx_hook(ptr.win, 17, 0, mouse_hook, &ptr);
	mlx_key_hook(ptr.win, get_key_hook, &ptr);
	mlx_loop(ptr.mlx);
	mlx_destroy_image(ptr.mlx, ptr.img.mlx_img);
	mlx_destroy_display(ptr.mlx);
	free(ptr.mlx);
	return (0);
}

void	print_img_simulation(t_info *ptr, int x, int j, t_math *ma)
{
	int		c;
	void	*tmp;

	c = 0;
	if (j < ptr->ma->draw_start)
		while (j++ < ptr->ma->draw_start)
			render_rect(&ptr->img, (t_rect){x, j, 1, 1, ptr->crgb});
	if (j < ma->draw_end)
	{
		while (j++ < ma->draw_end)
		{
			tmp = ptr->img.mlx_img;
			// envoyer l'image concerne: suivant si je pointe vers le Nord Sud Est ou West
			// il faut que je trouve comment avoir la couleur du pixel de l'image
			// parcourir l'image au meme coordonnee que ma fenetre puis recuperer
			// mon pixel
			// ptr->img.mlx_img = get_image(ptr, ma);
			image_helper(ptr, x, j, ma);
			img_pix_put(&ptr->img, x, j, c++);
			ptr->img.mlx_img = tmp;
		}
	}
	if (j > ma->draw_end)
		while (j++ < WINDOW_HEIGHT)
			img_pix_put(&ptr->img, x, j, ptr->frgb);
}

void	image_helper(t_info *ptr, int x, int j, t_math* ma)
{
	(void)x;
	(void)j;
	(void)ptr;
	double	step;
	double	texpos;
	int		texy;
	int		y;
	int		color;

	step = 1 * tex_height / ma->line_Height;
	texpos = (ma->draw_start - WINDOW_HEIGHT / 2 + ma->line_Height / 2) * step;
	y = ma->draw_start;
	while (y < ma->draw_end)
	{
		texy = (int)texpos  + (texhight - 1);
		texpos += step;
		color = texture[texnum][texheight * texy + texx];
		
		y++;
	}
}

void *get_image(t_info *ptr, t_math *ma)
{
	if (ma->raydirx == 1 && ma->side == 0)
		return (ptr->img_1); // Est
	else if (ma->raydiry == -1 && ma->side == 0)
		return (ptr->img_2); // West
	else if (ma->raydiry == 1 && ma->side == 1)
		return (ptr->img_3); // North
	else if (ma->raydiry == -1 && ma->side == 0)
		return (ptr->img_4); // South
	// printf("voici une texture %s\n", ptr->img_1);
	return (NULL);
}
