/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:36:20 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/17 11:01:36 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_cf(t_info *ptr)
{
	int		i;
	int		j;

	i = ((j = 0));
	printf("coucouc\n");
	render_rect(&ptr->img, (t_rect){0, 0,
			WINDOW_WIDTH, WINDOW_HEIGHT / 2, BLUE_PIXEL});
	render_rect(&ptr->img, (t_rect){WINDOW_WIDTH, WINDOW_HEIGHT / 2,
			WINDOW_WIDTH, WINDOW_HEIGHT / 2, RED_PIXEL});
	// mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
}
