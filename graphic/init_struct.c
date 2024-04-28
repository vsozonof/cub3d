/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:59:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/28 11:06:23 by tpotilli         ###   ########.fr       */
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
	ma->posx = found_player_pos_x(ptr->utils->map) + 0.5; /// trouver pos joueur
	if (ma->posx < 0)
		return (NULL); // faudra free
	ma->posy = found_player_pos_y(ptr->utils->map) + 0.5;
	if (ma->posy < 0)
		return (NULL); // faudra free
	printf("\nmes position de base x %f y %f \n", ma->posx, ma->posy);
	setup_cardinal_point(ma, ptr);
	ma->out = 0;
	return (ma);
}

void	setup_cardinal_point(t_math *ma, t_info *ptr)
{
	if (player_tag(ptr) == 1) // Nord
	{
		printf("je suis dans le nord\n");
		ma->dirx = 0;
		ma->diry = 0; // initialisation des vecteurs
		ma->planex = 0;
		ma->planey = -0.66;
	}
	else if (player_tag(ptr) == 2) // Sud -> deuxieme bon
	{ // voir comment changer les mouvements 
		printf("je suis dans le sud\n");
		ma->dirx = 0;
		ma->diry = 0; // initialisation des vecteurs
		ma->planex = -0.66;
		ma->planey = 0;
	}
	else if (player_tag(ptr) == 3) // Est -> le seul bon pour le moment
	{ // voir comment changer les mouvements
		ma->dirx = 0;
		ma->diry = 0; // initialisation des vecteurs
		ma->planex = 0;
		ma->planey = 0.66;
	}
	else if (player_tag(ptr) == 4) // West
	{
		printf("je suis dans le ouest\n");
		ma->dirx = 0;
		ma->diry = 0; // initialisation des vecteurs
		ma->planex = -0.66;
		ma->planey = 0;
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
