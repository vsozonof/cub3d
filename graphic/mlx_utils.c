/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:24:12 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/06 08:24:50 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_windows_esc(t_info *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit(0);
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
