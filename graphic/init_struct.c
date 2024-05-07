/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/07 14:32:55 by tpotilli         ###   ########.fr       */
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

//mlx file to img

t_info	initialize_tex(t_info ptr)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	ptr.tex[0].save = mlx_xpm_file_to_image(ptr.utils->mlx, "texture/colorstone.xpm",
			&img_width, &img_height);
	ptr.tex[1].save = mlx_xpm_file_to_image(ptr.utils->mlx, "texture/eagle.xpm",
			&img_width, &img_height);
	ptr.tex[2].save = mlx_xpm_file_to_image(ptr.utils->mlx, "texture/greystone.xpm",
			&img_width, &img_height);
	ptr.tex[3].save = mlx_xpm_file_to_image(ptr.utils->mlx, "texture/redbrick.xpm",
			&img_width, &img_height);
	ptr.tex[0].w = 64;
	ptr.tex[0].h = 64;
	ptr.tex[1].w = 64;
	ptr.tex[1].h = 64;
	ptr.tex[2].w = 64;
	ptr.tex[2].h = 64;
	ptr.tex[3].w = 64;
	ptr.tex[3].h = 64;
	ptr.tex[0].addr = (int *)mlx_get_data_addr(ptr.utils->north, &ptr.tex[0].bpp,
		&ptr.tex[0].line_len, &ptr.tex[0].endian);
	ptr.tex[1].addr = (int *)mlx_get_data_addr(ptr.utils->east, &ptr.tex[1].bpp,
		&ptr.tex[1].line_len, &ptr.tex[1].endian);
	ptr.tex[2].addr = (int *)mlx_get_data_addr(ptr.utils->south, &ptr.tex[2].bpp,
		&ptr.tex[2].line_len, &ptr.tex[2].endian);
	ptr.tex[3].addr = (int *)mlx_get_data_addr(ptr.utils->west, &ptr.tex[3].bpp,
		&ptr.tex[3].line_len, &ptr.tex[3].endian);
	return (ptr);
}
