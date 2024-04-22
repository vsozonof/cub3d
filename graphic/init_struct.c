/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/22 10:48:40 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_struct(t_info *ptr, t_utils *util, t_math *ma)
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
	// found_pos_player_minimap();
	ptr->p_mov = 0;
	ptr->pa = 90;
	ptr->ma = ma_init(ma, ptr);
	// ptr->x
	return (0);
}

t_math	*ma_init(t_math *ma, t_info *ptr)
{
	ma->posx = found_player_pos_x(ptr->map) + 0.5; /// trouver pos joueur
	if (ma->posx < 0)
		return (NULL); // faudra free
	ma->posy = found_player_pos_y(ptr->map) + 0.5;
	if (ma->posy < 0)
		return (NULL); // faudra free
	printf("\nmes position de base x %f y %f \n", ma->posx, ma->posy);
	ma->dirx = 0;
	ma->diry = 0; // initialisation des vecteurs
	ma->planex = 0;
	ma->planey = -0.66;
	ma->out = 0;
	return (ma);
}
