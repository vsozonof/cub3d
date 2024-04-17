/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:36:20 by tpotilli          #+#    #+#             */
/*   Updated: 2024/04/17 11:27:03 by tpotilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_cf(t_info *ptr)
{
	int		i;
	int		j;

	i = ((j = 0));
	printf("coucou voici draw start et end %d %d\n", ptr->ma->draw_start, ptr->ma->draw_end);
	if (ptr->ma->draw_start > WINDOW_HEIGHT / 2)
	{
		render_rect(&ptr->img, (t_rect){0, 0,
			WINDOW_WIDTH, WINDOW_HEIGHT / 2, BLUE_PIXEL});
	}
	// if (ptr->ma->draw_end < )
	render_rect(&ptr->img, (t_rect){WINDOW_WIDTH, WINDOW_HEIGHT / 2,
			WINDOW_WIDTH, WINDOW_HEIGHT / 2, WHITE_PIXEL});
	// mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.mlx_img, 0, 0);
}
