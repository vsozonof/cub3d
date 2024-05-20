/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:24:12 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/20 08:54:02 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_windows_esc(t_info *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->utils->north);
	mlx_destroy_image(ptr->mlx, ptr->utils->west);
	mlx_destroy_image(ptr->mlx, ptr->utils->east);
	mlx_destroy_image(ptr->mlx, ptr->utils->south);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	free_db_tab(ptr->utils->map);
	free(ptr->utils->floor_color[0]);
	free(ptr->utils->floor_color[1]);
	free(ptr->utils->floor_color[2]);
	free(ptr->utils->ceiling_color[0]);
	free(ptr->utils->ceiling_color[1]);
	free(ptr->utils->ceiling_color[2]);
	free(ptr->utils->floor_color);
	free(ptr->utils->ceiling_color);
	exit(0);
}

int	mouse_hook(t_info *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	free_db_tab(ptr->utils->map);
	exit (0);
}
