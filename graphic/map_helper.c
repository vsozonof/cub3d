/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:05:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/11 11:59:17 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pov_rotation(t_math *ma, int input)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = ma->dirx;
	printf("voici mon code %d\n", input);
	if (input == 7) // droite
	{
		ma->dirx = ma->dirx * cos(1) - ma->diry * sin(-1);
		ma->diry = oldDirX * sin(-1) + ma->diry * cos(-1);
		oldPlaneX = ma->planex;
		ma->planex = ma->planex * cos(-1) - ma->planey * sin(-1);
		ma->planey = oldPlaneX * sin(-1) + ma->planey * cos(-1);
	}
	else if (input == 5) // gauche
	{
		ma->dirx = ma->dirx * cos(1) - ma->diry * sin(1);
		ma->diry = oldDirX * sin(1) + ma->diry * cos(1);
		oldPlaneX = ma->planex;
		ma->planex = ma->planex * cos(1) - ma->planey * sin(1);
		ma->planey = oldPlaneX * sin(1) + ma->planey * cos(1);
	}
	// printf("pdx = %f et pdy = %f\n", ptr->ma->posx, ptr->ma->posy);
}

void	player_movement(t_math *ma, int input, t_info *ptr)
{
	int	x;
	int	y;
	int	tmp;

	y = ma->posy;
	x = ma->posx;
	printf("voici input %d et voici dirx %f t diry %f\n", input, ma->dirx, ma->diry);
	if (input == 1) // devant
	{
		tmp = (int)ma->posx;
		if(ptr->map[tmp + (int)ma->dirx * 1][(int)ma->posy] == 0) 
			ma->posx += ma->dirx * 1;
		if(ptr->map[(int)ma->posx][(int)ma->posy + (int)ma->diry * 1] == 0) 
			ma->posy += ma->diry * 1;
	}
	// else if (input == 2) // gauche
		// ma->posx -= ma->dirx - 0.5;
	else if (input == 3) // bas
	{
		tmp = (int)ma->posx;
		if(ptr->map[tmp - (int)ma->dirx * 1][(int)ma->posy] == 0) 
			ma->posx -= ma->dirx * 1;
		if(ptr->map[(int)ma->posx][(int)ma->posy - (int)ma->diry * 1] == 0) 
			ma->posy -= ma->diry * 1;
	}
	// else if (input == 4) // droite
		// ma->posx -= ma->dirx - 0.5;
	// ptr->ma->posy = y;
	// ptr->ma->posx = x;
}

void	player_movement_minimap(t_math *ma, int input, t_info *ptr)
{
	int	x;
	int	y;
	(void)ptr;

	y = ma->posy;
	x = ma->posx;
	if (input == 1)
		y = y - 0.5;
	else if (input == 2)
		x = x - 0.5;
	else if (input == 3)
		y = y + 0.5;
	else if (input == 4)
		x = x + 0.5;
	ma->posy = y;
	ma->posx = x;
}

// void	wall_creation_minimap(t_info *ptr)
// {
// 	int		i;
// 	int		j;
// 	int		x;
// 	int		y;

// 	i = ((y = 0));
// 	while (ptr->map[i])
// 	{
// 		j = 0;
// 		x = 0;
// 		while (ptr->map[i][j])
// 		{
// 			if (ptr->map[i][j] == '1')
// 			{
// 				printf("start %d end %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
// 				printf("voici windows height %d\n", ptr->ma->line_Height);
// 				render_rect(&ptr->img, (t_rect){ptr->ma->draw_start, ptr->ma->draw_end,
// 				ptr->ma->draw_start, ptr->ma->draw_end, RED_PIXEL});
// 			}
// 			x = x + 100;
// 			j++;
// 		}
// 		y = y + 120;
// 		i++;
// 	}
// 	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
// }

void	wall_creation_minimap(t_info *ptr)
{
	printf("start %d end %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
	// render_background(&ptr->img, BLACK_PIXEL);
	printf("voici windows height %d\n", ptr->ma->line_Height);
	render_rect(&ptr->img, (t_rect){ptr->ma->draw_start, ptr->ma->draw_end,
				100, 100, RED_PIXEL});
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
}

void	found_pos_player_minimap(t_info *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == 'N' || ptr->map[i][j] == 'S'
				|| ptr->map[i][j] == 'W' || ptr->map[i][j] == 'E')
			{
				ptr->ma->posx = WINDOW_WIDTH - 50;
				ptr->ma->posy = 50;
			}
			j++;
		}
		i++;
	}
}

