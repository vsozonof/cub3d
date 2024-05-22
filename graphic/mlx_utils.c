/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 08:24:12 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/22 10:53:28 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_windows_esc(t_info *ptr)
{
	free_parsing_fonction(ptr);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_image(ptr->mlx, ptr->img.mlx_img);
	mlx_destroy_image(ptr->mlx, ptr->tex[0].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[1].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[2].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[3].save);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit(0);
}

int	mouse_hook(t_info *ptr)
{
	free_parsing_fonction(ptr);
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_image(ptr->mlx, ptr->img.mlx_img);
	mlx_destroy_image(ptr->mlx, ptr->tex[0].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[1].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[2].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[3].save);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit(0);
}
