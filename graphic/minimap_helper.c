/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:05:36 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/06 08:03:13 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pov_rotation(t_info *ptr, int input)
{
	printf("voici mon code %d\n", input);
	if (input == 5) // gauche
	{
		ptr->pa -= 0.1;
		if (ptr->pa < 0)
			ptr->pa += 2 * PI;
		ptr->pdx = cos(ptr->pa) * 5;
		ptr->pdy = sin(ptr->pa) * 5;
	}
	else if (input == 7) // droite
	{
		ptr->pa += 0.1;
		if (ptr->pa > 2 * PI)
			ptr->pa -= 2 * PI;
		ptr->pdx = cos(ptr->pa) * 5;
		ptr->pdy = sin(ptr->pa) * 5;
	}
	printf("pdx = %f et pdy = %f\n", ptr->pdx, ptr->pdy);
	// else if (input == 6) // haut
	// {
	// 	ptr->p_x += ptr->pdx;
	// 	ptr->p_y += ptr->pdy;
	// }
	// else if (input == 8) // bas
	// {
	// 	ptr->p_x -= ptr->pdx;
	// 	ptr->p_y -= ptr->pdy;
	// }
}

void	player_movement_minimap(t_info *ptr, int input)
{
	int	x;
	int	y;

	y = ptr->p_y;
	x = ptr->p_x;
	if (input == 1)
		y = y -1;
	else if (input == 2)
		x = x - 1;
	else if (input == 3)
		y = y + 1;
	else if (input == 4)
		x = x + 1;
	ptr->p_y = y;
	ptr->p_x = x;
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
				ptr->p_x = WINDOW_WIDTH - 50;
				ptr->p_y = 50;
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
		ptr->pdx = cos(ptr->pa) * 5;
		ptr->pdy = sin(ptr->pa) * 5;
	}
	else if (input == 7) // droite
	{
		ptr->pa += 0.1;
		if (ptr->pa > 2 * PI)
			ptr->pa -= 2 * PI;
		ptr->pdx = cos(ptr->pa) * 5;
		ptr->pdy = sin(ptr->pa) * 5;
	}
	printf("pdx = %f et pdy = %f\n", ptr->pdx, ptr->pdy);
	// else if (input == 6) // haut
	// {
	// 	ptr->p_x += ptr->pdx;
	// 	ptr->p_y += ptr->pdy;
	// }
	// else if (input == 8) // bas
	// {
	// 	ptr->p_x -= ptr->pdx;
	// 	ptr->p_y -= ptr->pdy;
	// }
}

void	player_movement_minimap(t_info *ptr, int input)
{
	int	x;
	int	y;

	y = ptr->p_y;
	x = ptr->p_x;
	if (input == 1)
		y = y -1;
	else if (input == 2)
		x = x - 1;
	else if (input == 3)
		y = y + 1;
	else if (input == 4)
		x = x + 1;
	ptr->p_y = y;
	ptr->p_x = x;
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
				ptr->p_x = WINDOW_WIDTH - 50;
				ptr->p_y = 50;
			}
			j++;
		}
		i++;
	}
}
*/