/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:16:22 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/03 18:40:10 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exec_manager(int argc, char **argv, t_data *data, t_utils *utils)
{
	(void)argc;
	(void)argv;
	// t_game	game;
	// t_info	ptr;
	(void)data;

	// ptr.mlx = mlx_init();
	// if (!ptr.mlx)
		// return (-1);
	// puis ici init image
	window_create(data, utils);
	// init_struct(&game, argv);
	// exec_tmp();
	// free(ptr.mlx);
	// mlx_destroy_display(&ptr.mlx);
	return (0);
}

int		essaie(t_data *data, t_info *ptr, t_utils *utils)
{
	int	token;
	(void)data;

	token = 0;
	token = found_player_type(utils);
	if (token == 0)
		printf("error when searching player pos\n");
	if (refresh_player_pos(utils->map, ptr) == -1)
		return (-1);
	printf("voici les pos joueur %d %d\n", ptr->p_x, ptr->p_y);
	return (0);
}

// donc ce que je dois faire: prendre la position du joueur suivant la lettre 
// (R par exemple) puis a partir de sa position regarder les wall suivants
// peut etre devoir utiliser double

int	refresh_player_pos(char **argv, t_info *ptr)
{
	ptr->p_x = found_player_pos_x(argv);
	if (ptr->p_x == -1)
		return (printf("error when searching player 1\n"), -1);
	ptr->p_y = found_player_pos_y(argv);
	if (ptr->p_y == -1)
		return (printf("error when searching player 2\n"), -1);
	return (0);
}

// int	init_struct(t_game *ptr, char **argv)
// {
// 	ptr->x;
// 	ptr->y;
// }

	// printf("voici map %s\n", data->map);
	// printf("voici floor %s\n", data->floor_color);
	// printf("voici ceiling %s\n", data->ceiling_color);