/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:59:18 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/28 12:31:11 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	make_map(t_info *ptr, int i)//les position du joueur doit deprendre de sa pos de depart
{
	(void)i;
	// render_background(&ptr->img, BLACK_PIXEL);
	// render_rect(&ptr->img, (t_rect){0, 0,
				// WINDOW_WIDTH, WINDOW_HEIGHT, BLACK_PIXEL});
	// wall_creation_map(ptr, i);
	// player_creation_minimap(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
	return (0);
}

/*
int	make_map(t_info *ptr)//les position du joueur doit deprendre de sa pos de depart
{
	(void)ptr;
	// int		map_w;
	// int		map_h;

	// map_w = WINDOW_WIDTH / 100 * 10;
	render_background(&ptr->img, BLACK_PIXEL);
	render_rect(&ptr->img, (t_rect){0, 0, // le deuxieme est la hauteur
				WINDOW_WIDTH, WINDOW_HEIGHT, BLACK_PIXEL});
	// wall_creation_minimap(ptr);
	// player_creation_minimap(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
	return (0);
}
*/

int	window_creation(t_data *data, t_utils *utils)
{
	t_info	ptr;
	t_math	ma;

	ptr.utils = utils;
	if (init_struct(&ptr, utils, &ma) == 1)
		return (1);
	ptr.crgb = data->ceiling_color;
	ptr.frgb = data->floor_color;
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

/* code du 6 avril, juste la minimap
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
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

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

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
	make_minimap(ptr);
	return (0);
}

int	make_minimap(t_info *ptr)//les position du joueur doit deprendre de sa pos de depart
{
	// int		map_w;
	// int		map_h;

	// map_w = WINDOW_WIDTH / 100 * 10;
	render_background(&ptr->img, WHITE_PIXEL);
	render_rect(&ptr->img, (t_rect){WINDOW_WIDTH - 100, 0, // le deuxieme est la hauteur
				100, 100, GREEN_PIXEL});
	// render_rect(&ptr->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	wall_creation_minimap(ptr);
	player_creation_minimap(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
	return (0);
}

// render_rect(&ptr->img, (t_rect){WINDOW_WIDTH - 50, 50,
				// 5, 5, YELLOW_PIXEL});

int	window_creation(t_data *data, t_utils *utils)
{
	(void)data;
	(void)utils;
	t_info	ptr;

	init_struct(&ptr, utils);
	struct_map(utils->map, &ptr);
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

int		init_struct(t_info *ptr, t_utils *util)
{
	ptr->mlx = util->mlx;
	if (ptr->mlx == NULL)
		return (MLX_ERROR);
	ptr->win = mlx_new_window(ptr->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (ptr->win == NULL)
	{
		free(ptr->win);
		return (MLX_ERROR);
	}
	found_pos_player_minimap(ptr);
	ptr->ma->posx = WINDOW_WIDTH - 50;
	ptr->ma->posy = 50;
	ptr->ma->posx = cos(ptr->pa) * 5;
	ptr->ma->posy = sin(ptr->pa) * 5;
	ptr->p_mov = 0;
	ptr->pa = 90;
	return (0);
}

*/