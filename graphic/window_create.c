/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:22:35 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/03 13:41:28 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// pour ca j'ai beosin de cree des pointeur de la mlx
int	window_create(t_data *data, t_utils *utils)
{
	// ptr->win = mlx_new_window(ptr->mlx, WINDOW_WIDTH,
	// 				WINDOW_HEIGHT, "Cub3d");
	// if (ptr->win == NULL)
	// 	return (-1);
	// ptr->fov = 90;
	// essaie(data, ptr, utils);
	// draw_player_minimap(data, ptr, utils);
	window_creation(data, utils);
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
	else
		ptr->p_mov = check_keycode(keycode);
	if (keycode == 65307)
	{
		close_windows_esc(ptr);
		exit (0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115
		|| keycode == 100)
	{
		// if (try_moove(ptr) == 0)
		player_movement_minimap(ptr, ptr->p_mov);
	}
	if (ptr->p_mov == 5 || ptr->p_mov == 6 ||
		ptr->p_mov == 7 || ptr->p_mov == 8)
	{
		player_pov_rotation(ptr, ptr->p_mov);
	}
	// else
	// {
	// 	ptr->pdx = 0;
	// 	ptr->pdy = 0;
	// 	ptr->pa = 0;
	// }
	return (0);
}

int	check_keycode(int keycode)
{
	if (keycode == 65363) // droite
		return (7);
	else if (keycode == 65362) // haut
		return (6);
	else if (keycode == 65361) // gauche
		return (5);
	else if (keycode == 65364) // bas
		return (8);
	return (-1);
}

int	try_moove(t_info *ptr)
{
	if (ptr->p_mov == 1)
	{
		if (ptr->map[ptr->p_y - 1][ptr->p_x] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 2)
	{
		if (ptr->map[ptr->p_y][ptr->p_x - 1] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 3)
	{
		if (ptr->map[ptr->p_y + 1][ptr->p_x] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 4)
	{
		if (ptr->map[ptr->p_y][ptr->p_x + 1] == '1')
			return (-1);
	}
	return (0);
}

void	close_windows_esc(t_info *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit(0);
}
