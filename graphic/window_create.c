/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:22:35 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/11 07:40:47 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// pour ca j'ai besoin de cree des pointeur de la mlx
int	window_create(t_data *data, t_utils *utils)
{
	window_creation(data, utils);
	return (0);
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
		player_movement(ptr->ma, ptr->p_mov, ptr);
	}
	if (ptr->p_mov == 5 || ptr->p_mov == 6 ||
		ptr->p_mov == 7 || ptr->p_mov == 8)
	{
		player_pov_rotation(ptr->ma, ptr->p_mov);
	}
	// else
	// {
	// 	ptr->ma->posx = 0;
	// 	ptr->ma->posy = 0;
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
		if (ptr->map[(int)ptr->ma->posy - 1][(int)ptr->ma->posx] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 2)
	{
		if (ptr->map[(int)ptr->ma->posy][(int)ptr->ma->posx - 1] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 3)
	{
		if (ptr->map[(int)ptr->ma->posy + 1][(int)ptr->ma->posx] == '1')
			return (-1);
	}
	else if (ptr->p_mov == 4)
	{
		if (ptr->map[(int)ptr->ma->posy][(int)ptr->ma->posx + 1] == '1')
			return (-1);
	}
	return (0);
}
