/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:36:10 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/27 09:11:10 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	soft_free(t_info *ptr)
{
	free(ptr->win);
	free(ptr->mlx);
	exit (1);
}

void	free_all_img(t_info *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->tex[0].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[1].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[2].save);
	mlx_destroy_image(ptr->mlx, ptr->tex[3].save);
	soft_free(ptr);
}

void	free_parsing_fonction(t_info *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->utils->north);
	mlx_destroy_image(ptr->mlx, ptr->utils->west);
	mlx_destroy_image(ptr->mlx, ptr->utils->east);
	mlx_destroy_image(ptr->mlx, ptr->utils->south);
	free(ptr->data->north_texture);
	free(ptr->data->east_texture);
	free(ptr->data->west_texture);
	free(ptr->data->south_texture);
	free_db_tab(ptr->utils->map);
	free(ptr->utils->floor_color[0]);
	free(ptr->utils->floor_color[1]);
	free(ptr->utils->floor_color[2]);
	free(ptr->utils->ceiling_color[0]);
	free(ptr->utils->ceiling_color[1]);
	free(ptr->utils->ceiling_color[2]);
	free(ptr->utils->floor_color);
	free(ptr->utils->ceiling_color);
}

void		free_all_bef(t_info *ptr)
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
