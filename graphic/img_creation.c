/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:12:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/06 10:23:02 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	handle_keypress(int keysym, t_info *ptr)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		ptr->win = NULL;
	}
	return (0);
}

int	render(t_info *ptr)
{
	if (ptr->win == NULL)
		return (1);
	// ptr->tex[1].img = mlx_new_image(ptr->mlx, 64, 64);
	// printf("voici endian %d\n", ptr->tex[1].endian);
	// printf("voici line_len %d\n", ptr->tex[1].line_len);
	// printf("voici bpp %d\n", ptr->tex[1].bpp);
	// ptr->tex[1].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[1].bpp,
	// 		&ptr->tex[1].line_len, &ptr->tex[1].endian);
	// ptr->tex[2].texture = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[3].texture = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[4].texture = mlx_new_image(ptr->mlx, 64, 64);
	// ptr->tex[2].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[2].bpp, &ptr->tex[2].line_len, &ptr->tex[2].endian);
	// ptr->tex[3].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[3].bpp, &ptr->tex[3].line_len, &ptr->tex[3].endian);
	// ptr->tex[4].addr = (int *)mlx_get_data_addr(ptr->utils->north, &ptr->tex[4].bpp, &ptr->tex[4].line_len, &ptr->tex[4].endian);
	render_background(&ptr->img, BLACK_PIXEL);
	render_rect(&ptr->img, (t_rect){0, 0,
		WINDOW_WIDTH, WINDOW_HEIGHT, BLACK_PIXEL});
	raycasting(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
	return (0);
}
