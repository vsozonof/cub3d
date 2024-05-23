/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/23 11:42:26 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_struct(t_info *ptr, t_utils *util, t_math *ma)
{
	ptr->mlx = util->mlx;
	ptr->win = mlx_new_window(ptr->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "my window");
	if (ptr->win == NULL)
	{
		free_parsing_fonction(ptr);
		free(ptr->mlx);
		return (1);
	}
	ptr->p_mov = 0;
	ptr->pa = 90;
	ptr->ma = ma_init(ma, ptr);
	ptr->img.mlx_img = mlx_new_image(ptr->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!ptr->img.mlx_img)
	{
		free_parsing_fonction(ptr);
		mlx_destroy_window(ptr->mlx, ptr->win);
		mlx_destroy_display(ptr->mlx);
		free(ptr->mlx);
		return (1);
	}
	return (0);
}

t_math	*ma_init(t_math *ma, t_info *ptr)
{
	ma->posx = found_player_pos_x(ptr->utils->map) + 0.5;
	if (ma->posx < 0)
		return (NULL);
	ma->posy = found_player_pos_y(ptr->utils->map) + 0.5;
	if (ma->posy < 0)
		return (NULL);
	setup_cardinal_point(ma, ptr);
	ma->out = 0;
	return (ma);
}

void	setup_cardinal_point(t_math *ma, t_info *ptr)
{
	if (player_tag(ptr) == 1)
	{
		ma->dirx = 0;
		ma->diry = -1;
		ma->planex = 0.66;
		ma->planey = 0;
	}
	else if (player_tag(ptr) == 2)
	{
		ma->dirx = 0;
		ma->diry = 1;
		ma->planex = -0.66;
		ma->planey = 0;
	}
	else
		setup_cardinal_helper(ma, ptr);
}

void	setup_cardinal_helper(t_math *ma, t_info *ptr)
{
	if (player_tag(ptr) == 3)
	{
		ma->dirx = 1;
		ma->diry = 0;
		ma->planex = 0;
		ma->planey = 0.66;
	}
	else if (player_tag(ptr) == 4)
	{
		ma->dirx = -1;
		ma->diry = 0;
		ma->planex = 0;
		ma->planey = -0.66;
	}
}

void	initialize_tex(t_info *ptr)
{
	ptr->tex[0].save = mlx_xpm_file_to_image(ptr->utils->mlx,
		ptr->data->north_texture, &ptr->tex[0].w, &ptr->tex[0].h);
	ptr->tex[1].save = mlx_xpm_file_to_image(ptr->utils->mlx,
		ptr->data->east_texture, &ptr->tex[1].w, &ptr->tex[1].h);
	ptr->tex[2].save = mlx_xpm_file_to_image(ptr->utils->mlx,
		ptr->data->south_texture, &ptr->tex[2].w, &ptr->tex[2].h);
	ptr->tex[3].save = mlx_xpm_file_to_image(ptr->utils->mlx,
		ptr->data->west_texture, &ptr->tex[3].w, &ptr->tex[3].h);
	check_xpm(ptr);
	initialize_addr(ptr);
}
