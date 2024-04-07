/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:05:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/07 10:43:41 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pov_rotation(t_math *ma, int input)
{
	printf("voici mon code %d\n", input);
	if (input == 7) // droite
	{
		ma->old_dirx = ma->dirx;
		ma->dirx = ma->dirx * cos(-5) - ma->diry * sin(-5);
		ma->diry = ma->old_diry * sin(-5) + ma->diry * cos(-5);
		ma->old_planex = ma->planex;
		ma->planex = ma->planex * cos(-5) - ma->planey * sin(-5);
		ma->planey = ma->old_planex * sin(-5) + ma->planey * cos(-5);
	}
	else if (input == 5) // gauche
	{
		ma->old_dirx = ma->dirx;
		ma->dirx = ma->dirx * cos(5) - ma->diry * sin(5);
		ma->diry = ma->old_diry * sin(5) + ma->diry * cos(5);
		ma->old_planex = ma->planex;
		ma->planex = ma->planex * cos(5) - ma->planey * sin(5);
		ma->planey = ma->old_planex * sin(5) + ma->planey * cos(5);
	}
	// printf("pdx = %f et pdy = %f\n", ptr->ma->posx, ptr->ma->posy);
}

void	player_movement(t_math *ma, int input)
{
	int	x;
	int	y;

	y = ma->posy;
	x = ma->posx;
	if (input == 1) // devant
	{
		ma->posx += ma->dirx * 2;
		ma->posy += ma->diry * 2;
	}
	else if (input == 2) // derriere
	{
		ma->posx -= ma->dirx * 2;
		ma->posy -= ma->diry * 2;
	}
	else if (input == 3) // droite a voir plus tard
		y = y + 1;
	else if (input == 4) // gauche
		x = x + 1;
	// ptr->ma->posy = y;
	// ptr->ma->posx = x;
}

void	wall_creation_minimap(t_info *ptr)
{
	render_rect(&ptr->img, (t_rect){ptr->ma->draw_start, ptr->ma->draw_end,
				ptr->ma->line_Height, 30, WHITE_PIXEL});
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