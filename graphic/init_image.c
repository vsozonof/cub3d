/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:45:26 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/23 13:27:06 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_xpm(t_info *ptr)
{
	if (!ptr->tex[0].save || !ptr->tex[1].save
		|| !ptr->tex[2].save || !ptr->tex[3].save)
	{
		if (ptr->tex[0].save)
			mlx_destroy_image(ptr->mlx, ptr->tex[0].save);
		if (ptr->tex[1].save)
			mlx_destroy_image(ptr->mlx, ptr->tex[1].save);
		if (ptr->tex[2].save)
			mlx_destroy_image(ptr->mlx, ptr->tex[2].save);
		if (ptr->tex[3].save)
			mlx_destroy_image(ptr->mlx, ptr->tex[3].save);
		free_parsing_fonction(ptr);
		mlx_destroy_image(ptr->mlx, ptr->img.mlx_img);
		mlx_destroy_window(ptr->mlx, ptr->win);
		mlx_destroy_display(ptr->mlx);
		free(ptr->mlx);
		exit(1);
	}
}

void	initialize_addr(t_info *ptr)
{
	if (!ptr->tex[0].addr || !ptr->tex[1].addr
		|| !ptr->tex[2].addr || !ptr->tex[3].addr
		|| !ptr->img.addr)
	{
		mlx_destroy_image(ptr->mlx, ptr->tex[0].save);
		mlx_destroy_image(ptr->mlx, ptr->tex[1].save);
		mlx_destroy_image(ptr->mlx, ptr->tex[2].save);
		mlx_destroy_image(ptr->mlx, ptr->tex[3].save);
		free_parsing_fonction(ptr);
		mlx_destroy_image(ptr->mlx, ptr->img.mlx_img);
		mlx_destroy_window(ptr->mlx, ptr->win);
		mlx_destroy_display(ptr->mlx);
		free(ptr->mlx);
		exit(1);
	}
}
