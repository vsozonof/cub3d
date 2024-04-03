/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:22:35 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/03 08:10:11 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// pour ca j'ai beosin de cree des pointeur de la mlx
int	window_create(t_data *data, t_utils *utils)
{
	(void)data;
	(void)utils;
	// ptr->win = mlx_new_window(ptr->mlx, WINDOW_WIDTH,
	// 				WINDOW_HEIGHT, "Cub3d");
	// if (ptr->win == NULL)
	// 	return (-1);
	// ptr->fov = 90;
	// essaie(data, ptr, utils);
	// draw_player_minimap(data, ptr, utils);
	minimap();
	// game_start(ptr);
	// apres mettre image
	return (0);
}

void	game_start(t_info *ptr)
{
	mlx_loop_hook(ptr->mlx, &render, ptr);
	mlx_hook(ptr->win, 17, 0, mouse_hook, ptr);
	mlx_key_hook(ptr->win, get_key_hook, ptr);
	mlx_loop(ptr->mlx);
}

int	mouse_hook(t_info *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit (0);
}

int	get_key_hook(int keycode, t_info *ptr)
{
	if (keycode == 65107)
		return (0);
	ptr->p_mov = 0;
	if (keycode == 119)
		ptr->p_mov = 1;
	else if (keycode == 97)
		ptr->p_mov = 2;
	else if (keycode == 115)
		ptr->p_mov = 3;
	else if (keycode == 100)
		ptr->p_mov = 4;
	if (keycode == 65307)
	{
		close_windows_esc(ptr);
		exit (0);
	}
	// if (keycode == 119 || keycode == 97 || keycode == 115
	// 	|| keycode == 100)
	// {
	// 	if (try_moove(ptr) == 0)
	// 		player_movement(ptr, ptr->p_mov);
	// }
	return (0);
}

void	close_windows_esc(t_info *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit(0);
}