/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:45:26 by tpotilli          #+#    #+#             */
/*   Updated: 2024/05/22 14:22:01 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_xpm(t_info *ptr)
{
	if (!ptr->tex[0].save || !ptr->tex[1].save
		|| !ptr->tex[2].save || !ptr->tex[3].save)
	{
		printf("donc ici\n");
		if (ptr->tex[0].save)
		{
			printf("non non\n");
			mlx_destroy_image(ptr->mlx, ptr->tex[0].save);
		}
		if (ptr->tex[1].save)
		{
			printf("oui oui\n");
			mlx_destroy_image(ptr->mlx, ptr->tex[1].save);
		}
		if (ptr->tex[2].save)
		{
			printf("la meme\n");
			mlx_destroy_image(ptr->mlx, ptr->tex[2].save);
		}
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
	ptr->tex[0].addr = (int *)mlx_get_data_addr(ptr->tex[0].save, &ptr->tex[0].bpp,
			&ptr->tex[0].line_len, &ptr->tex[0].endian);
	if (!ptr->tex[0].addr)
		free_all_img(ptr);
	ptr->tex[1].addr = (int *)mlx_get_data_addr(ptr->tex[1].save, &ptr->tex[1].bpp,
			&ptr->tex[1].line_len, &ptr->tex[1].endian);
	if (!ptr->tex[1].addr)
		free_all_img(ptr);
	initialize_addr_help(ptr);
}

void	initialize_addr_help(t_info *ptr)
{
	ptr->tex[2].addr = (int *)mlx_get_data_addr(ptr->tex[2].save, &ptr->tex[2].bpp,
			&ptr->tex[2].line_len, &ptr->tex[2].endian);
	if (!ptr->tex[2].addr)
		free_all_img(ptr);
	ptr->tex[3].addr = (int *)mlx_get_data_addr(ptr->tex[3].save, &ptr->tex[3].bpp,
			&ptr->tex[3].line_len, &ptr->tex[3].endian);
	if (!ptr->tex[3].addr)
		free_all_img(ptr);
}
