/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/03 14:04:26 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_struct(t_info *ptr, t_utils *util, t_math *ma)
{
	ptr->mlx = util->mlx;
	if (ptr->mlx == NULL)
		return (MLX_ERROR);
	ptr->win = mlx_new_window(ptr->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "my window");
	if (ptr->win == NULL)
	{
		free(ptr->win);
		return (MLX_ERROR);
	}
	// tmp_image(ptr);
	ptr->p_mov = 0;
	ptr->pa = 90;
	ptr->ma = ma_init(ma, ptr);
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
	else if (player_tag(ptr) == 3)
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

int	player_tag(t_info *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr->utils->map[i])
	{
		j = 0;
		while (ptr->utils->map[i][j])
		{
			if (ptr->utils->map[i][j] == 'N')
				return (1);
			else if (ptr->utils->map[i][j] == 'S')
				return (2);
			else if (ptr->utils->map[i][j] == 'E')
				return (3);
			else if (ptr->utils->map[i][j] == 'W')
				return (4);
			j++;
		}
		i++;
	}
	return (-1);
}

// int	tmp_image(t_info *ptr)
// {
// 	ptr->ma->tex_height;
// 	ptr->ma->tex_width;

// 	ptr->img_1 = mlx_xpm_file_to_image(ptr->utils->mlx,
// 			"texture/colorstone.xpm", ma->tex_width, ma->tex_height);
// 	ptr->img_2 = mlx_xpm_file_to_image(ptr->utils->mlx,
// 			"texture/eagle.xpm", ma->tex_width, ma->tex_height);
// 	ptr->img_3 = mlx_xpm_file_to_image(ptr->utils->mlx,
// 			"texture/greystone.xpm", ma->tex_width, ma->tex_height);
// 	ptr->img_4 = mlx_xpm_file_to_image(ptr->utils->mlx,
// 			"texture/redbrick.xpm", ma->tex_width, ma->tex_height);
// 	return (0);
// }