// void	wall_creation_minimap(t_info *ptr)
// {
// 	int		i;
// 	int		j;
// 	int		x;
// 	int		y;

// 	i = ((y = 0));
// 	while (ptr->map[i])
// 	{
// 		j = 0;
// 		x = 0;
// 		while (ptr->map[i][j])
// 		{
// 			if (ptr->map[i][j] == '1')
// 			{
// 				render_rect(&ptr->img, (t_rect){x, y,
// 				100, 120, WHITE_PIXEL});
// 			}
// 			x = x + 100;
// 			j++;
// 		}
// 		y = y + 120;
// 		i++;
// 	}
// }

// void	wall_creation_minimap(t_info *ptr)
// {
// 	int		i;
// 	int		j;
// 	int		x;
// 	int		y;

// 	i = ((y = 0));
// 	while (ptr->map[i])
// 	{
// 		j = 0;
// 		x = 0;
// 		while (ptr->map[i][j])
// 		{
// 			if (ptr->map[i][j] == '1')
// 			{
// 				printf("start %d end %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
// 				printf("voici windows height %d\n", ptr->ma->line_Height);
// 				render_rect(&ptr->img, (t_rect){j, i,
// 				ptr->ma->draw_start, ptr->ma->draw_end, RED_PIXEL});
// 			}
// 			x = x + 100;
// 			j++;
// 		}
// 		y = y + 120;
// 		i++;
// 	}
// 	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
// }

/* code du 6 avril juste minimap
void	player_pov_rotation(t_info *ptr, int input)
{
	printf("voici mon code %d\n", input);
	if (input == 5) // gauche
	{
		ptr->pa -= 0.1;
		if (ptr->pa < 0)
			ptr->pa += 2 * PI;
		ptr->ma->posx = cos(ptr->pa) * 5;
		ptr->ma->posy = sin(ptr->pa) * 5;
	}
	else if (input == 7) // droite
	{
		ptr->pa += 0.1;
		if (ptr->pa > 2 * PI)
			ptr->pa -= 2 * PI;
		ptr->ma->posx = cos(ptr->pa) * 5;
		ptr->ma->posy = sin(ptr->pa) * 5;
	}
	printf("pdx = %f et pdy = %f\n", ptr->ma->posx, ptr->ma->posy);
	// else if (input == 6) // haut
	// {
	// 	ptr->ma->posx += ptr->ma->posx;
	// 	ptr->ma->posy += ptr->ma->posy;
	// }
	// else if (input == 8) // bas
	// {
	// 	ptr->ma->posx -= ptr->ma->posx;
	// 	ptr->ma->posy -= ptr->ma->posy;
	// }
}

void	player_movement_minimap(t_info *ptr, int input)
{
	int	x;
	int	y;

	y = ptr->ma->posy;
	x = ptr->ma->posx;
	if (input == 1)
		y = y -1;
	else if (input == 2)
		x = x - 1;
	else if (input == 3)
		y = y + 1;
	else if (input == 4)
		x = x + 1;
	ptr->ma->posy = y;
	ptr->ma->posx = x;
}

void	wall_creation_minimap(t_info *ptr)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = ((y = 0));
	while (ptr->map[i])
	{
		j = 0;
		x = WINDOW_WIDTH - 100;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == '1')
			{
				render_rect(&ptr->img, (t_rect){x, y,
				10, 10, RED_PIXEL});
			}
			x = x + 10;
			j++;
		}
		y = y + 10;
		i++;
	}
}

void	found_pos_player_minimap(t_info *ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr->map[i])
	{
		j = 0;
		while (ptr->map[i][j])
		{
			if (ptr->map[i][j] == 'N' || ptr->map[i][j] == 'S'
				|| ptr->map[i][j] == 'W' || ptr->map[i][j] == 'E')
			{
				ptr->ma->posx = WINDOW_WIDTH - 50;
				ptr->ma->posy = 50;
			}
			j++;
		}
		i++;
	}
}
*/